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
    std::vector<Disciplina> disciplinas;
public:
    Aluno();
    Aluno(const std::string& nome, const std::string& matricula, const std::string& curso);
    void exibirInformacoes() const;

    const std::string& getNome() const;
    const std::string& getMatricula() const;
    const std::string& getCurso() const;

    // Associação de disciplinas
    void adicionarDisciplina(const Disciplina& d);
    void exibirDisciplinas() const;
};

#endif // ALUNO_H
