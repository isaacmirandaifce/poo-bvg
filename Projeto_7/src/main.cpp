#include <iostream>
#include "DataFilter.h"
#include "Transacao.h"
#include "LogSeguranca.h"

using namespace std;

int main() {
    cout << "===== SecureBank Pro - Motor Generico de Filtragem (DataFilter<T>) =====" << endl << endl;

    // ----- DataFilter<Transacao> -----
    DataFilter<Transacao> filtroTransacoes;
    filtroTransacoes.adicionar(Transacao(1, 1500.0, "PIX"));
    filtroTransacoes.adicionar(Transacao(2, 12000.0, "TED"));
    filtroTransacoes.adicionar(Transacao(3, 8700.5, "PIX"));
    filtroTransacoes.adicionar(Transacao(4, 25000.0, "TED"));
    filtroTransacoes.adicionar(Transacao(5, 300.0, "PIX"));

    cout << "--- Todas as transacoes cadastradas (" << filtroTransacoes.tamanho() << ") ---" << endl;
    filtroTransacoes.processar([](const Transacao& t) {
        t.exibir();
    });
    cout << endl;

    cout << "--- Transacoes suspeitas (valor > R$ 10.000) ---" << endl;
    vector<Transacao> suspeitas = filtroTransacoes.filtrar([](const Transacao& t) {
        return t.getValor() > 10000.0;
    });
    for (const Transacao& t : suspeitas) {
        t.exibir();
    }
    cout << endl;

    // ----- DataFilter<LogSeguranca> -----
    DataFilter<LogSeguranca> filtroLogs;
    filtroLogs.adicionar(LogSeguranca("2026-07-22 08:00", "INFO", "Login efetuado com sucesso"));
    filtroLogs.adicionar(LogSeguranca("2026-07-22 08:15", "CRITICAL", "Tentativa de acesso nao autorizado"));
    filtroLogs.adicionar(LogSeguranca("2026-07-22 09:02", "INFO", "Consulta de saldo realizada"));
    filtroLogs.adicionar(LogSeguranca("2026-07-22 09:40", "CRITICAL", "Falha de integridade no arquivo de ledger"));

    cout << "--- Todos os logs de seguranca (" << filtroLogs.tamanho() << ") ---" << endl;
    filtroLogs.processar([](const LogSeguranca& log) {
        log.exibir();
    });
    cout << endl;

    cout << "--- Logs criticos (nivel == CRITICAL) ---" << endl;
    vector<LogSeguranca> criticos = filtroLogs.filtrar([](const LogSeguranca& log) {
        return log.getNivel() == "CRITICAL";
    });
    for (const LogSeguranca& log : criticos) {
        log.exibir();
    }

    return 0;
}
