#ifndef ALUNO_H
#define ALUNO_H

#include <vector>
#include <string>
#include <iostream>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Aluno : public UsuarioAutenticavel, public Relatorio {
public:
    class HistoricoDisciplinar {
        std::string disciplina;
        int ano;
        float nota;

    public:
        HistoricoDisciplinar(std::string d, int a, float n)
            : disciplina(d), ano(a), nota(n) {}

        void exibir() const {
            std::cout << " - " << disciplina << " (" << ano << ") Nota: " << nota << "\n";
        }
    };

private:
    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(std::string nome, std::string email, std::string senha);

    bool autenticar(std::string senha) const override;
    void gerarRelatorio() const override;

    void adicionarDisciplina(std::string disciplina, int ano, float nota);
};

#endif
