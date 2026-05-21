#include "DataFilter.h"
#include "Transacao.h"
#include "LogSeguranca.h"

void adicionarTransacao(FiltroTransacao& filtro, Transacao t) {
    if (filtro.tamanho < MAX) {
        filtro.dados[filtro.tamanho] = t;
        filtro.tamanho++;
    }
}

void processarTransacoes(FiltroTransacao& filtro) {
    for (int i = 0; i < filtro.tamanho; i++) {
        exibirTransacao(filtro.dados[i]);
    }
}

void filtrarSuspeitas(FiltroTransacao& filtro) {
    for (int i = 0; i < filtro.tamanho; i++) {
        if (filtro.dados[i].valor > 5000) {
            exibirTransacao(filtro.dados[i]);
        }
    }
}

void adicionarLog(FiltroLog& filtro, LogSeguranca log) {
    if (filtro.tamanho < MAX) {
        filtro.dados[filtro.tamanho] = log;
        filtro.tamanho++;
    }
}

void processarLogs(FiltroLog& filtro) {
    for (int i = 0; i < filtro.tamanho; i++) {
        exibirLog(filtro.dados[i]);
    }
}

void filtrarCriticos(FiltroLog& filtro) {
    for (int i = 0; i < filtro.tamanho; i++) {
        if (filtro.dados[i].nivel == "CRITICAL") {
            exibirLog(filtro.dados[i]);
        }
    }
}