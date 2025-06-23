#ifndef RELATORIO_H
#define RELATORIO_H

#include <string>

class Relatorio {
public:
    virtual ~Relatorio() {}
    virtual std::string gerarRelatorio() const = 0; 
};

#endif 