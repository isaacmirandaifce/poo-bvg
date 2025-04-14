#include "Professor.h"
#include <iostream>

int main() {
    Professor prof("Maria", "maria@example.com", {"Matemática", "Física"});

    std::cout << "Teste de autenticação do Professor:\n";
    std::cout << "Senha correta (senhaProf): " << (prof.autenticar("senhaProf") ? "Sucesso" : "Falha") << "\n";
    std::cout << "Senha incorreta (abc123): " << (prof.autenticar("abc123") ? "Sucesso" : "Falha") << "\n";

    std::cout << "\nRelatório do Professor:\n";
    prof.gerarRelatorio();

    return 0;
}