#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <string>

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string setor;  // Ex: Secretaria, Financeiro, Coordenação

public:
    FuncionarioAdministrativo(const std::string& nome,
                              const std::string& email,
                              const std::string& senha,
                              const std::string& setor);

    bool autenticar(const std::string& senhaInformada) const override;
    void gerarRelatorio() const override;
};

#endif