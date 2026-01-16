#include "Professor.h"
#include <iostream>

// Construtor padrão: inicializa a área de atuação vazia
Professor::Professor() : Usuario(), areaDeAtuacao("") {}

// Construtor com parâmetros: recebe nome, email e área de atuação
// Passa "Professor" como tipo de usuário para o construtor da classe base Usuario
Professor::Professor(const std::string& nome,
                     const std::string& email,
                     const std::string& areaDeAtuacao)
    : Usuario(nome, email, "Professor"), // chama o construtor da classe base
      areaDeAtuacao(areaDeAtuacao) {}

// Exibe relatório básico do professor
void Professor::gerarRelatorio() const {
    std::cout << "Nome: " << nome
              << "\nÁrea de Atuação: " << areaDeAtuacao
              << std::endl;
}

// Adiciona uma disciplina ao vetor de disciplinas ministradas
void Professor::adicionarDisciplina(const std::string& disciplina) {
    disciplinasMinistradas.push_back(disciplina);
}