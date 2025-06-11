#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <vector>
#include <string>

class Aluno : virtual public Usuario {
protected:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinas;

public:
    Aluno();
    Aluno(std::string nome, std::string email, std::string matricula, std::string curso);

    void adicionarDisciplina(const std::string& disciplina);
    
    // sobrescrita do método gerarRelatorio()
    void gerarRelatorio() const override;

    // sobrecarga: mostra disciplinas com e sem notas
    void exibirDetalhes(bool comNotas);
};

#endif
