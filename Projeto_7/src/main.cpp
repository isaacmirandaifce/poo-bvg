#include <iostream>
#include "DataFilter.h"
#include "Transacao.h"
#include "LogSeguranca.h"

int main() {
    // ---------------------------------------------------------
    // 1. Pipeline de Transações
    // ---------------------------------------------------------
    DataFilter<Transacao> filtroTransacoes;
    filtroTransacoes.adicionar(Transacao(101, 1500.0, "PIX"));
    filtroTransacoes.adicionar(Transacao(102, 12000.0, "TED"));
    filtroTransacoes.adicionar(Transacao(103, 50.0, "PIX"));

    std::cout << "--- Processando Todas as Transacoes ---\n";
    filtroTransacoes.processar([](const Transacao& t) {
        std::cout << "ID: " << t.getId() << " | Tipo: " << t.getTipo() << " | Valor: R$ " << t.getValor() << "\n";
    });

    std::cout << "\n--- Filtrando Transacoes Suspeitas (> R$ 10.000) ---\n";
    auto transacoesSuspeitas = filtroTransacoes.filtrar([](const Transacao& t) {
        return t.getValor() > 10000.0; // Expressão Lambda para a regra de negócio
    });

    for (const auto& t : transacoesSuspeitas) {
        std::cout << "[ALERTA] Transacao Suspeita - ID: " << t.getId() << " no valor de R$ " << t.getValor() << "\n";
    }

    // ---------------------------------------------------------
    // 2. Pipeline de Logs de Segurança
    // ---------------------------------------------------------
    DataFilter<LogSeguranca> filtroLogs;
    filtroLogs.adicionar(LogSeguranca("2026-08-30 14:00:00", "INFO", "Login do usuario administrativo."));
    filtroLogs.adicionar(LogSeguranca("2026-08-30 14:05:32", "CRITICAL", "Falha de autenticacao - 5 tentativas falhas."));
    filtroLogs.adicionar(LogSeguranca("2026-08-30 14:15:10", "CRITICAL", "Tentativa de injeção de SQL detectada."));

    std::cout << "\n--- Filtrando Logs Criticos ---\n";
    auto logsCriticos = filtroLogs.filtrar([](const LogSeguranca& log) {
        return log.getNivel() == "CRITICAL"; // Expressão Lambda para a regra de negócio
    });

    for (const auto& log : logsCriticos) {
        std::cout << "[" << log.getTimestamp() << "] " << log.getNivel() << ": " << log.getMensagem() << "\n";
    }

    return 0;
}