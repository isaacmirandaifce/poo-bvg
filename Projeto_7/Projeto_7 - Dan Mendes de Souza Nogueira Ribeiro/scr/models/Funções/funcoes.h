#ifndef funcoes
#define funcoes
#include <iostream>
#include <string>
#include <functional>
#include "../LogSegurança/logSeguranca.h"
#include "../Transação/transacao.h"
#include "../dataFilter/dataFilter.h"

void criacaoTransacao(DataFilter<Transacao> &adi, int id, double valor, std::string tipo);

void criacaologSeguranca(DataFilter<LogSeguranca> &adi, int timestamp, std::string nivel, std::string mensagem);

#endif