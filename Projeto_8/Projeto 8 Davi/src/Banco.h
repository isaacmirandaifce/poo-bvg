#ifndef BANCO_H
#define BANCO_H

#include <vector>
#include "Conta.h"

class Banco {
    std::vector<Conta*> contas;
public:
    ~Banco();
    void adicionarConta(Conta* conta);
    void listarContas() const;
    void realizarOperacoes();
};

#endif
