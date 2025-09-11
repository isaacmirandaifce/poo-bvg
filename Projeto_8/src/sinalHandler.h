#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <csignal>
#include <iostream>
#include <cstdlib>
#include "Persistencia.h"

class SinalHandler {
public:
    static void inicializar();
    static void registrarDados(std::vector<std::shared_ptr<Aluno>>* alunos,
                                std::vector<std::shared_ptr<Professor>>* professores);
private:
    static void tratador(int sinal);
    static std::vector<std::shared_ptr<Aluno>>* alunosRef;
    static std::vector<std::shared_ptr<Professor>>* professoresRef;
};

#endif // SINALHANDLER_H