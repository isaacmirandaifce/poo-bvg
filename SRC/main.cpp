#include <iostream>
#include <vector>
#include <memory>
#include "Aluno.h"
#include "Professor.h"
#include "Funcionario.h"
#include "Monitor.h"
#include "Disciplina.h"

int main() {
    // Criando disciplinas
    Disciplina poo("COMP101", "Programação Orientada a Objetos", "Dr. Silva", 4);
    Disciplina ed("COMP102", "Estruturas de Dados", "Dr. Souza", 4);
    Disciplina calc("MATH101", "Cálculo I", "Dr. Oliveira", 6);

    // Criando usuários
    Aluno aluno1("João da Silva", "joao@email.com", "20230001");
    Aluno aluno2("Maria Oliveira", "maria@email.com", "20230002");
    
    Professor prof1("Dr. Silva", "silva@email.com", "Ciência da Computação");
    Professor prof2("Dr. Souza", "souza@email.com", "Ciência da Computação");
    
    Funcionario func1("Carlos Andrade", "carlos@email.com", "Secretário", "Secretaria Acadêmica");
    
    Monitor monitor1("Ana Costa", "ana@email.com", "20230003", "Engenharia de Software");

    // Matriculando alunos e professores
    aluno1.matricular(&poo);
    aluno1.matricular(&ed, 8.5);
    aluno2.matricular(&poo);
    aluno2.matricular(&calc, 7.0);
    
    prof1.adicionarDisciplina(&poo);
    prof2.adicionarDisciplina(&ed);
    
    monitor1.adicionarDisciplina(&calc);
    monitor1.adicionarDisciplinaMonitorada("COMP101");

    // Usando polimorfismo
    std::vector<std::unique_ptr<Usuario>> usuarios;
    usuarios.push_back(std::make_unique<Aluno>(aluno1));
    usuarios.push_back(std::make_unique<Aluno>(aluno2));
    usuarios.push_back(std::make_unique<Professor>(prof1));
    usuarios.push_back(std::make_unique<Professor>(prof2));
    usuarios.push_back(std::make_unique<Funcionario>(func1));
    usuarios.push_back(std::make_unique<Monitor>(monitor1));

    // Exibindo informações de forma polimórfica
    for (const auto& usuario : usuarios) {
        usuario->exibirInformacoes();
        std::cout << "-------------------\n";
    }

    // Demonstração de sobrecarga
    std::cout << "\n=== Demonstração de Sobrecarga ===\n";
    Disciplina bd("COMP103", "Banco de Dados", "Dr. Santos", 4);
    aluno1.matricular(&bd); // Sem nota
    aluno1.matricular(&bd, 9.0); // Com nota inicial

    // Demonstração de herança múltipla
    std::cout << "\n=== Demonstração de Herança Múltipla ===\n";
    monitor1.listarDisciplinas();
    monitor1.listarDisciplinasMonitoradas();

    return 0;
}