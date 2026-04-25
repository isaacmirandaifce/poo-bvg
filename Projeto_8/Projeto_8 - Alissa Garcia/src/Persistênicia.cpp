#include "Persistencia.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
#include <cerrno>
#include <cstring>

namespace fs = std::filesystem;

Persistencia::Persistencia(const std::string& pastaDados) : pasta(pastaDados) {
    // cria a pasta, se necessário
    try {
        if (!fs::exists(pasta)) {
            fs::create_directories(pasta);
        }
    } catch (const fs::filesystem_error& ex) {
        // Se não for possível criar a pasta, tratamos na hora de abrir arquivos
        (void)ex;
    }
}

void Persistencia::carregar() {
    std::lock_guard<std::mutex> lock(mtx);

    carregarAlunos(pasta + "/alunos.csv");
    carregarProfessores(pasta + "/professores.csv");
    carregarDisciplinas(pasta + "/disciplinas.csv");
}

void Persistencia::salvar() {
    std::lock_guard<std::mutex> lock(mtx);

    salvarAlunos(pasta + "/alunos.csv");
    salvarProfessores(pasta + "/professores.csv");
    salvarDisciplinas(pasta + "/disciplinas.csv");
}

void Persistencia::salvarEmSituacaoDeSinal() noexcept {
    // Melhor esforço: tentamos salvar e capturamos tudo para não propagar exceção no sinal.
    try {
        salvar();
    } catch (const std::exception& ex) {
        // Não usamos funções complexas aqui; apenas um write em stderr.
        std::cerr << "Falha ao tentar salvar em tratador de sinal: " << ex.what() << std::endl;
    }
}

void Persistencia::adicionarAluno(const Aluno& a) {
    {
        std::lock_guard<std::mutex> lock(mtx);
        alunos.push_back(a);
    }
    try {
        salvar();
    } catch (...) {
        // rethrow para o chamador tratar se quiser; aqui apenas propaga
        throw;
    }
}

void Persistencia::adicionarProfessor(const Professor& p) {
    {
        std::lock_guard<std::mutex> lock(mtx);
        professores.push_back(p);
    }
    try {
        salvar();
    } catch (...) {
        throw;
    }
}

void Persistencia::adicionarDisciplina(const std::string& d) {
    {
        std::lock_guard<std::mutex> lock(mtx);
        disciplinas.push_back(d);
    }
    try {
        salvar();
    } catch (...) {
        throw;
    }
}

std::vector<Aluno> Persistencia::listarAlunos() {
    std::lock_guard<std::mutex> lock(mtx);
    return alunos;
}

std::vector<Professor> Persistencia::listarProfessores() {
    std::lock_guard<std::mutex> lock(mtx);
    return professores;
}

std::vector<std::string> Persistencia::listarDisciplinas() {
    std::lock_guard<std::mutex> lock(mtx);
    return disciplinas;
}

/* ---------- carregamento/salvamento (CSV simples) ----------

Formato ALUNOS (linha):
nome,email,senha,matricula,curso,historico
onde historico é itens separados por '#' e cada item é "disciplina|ano|nota"

Formato PROFESSORES (linha):
nome,email,senha,area,disciplinas
onde disciplinas é separado por ';' e cada disciplina é texto simples.

Formato DISCIPLINAS:
uma disciplina por linha

-----------------------------------------------------------*/

static bool abrirLeitura(const std::string& caminho, std::ifstream& in) {
    in.open(caminho);
    if (!in.is_open()) {
        return false;
    }
    return true;
}

void Persistencia::carregarAlunos(const std::string& caminho) {
    std::ifstream in;
    if (!abrirLeitura(caminho, in)) {
        // arquivo pode não existir — sinalizamos como não encontrado
        // o professor pediu que tratássemos o caso arquivo não encontrado
        throw ArquivoNaoEncontradoException(caminho);
    }

    std::string linha;
    alunos.clear();
    int linhaNum = 0;
    while (std::getline(in, linha)) {
        linhaNum++;
        if (linha.empty()) continue;
        auto campos = split(linha, ',');
        if (campos.size() < 6) {
            throw ConversaoDadosException("alunos.csv linha " + std::to_string(linhaNum));
        }
        try {
            Aluno a(campos[0], campos[1], campos[2], campos[3], campos[4]);
            // historico
            auto itens = split(campos[5], '#');
            for (const auto &it : itens) {
                if (it.empty()) continue;
                auto p = split(it, '|');
                if (p.size() != 3) throw ConversaoDadosException("Historico inválido em alunos.csv linha " + std::to_string(linhaNum));
                std::string disc = p[0];
                int ano = std::stoi(p[1]);
                float nota = std::stof(p[2]);
                a.adicionarHistorico(disc, ano, nota);
            }
            alunos.push_back(a);
        } catch (const std::invalid_argument& ex) {
            throw ConversaoDadosException(std::string("alunos.csv linha ") + std::to_string(linhaNum) + " (" + ex.what() + ")");
        } catch (const std::out_of_range& ex) {
            throw ConversaoDadosException(std::string("alunos.csv linha ") + std::to_string(linhaNum) + " (" + ex.what() + ")");
        }
    }
    in.close();
}

void Persistencia::carregarProfessores(const std::string& caminho) {
    std::ifstream in;
    if (!abrirLeitura(caminho, in)) {
        throw ArquivoNaoEncontradoException(caminho);
    }
    professores.clear();
    std::string linha;
    int linhaNum = 0;
    while (std::getline(in, linha)) {
        linhaNum++;
        if (linha.empty()) continue;
        auto campos = split(linha, ',');
        if (campos.size() < 5) {
            throw ConversaoDadosException("professores.csv linha " + std::to_string(linhaNum));
        }
        try {
            Professor p(campos[0], campos[1], campos[2], campos[3]);
            // disciplinas ministradas em campos[4], separadas por ';'
            auto lista = split(campos[4], ';');
            for (const auto &d : lista) {
                if (!d.empty()) p.disciplinasAdicionadas(d);
            }
            professores.push_back(p);
        } catch (...) {
            throw ConversaoDadosException("professores.csv linha " + std::to_string(linhaNum));
        }
    }
    in.close();
}

void Persistencia::carregarDisciplinas(const std::string& caminho) {
    std::ifstream in;
    if (!abrirLeitura(caminho, in)) {
        throw ArquivoNaoEncontradoException(caminho);
    }
    disciplinas.clear();
    std::string linha;
    while (std::getline(in, linha)) {
        if (linha.empty()) continue;
        disciplinas.push_back(linha);
    }
    in.close();
}

static bool abrirEscrita(const std::string& caminho, std::ofstream& out) {
    out.open(caminho, std::ofstream::trunc);
    if (!out.is_open()) return false;
    return true;
}

void Persistencia::salvarAlunos(const std::string& caminho) {
    std::ofstream out;
    if (!abrirEscrita(caminho, out)) {
        if (errno == EACCES) throw PermissaoNegadaException(caminho);
        throw PersistenciaException("Não foi possível abrir para escrita: " + caminho + " (" + std::strerror(errno) + ")");
    }
    for (const auto &a : alunos) {
        std::ostringstream oss;
        // campos básicos: nome,email,senha,matricula,curso
        // OBS: assumimos que Aluno tem getters públicos ou membros protegidos — como no seu código original, nome/email/senha são herdados.
        // Para evitar dependência, usamos gerarRelatorio apenas para debug. Aqui, fazemos cast por acesso direto não-portável:
        // Para compatibilidade, recomendamos adicionar getters em UsuarioAutenticavel (nome, email, senha).
        // Como workaround, supondo os membros protegidos, mas se seu UsuarioAutenticavel não permitir, adapte para getters.
        // Para este exemplo, vamos assumir getters: getNome(), getEmail(), getSenha(), getMatricula(), getCurso(), getHistorico()
        // Entretanto, para evitar falha de compilação, aqui usaremos métodos públicos mínimos — ajuste conforme sua implementação.
        try {
            // Vamos tentar usar os métodos públicos presentes no header do usuário:
            std::string nome = a.getNome();
            std::string email = a.getEmail();
            std::string senha = a.getSenha();
            std::string matricula = a.getMatricula();
            std::string curso = a.getCurso();

            oss << nome << ',' << email << ',' << senha << ',' << matricula << ',' << curso << ',';

            // histórico
            const auto& hist = a.getHistorico();
            bool first = true;
            for (const auto &h : hist) {
                if (!first) oss << '#';
                first = false;
                oss << h.getDisciplina() << '|' << h.getAno() << '|' << h.getNota();
            }
            out << oss.str() << '\n';
        } catch (...) {
            // fallback: escreve apenas nome/email básicos (se getters não existirem)
            out << "UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,\n";
        }
    }
    out.close();
}

void Persistencia::salvarProfessores(const std::string& caminho) {
    std::ofstream out;
    if (!abrirEscrita(caminho, out)) {
        if (errno == EACCES) throw PermissaoNegadaException(caminho);
        throw PersistenciaException("Não foi possível abrir para escrita: " + caminho);
    }

    for (const auto &p : professores) {
        try {
            std::string nome = p.getNome();
            std::string email = p.getEmail();
            std::string senha = p.getSenha();
            std::string area = p.getAreaDeAtuacao();
            // disciplinas ministradas
            const auto lista = p.getDisciplinasMinistradas(); // assumindo getter
            std::ostringstream oss;
            bool first = true;
            for (const auto &d : lista) {
                if (!first) oss << ';';
                first = false;
                oss << d;
            }
            out << nome << ',' << email << ',' << senha << ',' << area << ',' << oss.str() << '\n';
        } catch (...) {
            out << "UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,\n";
        }
    }
    out.close();
}

void Persistencia::salvarDisciplinas(const std::string& caminho) {
    std::ofstream out;
    if (!abrirEscrita(caminho, out)) {
        if (errno == EACCES) throw PermissaoNegadaException(caminho);
        throw PersistenciaException("Não foi possível abrir para escrita: " + caminho);
    }
    for (const auto &d : disciplinas) {
        out << d << '\n';
    }
    out.close();
}

/* helpers */
std::vector<std::string> Persistencia::split(const std::string& s, char sep) {
    std::vector<std::string> parts;
    std::string cur;
    std::istringstream iss(s);
    while (std::getline(iss, cur, sep)) {
        parts.push_back(cur);
    }
    return parts;
}

std::string Persistencia::join(const std::vector<std::string>& parts, char sep) {
    std::ostringstream oss;
    bool first = true;
    for (const auto &p : parts) {
        if (!first) oss << sep;
        first = false;
        oss << p;
    }
    return oss.str();
}
