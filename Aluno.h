#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <vector>
#include <iostream>

class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
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
    Aluno(std::string nome, std::string senha)
        : UsuarioAutenticavel(nome, TipoUsuario::ALUNO, senha) {}

    void adicionarDisciplina(std::string nome, int ano, float nota) {
        historico.emplace_back(nome, ano, nota);
    }

    bool autenticar(std::string senhaDigitada) const override {
        return senhaDigitada == senha;
    }

    void gerarRelatorio() const override {
        std::cout << "Relatório do aluno: " << nome << "\n";
        for (const auto& h : historico) {
            std::cout << "- " << h.disciplina << " | Ano: " << h.ano
                      << " | Nota: " << h.nota << "\n";
        }
    }
};

#endif
