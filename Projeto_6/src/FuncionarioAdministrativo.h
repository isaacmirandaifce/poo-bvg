#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <string>
#include <sstream>

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string cargo;

public:
    FuncionarioAdministrativo(std::string nome, std::string cpf, std::string senha, std::string cargo);

    bool autenticar(const std::string& senhaFornecida) const override;
    std::string gerarRelatorio() const override;
};

#endif // FUNCIONARIO_ADMINISTRATIVO_H