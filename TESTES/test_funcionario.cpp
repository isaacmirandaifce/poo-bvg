#include <catch2/catch.hpp>
#include "../src/Funcionario.h"

TEST_CASE("Teste da classe Funcionario", "[funcionario]") {
    Funcionario func("Func. Teste", "func@email.com", "Secretário", "Secretaria");

    SECTION("Teste de informações básicas") {
        REQUIRE(func.getCargo() == "Secretário");
        REQUIRE(func.getSetor() == "Secretaria");
    }

    SECTION("Teste de exibição de informações") {
        func.exibirInformacoes();
        REQUIRE(true); // Smoke test
    }
}