#ifndef ALUNO_H
#define ALUNO_H

#include <vector>
#include <string>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Aluno : public UsuarioAutenticavel, public Relatorio {
public:
    class HistoricoDisciplinar {
    private:
        std::string disciplina;
        int ano;
        float nota;

    public:
        HistoricoDisciplinar(std::string disciplina, int ano, float nota);
        void exibir() const;
    };

private:
    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(std::string nome, std::string matricula, std::string senha);

    bool autenticar(const std::string& senha) const override;
    void gerarRelatorio() const override;

    void adicionarDisciplina(std::string disciplina, int ano, float nota);
};

#endif
