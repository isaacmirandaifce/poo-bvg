#include <iostream>
#include <vector>
#include <memory>

#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

void testarAutenticacaoEImprimir(std::shared_ptr<UsuarioAutenticavel> usuario, const std::string& senhaTentativa) {
    if (usuario->autenticar(senhaTentativa)) {
        std::cout << "Autenticado com sucesso!\n";
    } else {
        std::cout << "Falha na autenticação.\n";
    }
}

int main() {
    // criando os usuários
    auto aluno = std::make_shared<Aluno>("João da Silva", "joao@email.com", "1234");
    auto professor = std::make_shared<Professor>("Dra. Maria", "maria@ufx.br", "abcd", "Matemática");
    auto funcionario = std::make_shared<FuncionarioAdministrativo>("Carlos", "carlos@adm.br", "admin", "Secretaria");

    // adicionando disciplinas no histórico do aluno
    aluno->adicionarDisciplina("Algoritmos", 2023, 8.5);
    aluno->adicionarDisciplina("Estrutura de Dados", 2024, 9.0);

    // armazenando como ponteiros para interface de relatório
    std::vector<std::shared_ptr<Relatorio>> relatorios = { aluno, professor, funcionario };

    // autenticando os usuários
    std::cout << "Tentando autenticar aluno com senha correta:\n";
    testarAutenticacaoEImprimir(aluno, "1234");

    std::cout << "\nTentando autenticar professor com senha incorreta:\n";
    testarAutenticacaoEImprimir(professor, "errado");

    // gerando os relatórios
    std::cout << "\n--- Relatórios dos Usuários ---\n";
    for (const auto& r : relatorios) {
        r->gerarRelatorio();
        std::cout << "------------------------------\n";
    }

    return 0;
}
