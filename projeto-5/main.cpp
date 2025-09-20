#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    // --- 1. Criação dos Objetos ---
    std::cout << "Criando objetos de diferentes tipos..." << std::endl;

    Aluno* aluno1 = new Aluno("Joao Silva", "joao.silva@email.com", "202301", "Engenharia de Software");
    aluno1->adicionarDisciplina("Calculo I");
    aluno1->adicionarDisciplina("Algoritmos");

    Professor* prof1 = new Professor("Maria Souza", "maria.souza@email.com", "Inteligencia Artificial");
    prof1->adicionarDisciplina("Aprendizado de Maquina");
    prof1->adicionarDisciplina("Visao Computacional");

    FuncionarioAdministrativo* func1 = new FuncionarioAdministrativo("Carlos Pereira", "carlos.p@email.com", "Secretaria Academica", "Secretario");

    Monitor* monitor1 = new Monitor("Ana Costa", "ana.costa@email.com", "202205", "Ciencia da Computacao", "Estrutura de Dados");
    monitor1->adicionarDisciplinaMonitorada("Algoritmos");

    // --- 2. Usando Polimorfismo para armazenar todos em uma única lista ---
    std::vector<Usuario*> usuarios;
    usuarios.push_back(aluno1);
    usuarios.push_back(prof1);
    usuarios.push_back(func1);
    usuarios.push_back(monitor1);

    // --- 3. Demonstração de Polimorfismo e Sobrescrita ---
    // A mesma chamada de método se comporta de maneira diferente para cada objeto.
    std::cout << "\n--- GERANDO RELATORIOS DE FORMA POLIMORFICA ---\n" << std::endl;
    for (Usuario* u : usuarios) {
        u->gerarRelatorio();
        std::cout << "--------------------------------------------------\n" << std::endl;
    }

    // --- 4. Demonstração de Sobrecarga (específico da classe Aluno) ---
    std::cout << "--- DEMONSTRANDO SOBRECARGA NA CLASSE ALUNO ---\n" << std::endl;
    std::cout << "--> Chamando gerarRelatorio(false) - Relatorio simples:" << std::endl;
    aluno1->gerarRelatorio(false);
    std::cout << "\n--> Chamando gerarRelatorio(true) - Relatorio com notas (simuladas):" << std::endl;
    aluno1->gerarRelatorio(true);
    std::cout << "--------------------------------------------------\n" << std::endl;


    // --- 5. Liberando a memória alocada ---
    // Essencial para evitar vazamento de memória (memory leak).
    std::cout << "Limpando a memoria..." << std::endl;
    for (Usuario* u : usuarios) {
        delete u;
    }

    return 0;
}
