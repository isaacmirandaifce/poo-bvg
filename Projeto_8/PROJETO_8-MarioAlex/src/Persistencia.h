#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <vector>
#include <string>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"

// Classe responsável pela persistência dos dados
class Persistencia {
public:
    // Construtor recebe diretório dos dados (default: "./data/")
    Persistencia(const std::string &dir = "./data/");
    ~Persistencia();

    // Carrega todos os dados dos arquivos
    void carregarTudo(std::vector<Aluno> &alunos, std::vector<Professor> &profs, std::vector<Disciplina> &discs);

    // Salva todos os dados nos arquivos
    void salvarTudo(const std::vector<Aluno> &alunos, const std::vector<Professor> &profs, const std::vector<Disciplina> &discs);

    // Salva apenas os alunos
    void salvarAlunos(const std::vector<Aluno> &alunos);

private:
    std::string pasta;

    // Métodos auxiliares para obter caminhos dos arquivos
    std::string caminhoAlunos();
    std::string caminhoProfessores();
    std::string caminhoDisciplinas();

    // Métodos auxiliares para carregar/salvar arquivos
    void carregarArquivo(const std::string &caminho, std::vector<std::string> &linhas);
    void salvarArquivo(const std::string &caminho, const std::vector<std::string> &linhas);
};

#endif // PERSISTENCIA_H