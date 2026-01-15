#ifndef ALUNO_H
#define ALUNO_H

#include <vector>
#include <iostream>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
    std::string matricula;

    // Classe Interna (Inner Class)
    class HistoricoDisciplinar {
    public:
        std::string disciplina;
        int ano;
        float nota;

        HistoricoDisciplinar(std::string d, int a, float n)
            : disciplina(d), ano(a), nota(n) {}
    };

    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(std::string nome, std::string email, std::string senha, std::string matricula);

    // Métodos da classe
    void adicionarDisciplina(std::string disciplina, int ano, float nota);

    // Implementação das heranças
    bool autenticar(std::string senhaDigitada) override;
    void gerarRelatorio() const override;
};

#endif
