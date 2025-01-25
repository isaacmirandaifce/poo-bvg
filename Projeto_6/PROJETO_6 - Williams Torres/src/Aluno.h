#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <vector>
#include <string>

class Aluno : public UsuarioAutenticavel, public Relatorio {
public:
    class HistoricoDisciplinar {
    private:
        std::string nomeDisciplina;
        int ano;
        float nota;

    public:
        HistoricoDisciplinar(const std::string& nomeDisciplina, int ano, float nota);
        std::string getDetalhes() const;
    };

private:
    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(const std::string& nome, const std::string& senha);
    bool autenticar(const std::string& senha) const override;
    std::string gerarRelatorio() const override;
    void adicionarDisciplina(const std::string& nomeDisciplina, int ano, float nota);
};

#endif // ALUNO_H