#ifndef SISTEMA_GESTAO_ACADEMICA_H
#define SISTEMA_GESTAO_ACADEMICA_H

#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include <vector>
#include <memory>

class SistemaGestaoAcademica {
private:
    std::vector<std::unique_ptr<UsuarioAutenticavel>> usuarios;

public:
    ~SistemaGestaoAcademica() = default;

    // Métodos para adicionar usuários
    void adicionarAluno(std::unique_ptr<Aluno> aluno);
    void adicionarProfessor(std::unique_ptr<Professor> professor);
    void adicionarFuncionario(std::unique_ptr<FuncionarioAdministrativo> funcionario);

    // Métodos de autenticação
    UsuarioAutenticavel* autenticarUsuario(int id, const std::string& senha);

    // Métodos de relatórios
    void gerarRelatoriosGerais() const;
    void exibirEstatisticasTipoUsuario() const;

    // Busca de usuários
    UsuarioAutenticavel* buscarUsuarioPorId(int id);
    std::vector<UsuarioAutenticavel*> buscarUsuariosPorTipo(TipoUsuario tipo);

    void exibirTodosUsuarios() const;
};

#endif
