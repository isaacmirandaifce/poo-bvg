#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <vector>

class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
    double media;

public:
    class HistoricoDisciplinar {
    public:
        std::string disciplina;
        int ano;
        double nota;

        HistoricoDisciplinar(const std::string& d, int a, double n)
            : disciplina(d), ano(a), nota(n) {}
    };

    Aluno(const std::string& nome,
          const std::string& email,
          const std::string& senha,
          double media);

    bool autenticar(const std::string& senha) const override;
    void gerarRelatorio() const override;

    double getMedia() const;
};

#endif