#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <vector>

class Aluno : public virtual Usuario { 
protected:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinas;
    std::vector<float> notas;
public:
    Aluno();
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso);

    void adicionarDisciplina(const std::string& disciplina, float nota);

    void gerarRelatorio() const override; // sobrescrita

    // Sobrecarga: duas versões do método
    void exibirInformacoes() const; // sem notas
    void exibirInformacoes(bool mostrarNotas) const; // com ou sem notas
};

#endif