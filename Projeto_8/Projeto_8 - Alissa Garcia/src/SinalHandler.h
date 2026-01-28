#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <csignal>

class Persistencia; // forward

class SinalHandler {
public:
    // vincula um ponteiro de Persistencia para que o tratador possa chamar salvar em caso de sinal
    static void registrarPersistencia(Persistencia* p);

    // registra os tratadores para SIGINT, SIGTERM, SIGSEGV
    static void inicializar();

private:
    static void tratador(int sinal);
    static Persistencia* persistenciaPtr;
};

#endif // SINALHANDLER_H
