#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    Aluno aluno("Larissa", "larissa@gmail.com", "12893", "20230000", "ADS");
    aluno.adicionarDisciplina("Matemática", 2023, 9.0);
    aluno.adicionarDisciplina("Física", 2023, 7.0);

    Professor professor("Valdeci", "valdeci@gmail.com", "senha123", "Matemática", {"Cálculo", "Álgebra Linear"});

    FuncionarioAdministrativo funcionario("Jõao", "jõao@gmail.com", "admin123", "RH", "Gerente");

    Monitor monitor("Sara", "sara@gmail.com", "monitor123", "20232002", "Ciência da Computação",
                    {"Estruturas de Dados", "Algoritmos"});

    std::cout << "Autenticação de Aluno: " << (aluno.autenticar("12345") ? "Sucesso" : "Falha") << "\n";
    aluno.gerarRelatorio();

    std::cout << "\nAutenticação de Professor: " << (professor.autenticar("senha123") ? "Sucesso" : "Falha") << "\n";
    professor.gerarRelatorio();

    std::cout << "\nAutenticação de Funcionário: " << (funcionario.autenticar("admin123") ? "Sucesso" : "Falha") << "\n";
    funcionario.gerarRelatorio();

    std::cout << "\nAutenticação de Monitor: " << (monitor.autenticar("monitor123") ? "Sucesso" : "Falha") << "\n";
    monitor.gerarRelatorio();

    return 0;
}
