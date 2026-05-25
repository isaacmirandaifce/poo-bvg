#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <algorithm>
#include "models/dataFilter/dataFilter.h"
#include "models/LogSegurança/logSeguranca.h"
#include "models/Transação/transacao.h"
#include "models/Funções/funcoes.h"

int main() {

    // teste com a Transação
    DataFilter<Transacao> transacao;

    criacaoTransacao(transacao, 1, 120, "PIX");

    criacaoTransacao(transacao, 2, 100, "TED");

    criacaoTransacao(transacao, 3, 250, "TED");

    criacaoTransacao(transacao, 4, 350, "PIX");

    criacaoTransacao(transacao, 5, 300, "TED");

    criacaoTransacao(transacao, 6, 200, "PIX");

    transacao.filtrar([](const Transacao &t) { return t.getTipo() == "PIX" && t.getValor() > 150; });

    transacao.processar([](const Transacao &t){ std::cout << std::endl << "O ID: " << t.getID() << "\nO Valor: " << t.getValor() << "\nO Tipo: " << t.getTipo() << std::endl;});

    // teste com o Log de Segurança
    DataFilter<LogSeguranca> logSeg;

    criacaologSeguranca(logSeg, 13, "INFO", "men1");

    criacaologSeguranca(logSeg, 14, "INTO", "men2");

    criacaologSeguranca(logSeg, 15, "CRITICAL", "men3");

    criacaologSeguranca(logSeg, 16, "INTO", "men4");

    criacaologSeguranca(logSeg, 17, "CRITICAL", "men5");

    criacaologSeguranca(logSeg, 18, "INTO", "men6");

    criacaologSeguranca(logSeg, 19, "CRITICAL", "men7");

    logSeg.filtrar([](const LogSeguranca &lg) {return lg.getNivel() == "CRITICAL";});

    logSeg.processar([](const LogSeguranca &lg) {std::cout << std::endl << "O horario: " << lg.getTimeStamp() << "h \nO nivel: " << lg.getNivel() << " \nA Mensagem: " << lg.getMensagem() << std::endl;});

    return 0;
}