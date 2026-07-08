#ifndef RELATORIO_H
#define RELATORIO_H

class Relatorio {
public:
    virtual ~Relatorio() = default;
    // Método virtual puro que obriga a implementação nas classes concretas
    virtual void gerarRelatorio() const = 0;
};

#endif
