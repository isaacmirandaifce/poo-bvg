#include "Professor.h"
#include <iostream>

// Construtor para inicializar as variáveis do professor
Professor::Professor(std::string nome, std::string id, std::string disciplina) : nome(nome), id(id), disciplina(disciplina) {}

// Método para exibir as informações do professor
void Professor::exibirInformacoes() const {
    std::cout << "Nome: " << nome << "\nID: " << id << "\nDisciplina: " << disciplina << std::endl;
}
