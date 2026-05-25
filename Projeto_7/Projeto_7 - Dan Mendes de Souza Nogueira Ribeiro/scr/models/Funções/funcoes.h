#ifndef funcoes
#define funcoes
#include <iostream>
#include <string>
#include <functional>
#include "../LogSegurança/logSeguranca.h"
#include "../Transação/transacao.h"
#include "../dataFilter/dataFilter.h"

/**
 * @brief Instancia um objeto Transacao e o adiciona diretamente a um filtro.
 * * @param adi Referência para o objeto DataFilter que armazena transações.
 * @param id Identificador da transação.
 * @param valor Valor da transação.
 * @param tipo Tipo da transação.
 */
void criacaoTransacao(DataFilter<Transacao> &adi, int id, double valor, std::string tipo);

/**
 * @brief Instancia um objeto LogSeguranca e o adiciona diretamente a um filtro.
 * * @param adi Referência para o objeto DataFilter que armazena logs.
 * @param timestamp Marca de tempo do evento.
 * @param nivel Nível de criticidade (ex: "CRITICAL").
 * @param mensagem Mensagem do evento.
 */
void criacaologSeguranca(DataFilter<LogSeguranca> &adi, int timestamp, std::string nivel, std::string mensagem);

#endif