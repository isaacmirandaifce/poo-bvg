#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

using namespace std;

int main() {

    vector<Usuario*> usuarios;

    Aluno a("David", "david@email.com", "123", "ADS");
    Professor p("Carlos", "carlos@email.com", "Programacao");
    FuncionarioAdministrativo f("Ana", "ana@email.com", "Secretaria", "Atendente");

    usuarios.push_back(&a);
    usuarios.push_back(&p);
    usuarios.push_back(&f);

    for (Usuario* u : usuarios) {
        u->gerarRelatorio();
        cout << "-----" << endl;
    }

    return 0;
}
