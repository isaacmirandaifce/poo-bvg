#ifndef RELATORIO_H
#define RELATORIO_H

class Relatorio {
public:
    virtual ~Relatorio() = default;
    virtual void gerarRelatorio() const = 0; // Método virtual puro (Contrato de Interface)
};

#endif // RELATORIO_H