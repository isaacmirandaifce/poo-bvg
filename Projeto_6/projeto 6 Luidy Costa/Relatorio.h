#ifndef RELATORIO_H
#define RELATORIO_H

// Interface pura: Apenas métodos virtuais puros
class Relatorio {
public:
    virtual ~Relatorio() = default;
    virtual void gerarRelatorio() const = 0;
};

#endif
