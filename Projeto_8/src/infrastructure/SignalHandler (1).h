#ifndef SIGNALHANDLER_H
#define SIGNALHANDLER_H

#include <csignal>
#include <iostream>

class LedgerPersistence;

/**
 * @class SignalHandler
 * @brief Manipulador estático de sinais do sistema operacional.
 *
 * Toda a classe é estática por exigência da API de <csignal>: std::signal()
 * só aceita um ponteiro para função livre (void(*)(int)) como handler, não
 * um ponteiro para método de instância. Por isso `tratador` é `static` e
 * `persistenciaAtiva` é um ponteiro estático — é o único jeito do handler
 * "sem contexto" alcançar o LedgerPersistence ativo do processo.
 */
class SignalHandler {
public:
    /// Registra os hooks de SIGINT e SIGTERM. Deve ser chamado uma única
    /// vez, no início do main(), antes de qualquer escrita no ledger.
    static void inicializar();

    /// Informa ao handler qual instância de LedgerPersistence deve ser
    /// fechada com segurança caso um sinal seja interceptado.
    static void registrarPersistencia(LedgerPersistence* persistencia);

private:
    /// Handler propriamente dito. Assinatura exigida por std::signal.
    static void tratador(int sinal);

    static LedgerPersistence* persistenciaAtiva;
};

#endif // SIGNALHANDLER_H
