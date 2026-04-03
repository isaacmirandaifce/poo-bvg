#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include <string>
#include <iostream>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    TipoUsuario tipo;
    std::string nome;
public:
    FuncionarioAdministrativo(const std::string& nome, const std::string& senha);

    bool autenticar(const std::string& senhaTentativa) const override;
    void gerarRelatorio() const override;

    std::string getNome() const { return nome; }
};

#endif // FUNCIONARIO_ADMINISTRATIVO_H
