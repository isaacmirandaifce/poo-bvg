#ifndef RELATORIO_H
#define RELATORIO_H

class Relatorio {
public:
    virtual ~Relatorio() {}
    virtual void gerarRelatorio() = 0;
};

#endif // RELATORIO_H
