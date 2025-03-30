#include "Persistencia.h"
#include "ArquivoNaoEncontradoException.h"

void Persistencia::salvarDados(const std::vector<Aluno>& alunos, const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        throw std::ios_base::failure("Erro ao abrir arquivo para escrita.");
    }
    for (const auto& aluno : alunos) {
        arquivo << aluno.getNome() << "," << aluno.getIdade() << "\n";
    }
}

std::vector<Aluno> Persistencia::carregarDados(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        throw ArquivoNaoEncontradoException("Arquivo " + nomeArquivo + " nao encontrado.");
    }
    std::vector<Aluno> alunos;
    std::string linha;
    while (std::getline(arquivo, linha)) {
        size_t separador = linha.find(',');
        std::string nome = linha.substr(0, separador);
        int idade = std::stoi(linha.substr(separador + 1));
        alunos.emplace_back(nome, idade);
    }
    return alunos;
}