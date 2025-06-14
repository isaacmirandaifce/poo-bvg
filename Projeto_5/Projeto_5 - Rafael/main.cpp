#include <iostream>
#include <vector>
#include "src/Aluno/Aluno.h"
#include "src/Professor/Professor.h"
#include "src/FuncionarioAdministrativo/FuncionarioAdministrativo.h"
#include "src/Monitor/Monitor.h"
using namespace std;

int main() {
    vector<Usuario*> usuarios;

    Aluno* aluno = new Aluno("Rafael Maciel", "rafaelmn934@gmail.com", "Aluno", "2023001", "ADS", {"POO", "Engenharia de Software"});
    Professor* professor = new Professor("Isaac Miranda", "isaacpoomiranda@gmail.com", "Professor", "Programação", {"POO", "Banco de Dados"});
    FuncionarioAdministrativo* funcionario = new FuncionarioAdministrativo("Vandinha", "vandinha123@gmail.com", "Funcionario", "RH", "Recepcionista");
    Monitor* monitor = new Monitor("Luidy", "Luidyverde@gmail.com", "Monitor", "2023002", "Programação", {"Estrutura de dados", "Banco de Dados"}, "Programação", {"Lógica de programação", "Tecnologias Web"});

    usuarios.push_back(aluno);
    usuarios.push_back(professor);
    usuarios.push_back(funcionario);
    usuarios.push_back(monitor);

    for (Usuario* u : usuarios) {
        u->gerarRelatorio();
    }

    // Exemplo de polimorfismo: sobrecarga
    aluno->gerarRelatorio(true);

    // Liberação de memória
    for (Usuario* u : usuarios) {
        delete u;
    }

    return 0;
}