#include <iostream>
#include "ContaBancaria.h"
#include "Transacao.h"

// Implementação da Função Amiga
// acesso direto
bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao) {
    std::cout << "[AUDITORIA] Analisando transacao de R$ " << transacao.valor 
              << " na data " << transacao.data << "..." << std::endl;

    if (transacao.valor <= conta.saldo) {
        std::cout << " -> STATUS: APROVADA. Saldo compativel." << std::endl;
        return true;
    } else {
        std::cout << " -> STATUS: RECUSADA. Saldo insuficiente (R$ " 
                  << conta.saldo << ")." << std::endl;
        return false;
}
}

int main() {
    std::cout << "Sistema de Auditoria SecureBank Pro \n\n";

    // Instanciando os objetos
    ContaBancaria contaCliente("Alice Santos", "123.456.789-00", 2500.00);
    contaCliente.exibirDados();
    std::cout << "-------------------------------------------\n";

    // Criando transações
    Transacao txValida(1500.00, "22/06/2026");
    Transacao txInvalida(3000.00, "22/06/2026");

    // Chamando a função amiga global pra validar
    validarTransacao(contaCliente, txValida);
    std::cout << "\n";
    validarTransacao(contaCliente, txInvalida);

return 0;
}