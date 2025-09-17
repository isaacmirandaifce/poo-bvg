#include "../headers/SistemaAcademico.h"
#include <iostream>

void SistemaAcademico::adicionarUsuario(std::shared_ptr<UsuarioAutenticavel> usuario) {
    usuarios.push_back(usuario);
}

bool SistemaAcademico::autenticarUsuario(const std::string& matricula, const std::string& senha) {
    for (const auto& usuario : usuarios) {
        if (usuario->getMatricula() == matricula) {
            return usuario->autenticar(senha);
        }
    }
    return false;
}

void SistemaAcademico::gerarRelatorios() const {
    for (const auto& usuario : usuarios) {
        if (auto relatorio = dynamic_cast<Relatorio*>(usuario.get())) {
            relatorio->gerarRelatorio();
            std::cout << std::endl;
        }
    }
}

void SistemaAcademico::listarUsuarios() const {
    std::cout << "=== USUÁRIOS DO SISTEMA ===" << std::endl;
    for (const auto& usuario : usuarios) {
        std::string tipo;
        switch (usuario->getTipo()) {
            case TipoUsuario::ALUNO: tipo = "Aluno"; break;
            case TipoUsuario::PROFESSOR: tipo = "Professor"; break;
            case TipoUsuario::FUNCIONARIO_ADMINISTRATIVO: tipo = "Funcionário"; break;
        }
        std::cout << tipo << ": " << usuario->getNome() 
                  << " (" << usuario->getMatricula() << ")" << std::endl;
    }
    std::cout << "==========================" << std::endl;
}