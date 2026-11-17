#ifndef SEGUROS_H
#define SEGUROS_H

#include "cliente.h"

typedef struct Seguro Seguro;

struct Seguro {
    const char *tipo;
    Cliente *titular;
    double valor_base;
    double (*calcular_premio)(const Seguro *self);
};

typedef enum { CASA, APARTAMENTO } TipoImovel;

Seguro *seguro_auto_criar(Cliente *titular, double valor_base, int ano, const char *placa);
Seguro *seguro_vida_criar(Cliente *titular, double valor_base, int idade);
Seguro *seguro_residencial_criar(Cliente *titular, double valor_base, TipoImovel imovel);

void seguro_destruir(Seguro *s);

#endif
