#include <iostream>
#include <string>
#include "DataFilter.h"
#include "Transacao.h"
#include "LogSeguranca.h"

int main() {
    // ===== PIPELINE DE TRANSACOES =====
    DataFilter<Transacao> filtroTransacoes;

    filtroTransacoes.adicionar(Transacao(1, 500.00,   "PIX"));
    filtroTransacoes.adicionar(Transacao(2, 15000.00, "TED"));
    filtroTransacoes.adicionar(Transacao(3, 8000.00,  "PIX"));
    filtroTransacoes.adicionar(Transacao(4, 25000.00, "TED"));
    filtroTransacoes.adicionar(Transacao(5, 200.00,   "PIX"));

    std::cout << "=== Todas as Transacoes ===" << std::endl;
    filtroTransacoes.processar([](const Transacao& t) {
        t.exibir();
    });

    std::cout << "\n=== Transacoes Suspeitas (acima de R$ 10.000) ===" << std::endl;
    auto suspeitas = filtroTransacoes.filtrar([](const Transacao& t) {
        return t.valor > 10000.00;
    });
    for (const Transacao& t : suspeitas) {
        t.exibir();
    }

    std::cout << "\n=== Transacoes PIX ===" << std::endl;
    auto pix = filtroTransacoes.filtrar([](const Transacao& t) {
        return t.tipo == "PIX";
    });
    for (const Transacao& t : pix) {
        t.exibir();
    }

    // ===== PIPELINE DE LOGS =====
    DataFilter<LogSeguranca> filtroLogs;

    filtroLogs.adicionar(LogSeguranca(1700000001, "INFO",     "Login realizado com sucesso."));
    filtroLogs.adicionar(LogSeguranca(1700000002, "CRITICAL", "Tentativa de acesso nao autorizado."));
    filtroLogs.adicionar(LogSeguranca(1700000003, "INFO",     "Relatorio gerado."));
    filtroLogs.adicionar(LogSeguranca(1700000004, "CRITICAL", "Falha na autenticacao de dois fatores."));
    filtroLogs.adicionar(LogSeguranca(1700000005, "INFO",     "Sessao encerrada."));

    std::cout << "\n=== Todos os Logs ===" << std::endl;
    filtroLogs.processar([](const LogSeguranca& l) {
        l.exibir();
    });

    std::cout << "\n=== Logs Criticos ===" << std::endl;
    auto criticos = filtroLogs.filtrar([](const LogSeguranca& l) {
        return l.nivel == "CRITICAL";
    });
    for (const LogSeguranca& l : criticos) {
        l.exibir();
    }

    return 0;
}