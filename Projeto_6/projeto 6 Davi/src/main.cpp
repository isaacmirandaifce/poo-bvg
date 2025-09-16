
#include <iostream>
#include "../include/Aluno.h"
#include "../include/Professor.h"
#include "../include/FuncionarioAdministrativo.h"

int main() {
    Aluno aluno("João", "joao123", "senha123");
    Professor prof("Maria", "maria123", "senhaProf");
    FuncionarioAdministrativo func("Carlos", "carlos123", "senhaFunc");

    std::cout << "\nTentando autenticar aluno..." << std::endl;
    if (aluno.autenticar("senha123")) {
        aluno.adicionarDisciplina("POO", 2025, 9.5);
        aluno.gerarRelatorio();
    }

    std::cout << "\nRelatório do Professor:" << std::endl;
    prof.gerarRelatorio();

    std::cout << "\nRelatório do Funcionário:" << std::endl;
    func.gerarRelatorio();

    return 0;
}
