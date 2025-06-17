#include <iostream>
#include <vector>
#include <memory> // Para std::unique_ptr

#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

int main() {
    // ---- Demonstração de Polimorfismo com a hierarquia de classes ---- 
    std::cout << "========= DEMONSTRACAO DE POLIMORFISMO =========" << std::endl;
    std::vector<std::unique_ptr<Usuario>> usuarios;

    // Criando objetos de classes derivadas e adicionando ao vetor de ponteiros da classe base.
    auto aluno1 = std::make_unique<Aluno>("Joao Silva", "joao.silva@email.com", "2023001", "Engenharia de Software");
    aluno1->adicionarDisciplina("Calculo I");
    aluno1->adicionarDisciplina("Programacao I");
    
    auto professor1 = std::make_unique<Professor>("Dr. Carlos Pereira", "carlos.p@email.com", "Inteligencia Artificial");
    professor1->adicionarDisciplina("Sistemas Inteligentes");

    auto func1 = std::make_unique<FuncionarioAdministrativo>("Ana Costa", "ana.costa@email.com", "Secretaria", "Secretaria Academica");

    usuarios.push_back(std::move(aluno1));
    usuarios.push_back(std::move(professor1));
    usuarios.push_back(std::move(func1));
    
    // Chamando o método polimórfico gerarRelatorio()
    for (const auto& usuario : usuarios) {
        usuario->gerarRelatorio();
    }

    // ---- Demonstração de Sobrecarga na classe Aluno ---- 
    std::cout << "\n========= DEMONSTRACAO DE SOBRECARGA (ALUNO) =========" << std::endl;
    Aluno aluna_detalhes("Maria Oliveira", "maria.o@email.com", "2023002", "Ciencia da Computacao");
    aluna_detalhes.adicionarDisciplina("Estrutura de Dados");
    
    std::cout << "Exibindo detalhes SEM notas:" << std::endl;
    aluna_detalhes.exibirInformacoesDetalhadas();
    
    std::cout << "Exibindo detalhes COM notas:" << std::endl;
    aluna_detalhes.exibirInformacoesDetalhadas(true);

    // ---- Demonstração de Herança Múltipla com a classe Monitor ---- 
    std::cout << "\n========= DEMONSTRACAO DE HERANCA MULTIPLA (MONITOR) =========" << std::endl;
    Monitor monitor1("Pedro Martins", "pedro.m@email.com", "2022015", "Engenharia de Software", "Desenvolvimento Web");
    monitor1.adicionarDisciplinaMonitorada("Programacao I");
    monitor1.gerarRelatorio();

    return 0;
}