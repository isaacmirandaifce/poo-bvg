#include "DataFilter.h"
#include "Transacao.h"
#include "LogSeguranca.h"

int main() {

    // --- TRANSAÇÕES ---

    FiltroTransacao filtroTransacoes;
    filtroTransacoes.tamanho = 0;

    Transacao t1 = {1, 1500.0, "PIX"};
    Transacao t2 = {2, 12000.0, "TED"};
    Transacao t3 = {3, 8500.0, "PIX"};

    adicionarTransacao(filtroTransacoes, t1);
    adicionarTransacao(filtroTransacoes, t2);
    adicionarTransacao(filtroTransacoes, t3);

    cout << "=== Todas as Transacoes ===" << endl;
    processarTransacoes(filtroTransacoes);

    cout << "\n=== Transacoes Suspeitas ===" << endl;
    filtrarSuspeitas(filtroTransacoes);

    // --- LOGS ---

    FiltroLog filtroLogs;
    filtroLogs.tamanho = 0;

    LogSeguranca l1 = {"21/05/2026 10:30", "INFO", "Login realizado"};
    LogSeguranca l2 = {"21/05/2026 10:45", "CRITICAL", "Tentativa de invasao"};
    LogSeguranca l3 = {"21/05/2026 11:00", "INFO", "Logout realizado"};

    adicionarLog(filtroLogs, l1);
    adicionarLog(filtroLogs, l2);
    adicionarLog(filtroLogs, l3);

    cout << "\n=== Todos os Logs ===" << endl;
    processarLogs(filtroLogs);

    cout << "\n=== Logs Criticos ===" << endl;
    filtrarCriticos(filtroLogs);

    return 0;
}