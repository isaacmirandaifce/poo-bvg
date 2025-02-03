#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include <string>

class FuncionarioAdministrativo {
private:
    std::string nome;
    std::string cargo;

public:
    FuncionarioAdministrativo(const std::string& nome, const std::string& cargo)
        : nome(nome), cargo(cargo) {}

    std::string getNome() const { return nome; }
    std::string getCargo() const { return cargo; }

    void imprimir() const {
        std::cout << "Funcionário: " << nome << ", Cargo: " << cargo << std::endl;
    }
};

#endif // FUNCIONARIOADMINISTRATIVO_H
