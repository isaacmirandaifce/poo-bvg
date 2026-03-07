#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <vector>
#include <string>
#include "Aluno.h"

class Persistencia {
public:
    static std::vector<Aluno> carregarAlunos(const std::string& arquivo);
    static void salvarAlunos(const std::string& arquivo, const std::vector<Aluno>& alunos);
};

#endif