#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <string>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "Excecoes.h"

class Persistencia {
public:
    static void salvarAlunos(const std::string& nomeArquivo, const std::vector<Aluno*>& alunos);
    static void salvarProfessores(const std::string& nomeArquivo, const std::vector<Professor*>& professores);
    static std::vector<Aluno*> carregarAlunos(const std::string& nomeArquivo);
    static std::vector<Professor*> carregarProfessores(const std::string& nomeArquivo);
};

#endif // PERSISTENCIA_H
