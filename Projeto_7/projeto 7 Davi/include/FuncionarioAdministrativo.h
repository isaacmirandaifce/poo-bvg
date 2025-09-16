#ifndef FUNCIONARIO_ADMINISTRATIVO_H
#define FUNCIONARIO_ADMINISTRATIVO_H

#include <string>
#include <iostream>

class FuncionarioAdministrativo {
private:
    std::string nome;
    std::string setor;

public:
    FuncionarioAdministrativo(const std::string& nome, const std::string& setor);

    const std::string& getNome() const;
    const std::string& getSetor() const;

    void imprimir() const;
};

#endif
