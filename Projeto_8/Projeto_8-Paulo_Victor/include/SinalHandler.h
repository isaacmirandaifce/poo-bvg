#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <csignal>
#include <iostream>
#include "Persistencia.h"

class SinalHandler {
public:
    static void inicializar();
    static void setDados(const std::vector<Aluno>& alunos, const std::vector<Professor>& professores);

private:
    static std::vector<Aluno> alunos;
    static std::vector<Professor> professores;
    static void tratador(int sinal);
};

#endif