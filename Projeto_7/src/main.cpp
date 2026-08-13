#include <iostream>
#include <vector>

#include "DataFilter.h"
#include "Transacao.h"
#include "LogSeguranca.h"

/**
 * @brief Imprime um cabeçalho de seção no console para organizar a saída.
 */
static void imprimirCabecalho(const std::string& titulo) {
    std::cout << "\n=== " << titulo << " ===\n";
}

int main() {
    std::cout << "SecureBank Pro - Modulo de Data Analytics\n";
    std::cout << "Motor Generico de Filtragem (DataFilter<T>)\n";

    // ---------------------------------------------------------------
    // 1. Pipeline de Transacoes -> DataFilter<Transacao>
    // ---------------------------------------------------------------
    DataFilter<Transacao> filtroTransacoes;

    filtroTransacoes.adicionar(Transacao(1, 250.00, "PIX"));
    filtroTransacoes.adicionar(Transacao(2, 12500.00, "TED"));
    filtroTransacoes.adicionar(Transacao(3, 9800.00, "PIX"));
    filtroTransacoes.adicionar(Transacao(4, 15300.50, "TED"));
    filtroTransacoes.adicionar(Transacao(5, 500.00, "PIX"));
    filtroTransacoes.adicionar(Transacao(6, 10000.01, "PIX"));

    imprimirCabecalho("Todas as transacoes cadastradas");
    filtroTransacoes.processar([](const Transacao& t) {
        std::cout << t.toString() << '\n';
    });

    // Regra de negocio: transacoes suspeitas sao aquelas acima de R$10.000,00.
    auto transacoesSuspeitas = filtroTransacoes.filtrar([](const Transacao& t) {
        return t.getValor() > 10000.00;
    });

    imprimirCabecalho("Transacoes suspeitas (valor > R$10.000,00)");
    for (const Transacao& t : transacoesSuspeitas) {
        std::cout << t.toString() << '\n';
    }

    // Regra de negocio: transacoes do tipo PIX de alto valor (>= R$5.000,00).
    auto pixAltoValor = filtroTransacoes.filtrar([](const Transacao& t) {
        return t.getTipo() == "PIX" && t.getValor() >= 5000.00;
    });

    imprimirCabecalho("PIX de alto valor (>= R$5.000,00)");
    for (const Transacao& t : pixAltoValor) {
        std::cout << t.toString() << '\n';
    }

    // ---------------------------------------------------------------
    // 2. Pipeline de Logs de Seguranca -> DataFilter<LogSeguranca>
    // ---------------------------------------------------------------
    DataFilter<LogSeguranca> filtroLogs;

    filtroLogs.adicionar(LogSeguranca("2026-08-11 09:12:03", "INFO", "Login efetuado com sucesso"));
    filtroLogs.adicionar(LogSeguranca("2026-08-11 09:15:47", "CRITICAL", "Tentativa de acesso com credenciais invalidas (5x)"));
    filtroLogs.adicionar(LogSeguranca("2026-08-11 09:20:11", "INFO", "Consulta de saldo realizada"));
    filtroLogs.adicionar(LogSeguranca("2026-08-11 09:31:59", "CRITICAL", "Possivel injecao de SQL detectada no endpoint /login"));
    filtroLogs.adicionar(LogSeguranca("2026-08-11 09:40:22", "INFO", "Transferencia TED autorizada"));

    imprimirCabecalho("Todos os logs de seguranca");
    filtroLogs.processar([](const LogSeguranca& log) {
        std::cout << log.toString() << '\n';
    });

    // Regra de negocio: apenas logs criticos exigem escalonamento imediato.
    auto logsCriticos = filtroLogs.filtrar([](const LogSeguranca& log) {
        return log.getNivel() == "CRITICAL";
    });

    imprimirCabecalho("Logs criticos (escalonamento imediato)");
    for (const LogSeguranca& log : logsCriticos) {
        std::cout << log.toString() << '\n';
    }

    std::cout << "\nTotal de transacoes cadastradas: " << filtroTransacoes.tamanho() << '\n';
    std::cout << "Total de logs cadastrados: " << filtroLogs.tamanho() << '\n';

    return 0;
}
