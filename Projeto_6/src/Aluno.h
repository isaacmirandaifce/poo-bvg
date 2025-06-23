#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <vector>
#include <string>
#include <sstream> 

class Aluno : public UsuarioAutenticavel, public Relatorio {
public:

    class HistoricoDisciplinar {
    private:
        struct DisciplinaCursada {
            std::string nomeDisciplina;
            int anoCursado;
            float nota;
        };
        std::vector<DisciplinaCursada> disciplinas;

    public:
        void adicionarDisciplina(const std::string& nome, int ano, float nota);
        std::string getHistoricoFormatado() const;
    };

private:
    std::string matricula;
    HistoricoDisciplinar historico;

public:
    Aluno(std::string nome, std::string cpf, std::string senha, std::string matricula);

    bool autenticar(const std::string& senhaFornecida) const override;
    std::string gerarRelatorio() const override;

    HistoricoDisciplinar& getHistorico();
};

#endif 