#include <iostream>
#include "DataFilter.h"
#include "Transacao.h"
#include "LogSeguranca.h"

int main() {

// TESTE 1: Pipeline de Transações
    std::cout << "=== ANALISANDO TRANSACOES ===" << std::endl;
    DataFilter<Transacao> filtroTransacoes;

    filtroTransacoes.adicionar(Transacao(101, 1500.0, "PIX"));
    filtroTransacoes.adicionar(Transacao(102, 12500.0, "TED"));
    filtroTransacoes.adicionar(Transacao(103, 300.0, "PIX"));
    filtroTransacoes.adicionar(Transacao(104, 5200.0, "DOC"));

    std::cout << "\n[Processando todas as transacoes via lambda]" << std::endl;
    filtroTransacoes.processar([](const Transacao& t) {
        std::cout << "- ID: " << t.getId() << " | Tipo: " << t.getTipo() 
                  << " | Valor: R$" << t.getValor() << std::endl;
    });

    std::cout << "\n[Filtrando transacoes suspeitas (> R$5000)]" << std::endl;
    auto transacoesSuspeitas = filtroTransacoes.filtrar([](const Transacao& t) {
        return t.getValor() > 5000.0;
    });

    for (const auto& t : transacoesSuspeitas) {
        std::cout << "-> ALERTA: Transacao de alto valor bloqueada! ID: " 
                  << t.getId() << " (R$" << t.getValor() << ")" << std::endl;
    }

    std::cout << "\n\n";

// Pipeline de Logs de Segurança
    std::cout << "=== ANALISANDO LOGS DE SEGURANCA ===" << std::endl;
    DataFilter<LogSeguranca> filtroLogs;

    filtroLogs.adicionar(LogSeguranca("22/05/2026 08:00:00", "INFO", "Servico iniciado."));
    filtroLogs.adicionar(LogSeguranca("22/05/2026 09:15:30", "CRITICAL", "Tentativa de injecao SQL detectada na API."));
    filtroLogs.adicionar(LogSeguranca("22/05/2026 10:00:00", "INFO", "Backup concluido."));
    filtroLogs.adicionar(LogSeguranca("22/05/2026 11:45:12", "CRITICAL", "Falha de autenticacao de administrador."));

    std::cout << "\n[Processando todos os logs via lambda]" << std::endl;
    filtroLogs.processar([](const LogSeguranca& log) {
        std::cout << "[" << log.getTimestamp() << "] [" << log.getNivel() << "] " 
                  << log.getMensagem() << std::endl;
    });

    std::cout << "\n[Filtrando apenas logs Criticos]" << std::endl;
    auto logsCriticos = filtroLogs.filtrar([](const LogSeguranca& log) {
        return log.getNivel() == "CRITICAL";
    });

    for (const auto& log : logsCriticos) {
        std::cout << "-> URGENTE: Disparar e-mail para SysAdmin! Detalhe: " 
                  << log.getMensagem() << std::endl;
    }

    return 0;
}