#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include <iostream>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"

class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
    TipoUsuario tipo;
    std::string nome;
public:
    Aluno(const std::string& nome, const std::string& senha);
    bool autenticar(const std::string& senhaTentativa) const override;
    void gerarRelatorio() const override;

    class HistoricoDisciplinar {
    private:
        std::string disciplina;
        int ano;
        double nota;
    public:
        HistoricoDisciplinar(const std::string& disciplina, int ano, double nota);
        void exibir() const;
        std::string getDisciplina() const { return disciplina; }
        int getAno() const { return ano; }
        double getNota() const { return nota; }
    };

    std::vector<HistoricoDisciplinar> historico;

    std::string getNome() const { return nome; }
    double media() const {
        if (historico.empty()) return 0.0;
        double soma = 0.0;
        for (const auto& h : historico) soma += h.getNota();
        return soma / historico.size();
    }
};

#endif // ALUNO_H
