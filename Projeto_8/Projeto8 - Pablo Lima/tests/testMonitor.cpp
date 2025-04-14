#include <iostream>
#include "../Monitor.h"

void testMonitor() {
    // Criando um objeto Monitor
    Monitor monitor(
        "Lucas Andrade",
        "lucas@email.com",
        "202302",
        "Engenharia de Software",
        "Programação"
    );

    // Adicionando disciplinas monitoradas
    monitor.adicionarDisciplinaMonitorada("Algoritmos");
    monitor.adicionarDisciplinaMonitorada("Programação Avançada");

    // Exibindo informações
    std::cout << "== Teste Monitor ==" << std::endl;
    monitor.gerarRelatorio();
}

int main() {
    testMonitor();
    return 0;
}
