#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Disciplina.h"
#include <vector>

class Aluno : public UsuarioAutenticavel {
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
    void gerarRelatorio() const;
};

#endif // ALUNO_H
