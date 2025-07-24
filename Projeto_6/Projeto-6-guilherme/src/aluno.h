#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"
#include <vector>

class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
    std::string matricula;
    std::string curso;
    TipoUsuario tipoUsuario;

    class HistoricoDisciplinar {
    public:
        std::string nomeDisciplina;
        int ano;
        float nota;

        HistoricoDisciplinar(std::string nome, int ano, float nota)
            : nomeDisciplina(nome), ano(ano), nota(nota) {}
    };

    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno();
    Aluno(std::string nome, std::string email, std::string senha,
          std::string matricula, std::string curso);

    void adicionarDisciplinaHistorico(std::string nome, int ano, float nota);

    void gerarRelatorio() const override;
    void exibirInformacoes(bool comNotas) const;
    bool autenticar(std::string senhaDigitada) const override;
};

#endif