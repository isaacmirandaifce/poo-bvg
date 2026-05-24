#include <iostream>
#include <vector>

#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

using namespace std;

int main() {

    Aluno a1("Carlos", "carlos@email.com",
              "2023001", "Computacao");

    a1.adicionarDisciplina("POO");
    a1.adicionarDisciplina("Estruturas de Dados");

    Professor p1("Fernanda",
                 "fernanda@email.com",
                 "Programacao");

    p1.adicionarDisciplina("POO");
    p1.adicionarDisciplina("C++");

    FuncionarioAdministrativo f1(
        "Marcos",
        "marcos@email.com",
        "Secretaria",
        "Coordenador");

    Monitor m1(
        "Ana",
        "ana@email.com",
        "2023555",
        "Computacao",
        "Algoritmos");

    m1.adicionarMonitoria("Algoritmos");
    m1.adicionarMonitoria("POO");

    // POLIMORFISMO
    vector<Usuario*> usuarios;

    usuarios.push_back(&a1);
    usuarios.push_back(&p1);
    usuarios.push_back(&f1);
    usuarios.push_back(&m1);

    for (Usuario* u : usuarios) {
        u->gerarRelatorio();
    }

    // SOBRECARGA
    a1.exibirInformacoes();
    a1.exibirInformacoes(9.5);

    return 0;
}