#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>

struct DisciplinaHistorico {
    std::string nomeDisciplina;
    int ano;
    double nota;
};

class Aluno {
private:
    std::string nome;
    std::string matricula;
    double media;
    std::vector<DisciplinaHistorico> historico;

public:
    Aluno(const std::string& nome, const std::string& matricula, double media);

    void adicionarDisciplina(const std::string& nomeDisciplina, int ano, double nota);

    const std::string& getNome() const;
    const std::string& getMatricula() const;
    double getMedia() const;
    const std::vector<DisciplinaHistorico>& getHistorico() const;

    void imprimir() const;
};

#endif
