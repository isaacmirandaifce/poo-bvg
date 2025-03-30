#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    Aluno aluno("Jhonata", "jhonata@gmail.com", "12345", "20231001", "ADS");
    aluno.adicionarDisciplina("Matemática", 2023, 9.5);
    aluno.adicionarDisciplina("Física", 2023, 8.0);

    Professor professor("Isaac", "isaac@gmail.com", "senha123", "Matemática", {"Cálculo", "Álgebra Linear"});

    FuncionarioAdministrativo funcionario("Carlos", "carlos@gmail.com", "admin123", "RH", "Gerente");

    Monitor monitor("Ana", "ana@gmail.com", "monitor123", "20232002", "Ciência da Computação",
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
