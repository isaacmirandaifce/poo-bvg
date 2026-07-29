#include "Transacao.h"
#include "ContaBancaria.h"

Transacao::Transacao(double valor, std::string data)
    : valor(valor), data(data) {}

void Transacao::exibirTransacao() const {
    std::cout << "Data: " << this->data << " | Valor da Operacao: R$ " << this->valor << std::endl;
}

// Implementação da Função Amiga (Sem prefixo de classe, pois é uma função global amiga)
bool validarTransacao(const ContaBancaria& conta, const Transacao& transacao) {
    std::cout << "\n[AUDITORIA DE SEGURANCA]: Verificando transacao..." << std::endl;
    std::cout << "-> Lendo Saldo Protegido da Conta: R$ " << conta.saldo << std::endl;
    std::cout << "-> Lendo Valor Privado da Transacao: R$ " << transacao.valor << std::endl;

    // Regra de Auditoria: A transação é válida se o valor for positivo e não exceder o saldo atual
    if (transacao.valor <= 0) {
        std::cout << "[ALERTA AUDITORIA]: Transacao recusada! Valor invalido." << std::endl;
        return false;
    }

    if (transacao.valor > conta.saldo) {
        std::cout << "[ALERTA AUDITORIA]: Transacao recusada! Saldo insuficiente." << std::endl;
        return false;
    }

    std::cout << "[AUDITORIA OK]: Transacao APROVADA com sucesso." << std::endl;
    return true;
}