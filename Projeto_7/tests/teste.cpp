#include <iostream>
#include <memory>
#include "../src/Aluno.h"
#include "../src/Filtro.h"

int main() {
    // criando alunos
    auto aluno1 = std::make_shared<Aluno>("Leticia", "leticia123", "123456");
    aluno1->adicionarDisciplina("POO", 2023, 9.0);
    aluno1->adicionarDisciplina("Estrutura de Dados", 2023, 8.0);

    auto aluno2 = std::make_shared<Aluno>("Joao", "joao@email.com", "senha123");
    aluno2->adicionarDisciplina("POO", 2023, 5.0);
    aluno2->adicionarDisciplina("Cálculo", 2023, 6.0);

    auto aluno3 = std::make_shared<Aluno>("Maria", "maria@email.com", "maria123");
    aluno3->adicionarDisciplina("POO", 2023, 10.0);
    aluno3->adicionarDisciplina("Cálculo", 2023, 9.5);

    // teste autenticação
    std::cout << "[TESTE AUTENTICAÇÃO - Correta] ";
    std::cout << (aluno1->autenticar("123456") ? "Sucesso\n" : "Falha\n");

    std::cout << "[TESTE AUTENTICAÇÃO - Errada] ";
    std::cout << (!aluno1->autenticar("errada") ? "Sucesso (bloqueado corretamente)\n" : "Falha\n");

    // teste relatório
    std::cout << "\n[TESTE RELATÓRIO - Leticia]\n";
    aluno1->gerarRelatorio();

    // filtro
    Filtro<std::shared_ptr<Aluno>> filtro;
    filtro.adicionarElemento(aluno1);
    filtro.adicionarElemento(aluno2);
    filtro.adicionarElemento(aluno3);

    // teste filtrarPorCondicao
    std::cout << "\n[TESTE FILTRO - Alunos com média > 7.0]\n";
    auto aprovados = filtro.filtrarPorCondicao([](const std::shared_ptr<Aluno>& a) {
        return a->calcularMediaGeral() > 7.0;
    });

    for (const auto& aluno : aprovados) {
        std::cout << "Aprovado: " << aluno->getNome()
                  << " - Média: " << aluno->calcularMediaGeral() << "\n";
    }

    // teste imprimirTodos
    std::cout << "\n[TESTE imprimirTodos - Listando todos os alunos]\n";
    filtro.imprimirTodos([](const std::shared_ptr<Aluno>& a) {
        std::cout << a->getNome() << " - Média: " << a->calcularMediaGeral() << "\n";
    });

    // teste ordenarPor
    std::cout << "\n[TESTE ordenarPor - Alunos em ordem decrescente de média]\n";
    auto ordenados = filtro.ordenarPor([](const std::shared_ptr<Aluno>& a1, const std::shared_ptr<Aluno>& a2) {
        return a1->calcularMediaGeral() > a2->calcularMediaGeral();
    });

    for (const auto& aluno : ordenados) {
        std::cout << aluno->getNome() << " - Média: " << aluno->calcularMediaGeral() << "\n";
    }

    // validação final
    if (!ordenados.empty() && ordenados[0]->getNome() == "Maria") {
        std::cout << "Ordenação por média está funcionando corretamente\n";
    } else {
        std::cout << "Ordenação por média falhou\n";
    }

    return 0;
}
