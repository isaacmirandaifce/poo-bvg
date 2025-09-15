#ifndef RELATORIO_H
#define RELATORIO_H

// interface relatorio
class Relatorio {
    public:
        virtual ~Relatorio() = default;
        virtual void gerarRelatorio() const = 0; //metodo obrigatorio
};

#endif