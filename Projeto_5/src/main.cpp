#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    Aluno aluno("Jhonata", "jhonata@gmail.com", "123456789", "ADS");
    aluno.adicionarDisciplina("Matemática");
    aluno.adicionarDisciplina("Física");

    Professor professor("Isaac", "Isaac@gmail.com", "ADS");
    professor.adicionarDisciplina("Matemática");
    professor.adicionarDisciplina("Física");

    FuncionarioAdministrativo func("Rogilson", "rogilson@gmail.com", "RH", "Analista");

    Monitor monitor("Maria", "maria@gmail.com", "202312346", "Engenharia", "Programação");
    monitor.adicionarDisciplina("Algoritmos");
    monitor.adicionarDisciplinaMonitorada("Lógica");

    std::vector<Usuario*> usuarios = {&aluno, &professor, &func, &monitor};

    for (const auto& usuario : usuarios) {
        usuario->gerarRelatorio();
        std::cout << std::endl;
    }

    return 0;
}
