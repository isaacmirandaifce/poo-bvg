#ifndef RELATORIO_H
#define RELATORIO_H

// Interface: contrato operacional de auditoria
// Qualquer classe que assinar essa interface DEVE implementar gerarRelatorio()
class Relatorio {
public:
    virtual void gerarRelatorio() const = 0; // Método virtual puro
    virtual ~Relatorio() = default;          // Destrutor virtual (boa prática com polimorfismo)
};

#endif