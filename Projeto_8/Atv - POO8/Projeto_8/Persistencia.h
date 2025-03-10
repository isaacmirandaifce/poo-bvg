#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <vector>
#include <string>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

class Persistencia {
public:
    static void salvarDados(const std::vector<Aluno>& alunos, const std::vector<Professor>& professores, const std::vector<Disciplina>& disciplinas);
    static void carregarDados(std::vector<Aluno>& alunos, std::vector<Professor>& professores, std::vector<Disciplina>& disciplinas);
};

#endif // PERSISTENCIA_H