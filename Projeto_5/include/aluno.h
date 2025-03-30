#ifndef ALUNO_H
#define ALUNO_H

#include "usuario.h"
#include "disciplina.h"
#include <vector>
#include <memory>

class Aluno : public Usuario {
protected:
    std::string curso;
    std::vector<std::shared_ptr<Disciplina>> disciplinas; // Disciplinas do aluno

public:
    Aluno(const std::string& nome, const std::string& email, const std::string& tipo, const std::string& curso);

    // Método para adicionar uma disciplina ao aluno
    void adicionarDisciplina(const std::shared_ptr<Disciplina>& disciplina);

    // Método sobrescrito para gerar o relatório do aluno
    void gerarRelatorio() const override;

    // Obter disciplinas
    const std::vector<std::shared_ptr<Disciplina>>& getDisciplinas() const;
};

#endif // ALUNO_H
