#include <iostream>
#include <vector>
#include <memory> 
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

using namespace std;

int main() {
    // Criar lista polimórfica de usuários usando ponteiros para Usuario
    vector<Usuario*> usuarios;

    // Criar e adicionar Aluno
    Aluno* a1 = new Aluno("Joao", "joao@uni.edu", "2023001", "ADS");
    a1->adicionarDisciplina("Programacao I");
    a1->adicionarDisciplina("POO");
    usuarios.push_back(a1);

    // Criar e adicionar Professor
    Professor* p1 = new Professor("Dra. Ana", "ana@uni.edu", "Computacao");
    p1->adicionarDisciplina("POO");
    p1->adicionarDisciplina("Algoritmos");
    usuarios.push_back(p1);

    // Criar e adicionar FuncionarioAdministrativo
    FuncionarioAdministrativo* f1 = new FuncionarioAdministrativo("Carlos", "carlos@uni.edu", "Secretaria", "Assistente");
    usuarios.push_back(f1);

    // Criar Monitor (herança múltipla)
    Monitor* m1 = new Monitor("Marina", "marina@uni.edu", "2023050", "ADS", "Computacao");
    m1->adicionarDisciplina("POO");
    m1->adicionarDisciplinaMonitorada("POO");
    usuarios.push_back(m1);

    // Polimorfismo: chamar gerarRelatorio em cada usuário
    cout << "\n== Relatorios (polimorfismo) ==\n";
    for (Usuario* u : usuarios) {
        u->gerarRelatorio();
        cout << endl;
    }

    // Demonstração de sobrecarga no Aluno
    cout << "\n== Demonstracao de sobrecarga (Aluno) ==\n";
    vector<float> notas = {8.5f, 7.0f};
    a1->exibirInformacoes();              // sem notas
    a1->exibirInformacoes(notas);         // com notas (sobrecarga)

    // liberar memória
    for (Usuario* u : usuarios) delete u;

    return 0;
}