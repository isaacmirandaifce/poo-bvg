#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string disciplina;
    TipoUsuario tipo;

public:
    Professor(const std::string& nome, const std::string& email, const std::string& senha, const std::string& disciplina);

    bool autenticar(const std::string& tentativaSenha) const override;
    void gerarRelatorio() const override;

    TipoUsuario getTipo() const;
    std::string getDisciplina() const;
    void setDisciplina(const std::string& novaDisciplina);
};

#endif // PROFESSOR_H