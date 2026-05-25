#include <iostream>
#include <string>
#include <functional>
#include "../LogSegurança/logSeguranca.h"
#include "../Transação/transacao.h"
#include "../dataFilter/dataFilter.h"
#include "../Funções/funcoes.h"

void criacaoTransacao(DataFilter<Transacao> &adi, int id, double valor, std::string tipo)
{
    Transacao trans;
    trans.setID(id);
    trans.setValor(valor);
    trans.setTipo(tipo);
    adi.adicionar(trans);
};

void criacaologSeguranca(DataFilter<LogSeguranca> &adi, int timestamp, std::string nivel, std::string mensagem)
{
    LogSeguranca log;
    log.setTimeStamp(timestamp);
    log.setNivel(nivel);
    log.setMensagem(mensagem);
    adi.adicionar(log);
};