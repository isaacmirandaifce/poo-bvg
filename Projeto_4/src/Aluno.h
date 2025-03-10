#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include "Disciplina.h"

class Aluno {
private:
    std::string nome;
    std::string matricula;
    std::string curso;

public:
    Aluno();

    Aluno(const std::string& nome, const std::string& matricula, const std::string& curso);

    void exibirInformacoes() const;

    void adicionarDisciplina(const Disciplina& disciplina);

    // Método para exibir as notas das disciplinas
    void exibirDisciplinas() const;

private:
    std::vector<Disciplina> disciplinas;
};

#endif // ALUNO_H
