#ifndef ALUNO_H
#define ALUNO_H

#include <vector>
#include <string>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Aluno : public UsuarioAutenticavel, public Relatorio {
public:
    // Classe interna
    class HistoricoDisciplinar {
    public:
        std::string disciplina;
        int ano;
        float nota;

        HistoricoDisciplinar(std::string disciplina, int ano, float nota);
    };
private:
    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(std::string nome, std::string senha);

    bool autenticar(std::string senha) const override;
    void gerarRelatorio() const override;

    void adicionarDisciplina(std::string disciplina, int ano, float nota);

    // Getter do histórico
    const std::vector<HistoricoDisciplinar>& getHistorico() const;

    std::string getSenha() const;
};

#endif