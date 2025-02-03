#include <iostream>
#include "../include/aluno.h"
#include "../include/professor.h"
#include "../include/funcionarioaAdministrativo.h"
#include "../include/monitor.h"
#include "../include/disciplina.h"

int main() {
    // Criando instâncias de Aluno, Professor, FuncionarioAdministrativo e Monitor
    Aluno aluno("Kaella Sales", "kaella@email.com", TipoUsuario::ALUNO, "Sales26.10", "ADS");
    aluno.adicionarDisciplina(std::make_shared<Disciplina>("Matematica", 60, 7.5));
    aluno.adicionarDisciplina(std::make_shared<Disciplina>("Programacao", 80, 5.8));

    Professor professor("Joao Silva", "joao@email.com", TipoUsuario::PROFESSOR, "Silva01.08", "Computacao");
    professor.adicionarDisciplina("Algoritmos");
    professor.adicionarDisciplina("Estruturas de Dados");

    FuncionarioAdministrativo funcionario("Maria Oliveira", "maria@email.com", TipoUsuario::FUNCIONARIO_ADMINISTRATIVO, "Oliveira15.02", "Secretaria", "Assistente");

    Monitor monitor("Carlos Souza", "carlos@email.com", TipoUsuario::ALUNO, "Souza17.09", "Fisica");
    monitor.adicionarDisciplina(std::make_shared<Disciplina>("Fisica I", 60, 8.0));
    monitor.adicionarDisciplina(std::make_shared<Disciplina>("Fisica II", 60, 9.0));


    // Realizando autenticação para cada usuário
    std::string senha;
    
    std::cout << "\nDigite a senha do Aluno (Kaella Sales): ";
    std::cin >> senha;
    if (aluno.autenticar(senha)) {
        std::cout << "Autenticado com sucesso!\n";
    } else {
        std::cout << "Falha na autenticacao do Aluno.\n";
    }

    std::cout << "\nDigite a senha do Professor (Joao Silva): ";
    std::cin >> senha;
    if (professor.autenticar(senha)) {
        std::cout << "Autenticado com sucesso!\n";
    } else {
        std::cout << "Falha na autenticacao do Professor.\n";
    }

    std::cout << "\nDigite a senha do Funcionario Administrativo (Maria Oliveira): ";
    std::cin >> senha;
    if (funcionario.autenticar(senha)) {
        std::cout << "Autenticado com sucesso!\n";
    } else {
        std::cout << "Falha na autenticacao do Funcionario Administrativo.\n";
    }

    std::cout << "\nDigite a senha do Monitor (Carlos Souza): ";
    std::cin >> senha;
    if (monitor.autenticar(senha)) {
        std::cout << "Autenticado com sucesso!\n";
    } else {
        std::cout << "Falha na autenticação do Monitor.\n";
    }


    // Exibindo informações de cada um
    std::cout << "\nInformacoes do Aluno:\n";
    aluno.gerarRelatorio();

    std::cout << "\nInformacoes do Professor:\n";
    professor.gerarRelatorio();

    std::cout << "\nInformacoes do Funcionario Administrativo:\n";
    funcionario.gerarRelatorio();

    
    std::cout << "\nInformacoes do Monitor:\n";
    monitor.gerarRelatorio();


    return 0;
}
