#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"

class Aluno : public UsuarioAutenticavel, public Relatorio {
public:
    class HistoricoDisciplinar {
    public:
        std::string nomeDisciplina;
        int anoCursado;
        float nota;

        HistoricoDisciplinar(std::string nome, int ano, float n)
            : nomeDisciplina(nome), anoCursado(ano), nota(n) {}
    };

private:
    std::vector<HistoricoDisciplinar> historico;

public:
    bool autenticar(const std::string& senha) override {
        return true;
    }

    void gerarRelatorio() const override {
    }

    void adicionarHistorico(const std::string& nome, int ano, float nota) {
        historico.emplace_back(nome, ano, nota);
    }
};

#endif
