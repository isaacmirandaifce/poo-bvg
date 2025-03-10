#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <vector>  // Adicione esta linha para incluir o vector
#include "Aluno.h"  // Certifique-se de que estas inclusões existem e estão corretas
#include "Professor.h"
#include "Disciplina.h"

class SinalHandler {
public:
    static void setDados(const std::vector<Aluno>& alunos, 
                         const std::vector<Professor>& professores, 
                         const std::vector<Disciplina>& disciplinas);
    
    static void tratador(int sinal);

private:
    static std::vector<Aluno> alunos;
    static std::vector<Professor> professores;
    static std::vector<Disciplina> disciplinas;
};

#endif
