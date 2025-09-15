#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <csignal>
#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

class SinalHandler {
public:
    static void inicializar();
    static void definirDados(std::vector<Aluno>* alunos,
                            std::vector<Professor>* professores,
                            std::vector<Disciplina>* disciplinas);

private:
    static void tratador(int sinal);
    static void salvarDadosEmergencia();

    // Ponteiros estáticos para os dados
    static std::vector<Aluno>* alunosPtr;
    static std::vector<Professor>* professoresPtr;
    static std::vector<Disciplina>* disciplinasPtr;
};

#endif
