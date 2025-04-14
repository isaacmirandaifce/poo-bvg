#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <vector>
#include "Aluno.h"

class Persistencia {
private:
    std::string nomeArquivo;

public:
    Persistencia();  
    void salvarAlunos(const std::vector<Aluno>& alunos);
    std::vector<Aluno> carregarAlunos();
};

#endif // PERSISTENCIA_H
