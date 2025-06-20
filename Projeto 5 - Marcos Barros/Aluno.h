#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <vector>

class Aluno : public Usuario {
private:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinas;

public:
    Aluno();
    Aluno(std::string nome, std::string email, std::string matricula, std::string curso);

    void adicionarDisciplina(std::string disciplina);
    void gerarRelatorio() const override;

    void gerarRelatorio(bool comNotas) const; // Método sobrecarregado
};

#endif // ALUNO_H
