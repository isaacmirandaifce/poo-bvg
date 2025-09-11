#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    // Exemplo de criação de objetos e uso polimórfico
    std::vector<Usuario*> usuarios;

    Aluno aluno("João", "joao@example.com", "20230101", "Ciência da Computação");
    aluno.adicionarDisciplina("Programação 1");

    Professor professor("Dr. Silva", "silva@example.com", "Inteligência Artificial");
    professor.adicionarDisciplina("Machine Learning");

    FuncionarioAdministrativo funcionario("Ana", "ana@example.com", "Financeiro", "Assistente Administrativa");

    Monitor monitor("Carlos", "carlos@example.com", "20230102", "Matemática", "Cálculo");
    monitor.adicionarDisciplinaMonitorada("Álgebra Linear");

    // Adicionando objetos ao vetor de usuários
    usuarios.push_back(&aluno);
    usuarios.push_back(&professor);
    usuarios.push_back(&funcionario);
    usuarios.push_back(&monitor);

    // Gerando relatórios polimorficamente
    for (const auto& usuario : usuarios) {
        usuario->gerarRelatorio();
        std::cout << "\n";
    }

    return 0;
}
