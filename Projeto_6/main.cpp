#include <iostream>
#include <vector>
#include "classes/aluno.h"                   
#include "classes/professor.h"
#include "classes/funcionario_administrativo.h"
#include "classes/monitor.h"

int main() {
    // Criando um vetor de ponteiros para a classe base (UsuarioAutenticavel)
    std::vector<UsuarioAutenticavel*> usuarios;

    // Criando instâncias de Aluno, Professor, Funcionario e Monitor
    Aluno aluno("Luciana", "luci123@gmail.com", "12345", "Ciência da Computação", "senha123");
    aluno.adicionarDisciplina("Matemática");
    aluno.adicionarDisciplina("Física");
    usuarios.push_back(&aluno);

    Professor professor("Giovana", "giovana@gmail.com", "Engenharia de Software", "senha123");
    professor.adicionarDisciplina("Algoritmos");
    professor.adicionarDisciplina("Banco de Dados");
    usuarios.push_back(&professor);

    FuncionarioAdministrativo funcionario("Rian", "rian@gmail.com", "RH", "Analista", "senha123");
    usuarios.push_back(&funcionario);

    Monitor monitor("Alice", "ana@gmail.com", "56789", "Engenharia de Produção", "Matemática Aplicada", "senha123");
    monitor.adicionarDisciplinaMonitorada("Cálculo I");
    monitor.adicionarDisciplinaMonitorada("Álgebra Linear");
    usuarios.push_back(&monitor);

    // Exibindo os relatórios de todos os usuários cadastrados
    for (const auto& usuario : usuarios) {
        usuario->gerarRelatorio();
        std::cout << "-------------------------\n";
    }

    // Tentativa de autenticação
    std::string senhaTentativa;
    std::cout << "Digite a senha para autenticar o aluno Luciana: ";
    std::cin >> senhaTentativa;
    if (aluno.autenticar(senhaTentativa)) {
        std::cout << "Aluno autenticado com sucesso!\n";
    } else {
        std::cout << "Falha na autenticação!\n";
    }

    return 0;
}
