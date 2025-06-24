#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>

class Aluno {
private:
    std::string nome;
    std::string matricula;
    double mediaGeral;
    std::vector<std::string> disciplinasCursadas; 

public:
    Aluno(const std::string& nome, const std::string& matricula, double media);

    std::string getNome() const;
    std::string getMatricula() const;
    double getMediaGeral() const;
    void adicionarDisciplinaCursada(const std::string& disciplina);
    const std::vector<std::string>& getDisciplinasCursadas() const;

    void imprimir() const;
};

#endif