#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <string>

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string cargo;
    std::string setor;

public:
    FuncionarioAdministrativo(int id, std::string nome, std::string senha, std::string cargo, std::string setor);

    // Implementação dos métodos herdados
    bool autenticar(const std::string& senha) const override;
    void gerarRelatorio() const override;
};

#endif // FUNCIONARIO_ADMINISTRATIVO_H