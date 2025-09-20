#ifndef RELATORIO_H
#define RELATORIO_H

// Define a interface para padronizar a geração de relatórios
class Relatorio {
public:

    virtual ~Relatorio() {}

    // Contrato: toda classe que implementar esta interface
    // DEVE fornecer uma implementação para este método.
    virtual void gerarRelatorio() = 0;
};

#endif // RELATORIO_H
