#include <iostream>
#include <vector>
#include "DataFilter.h"
#include "Transacao.h"
#include "LogSeguranca.h"

int main() {

    // 1. Testando DataFilter com a classe Transacao
    std::cout << "--- PROCESSANDO TRANSACOES ---\n";
    DataFilter<Transacao> filtroTransacoes;

    filtroTransacoes.adicionar(Transacao(1, 1500.00, "PIX"));
    filtroTransacoes.adicionar(Transacao(2, 12500.50, "TED"));
    filtroTransacoes.adicionar(Transacao(3, 50.00, "PIX"));
    filtroTransacoes.adicionar(Transacao(4, 30000.00, "TED"));

    // Lambda para filtrar transações suspeitas (> R$ 10.000)
    auto condicaoSuspeita = [](const Transacao& t) {
        return t.getValor() > 10000.00;
    };

    std::vector<Transacao> transacoesSuspeitas = filtroTransacoes.filtrar(condicaoSuspeita);

    // Novo pipeline apenas com os dados filtrados para usar o método 'processar'
    DataFilter<Transacao> pipelineSuspeito;
    for(const auto& t : transacoesSuspeitas) {
        pipelineSuspeito.adicionar(t);
    }

    // Lambda para imprimir
    pipelineSuspeito.processar([](const Transacao& t) {
        std::cout << "[ALERTA] Transacao Suspeita ID: " << t.getId() 
                  << " | Valor: R$" << t.getValor() 
                  << " | Tipo: " << t.getTipo() << "\n";
    });

    std::cout << "\n";

    // 2. Testando DataFilter com a classe LogSeguranca
    std::cout << "--- PROCESSANDO LOGS DE SEGURANCA ---\n";
    DataFilter<LogSeguranca> filtroLogs;

    filtroLogs.adicionar(LogSeguranca("2026-06-22 08:00:00", "INFO", "Login de usuario bem-sucedido."));
    filtroLogs.adicionar(LogSeguranca("2026-06-22 08:05:32", "CRITICAL", "Falha de autenticacao multipla no DB."));
    filtroLogs.adicionar(LogSeguranca("2026-06-22 08:15:10", "INFO", "Acesso ao relatorio gerencial."));
    filtroLogs.adicionar(LogSeguranca("2026-06-22 08:20:01", "CRITICAL", "Tentativa de injeção SQL detectada."));

    // Lambda para filtrar logs críticos
    std::vector<LogSeguranca> logsCriticos = filtroLogs.filtrar([](const LogSeguranca& log) {
        return log.getNivel() == "CRITICAL";
    });

    // Lambda para processar/imprimir no próprio vetor usando um DataFilter temporário
    DataFilter<LogSeguranca> pipelineLogs;
    for(const auto& log : logsCriticos) pipelineLogs.adicionar(log);

    pipelineLogs.processar([](const LogSeguranca& log) {
        std::cout << "[URGENTE] " << log.getTimestamp() 
                  << " - " << log.getMensagem() << "\n";
    });

    return 0;
}