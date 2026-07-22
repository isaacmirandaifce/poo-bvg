#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include "Usuario.h"

class Aluno : virtual public Usuario {
protected:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinasCursadas;
    std::vector<double> notas;

public:
    Aluno();
    Aluno(std::string nome, std::string email, std::string matricula, std::string curso);

    void adicionarDisciplina(const std::string& disciplina);
    void adicionarNota(double nota);

    // Sobrescrita: implementacao do relatorio geral herdado de Usuario
    void gerarRelatorio() const override;

    // Sobrecarga: mesma acao, assinaturas diferentes
    void exibirInformacoes() const;                 // sem notas
    void exibirInformacoes(bool comNotas) const;     // com notas, se solicitado
};

#endif // ALUNO_H
