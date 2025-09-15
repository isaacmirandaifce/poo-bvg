#include "SistemaGestaoAcademica.h"
#include <iostream>
#include <algorithm>

void SistemaGestaoAcademica::adicionarAluno(std::unique_ptr<Aluno> aluno) {
    usuarios.push_back(std::move(aluno));
}

void SistemaGestaoAcademica::adicionarProfessor(std::unique_ptr<Professor> professor) {
    usuarios.push_back(std::move(professor));
}

void SistemaGestaoAcademica::adicionarFuncionario(std::unique_ptr<FuncionarioAdministrativo> funcionario) {
    usuarios.push_back(std::move(funcionario));
}

UsuarioAutenticavel* SistemaGestaoAcademica::autenticarUsuario(int id, const std::string& senha) {
    for (auto& usuario : usuarios) {
        if (usuario->getId() == id && usuario->autenticar(senha)) {
            return usuario.get();
        }
    }
    return nullptr;
}

void SistemaGestaoAcademica::gerarRelatoriosGerais() const {
    std::cout << "\n========== RELATÓRIOS GERAIS DO SISTEMA ==========" << std::endl;

    for (const auto& usuario : usuarios) {
        // Usar dynamic_cast para acessar a interface Relatorio
        if (auto* relatorio = dynamic_cast<const Relatorio*>(usuario.get())) {
            relatorio->gerarRelatorio();
            std::cout << std::endl;
        }
    }
}

void SistemaGestaoAcademica::exibirEstatisticasTipoUsuario() const {
    int contadorAlunos = 0, contadorProfessores = 0, contadorFuncionarios = 0;

    for (const auto& usuario : usuarios) {
        switch (usuario->getTipo()) {
            case TipoUsuario::ALUNO:
                contadorAlunos++;
                break;
            case TipoUsuario::PROFESSOR:
                contadorProfessores++;
                break;
            case TipoUsuario::FUNCIONARIO_ADMINISTRATIVO:
                contadorFuncionarios++;
                break;
        }
    }

    std::cout << "\n=== ESTATÍSTICAS DO SISTEMA ===" << std::endl;
    std::cout << "Total de usuários: " << usuarios.size() << std::endl;
    std::cout << "Alunos: " << contadorAlunos << std::endl;
    std::cout << "Professores: " << contadorProfessores << std::endl;
    std::cout << "Funcionários Administrativos: " << contadorFuncionarios << std::endl;
    std::cout << "===============================" << std::endl;
}

UsuarioAutenticavel* SistemaGestaoAcademica::buscarUsuarioPorId(int id) {
    for (auto& usuario : usuarios) {
        if (usuario->getId() == id) {
            return usuario.get();
        }
    }
    return nullptr;
}

std::vector<UsuarioAutenticavel*> SistemaGestaoAcademica::buscarUsuariosPorTipo(TipoUsuario tipo) {
    std::vector<UsuarioAutenticavel*> resultado;

    for (auto& usuario : usuarios) {
        if (usuario->getTipo() == tipo) {
            resultado.push_back(usuario.get());
        }
    }

    return resultado;
}

void SistemaGestaoAcademica::exibirTodosUsuarios() const {
    std::cout << "\n=== TODOS OS USUÁRIOS DO SISTEMA ===" << std::endl;

    for (const auto& usuario : usuarios) {
        std::string tipoStr;
        switch (usuario->getTipo()) {
            case TipoUsuario::ALUNO:
                tipoStr = "Aluno";
                break;
            case TipoUsuario::PROFESSOR:
                tipoStr = "Professor";
                break;
            case TipoUsuario::FUNCIONARIO_ADMINISTRATIVO:
                tipoStr = "Funcionário Administrativo";
                break;
        }

        std::cout << "ID: " << usuario->getId() << " | Nome: " << usuario->getNome()
                  << " | Tipo: " << tipoStr << std::endl;
    }
    std::cout << "====================================" << std::endl;
}
