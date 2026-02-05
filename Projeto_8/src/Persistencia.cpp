#include "Persistencia.h"
#include "Excecoes.h"
#include <fstream>
#include <sstream>

std::vector<Aluno> Persistencia::carregarAlunos(const std::string& caminho) {
    std::ifstream arquivo(caminho);

    if (!arquivo.is_open()) {
        throw ArquivoNaoEncontradoException("Arquivo de alunos não encontrado.");
    }

    std::vector<Aluno> alunos;
    std::string linha;

    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string nome;
        int matricula;

        if (!(ss >> nome >> matricula)) {
            throw ErroConversaoException("Erro ao converter dados do aluno.");
        }

        alunos.emplace_back(nome, matricula);
    }

    return alunos;
}

void Persistencia::salvarAlunos(const std::string& caminho,
                               const std::vector<Aluno>& alunos) {
    std::ofstream arquivo(caminho);

    if (!arquivo.is_open()) {
        throw PermissaoNegadaException("Não foi possível gravar o arquivo.");
    }

    for (const auto& aluno : alunos) {
        arquivo << aluno.getNome() << " "
                << aluno.getMatricula() << std::endl;
    }
}