#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include "Usuario.h"
#include "Disciplina.h"

class Aluno : virtual public Usuario {
private:
    std::string matricula;
    std::string curso;
    std::vector<Disciplina> disciplinas;

public:
    Aluno();
    Aluno(const std::string& nome,
          const std::string& email,
          const std::string& matricula,
          const std::string& curso);

    void gerarRelatorio() const override;

    // sobrecarga: mesma função, parâmetros diferentes
    void exibirInformacoes() const;            // versão simples
    void exibirInformacoes(bool comNotas) const; // versão detalhada (com/sem notas)

    void adicionarDisciplina(const Disciplina& d);
    void listarDisciplinas() const;

    const std::string& getMatricula() const;
    const std::string& getCurso() const;
};

#endif // ALUNO_H
