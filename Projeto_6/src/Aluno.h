#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <vector>
#include <string>

class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
    std::string matricula;
    std::string curso;

    class HistoricoDisciplinar {
    private:
        std::string nomeDisciplina;
        int ano;
        float nota;

    public:
        HistoricoDisciplinar(const std::string& nomeDisciplina, int ano, float nota);
        std::string getDetalhes() const;
    };

    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno();
    Aluno(const std::string& nome, const std::string& email, const std::string& senha,
          const std::string& matricula, const std::string& curso);

    void adicionarDisciplina(const std::string& nomeDisciplina, int ano, float nota);
    bool autenticar(const std::string& senha) const override;
    void exibirInformacoes() const override;
    void gerarRelatorio() const override;
};

#endif