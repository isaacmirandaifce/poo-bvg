#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include <string>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string setor;
    TipoUsuario tipo;

public:
    FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& senha, const std::string& setor);

    bool autenticar(const std::string& tentativaSenha) const override;
    void gerarRelatorio() const override;

    TipoUsuario getTipo() const;
    std::string getSetor() const;
    void setSetor(const std::string& novoSetor);
};

#endif // FUNCIONARIO_ADMINISTRATIVO_H