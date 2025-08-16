#ifndef RELATORIO_H
#define RELATORIO_H

class Relatorio {
public:
    virtual void gerarRelatorio() = 0;
    virtual ~Relatorio() {}
};

#endif