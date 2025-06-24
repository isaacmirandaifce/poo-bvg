#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include <string>

class FuncionarioAdministrativo {
private:
    std::string nome;
    std::string cargo;

public:
    FuncionarioAdministrativo(const std::string& nome, const std::string& cargo);

    std::string getNome() const;
    std::string getCargo() const;

    void imprimir() const;
};

#endif 