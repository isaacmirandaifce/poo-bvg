#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "../usuario/UsuarioAutenticavel.h"  // Corrigido caminho relativo
#include "../relatorio/Relatorio.h"          // Corrigido caminho relativo
#include <string>

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string departamento;
    std::string cargo;

public:
    FuncionarioAdministrativo(const std::string& nome, const std::string& email, const std::string& departamento, const std::string& cargo, const std::string& senha);
    void gerarRelatorio() const override;
    bool autenticar(const std::string& senhaTentativa) override;
    ~FuncionarioAdministrativo() {}
};

#endif