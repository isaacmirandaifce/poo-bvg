#include <iostream>

#include "DataFilter.h"
#include "Transacao.h"
#include "LogSeguranca.h"

int main() {

    DataFilter<Transacao> filtroTransacoes;

    filtroTransacoes.adicionar(
        Transacao(1, 3000, "PIX"));

    filtroTransacoes.adicionar(
        Transacao(2, 8000, "TED"));

    filtroTransacoes.adicionar(
        Transacao(3, 12000, "PIX"));

    auto suspeitas =
        filtroTransacoes.filtrar(
            [](const Transacao& t) {
                return t.getValor() > 5000;
            }
        );

    std::cout << "TRANSACOES SUSPEITAS\n";

    for (const auto& t : suspeitas) {
        std::cout
            << "ID: " << t.getId()
            << " VALOR: " << t.getValor()
            << " TIPO: " << t.getTipo()
            << std::endl;
    }

    std::cout << "\n";

    DataFilter<LogSeguranca> filtroLogs;

    filtroLogs.adicionar(
        LogSeguranca(
            "2025-05-23",
            "INFO",
            "Login realizado"));

    filtroLogs.adicionar(
        LogSeguranca(
            "2025-05-23",
            "CRITICAL",
            "Tentativa de invasao"));

    auto logsCriticos =
        filtroLogs.filtrar(
            [](const LogSeguranca& log) {
                return log.getNivel() == "CRITICAL";
            }
        );

    std::cout << "LOGS CRITICOS\n";

    for (const auto& log : logsCriticos) {
        std::cout
            << log.getTimestamp()
            << " - "
            << log.getNivel()
            << " - "
            << log.getMensagem()
            << std::endl;
    }

    return 0;
}