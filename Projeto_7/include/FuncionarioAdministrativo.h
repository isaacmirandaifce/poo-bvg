#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include <string>

class FuncionarioAdministrativo {
private:
    std::string nome;
    std::string departamento;

public:
    FuncionarioAdministrativo(std::string nome, std::string departamento);
    std::string getNome() const;
    std::string getDepartamento() const;
};

#endif // FUNCIONARIOADMINISTRATIVO_H