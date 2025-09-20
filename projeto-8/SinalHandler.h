#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <csignal>
#include <iostream>
#include <vector>
#include "Persistencia.h"
#include "Aluno.h"
#include "Professor.h"

class SinalHandler {
public:
    static void inicializar(std::vector<Aluno*>& alunos, std::vector<Professor*>& professores);

private:
    static void tratador(int sinal);
    static std::vector<Aluno*>* alunos_ptr;
    static std::vector<Professor*>* professores_ptr;
};

#endif // SINALHANDLER_H
