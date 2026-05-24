#ifndef TRANSACAO_H
#define TRANSACAO_H

#include <string>

class Transacao {
    private:
        int id;
        double valor;
        std::string tipo;
    
    public:
        Transacao(int id, double valor, std::string tipo);

    // O uso de 'const' no final garante que estes métodos não alteram o estado do objeto.
    // Isso é vital, pois o DataFilter passa referências constantes.
        int getId() const;
        double getValor() const;
        std::string getTipo() const;
};

#endif