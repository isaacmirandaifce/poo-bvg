#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "Aluno.h"

class Persistencia {
public:
    void salvarDados(const std::vector<Aluno>& alunos, const std::string& nomeArquivo);
    std::vector<Aluno> carregarDados(const std::string& nomeArquivo);
};

#endif // PERSISTENCIA_H