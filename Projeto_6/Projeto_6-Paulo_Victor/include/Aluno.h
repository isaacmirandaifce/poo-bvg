#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"
#include <string>
#include <vector>

class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
    std::string nome;
    std::string matricula;
    std::string curso;
    TipoUsuario tipo;

    // Classe interna
    class HistoricoDisciplinar {
    private:
        std::string disciplina;
        int ano;
        float nota;

    public:
        HistoricoDisciplinar(std::string disciplina, int ano, float nota);
        void exibirHistorico() const;
    };

    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(std::string nome, std::string matricula, std::string curso, std::string senha);
    bool autenticar(std::string senha) const override;
    void gerarRelatorio() const override;
    void adicionarDisciplinaAoHistorico(std::string disciplina, int ano, float nota);
    void exibirHistoricoCompleto() const;
};

#endif