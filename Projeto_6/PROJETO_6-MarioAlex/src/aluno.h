#ifndef ALUNO_H
#define ALUNO_H

#include <vector>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
    // Classe interna
    class HistoricoDisciplinar {
    public:
        std::string disciplina;
        int ano;
        float nota;
        HistoricoDisciplinar(std::string disciplina, int ano, float nota);
    };

    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(std::string nome, std::string email, std::string senha);

    bool autenticar(std::string senhaDigitada) const override;
    void adicionarDisciplina(std::string disciplina, int ano, float nota);
    void gerarRelatorio() const override;
};

#endif