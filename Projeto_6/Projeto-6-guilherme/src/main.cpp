#include <iostream>
#include "Aluno.h"

int main() {
    Aluno a("Guilherme-Alves", "guilherme.12@gmail.com", "1234", "2023123", "ADS");

    a.adicionarDisciplinaHistorico("POO", 2023, 8.5);
    a.adicionarDisciplinaHistorico("IHC", 2024, 9.0);

    std::cout << "Autenticando...\n";
    std::cout << (a.autenticar("1234") ? "Acesso permitido.\n" : "Acesso negado.\n");

    a.gerarRelatorio();
    a.exibirInformacoes(true);

    return 0;
}