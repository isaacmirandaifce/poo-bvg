#ifndef SIGNALHANDLER_H
#define SIGNALHANDLER_H

#include <csignal>
#include <iostream>
#include <string>
#include <vector>
#include "LedgerPersistence.h"

// Manipulador estatico de sinais do SO (SIGINT/SIGTERM) do Ledger Engine.
class SignalHandler {
public:
    static void inicializar();

    // Permite que o main registre a instancia de persistencia e o buffer
    // pendente que devem ser protegidos em caso de interrupcao abrupta.
    static void registrarContexto(LedgerPersistence* persistencia, std::vector<std::string>* bufferPendente);

private:
    static LedgerPersistence* persistenciaAtiva;
    static std::vector<std::string>* bufferAtivo;

    static void tratador(int sinal);
};

#endif // SIGNALHANDLER_H
