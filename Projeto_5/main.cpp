#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "funcionario.administrativo.h"
#include "Monitor.h"

int main() {
    std::vector<Usuario*> usuarios;

    Aluno aluno("Luciana", "luci123@gmail.com", "12345", "Ciência da Computação");
    aluno.adicionarDisciplina("Matemática");
    aluno.adicionarDisciplina("Física");
    usuarios.push_back(&aluno);

    Professor professor("Giovana", "giovana@gmail.com", "Engenharia de Software");
    professor.adicionarDisciplina("Algoritmos");
    professor.adicionarDisciplina("Banco de Dados");
    usuarios.push_back(&professor);

    FuncionarioAdministrativo funcionario("Rian", "rian@gmail.com", "RH", "Analista");
    usuarios.push_back(&funcionario);

    Monitor monitor("Alice", "ana@gmail.com", "56789", "Engenharia de Produção", "Matemática Aplicada");
    monitor.adicionarDisciplinaMonitorada("Cálculo I");
    monitor.adicionarDisciplinaMonitorada("Álgebra Linear");
    usuarios.push_back(&monitor);

    for (const auto& usuario : usuarios) {
        usuario->gerarRelatorio();
        std::cout << "-------------------------\n";
    }

    return 0;
}
