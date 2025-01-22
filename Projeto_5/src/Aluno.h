#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <vector>
#include "Disciplina.h"

class Aluno : public Usuario {
private:
    std::string matricula;
    std::string curso;
    std::vector<Disciplina> disciplinas;

public:
    Aluno();
    Aluno(const std::string& nome, const std::string& matricula, const std::string& curso, const std::string& email);

    void adicionarDisciplina(const Disciplina& disciplina);
    void exibirInformacoes() const; 
    void exibirInformacoes(bool comNotas) const; 

    void gerarRelatorio() const override; 
};

#endif // ALUNO_H
