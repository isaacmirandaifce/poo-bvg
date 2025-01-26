#ifndef RELATORIO_H
#define RELATORIO_H

// Definição da interface Relatorio, que contém o método gerador de relatórios
class Relatorio {
public:
    // Método virtual puro, que será implementado por classes que necessitam gerar relatórios
    virtual void gerarRelatorio() const = 0;
    
    virtual ~Relatorio() {}
};

#endif