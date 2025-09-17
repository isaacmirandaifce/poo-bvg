#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include "Disciplina.h"
#include <vector>
#include <map>

class Aluno : public Usuario {
private:
    std::string matricula;
    std::vector<Disciplina*> disciplinas;
    std::map<std::string, float> notas; // Disciplina -> nota

public:
    Aluno(const std::string& nome, const std::string& email, 
          const std::string& matricula);

    // Sobrescrita do método virtual
    void exibirInformacoes() const override;

    // Sobrecarga de métodos
    void matricular(Disciplina* disciplina);
    void matricular(Disciplina* disciplina, float notaInicial);

    void adicionarNota(const std::string& codigoDisciplina, float nota);
    void listarDisciplinas() const;

    // Getters
    std::string getMatricula() const;
};

#endif // ALUNO_H