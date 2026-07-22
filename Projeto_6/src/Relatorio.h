#ifndef RELATORIO_H
#define RELATORIO_H

// Interface (classe totalmente abstrata): padroniza a geracao de relatorios
// entre classes que nao necessariamente compartilham a mesma hierarquia.
class Relatorio {
public:
    virtual ~Relatorio() = default;

    virtual void gerarRelatorio() const = 0; // Metodo virtual puro
};

#endif // RELATORIO_H
