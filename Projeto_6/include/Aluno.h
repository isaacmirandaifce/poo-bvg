#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"
#include <string>
#include <vector>

class Aluno : public UsuarioAutenticavel, public Relatorio {
public:
    Aluno(const std::string& nome, const std::string& senha);
    bool autenticar(const std::string& senha) const override;
    void gerarRelatorio() const override;
    TipoUsuario getTipo() const;

    class HistoricoDisciplinar {
    public:
        HistoricoDisciplinar(const std::string& disciplina, int ano, float nota);
        std::string getDisciplina() const;
        int getAno() const;
        float getNota() const;

    private:
        std::string disciplina;
        int ano;
        float nota;
    };

    void adicionarDisciplina(const std::string& disciplina, int ano, float nota);
    void mostrarHistorico() const;

private:
    std::string nome;
    std::string senha;
    std::vector<HistoricoDisciplinar> historico;
};

#endif 