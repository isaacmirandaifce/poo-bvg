#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdm.h"

using namespace std;

int main(){
    vector<Usuario*> usuarios;

    usuarios.push_back(new Aluno("Carlos", "c@edu.com", "2025001", "ADS"));
    usuarios.push_back(new Professor("Ana", "ana@edu.com", "Programacao"));
    usuarios.push_back(new FuncionarioAdm("Joao", "joao@edu.com", "Secretaria", "Atendente"));

    //Polimorfismo
    for (Usuario* u : usuarios) {
        u->gerarRelatorio();
        cout << "---------------------" << endl;
    }

    //Liberar Memória
    for (Usuario* u: usuarios) {
        delete u;
    }

    return 0;
}