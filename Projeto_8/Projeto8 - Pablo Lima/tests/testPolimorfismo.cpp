#include <iostream>
#include <vector>
#include "../Aluno.h"
#include "../Professor.h"
#include "../FuncionarioAdministrativo.h"

void testPolimorfismo() {
    // Criando objetos de diferentes tipos
    Aluno aluno("João Silva", "joao@email.com", "202301", "Engenharia de Software");
    Professor professor("Maria Oliveira", "maria@email.com", "Ciência da Computação");
    FuncionarioAdministrativo funcionario("Carlos Souza", "carlos@email.com", "Recursos Humanos", "Analista");

    // Vetor de ponteiros para Usuario
    std::vector<Usuario*> usuarios;
    usuarios.push_back(&aluno);
    usuarios.push_back(&professor);
    usuarios.push_back(&funcionario);

    // Exibindo relatórios polimorficamente
    std::cout << "== Teste Polimorfismo ==" << std::endl;
    for (Usuario* usuario : usuarios) {
        usuario->gerarRelatorio();
        std::cout << "---------------------" << std::endl;
    }
}

int main() {
    testPolimorfismo();
    return 0;
}
