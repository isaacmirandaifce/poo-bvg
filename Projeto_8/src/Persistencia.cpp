#include "Persistencia.h"

#include <filesystem>
#include <fstream>
#include <map>
#include <sstream>

Persistencia::Persistencia(std::string diretorioBase)
    : diretorioBase(std::move(diretorioBase)) {}

std::string Persistencia::caminhoAlunos() const {
    return diretorioBase + "/alunos.txt";
}

std::string Persistencia::caminhoHistorico() const {
    return diretorioBase + "/historico.txt";
}

std::string Persistencia::caminhoProfessores() const {
    return diretorioBase + "/professores.txt";
}

std::string Persistencia::caminhoProfessorDisciplinas() const {
    return diretorioBase + "/professor_disciplinas.txt";
}

std::string Persistencia::caminhoDisciplinas() const {
    return diretorioBase + "/disciplinas.txt";
}

std::vector<std::string> Persistencia::dividirLinha(const std::string& linha, char separador) const {
    std::vector<std::string> partes;
    std::stringstream ss(linha);
    std::string item;
    while (std::getline(ss, item, separador)) {
        partes.push_back(item);
    }
    return partes;
}

void Persistencia::salvarTudo(const DadosAcademicos& dados) const {
    std::filesystem::create_directories(diretorioBase);

    {
        std::ofstream arq(caminhoAlunos());
        if (!arq.is_open()) {
            throw PermissaoNegadaException(caminhoAlunos());
        }

        arq << "nome;email;senha\n";
        for (const auto& aluno : dados.alunos) {
            arq << aluno.getNome() << ';' << aluno.getEmail() << ';' << aluno.getSenha() << "\n";
        }
    }

    {
        std::ofstream arq(caminhoHistorico());
        if (!arq.is_open()) {
            throw PermissaoNegadaException(caminhoHistorico());
        }

        arq << "email;disciplina;ano;nota\n";
        for (const auto& aluno : dados.alunos) {
            for (const auto& item : aluno.getHistorico()) {
                arq << aluno.getEmail() << ';' << item.getDisciplina() << ';' << item.getAno() << ';'
                    << item.getNota() << "\n";
            }
        }
    }

    {
        std::ofstream arq(caminhoProfessores());
        if (!arq.is_open()) {
            throw PermissaoNegadaException(caminhoProfessores());
        }

        arq << "nome;email;senha;departamento\n";
        for (const auto& professor : dados.professores) {
            arq << professor.getNome() << ';' << professor.getEmail() << ';' << professor.getSenha() << ';'
                << professor.getDepartamento() << "\n";
        }
    }

    {
        std::ofstream arq(caminhoProfessorDisciplinas());
        if (!arq.is_open()) {
            throw PermissaoNegadaException(caminhoProfessorDisciplinas());
        }

        arq << "email;disciplina\n";
        for (const auto& professor : dados.professores) {
            for (const auto& disciplina : professor.getDisciplinasMinistradas()) {
                arq << professor.getEmail() << ';' << disciplina << "\n";
            }
        }
    }

    {
        std::ofstream arq(caminhoDisciplinas());
        if (!arq.is_open()) {
            throw PermissaoNegadaException(caminhoDisciplinas());
        }

        arq << "disciplina\n";
        for (const auto& disciplina : dados.disciplinas) {
            arq << disciplina << "\n";
        }
    }
}

void Persistencia::carregarTudo(DadosAcademicos& dados) const {
    using std::filesystem::exists;

    const std::vector<std::string> arquivosObrigatorios = {
        caminhoAlunos(),
        caminhoHistorico(),
        caminhoProfessores(),
        caminhoProfessorDisciplinas(),
        caminhoDisciplinas()
    };

    for (const auto& caminho : arquivosObrigatorios) {
        if (!exists(caminho)) {
            throw ArquivoNaoEncontradoException(caminho);
        }
    }

    dados.alunos.clear();
    dados.professores.clear();
    dados.disciplinas.clear();

    std::map<std::string, std::size_t> indiceAlunoPorEmail;
    std::map<std::string, std::size_t> indiceProfessorPorEmail;

    {
        std::ifstream arq(caminhoAlunos());
        if (!arq.is_open()) {
            throw PermissaoNegadaException(caminhoAlunos());
        }

        std::string linha;
        std::getline(arq, linha);

        while (std::getline(arq, linha)) {
            if (linha.empty()) {
                continue;
            }

            auto partes = dividirLinha(linha, ';');
            if (partes.size() != 3) {
                throw FalhaConversaoException("linha invalida em alunos.txt: " + linha);
            }

            dados.alunos.emplace_back(partes[0], partes[1], partes[2]);
            indiceAlunoPorEmail[partes[1]] = dados.alunos.size() - 1;
        }
    }

    {
        std::ifstream arq(caminhoHistorico());
        if (!arq.is_open()) {
            throw PermissaoNegadaException(caminhoHistorico());
        }

        std::string linha;
        std::getline(arq, linha);

        while (std::getline(arq, linha)) {
            if (linha.empty()) {
                continue;
            }

            auto partes = dividirLinha(linha, ';');
            if (partes.size() != 4) {
                throw FalhaConversaoException("linha invalida em historico.txt: " + linha);
            }

            auto itAluno = indiceAlunoPorEmail.find(partes[0]);
            if (itAluno == indiceAlunoPorEmail.end()) {
                throw FalhaConversaoException("email de aluno nao encontrado no historico: " + partes[0]);
            }

            int ano = 0;
            float nota = 0.0f;
            try {
                ano = std::stoi(partes[2]);
                nota = std::stof(partes[3]);
            } catch (const std::exception&) {
                throw FalhaConversaoException("ano/nota invalidos no historico: " + linha);
            }

            dados.alunos[itAluno->second].adicionarDisciplina(partes[1], ano, nota);
        }
    }

    {
        std::ifstream arq(caminhoProfessores());
        if (!arq.is_open()) {
            throw PermissaoNegadaException(caminhoProfessores());
        }

        std::string linha;
        std::getline(arq, linha);

        while (std::getline(arq, linha)) {
            if (linha.empty()) {
                continue;
            }

            auto partes = dividirLinha(linha, ';');
            if (partes.size() != 4) {
                throw FalhaConversaoException("linha invalida em professores.txt: " + linha);
            }

            dados.professores.emplace_back(partes[0], partes[1], partes[2], partes[3]);
            indiceProfessorPorEmail[partes[1]] = dados.professores.size() - 1;
        }
    }

    {
        std::ifstream arq(caminhoProfessorDisciplinas());
        if (!arq.is_open()) {
            throw PermissaoNegadaException(caminhoProfessorDisciplinas());
        }

        std::string linha;
        std::getline(arq, linha);

        while (std::getline(arq, linha)) {
            if (linha.empty()) {
                continue;
            }

            auto partes = dividirLinha(linha, ';');
            if (partes.size() != 2) {
                throw FalhaConversaoException("linha invalida em professor_disciplinas.txt: " + linha);
            }

            auto itProfessor = indiceProfessorPorEmail.find(partes[0]);
            if (itProfessor == indiceProfessorPorEmail.end()) {
                throw FalhaConversaoException("email de professor nao encontrado: " + partes[0]);
            }

            dados.professores[itProfessor->second].adicionarDisciplinaMinistrada(partes[1]);
        }
    }

    {
        std::ifstream arq(caminhoDisciplinas());
        if (!arq.is_open()) {
            throw PermissaoNegadaException(caminhoDisciplinas());
        }

        std::string linha;
        std::getline(arq, linha);

        while (std::getline(arq, linha)) {
            if (!linha.empty()) {
                dados.disciplinas.push_back(linha);
            }
        }
    }
}
