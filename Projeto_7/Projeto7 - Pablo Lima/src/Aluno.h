#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <string>

class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
    std::string matricula;
    std::string curso;
    double media;

public:
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso, double media);
    void gerarRelatorio() const override;
    bool autenticar(const std::string& senha) override;

    double getMedia() const { return media; }
    std::string getNome() const { return nome; }
};

#endif // ALUNO_H