#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <fstream>
#include <vector>
#include <stdexcept>
#include "Aluno.h"
#include "Disciplina.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

class Persistencia {
public:
    // Carrega os dados de um arquivo
    static std::vector<Aluno> carregarAlunos();
    static void salvarAlunos(const std::vector<Aluno>& alunos);
    static std::vector<Disciplina> carregarDisciplinas();
    static void salvarDisciplinas(const std::vector<Disciplina>& disciplinas);
    static std::vector<Professor> carregarProfessores();
    static void salvarProfessores(const std::vector<Professor>& professores);

private:
    // Verifica se o arquivo existe e está acessível
    static void verificarArquivo(const std::string& nomeArquivo);
};

#endif
