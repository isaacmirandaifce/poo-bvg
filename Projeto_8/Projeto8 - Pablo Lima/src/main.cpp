#include <iostream>
#include "Filtro.h"
#include "Aluno.h"
#include "Professor.h"
#include "Persistencia.h"
#include "SinalHandler.h"

int main() {
    SinalHandler::inicializar();

    Persistencia persistencia;
    Filtro<Aluno> filtroAlunos;

    try {
        std::vector<Aluno> alunosCarregados = persistencia.carregarAlunos();
        for (const auto& aluno : alunosCarregados) {
            filtroAlunos.adicionarElemento(aluno);
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro ao carregar alunos: " << e.what() << std::endl;
    }

    // Adicionando alunos com todos os 5 argumentos (nome, email, senha, curso, media)
    filtroAlunos.adicionarElemento(Aluno("João Silva", "joao@email.com", "senha123", "Engenharia", 8.5));
    filtroAlunos.adicionarElemento(Aluno("Maria Oliveira", "maria@email.com", "senha456", "Matemática", 6.0));
    filtroAlunos.adicionarElemento(Aluno("Carlos Souza", "carlos@email.com", "senha789", "Física", 9.2));

    // Usando filtrarPorCondicao para obter todos os alunos (sem filtro)
    auto todosAlunos = filtroAlunos.filtrarPorCondicao([](const Aluno&) { return true; });
    persistencia.salvarAlunos(todosAlunos);

    std::cout << "Alunos com média acima de 7.0:\n";
    auto alunosAprovados = filtroAlunos.filtrarPorCondicao([](const Aluno& a) { return a.getMedia() > 7.0; });

    for (const auto& aluno : alunosAprovados) {
        aluno.gerarRelatorio();
    }

    return 0;
}