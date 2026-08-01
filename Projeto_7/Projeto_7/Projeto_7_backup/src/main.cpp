#include <iostream>
#include "DataFilter.h"
#include "Transacao.h"
#include "LogSeguranca.h"

int main() {
    
    DataFilter<Transacao> filtroTransacoes;

    filtroTransacoes.adicionar(Transacao(101, 150.50, "PIX"));
    filtroTransacoes.adicionar(Transacao(102, 12500.00, "PIX"));
    filtroTransacoes.adicionar(Transacao(103, 450.00, "TED"));
    filtroTransacoes.adicionar(Transacao(104, 30000.00, "TED"));
    filtroTransacoes.adicionar(Transacao(105, 80.00, "PIX"));

    std::cout << "--- TODAS AS TRANSACOES ---\n";
    filtroTransacoes.processar([](const Transacao& t) {
        t.exibir();
    });

    std::cout << "\n--- TRANSACOES ACIMA DE 10.000 ---\n";
    auto transacoesSuspeitas = filtroTransacoes.filtrar([](const Transacao& t) {
        return t.getValor() > 10000.00;
    });

    for (const auto& t : transacoesSuspeitas) {
        t.exibir();
    }

    std::cout << "\n========================================\n\n";

   
    DataFilter<LogSeguranca> filtroLogs;

    filtroLogs.adicionar(LogSeguranca("2026-07-31 08:00", "INFO", "Usuario logado"));
    filtroLogs.adicionar(LogSeguranca("2026-07-31 08:05", "CRITICAL", "Ataque detectado"));
    filtroLogs.adicionar(LogSeguranca("2026-07-31 08:12", "INFO", "Backup feito"));
    filtroLogs.adicionar(LogSeguranca("2026-07-31 08:15", "CRITICAL", "Erro no sistema"));

    std::cout << "--- TODOS OS LOGS ---\n";
    filtroLogs.processar([](const LogSeguranca& log) {
        log.exibir();
    });

    std::cout << "\n--- LOGS CRITICOS ---\n";
    auto logsCriticos = filtroLogs.filtrar([](const LogSeguranca& log) {
        return log.getNivel() == "CRITICAL";
    });

    for (const auto& log : logsCriticos) {
        log.exibir();
    }

    return 0;
}