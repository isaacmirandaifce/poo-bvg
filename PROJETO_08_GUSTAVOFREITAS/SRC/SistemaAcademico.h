#ifndef SISTEMA_ACADEMICO_H
#define SISTEMA_ACADEMICO_H

#include <vector>
#include <memory>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Filtro.h"
#include "FiltroAcademico.h"

class SistemaAcademico {
private:
    std::vector<std::shared_ptr<UsuarioAutenticavel>> usuarios;

public:
    void adicionarUsuario(std::shared_ptr<UsuarioAutenticavel> usuario);
    bool autenticarUsuario(const std::string& matricula, const std::string& senha);
    void gerarRelatorios() const;
    void listarUsuarios() const;

    /**
     * @brief Obtém todos os alunos do sistema
     * @return Filtro<Aluno> Filtro com todos os alunos
     */
    Filtro<Aluno> obterTodosAlunos() const;

    /**
     * @brief Obtém todos os professores do sistema
     * @return Filtro<Professor> Filtro com todos os professores
     */
    Filtro<Professor> obterTodosProfessores() const;

    /**
     * @brief Obtém todos os funcionários do sistema
     * @return Filtro<FuncionarioAdministrativo> Filtro com todos os funcionários
     */
    Filtro<FuncionarioAdministrativo> obterTodosFuncionarios() const;
};

#endif // SISTEMA_ACADEMICO_H