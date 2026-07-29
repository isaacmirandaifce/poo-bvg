#include <iostream>
#include "DataFilter.h"
#include "Transacao.h"
#include "LogSeguranca.h"

int main() {
    std::cout << "=== SECUREBANK PRO: MOTOR GENERICO DE FILTRAGEM (DATA PIPELINE) ===\n\n";

    // --- PIPELINE 1: DOMÍNIO DE TRANSAÇÕES ---
    DataFilter<Transacao> filtroTransacoes;

    filtroTransacoes.adicionar(Transacao(1, 1500.0, "PIX"));
    filtroTransacoes.adicionar(Transacao(2, 12500.50, "TED"));
    filtroTransacoes.adicionar(Transacao(3, 450.0, "PIX"));
    filtroTransacoes.adicionar(Transacao(4, 55000.00, "TED"));

    std::cout << "--> Todas as Transacoes Registradas:\n";
    filtroTransacoes.processar([](const Transacao& t) {
        t.exibir();
    });

    std::cout << "\n--> Filtrando Transacoes Suspeitas (Valor > R$ 10.000):\n";
    std::vector<Transacao> transacoesSuspeitas = filtroTransacoes.filtrar([](const Transacao& t) {
        return t.getValor() > 10000.0;
    });

    for (const auto& t : transacoesSuspeitas) {
        t.exibir();
    }

    std::cout << "\n---------------------------------------------------------------\n\n";

    // --- PIPELINE 2: DOMÍNIO DE LOGS DE SEGURANÇA ---
    DataFilter<LogSeguranca> filtroLogs;

    filtroLogs.adicionar(LogSeguranca("2026-07-29 11:00:01", "INFO", "Login bem-sucedido do operador."));
    filtroLogs.adicionar(LogSeguranca("2026-07-29 11:15:42", "CRITICAL", "Tentativa de acesso nao autorizado detectada na API Core."));
    filtroLogs.adicionar(LogSeguranca("2026-07-29 11:30:10", "INFO", "Backup automatico executado com sucesso."));
    filtroLogs.adicionar(LogSeguranca("2026-07-29 11:45:22", "CRITICAL", "Falha de estouro de buffer no modulo de criptografia."));

    std::cout << "--> Filtrando Apenas Logs Criticos de Seguranca:\n";
    std::vector<LogSeguranca> logsCriticos = filtroLogs.filtrar([](const LogSeguranca& log) {
        return log.getNivel() == "CRITICAL";
    });

    for (const auto& log : logsCriticos) {
        log.exibir();
    }

    return 0;
}