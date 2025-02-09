#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <vector>
#include <string>
#include "Disciplina.h"

class Aluno : public Usuario {
private:
    std::string matricula;
    std::string curso;
    std::vector<Disciplina> disciplinas;

public:
    // Construtores
    Aluno();
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso);

    // Métodos
    void gerarRelatorio() const override;
    void adicionarDisciplina(const Disciplina& disciplina);

    // Sobrecarga de método
    void exibirInformacoes(bool comNotas) const;
};

#endif // ALUNO_H