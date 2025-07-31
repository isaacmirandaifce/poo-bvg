#ifndef RELATORIO_H
#define RELATORIO_H

class Relatorio {
public:
    virtual void gerarRelatorio() const = 0;
    virtual ~Relatorio() {}
};

#endif