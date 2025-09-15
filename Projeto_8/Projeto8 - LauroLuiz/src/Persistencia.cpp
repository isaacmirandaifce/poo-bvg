#include "Persistencia.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

void Persistencia::verificarArquivo(const std::string& arquivo, std::ios_base::openmode modo) {
    std::fstream file(arquivo, modo);
    if (!file.is_open()) {
        if (modo & std::ios::in) {
            throw ArquivoNaoEncontradoException(arquivo);
        } else {
            throw PermissaoNegadaException(arquivo);
        }
    }
    file.close();
}

std::vector<std::string> Persistencia::split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

int Persistencia::stringParaInt(const std::string& str) {
    try {
        return std::stoi(str);
    } catch (const std::invalid_argument&) {
        throw FalhaConversaoException("Conversão para inteiro: " + str);
    } catch (const std::out_of_range&) {
        throw FalhaConversaoException("Valor fora do alcance para inteiro: " + str);
    }
}

double Persistencia::stringParaDouble(const std::string& str) {
    try {
        return std::stod(str);
    } catch (const std::invalid_argument&) {
        throw FalhaConversaoException("Conversão para double: " + str);
    } catch (const std::out_of_range&) {
        throw FalhaConversaoException("Valor fora do alcance para double: " + str);
    }
}

void Persistencia::salvarAlunos(const std::vector<Aluno>& alunos, const std::string& arquivo) {
    try {
        std::ofstream file(arquivo);
        if (!file.is_open()) {
            throw PermissaoNegadaException(arquivo);
        }

        file << "id,nome,curso,nota\n";
        for (const auto& aluno : alunos) {
            file << aluno.getId() << ","
                 << aluno.getNome() << ","
                 << aluno.getCurso() << ","
                 << aluno.getNota() << "\n";
        }

        file.close();
        std::cout << "Dados dos alunos salvos com sucesso em " << arquivo << std::endl;
    } catch (const std::exception& e) {
        throw;
    }
}

void Persistencia::salvarProfessores(const std::vector<Professor>& professores, const std::string& arquivo) {
    try {
        std::ofstream file(arquivo);
        if (!file.is_open()) {
            throw PermissaoNegadaException(arquivo);
        }

        file << "id,nome,disciplina,departamento\n";
        for (const auto& professor : professores) {
            file << professor.getId() << ","
                 << professor.getNome() << ","
                 << professor.getDisciplina() << ","
                 << professor.getDepartamento() << "\n";
        }

        file.close();
        std::cout << "Dados dos professores salvos com sucesso em " << arquivo << std::endl;
    } catch (const std::exception& e) {
        throw;
    }
}

void Persistencia::salvarDisciplinas(const std::vector<Disciplina>& disciplinas, const std::string& arquivo) {
    try {
        std::ofstream file(arquivo);
        if (!file.is_open()) {
            throw PermissaoNegadaException(arquivo);
        }

        file << "codigo,nome,carga_horaria,creditos\n";
        for (const auto& disciplina : disciplinas) {
            file << disciplina.getCodigo() << ","
                 << disciplina.getNome() << ","
                 << disciplina.getCargaHoraria() << ","
                 << disciplina.getCreditos() << "\n";
        }

        file.close();
        std::cout << "Dados das disciplinas salvos com sucesso em " << arquivo << std::endl;
    } catch (const std::exception& e) {
        throw;
    }
}

std::vector<Aluno> Persistencia::carregarAlunos(const std::string& arquivo) {
    std::vector<Aluno> alunos;

    try {
        std::ifstream file(arquivo);
        if (!file.is_open()) {
            throw ArquivoNaoEncontradoException(arquivo);
        }

        std::string linha;
        bool primeiraLinha = true;

        while (std::getline(file, linha)) {
            if (primeiraLinha) {
                primeiraLinha = false;
                continue; // Pular cabeçalho
            }

            if (linha.empty()) continue;

            std::vector<std::string> campos = split(linha, ',');
            if (campos.size() != 4) {
                throw FalhaConversaoException("Formato inválido na linha: " + linha);
            }

            int id = stringParaInt(campos[0]);
            std::string nome = campos[1];
            std::string curso = campos[2];
            double nota = stringParaDouble(campos[3]);

            alunos.emplace_back(id, nome, curso, nota);
        }

        file.close();
        std::cout << "Carregados " << alunos.size() << " alunos de " << arquivo << std::endl;
    } catch (const ArquivoNaoEncontradoException&) {
        std::cout << "Arquivo de alunos não encontrado. Iniciando com lista vazia." << std::endl;
    }

    return alunos;
}

std::vector<Professor> Persistencia::carregarProfessores(const std::string& arquivo) {
    std::vector<Professor> professores;

    try {
        std::ifstream file(arquivo);
        if (!file.is_open()) {
            throw ArquivoNaoEncontradoException(arquivo);
        }

        std::string linha;
        bool primeiraLinha = true;

        while (std::getline(file, linha)) {
            if (primeiraLinha) {
                primeiraLinha = false;
                continue; // Pular cabeçalho
            }

            if (linha.empty()) continue;

            std::vector<std::string> campos = split(linha, ',');
            if (campos.size() != 4) {
                throw FalhaConversaoException("Formato inválido na linha: " + linha);
            }

            int id = stringParaInt(campos[0]);
            std::string nome = campos[1];
            std::string disciplina = campos[2];
            std::string departamento = campos[3];

            professores.emplace_back(id, nome, disciplina, departamento);
        }

        file.close();
        std::cout << "Carregados " << professores.size() << " professores de " << arquivo << std::endl;
    } catch (const ArquivoNaoEncontradoException&) {
        std::cout << "Arquivo de professores não encontrado. Iniciando com lista vazia." << std::endl;
    }

    return professores;
}

std::vector<Disciplina> Persistencia::carregarDisciplinas(const std::string& arquivo) {
    std::vector<Disciplina> disciplinas;

    try {
        std::ifstream file(arquivo);
        if (!file.is_open()) {
            throw ArquivoNaoEncontradoException(arquivo);
        }

        std::string linha;
        bool primeiraLinha = true;

        while (std::getline(file, linha)) {
            if (primeiraLinha) {
                primeiraLinha = false;
                continue; // Pular cabeçalho
            }

            if (linha.empty()) continue;

            std::vector<std::string> campos = split(linha, ',');
            if (campos.size() != 4) {
                throw FalhaConversaoException("Formato inválido na linha: " + linha);
            }

            int codigo = stringParaInt(campos[0]);
            std::string nome = campos[1];
            int cargaHoraria = stringParaInt(campos[2]);
            int creditos = stringParaInt(campos[3]);

            disciplinas.emplace_back(codigo, nome, cargaHoraria, creditos);
        }

        file.close();
        std::cout << "Carregadas " << disciplinas.size() << " disciplinas de " << arquivo << std::endl;
    } catch (const ArquivoNaoEncontradoException&) {
        std::cout << "Arquivo de disciplinas não encontrado. Iniciando com lista vazia." << std::endl;
    }

    return disciplinas;
}
