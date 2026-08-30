#include <iostream>
#include "ContaBancaria.h"
#include "Transacao.h"

// Implementação da Função Amiga (não pertence a nenhuma das classes)
bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao) {
    // Como é 'friend', pode acessar 'saldo' (protected) e 'valor' (private) diretamente
    if (transacao.valor <= conta.saldo) {
        std::cout << "[AUDITORIA] APROVADA: Transacao de R$" << transacao.valor 
                  << " liberada. Saldo atual: R$" << conta.saldo << ".\n";
        return true;
    } else {
        std::cout << "[AUDITORIA] NEGADA: Tentativa de transacao de R$" << transacao.valor 
                  << " excede o saldo de R$" << conta.saldo << ".\n";
        return false;
    }
}

int main() {
    std::cout << "--- Sistema SecureBank Pro ---\n\n";

    // Criando uma conta
    ContaBancaria conta("Ana Oliveira", "123.456.789-00", 5000.0);
    conta.exibirDados();

    std::cout << "------------------------------\n";

    // Simulando transações
    Transacao t1(2500.0, "30/08/2026");
    Transacao t2(6000.0, "30/08/2026");

    // Validações via Módulo de Auditoria
    std::cout << "Analisando Transacao 1...\n";
    validarTransacao(conta, t1);

    std::cout << "\nAnalisando Transacao 2...\n";
    validarTransacao(conta, t2);

    return 0;
}