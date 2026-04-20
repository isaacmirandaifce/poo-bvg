#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

using namespace std;

int main() {
    vector<Usuario*> listaUsuarios;

    // Instanciação de objetos e upcasting para classe base
    listaUsuarios.push_back(new Aluno("Luidy", "luidy@aluno.com", "2026100", "Sistemas de Informacao"));
    listaUsuarios.push_back(new Professor("Carlos Silva", "carlos@prof.com", "Engenharia de Software", {"POO", "Estrutura de Dados"}));
    listaUsuarios.push_back(new FuncionarioAdministrativo("Mariana Souza", "mariana@adm.com", "Recursos Humanos", "Analista Senior"));
    listaUsuarios.push_back(new Monitor("Joao Pedro", "joao@monitor.com", "2026101", "Ciencia da Computacao", "Algoritmos"));

    cout << "=== Geracao de Relatorios (Polimorfismo) ===" << endl;

    // Iteração polimórfica sobre o vetor
    for (Usuario* u : listaUsuarios) {
        u->gerarRelatorio();
        cout << endl;
    }

    cout << "=== Teste de Sobrecarga (Classe Aluno) ===" << endl;

    // Cast necessário para acessar métodos específicos de Aluno não presentes em Usuario
    Aluno* refAluno = dynamic_cast<Aluno*>(listaUsuarios[0]);
    if (refAluno) {
        refAluno->exibirDetalhes();
        refAluno->exibirDetalhes(true);
    }

    // Liberação de memória
    for (Usuario* u : listaUsuarios) {
        delete u;
    }
    listaUsuarios.clear();

    return 0;
}
