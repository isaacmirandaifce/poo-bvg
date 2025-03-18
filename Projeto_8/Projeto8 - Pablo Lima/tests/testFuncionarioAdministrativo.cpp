#include <iostream>
#include "../FuncionarioAdministrativo.h"

void testFuncionarioAdministrativo() {
    // Criando um objeto FuncionarioAdministrativo
    FuncionarioAdministrativo funcionario("Carlos Souza", "carlos@email.com", "Recursos Humanos", "Analista");

    // Exibindo informações
    std::cout << "== Teste Funcionário Administrativo ==" << std::endl;
    funcionario.gerarRelatorio();
}

int main() {
    testFuncionarioAdministrativo();
    return 0;
}
