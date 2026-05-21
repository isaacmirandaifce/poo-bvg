#ifndef DATAFILTER_H
#define DATAFILTER_H

#include <iostream>
#include <string>
#include "Transacao.h"
#include "LogSeguranca.h"
using namespace std;

#define MAX 10

struct FiltroTransacao {
    Transacao dados[MAX];
    int tamanho;
};

struct FiltroLog {
    LogSeguranca dados[MAX];
    int tamanho;
};

void adicionarTransacao(FiltroTransacao& filtro, Transacao t);
void processarTransacoes(FiltroTransacao& filtro);
void filtrarSuspeitas(FiltroTransacao& filtro);

void adicionarLog(FiltroLog& filtro, LogSeguranca log);
void processarLogs(FiltroLog& filtro);
void filtrarCriticos(FiltroLog& filtro);

#endif