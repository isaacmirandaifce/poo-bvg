
#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"
#include <vector>
#include <string>

class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
    class HistoricoDisciplinar {
    public:
        std::string nomeDisciplina;
        int ano;
        float nota;
        HistoricoDisciplinar(std::string nome, int ano, float nota);
        void exibir() const;
    };
    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(std::string nome, std::string login, std::string senha);
    bool autenticar(std::string senha) override;
    void adicionarDisciplina(std::string nome, int ano, float nota);
    void gerarRelatorio() const override;
};

#endif
