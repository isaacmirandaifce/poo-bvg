#ifndef FILTRO_ACADEMICO_H
#define FILTRO_ACADEMICO_H

#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include <memory>

/**
 * @brief Classe utilitária com filtros pré-definidos para o sistema acadêmico
 */
class FiltroAcademico {
public:
    /**
     * @brief Filtra alunos com média acima de um valor
     * @param alunos Filtro de alunos
     * @param mediaMinima Média mínima
     * @return Filtro<Aluno> Alunos com média acima do valor
     */
    static Filtro<Aluno> filtrarAlunosPorMedia(const Filtro<Aluno>& alunos, double mediaMinima) {
        return alunos.filtrarPorCondicao([mediaMinima](const Aluno& aluno) {
            return aluno.calcularMedia() >= mediaMinima;
        });
    }

    /**
     * @brief Filtra professores por departamento
     * @param professores Filtro de professores
     * @param departamento Departamento desejado
     * @return Filtro<Professor> Professores do departamento
     */
    static Filtro<Professor> filtrarProfessoresPorDepartamento(
        const Filtro<Professor>& professores, const std::string& departamento) {
        return professores.filtrarPorCondicao([&departamento](const Professor& professor) {
            return professor.getDepartamento() == departamento;
        });
    }

    /**
     * @brief Filtra funcionários por setor
     * @param funcionarios Filtro de funcionários
     * @param setor Setor desejado
     * @return Filtro<FuncionarioAdministrativo> Funcionários do setor
     */
    static Filtro<FuncionarioAdministrativo> filtrarFuncionariosPorSetor(
        const Filtro<FuncionarioAdministrativo>& funcionarios, const std::string& setor) {
        return funcionarios.filtrarPorCondicao([&setor](const FuncionarioAdministrativo& funcionario) {
            return funcionario.getSetor() == setor;
        });
    }

    /**
     * @brief Ordena alunos por nome
     * @param alunos Filtro de alunos
     * @return Filtro<Aluno> Alunos ordenados por nome
     */
    static Filtro<Aluno> ordenarAlunosPorNome(Filtro<Aluno> alunos) {
        alunos.ordenarPor([](const Aluno& a1, const Aluno& a2) {
            return a1.getNome() < a2.getNome();
        });
        return alunos;
    }

    /**
     * @brief Ordena alunos por média (decrescente)
     * @param alunos Filtro de alunos
     * @return Filtro<Aluno> Alunos ordenados por média
     */
    static Filtro<Aluno> ordenarAlunosPorMedia(Filtro<Aluno> alunos) {
        alunos.ordenarPor([](const Aluno& a1, const Aluno& a2) {
            return a1.calcularMedia() > a2.calcularMedia();
        });
        return alunos;
    }

    /**
     * @brief Ordena professores por nome
     * @param professores Filtro de professores
     * @return Filtro<Professor> Professores ordenados por nome
     */
    static Filtro<Professor> ordenarProfessoresPorNome(Filtro<Professor> professores) {
        professores.ordenarPor([](const Professor& p1, const Professor& p2) {
            return p1.getNome() < p2.getNome();
        });
        return professores;
    }
};

#endif // FILTRO_ACADEMICO_H