#include <iostream>
#include <vector>
#include "DataFilter.h"
#include "Transacao.h"
#include "LogSeguranca.h"

int main() {
    std::cout << "=== Teste do Modulo de Analytics (Generics) ===\n\n";

    // DOMÍNIO 1: Transações Financeiras
    DataFilter<Transacao> filtroTransacoes;
    filtroTransacoes.adicionar(Transacao(1, 1500.50, "PIX"));
    filtroTransacoes.adicionar(Transacao(2, 12500.00, "TED"));
    filtroTransacoes.adicionar(Transacao(3, 50.00, "PIX"));
    filtroTransacoes.adicionar(Transacao(4, 50000.00, "TED"));

    std::cout << "[PROCESSANDO] Todas as Transacoes Registradas:\n";
    filtroTransacoes.processar([](const Transacao& t) {
        std::cout << " - ID: " << t.getId() << " | Tipo: " << t.getTipo() << " | Valor: R$" << t.getValor() << "\n";
    });

    std::cout << "\n[FILTRANDO] Transacoes Suspeitas (Acima de R$ 10.000):\n";
    auto transacoesSuspeitas = filtroTransacoes.filtrar([](const Transacao& t) {
        return t.getValor() > 10000.0;
    });

    for (const auto& t : transacoesSuspeitas) {
        std::cout << " -> ALERTA: Transacao ID " << t.getId() << " retida para analise.\n";
    }

    std::cout << "\n---------------------------------------------------------\n\n";

    // DOMÍNIO 2: Logs de Segurança
    DataFilter<LogSeguranca> filtroLogs;
    filtroLogs.adicionar(LogSeguranca("2026-07-08 10:00:00", "INFO", "Login bem-sucedido."));
    filtroLogs.adicionar(LogSeguranca("2026-07-08 10:05:00", "CRITICAL", "Tentativa de injecao SQL detectada."));
    filtroLogs.adicionar(LogSeguranca("2026-07-08 10:15:00", "INFO", "Logout do usuario."));

    std::cout << "[PROCESSANDO] Todos os Logs de Seguranca:\n";
    filtroLogs.processar([](const LogSeguranca& log) {
        std::cout << " - [" << log.getTimestamp() << "] " << log.getNivel() << ": " << log.getMensagem() << "\n";
    });

    std::cout << "\n[FILTRANDO] Logs Criticos:\n";
    auto logsCriticos = filtroLogs.filtrar([](const LogSeguranca& log) {
        return log.getNivel() == "CRITICAL";
    });

    for (const auto& log : logsCriticos) {
        std::cout << " -> URGENTE: " << log.getMensagem() << " (Data: " << log.getTimestamp() << ")\n";
    }

    return 0;
}
