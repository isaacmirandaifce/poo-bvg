#include <iostream>
#include <vector>
#include "../include/Aluno.h"
#include "../include/Professor.h"
#include "../include/FuncionarioAdministrativo.h"
#include "../include/Monitor.h"

int main() {
    // Criando aluno
    Aluno aluno("João Silva", "joao@email.com", "202301", "Engenharia da Computação", "senha123");
    aluno.adicionarHistorico(Aluno::HistoricoDisciplinar("Matemática", 2023, 7.5f));
    aluno.adicionarHistorico(Aluno::HistoricoDisciplinar("Física", 2023, 8.2f));

    // Criando professor
    Professor professor("Maria Souza", "maria@email.com", "Ciência da Computação", "senha456");
    professor.adicionarDisciplina("Algoritmos");
    professor.adicionarDisciplina("Estruturas de Dados");

    // Criando funcionário administrativo
    FuncionarioAdministrativo funcionario("Carlos Lima", "carlos@email.com", "RH", "Gerente", "senha789");

    // Criando monitor
    std::vector<std::string> disciplinasMinistradas = {"Algoritmos", "Estruturas de Dados"};
    std::vector<std::string> disciplinasMonitoradas = {"Matemática", "Física"};
    Monitor monitor("Ana Paula", "ana@email.com", "202302", "Engenharia da Computação", "Ciência da Computação", disciplinasMinistradas, disciplinasMonitoradas);

    // Vetor de usuários autenticáveis
    std::vector<UsuarioAutenticavel*> usuarios = {&aluno, &professor, &funcionario};

    // Testando autenticação e relatórios
    for (auto usuario : usuarios) {
        std::string senha;
        std::cout << "Digite a senha de " << typeid(*usuario).name() << ": ";
        std::cin >> senha;

        if (usuario->autenticar(senha)) {
            std::cout << "Autenticação bem-sucedida!\n\n";
            usuario->gerarRelatorio();
        } else {
            std::cout << "Senha incorreta. Acesso negado.\n\n";
        }
    }

    // Exibindo relatório do monitor
    std::cout << "\nRelatório do Monitor:\n";
    monitor.gerarRelatorio();

    return 0;
}


