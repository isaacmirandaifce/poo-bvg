#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

int main() {
    Aluno aluno1("Carlos Silva", "senha123");
    aluno1.adicionarDisciplina("POO", 2024, 8.5);
    aluno1.adicionarDisciplina("Estrutura de Dados", 2024, 7.0);

    Professor prof1("Ana Lima", "prof2024");
    FuncionarioAdministrativo func1("João Martins", "adm789");

    std::string senhaDigitada;
    
    std::cout << "Autenticando aluno...\nSenha: ";
    std::cin >> senhaDigitada;
    if (aluno1.autenticar(senhaDigitada)) {
        aluno1.gerarRelatorio();
    } else {
        std::cout << "Senha incorreta.\n";
    }

    std::cout << "\nAutenticando professor...\nSenha: ";
    std::cin >> senhaDigitada;
    if (prof1.autenticar(senhaDigitada)) {
        prof1.gerarRelatorio();
    }

    return 0;
}
