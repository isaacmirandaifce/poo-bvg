#include "Usuario.h"

Usuario::Usuario(int id, std::string nome, TipoUsuario tipo)
    : id(id), nome(nome), tipo(tipo) {}

std::string Usuario::getNome() const {
    return nome;
}

int Usuario::getId() const {
    return id;
}

// Função auxiliar para converter o enum em string para exibição
std::string Usuario::getTipoAsString() const {
    switch (tipo) {
        case TipoUsuario::ALUNO: return "Aluno";
        case TipoUsuario::PROFESSOR: return "Professor";
        case TipoUsuario::FUNCIONARIO_ADMINISTRATIVO: return "Funcionario Administrativo";
        default: return "Desconhecido";
    }
}