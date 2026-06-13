#ifndef RELATORIO
#define RELATORIO
#include <iostream>
#include <string>

class Relatorio{
    public:
    virtual void gerarRelatorio() const = 0;

    virtual ~Relatorio() {};
};

#endif