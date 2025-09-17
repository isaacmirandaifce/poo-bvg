#include <catch2/catch.hpp>
#include "../src/Monitor.h"

TEST_CASE("Teste da classe Monitor", "[monitor]") {
    Monitor monitor("Monitor Teste", "monitor@email.com", "20230002", "Eng. Software");

    SECTION("Teste de herança múltipla") {
        REQUIRE(monitor.getMatricula() == "20230002");
    }

    SECTION("Teste de disciplinas monitoradas") {
        monitor.adicionarDisciplinaMonitorada("COMP101");
        monitor.listarDisciplinasMonitoradas();
        REQUIRE(true); // Smoke test
    }

    SECTION("Teste de exibição de informações") {
        monitor.exibirInformacoes();
        REQUIRE(true); // Smoke test
    }
}