#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <vector>
#include <iostream>

class Aluno : public UsuarioAutenticavel, public Relatorio {
public:
    class HistoricoDisciplinar {
    private:
        std::string disciplina;
        int ano;
        float nota;

    public:
        HistoricoDisciplinar(const std::string& disciplina, int ano, float nota);
        void exibir() const;
    };

private:
    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(const std::string& nome,
          const std::string& email,
          const std::string& senha);

    bool autenticar(const std::string& senhaInformada) const override;
    void adicionarHistorico(const std::string& disciplina, int ano, float nota);
    void gerarRelatorio() const override;
};

#endif