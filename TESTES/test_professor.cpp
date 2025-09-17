#include <catch2/catch.hpp>
#include "../src/Professor.h"
#include "../src/Disciplina.h"

TEST_CASE("Teste da classe Professor", "[professor]") {
    Professor prof("Prof. Teste", "prof@email.com", "Ciência da Computação");
    Disciplina poo("COMP101", "POO", "Prof. Teste", 4);

    SECTION("Teste de adição de disciplina") {
        prof.adicionarDisciplina(&poo);
        REQUIRE(prof.getDepartamento() == "Ciência da Computação");
    }

    SECTION("Teste de exibição de informações") {
        prof.exibirInformacoes();
        REQUIRE(true); // Smoke test
    }
}