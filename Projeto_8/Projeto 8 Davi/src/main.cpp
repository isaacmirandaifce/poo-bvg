#include <iostream>
#include "Banco.h"
#include "ContaCorrente.h"
#include "ContaPoupanca.h"
#include "Persistencia.h"
#include "SistemaAcademico.h"

int main() {
    // Demonstração simples do módulo bancário
    Banco banco;
    banco.adicionarConta(new ContaCorrente("Joao", 1000, 500));
    banco.adicionarConta(new ContaPoupanca("Maria", 2000, 0.05));
    banco.listarContas();
    banco.realizarOperacoes();

    // Demonstração do sistema acadêmico com persistência CSV
    Persistencia persist("data");
    SistemaAcademico sistema;
    sistema.setPersistencia(&persist);
    persist.loadAll(sistema);
    std::cout << "\\nResumo do sistema acadêmico após carregar CSVs:" << std::endl;
    sistema.listarResumo();

    return 0;
}
