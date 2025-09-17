#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <fstream>
#include <vector>
#include <string>
#include "../Aluno/Aluno.h"
#include "../Excecoes/Excecoes.h"
#include "../Professor/Professor.h"

class Persistencia {
public:
    static std::vector<Aluno> carregarAlunos(const std::string& caminhoArquivo);
    static void salvarAlunos(const std::string& caminhoArquivo, const std::vector<Aluno>& alunos);

    static std::vector<Professor> carregarProfessores(const std::string& caminhoArquivo);
    static void salvarProfessores(const std::string& caminhoArquivo, const std::vector<Professor>& professores);
};

#endif // PERSISTENCIA_H