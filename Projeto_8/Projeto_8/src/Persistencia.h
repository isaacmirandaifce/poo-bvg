#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <fstream>
#include <vector>
#include <string>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

class Persistencia {
public:
    static std::vector<Aluno> carregarAlunos(const std::string& caminho);
    static void salvarAlunos(const std::string& caminho, const std::vector<Aluno>& alunos);

    static std::vector<Professor> carregarProfessores(const std::string& caminho);
    static void salvarProfessores(const std::string& caminho, const std::vector<Professor>& professores);

    static std::vector<Disciplina> carregarDisciplinas(const std::string& caminho);
    static void salvarDisciplinas(const std::string& caminho, const std::vector<Disciplina>& disciplinas);
};

#endif // PERSISTENCIA_H