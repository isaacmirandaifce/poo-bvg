#include <iostream>
#include <vector>

#include "aluno.h"
#include "professor.h"
#include "funcionarioAdm.h"
#include "monitor.h"

int main() {
// Vetor de ponteiros para a classe base Usuario
    std::vector<Usuario*> usuarios;

    Aluno* a1 = new Aluno("Fernanda", "f@gmail.com", "202501", "ADS");
    a1->adicionarDisciplina("Estrutura de Dados");

    Professor* p1 = new Professor("Isaac", "isaac@ifce.edu.br", "Computação");
    p1->adicionarDisciplinaMinistrada("POO");

    FuncionarioAdministrativo* f1 =
        new FuncionarioAdministrativo("Carlos", "c@ifce.edu.br", "Secretaria", "Assistente");

    Monitor* m1 = new Monitor("João", "joao@gmail.com", "2024001", "ADS", "Computação");
    m1->adicionarDisciplinaMonitorada("Algoritmos");

    // Adiciona os usuários ao vetor
    usuarios.push_back(a1);
    usuarios.push_back(p1);
    usuarios.push_back(f1);
    usuarios.push_back(m1);

    // POLIMORFISMO
    for (auto u : usuarios) {
        u->gerarRelatorio();
    }

    for (auto u : usuarios) delete u;

    return 0;
}
