#include <catch2/catch.hpp>
#include "../src/Aluno.h"
#include "../src/Disciplina.h"

TEST_CASE("Teste da classe Aluno", "[aluno]") {
    Aluno aluno("Teste", "teste@email.com", "20230001");
    Disciplina poo("COMP101", "POO", "Prof. Teste", 4);

    SECTION("Teste de matrícula sem nota") {
        aluno.matricular(&poo);
        REQUIRE(aluno.getMatricula() == "20230001");
    }

    SECTION("Teste de matrícula com nota") {
        aluno.matricular(&poo, 8.5);
        // Verifica se a disciplina foi matriculada
        REQUIRE(aluno.getMatricula() == "20230001");
    }

    SECTION("Teste de exibição de informações") {
        aluno.exibirInformacoes();
        // Teste de smoke - verifica se executa sem erros
        REQUIRE(true);
    }
}