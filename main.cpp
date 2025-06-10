#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    std::vector<std::string> disciplinasAluno = {"Matemática", "Física"};
    std::vector<std::string> disciplinasProfessor = {"Matemática", "Cálculo"};
    std::vector<std::string> disciplinasMonitoradas = {"Matemática"};

    Aluno aluno("João Silva", "joao@email.com", "2023123", "Engenharia", disciplinasAluno);
    Professor prof("Dr. Carlos", "carlos@email.com", "Matemática Aplicada", disciplinasProfessor);
    FuncionarioAdministrativo func("Maria Souza", "maria@email.com", "Secretaria", "Atendente");

    Monitor monitor("Lucas Lima", "lucas@email.com",
                    "2023005", "Computação", disciplinasAluno,
                    "Matemática", disciplinasProfessor, disciplinasMonitoradas);

    // Polimorfismo
    std::vector<Usuario*> usuarios = {&aluno, &prof, &func, &monitor};

    for (const auto& user : usuarios) {
        user->gerarRelatorio();
        std::cout << "-------------------\n";
    }

    // Sobrecarga: Aluno gera relatório com notas
    std::vector<float> notas = {8.5f, 7.0f};
    aluno.gerarRelatorio(notas);

    return 0;
}


