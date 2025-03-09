#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"
#include <string>
#include <vector>

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string nome;
    std::string areaDeAtuacao;
    TipoUsuario tipo;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor(std::string nome, std::string areaDeAtuacao, std::string senha);
    bool autenticar(std::string senha) const override;
    void gerarRelatorio() const override;
    void adicionarDisciplinaMinistrada(std::string disciplina);
};

#endif