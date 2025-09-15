#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>

struct Disciplina {
    std::string nome;
    int ano;
    float nota;
};

class Aluno {
private:
    std::string nome;
    std::string email;
    std::string senha;
    std::vector<Disciplina> historico;

public:
    Aluno(const std::string& n, const std::string& e, const std::string& s)
        : nome(n), email(e), senha(s) {}

    void adicionarDisciplina(const std::string& nomeDisc, int ano, float nota) {
        historico.push_back({nomeDisc, ano, nota});
    }

    std::vector<Disciplina> getHistorico() const { return historico; }
    std::string getNome() const { return nome; }
};

#endif