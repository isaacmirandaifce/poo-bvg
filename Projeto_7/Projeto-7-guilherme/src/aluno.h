#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"
#include <vector>
#include <string>
#include <iostream>

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
    bool cursouDisciplinaNoAno(const std::string& nome, int ano) const;
    void imprimirInformacoes() const;
    void gerarRelatorio() const override;
    void exibirInformacoes(bool comNotas) const;
    bool autenticar(std::string senhaDigitada) const override;

    template<typename Func>
    void executarNoHistorico(Func func) const {
        for (const auto& h : historico) {
            func(h.nomeDisciplina, h.ano, h.nota);
        }
    }
};


#endif
