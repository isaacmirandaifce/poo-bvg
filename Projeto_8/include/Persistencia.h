#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <vector>
#include <string>
#include <fstream>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Excecoes.h"

class Persistencia {
public:
    static std::vector<Aluno> carregarAlunos(const std::string& caminhoArquivo);
    static void salvarAlunos(const std::string& caminhoArquivo, const std::vector<Aluno>& alunos);

    static std::vector<Professor> carregarProfessores(const std::string& caminhoArquivo);
    static void salvarProfessores(const std::string& caminhoArquivo, const std::vector<Professor>& professores);

    static std::vector<Disciplina> carregarDisciplinas(const std::string& caminhoArquivo);
    static void salvarDisciplinas(const std::string& caminhoArquivo, const std::vector<Disciplina>& disciplinas);

private:
    static void verificarErrosArquivo(const std::ifstream& arquivo, const std::string& caminhoArquivo);
    static void verificarErrosArquivo(const std::ofstream& arquivo, const std::string& caminhoArquivo);
};

#endif // PERSISTENCIA_H