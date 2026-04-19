#include <string>

class Cliente {
    private:
    std::string nome;
    std::string cpf;

public: Cliente(std::string n, std::string c) : nome(n), cpf(c) {}

std::string getCliente(){ return nome;}
};
