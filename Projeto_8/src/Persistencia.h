#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <vector>
#include <string>
#include "Aluno.h"

class Persistencia {
public:
    static std::vector<Aluno> carregarAlunos(const std::string& caminho);
    static void salvarAlunos(const std::string& caminho,
                             const std::vector<Aluno>& alunos);
};

#endif