#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    std::vector<Usuario*> usuarios;

    // Criando um aluno
    Aluno* a = new Aluno("Joao", "joao@email.com", "20231234", "Engenharia");
    a->Aluno::adicionarDisciplina("Calculo I");
    a->Aluno::adicionarDisciplina("Fisica I");
    usuarios.push_back(a);

    // Criando um professor
    Professor* p = new Professor("Maria", "maria@email.com", "Matematica");
    p->Professor::adicionarDisciplina("Algebra Linear");
    p->Professor::adicionarDisciplina("Geometria Analitica");
    usuarios.push_back(p);

    // Criando um funcionário administrativo
    FuncionarioAdministrativo* f = new FuncionarioAdministrativo("Carlos", "carlos@email.com", "Financeiro", "Assistente");
    usuarios.push_back(f);

    // Criando um monitor
    Monitor* m = new Monitor("Ana", "ana@email.com", "20234567", "Ciencia da Computaçao", "Logica de Programacao");
    m->Aluno::adicionarDisciplina("Estrutura de Dados");
    m->Professor::adicionarDisciplina("POO");
    m->adicionarDisciplinaMonitorada("Algoritmos");
    m->adicionarDisciplinaMonitorada("Matematica Discreta");
    usuarios.push_back(m);

    // Exibindo os relatórios (polimorfismo)
    for (Usuario* u : usuarios) {
        std::cout << "---------------------------\n";
        u->gerarRelatorio();

        // Se for um monitor, também mostra disciplinas monitoradas
        Monitor* monitorPtr = dynamic_cast<Monitor*>(u);
        if (monitorPtr != nullptr) {
            std::cout << ">> Disciplinas Monitoradas:\n";
            monitorPtr->listarDisciplinasMonitoradas();
        }
    }

    // Limpando memória
    for (Usuario* u : usuarios) {
        delete u;
    }

    return 0;
}
