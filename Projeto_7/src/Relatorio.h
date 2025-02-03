#ifndef RELATORIO_H
#define RELATORIO_H

#include <iostream>

class Relatorio {
public:
    virtual ~Relatorio() = default;
    virtual void gerarRelatorio() const {

        std::cout << "Gerando relatório...\n";
    }
};

#endif
