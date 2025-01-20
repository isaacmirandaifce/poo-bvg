#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    std::vector<Usuario*> usuarios;

    Aluno aluno("Rikelme", "rikelme@email.com", "2025001", "ADS");
    aluno.adicionarDisciplina("Algoritmos");
    aluno.adicionarDisciplina("Banco de Dados");
    usuarios.push_back(&aluno);

    Professor professor("Maria", "maria@email.com", "Computação");
    professor.adicionarDisciplina("Estruturas de Dados");
    usuarios.push_back(&professor);

    FuncionarioAdministrativo funcionario("Alexander Hamilton", "Hamilton@email.com", "RH", "Coordenador");
    usuarios.push_back(&funcionario);

    for (const auto& usuario : usuarios) {
        usuario->gerarRelatorio();
        std::cout << "\n";
    }

    return 0;
}
