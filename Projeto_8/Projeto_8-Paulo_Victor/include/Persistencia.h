#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <fstream>
#include <vector>
#include <string>
#include "Aluno.h"
#include "Professor.h"
#include "Excecoes.h"

class Persistencia {
public:
    static void salvarAlunos(const std::vector<Aluno>& alunos, const std::string& arquivo);
    static std::vector<Aluno> carregarAlunos(const std::string& arquivo);

    static void salvarProfessores(const std::vector<Professor>& professores, const std::string& arquivo);
    static std::vector<Professor> carregarProfessores(const std::string& arquivo);
};

#endif