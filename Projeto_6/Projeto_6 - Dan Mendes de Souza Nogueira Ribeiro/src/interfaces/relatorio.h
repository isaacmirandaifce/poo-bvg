#ifndef RELATORIO
#define RELATORIO
#include <iostream>
#include <string>

/**
 * @interface Relatorio
 * @brief Interface puramente abstrata que atua como contrato para emissão de relatórios.
 */
class Relatorio
{
public:
    /**
     * @brief Método virtual puro para exibir o relatório.
     */
    virtual void gerarRelatorio() const = 0;

    /**
     * @brief Destrutor virtual para garantir a desalocação correta da memória nas classes filhas.
     */
    virtual ~Relatorio() {};
};

#endif