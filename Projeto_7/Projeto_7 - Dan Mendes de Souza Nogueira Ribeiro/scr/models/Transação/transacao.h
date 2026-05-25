#ifndef transcacao
#define transcacao
#include <iostream>
#include <string>

class Transacao {
    private:
        int id;
        double valor;
        std::string tipo;

    public:

    void setID(int id);
    void setValor(double valor);
    void setTipo(std::string tipo);

    int getID() const;
    double getValor() const;
    std::string getTipo() const;
};

#endif