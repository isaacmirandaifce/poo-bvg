#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <vector>
#include <string>

class Aluno : public UsuarioAutenticavel, public Relatorio {
public:
    // Classe interna
    class HistoricoDisciplinar {
    public:
        std::string nomeDisciplina;
        int ano;
        float nota;

        HistoricoDisciplinar(const std::string& nome, int ano, float nota);
    };

private:
    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(const std::string& nome, const std::string& email, const std::string& senha);
    void gerarRelatorio() const override;
    bool autenticar(const std::string& senha) const override;

    void adicionarDisciplina(const std::string& nome, int ano, float nota);

};

#endif
