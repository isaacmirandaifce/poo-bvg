#ifndef RELATORIO_H
#define RELATORIO_H


// Qualquer classe que implementar esta interface DEVE fornecer uma implementação para gerarRelatorio().
class Relatorio {
public:
    // Destrutor virtual 
    virtual ~Relatorio() = default;

    // Método virtual puro (abstrato) para gerar o relatório.
    virtual void gerarRelatorio() const = 0;
};

#endif 