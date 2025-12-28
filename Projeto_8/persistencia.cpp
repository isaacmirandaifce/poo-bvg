#include "Persistencia.h"
#include <fstream>

std::vector<Aluno> Persistencia::carregarAlunos(const std::string& arquivo) {
    std::ifstream file(arquivo);
    if (!file.is_open()) {
        throw ArquivoNaoEncontradoException();
    }

    std::vector<Aluno> alunos;
    std::string linha;

    try {
        while (std::getline(file, linha)) {
            alunos.push_back(Aluno::fromString(linha));
        }
    } catch (...) {
        throw ConversaoDadosException();
    }

    return alunos;
}

void Persistencia::salvarAlunos(const std::string& arquivo, const std::vector<Aluno>& alunos) {
    std::ofstream file(arquivo);
    if (!file.is_open()) {
        throw PermissaoNegadaException();
    }

    for (const auto& aluno : alunos) {
        file << aluno.toString() << "\n";
    }
}
