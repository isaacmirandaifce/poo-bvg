#include <iostream>
#include <vector>
#include "../include/Aluno.h"
#include "../include/Professor.h"
#include "../include/FuncionarioAdministrativo.h"

int main() {
    // Criando objetos
    Aluno aluno("Joao Silva", "joao@email.com", "202301", "Engenharia da Computacao");
    Professor professor("Maria Souza", "maria@email.com", "Ciência da Computacao");
    FuncionarioAdministrativo funcionario("Carlos Lima", "carlos@email.com", "RH", "Gerente");

    // Adicionando disciplinas
    aluno.adicionarDisciplina(Disciplina("Matematica", 60, 7.5f));
    aluno.adicionarDisciplina(Disciplina("Fisica", 40, 8.2f));
    professor.adicionarDisciplina("Algoritmos");
    professor.adicionarDisciplina("Estruturas de Dados");

    // Vetor de usuários
    std::vector<Usuario*> usuarios = {&aluno, &professor, &funcionario};

    // Gerando relatórios polimorficamente
    for (const auto& usuario : usuarios) {
        usuario->gerarRelatorio();
        std::cout << "-----------------------------\n";
    }

    return 0;
}
