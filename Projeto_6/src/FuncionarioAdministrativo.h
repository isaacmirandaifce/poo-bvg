#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include <string>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class FuncionarioAdministrativo : public UsuarioAutenticavel, public Relatorio {
private:
    std::string departamento;
    std::string cargo;

public:
    FuncionarioAdministrativo();
    FuncionarioAdministrativo(std::string nome, std::string email, const std::string& senha,
                              std::string departamento, std::string cargo);

    // Sobrescrita: implementacao do metodo abstrato herdado de UsuarioAutenticavel
    bool autenticar(std::string senha) override;

    // Sobrescrita: implementacao do metodo virtual puro da interface Relatorio
    void gerarRelatorio() const override;
};

#endif // FUNCIONARIOADMINISTRATIVO_H
