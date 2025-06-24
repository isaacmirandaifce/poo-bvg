#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"

class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
    TipoUsuario tipo;
    
    class HistoricoDisciplinar {
    private:
        std::string nomeDisciplina;
        int ano;
        double nota;
    public:
        HistoricoDisciplinar(const std::string& nome, int ano, double nota);
        void exibir() const;
    };

    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(const std::string& nome, const std::string& email, const std::string& senha);
    bool autenticar(const std::string& tentativaSenha) const override;
    void adicionarDisciplina(const std::string& nome, int ano, double nota);
    void gerarRelatorio() const override;
    TipoUsuario getTipo() const;
};

#endif
