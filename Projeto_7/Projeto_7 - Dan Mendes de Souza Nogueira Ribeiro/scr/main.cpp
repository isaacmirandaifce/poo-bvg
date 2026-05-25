/**
 * @file main.cpp
 * @brief Arquivo principal que demonstra a aplicação prática da classe template DataFilter
 * utilizando funções lambda e injeção de dependência para regras de negócio.
 */

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

    /** Filtra a coleção: Mantém apenas as transações que são do tipo "PIX" e possuem valor estritamente maior que 150. */
    transacao.filtrar([](const Transacao &t) { return t.getTipo() == "PIX" && t.getValor() > 150; });

    /** Processa e imprime as transações que passaram no filtro. */
    transacao.processar([](const Transacao &t){ std::cout << std::endl << "O ID: " << t.getID() << "\nO Valor: " << t.getValor() << "\nO Tipo: " << t.getTipo() << std::endl;});

    /** teste com o Log de Segurança */
    DataFilter<LogSeguranca> logSeg;

    criacaologSeguranca(logSeg, 13, "INFO", "men1");

    criacaologSeguranca(logSeg, 14, "INFO", "men2");

    criacaologSeguranca(logSeg, 15, "CRITICAL", "men3");

    criacaologSeguranca(logSeg, 16, "INFO", "men4");

    criacaologSeguranca(logSeg, 17, "CRITICAL", "men5");

    criacaologSeguranca(logSeg, 18, "INFO", "men6");

    criacaologSeguranca(logSeg, 19, "CRITICAL", "men7");

    /** Filtra a coleção: Mantém apenas os logs com nível "CRITICAL". */
    logSeg.filtrar([](const LogSeguranca &lg) {return lg.getNivel() == "CRITICAL";});

    /** Processa e imprime os logs que passaram no filtro. */
    logSeg.processar([](const LogSeguranca &lg) {std::cout << std::endl << "O Horário: " << lg.getTimeStamp() << "h \nO Nível: " << lg.getNivel() << " \nA Mensagem: " << lg.getMensagem() << std::endl;});

    return 0;
}