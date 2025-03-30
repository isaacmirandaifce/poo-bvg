#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <vector>

class Aluno : virtual public Usuario {
protected:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinas;

public:
    Aluno();
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso);

    void adicionarDisciplina(const std::string& disciplina);
    virtual void gerarRelatorio() const override;

    void exibirInformacoes(bool incluirNotas = false) const; // Sobrecarga
};

#endif // ALUNO_H
