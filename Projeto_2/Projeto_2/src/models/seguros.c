#include <stdio.h>
#include <stdlib.h>
#include "seguros.h"

typedef struct {
    Seguro base;
    int ano;
    char placa[9];
} SeguroAuto;

typedef struct {
    Seguro base;
    int idade;
} SeguroVida;

typedef struct {
    Seguro base;
    TipoImovel imovel;
} SeguroResidencial;

static double premio_auto(const Seguro *self) {
    const SeguroAuto *a = (const SeguroAuto *)self;
    if (a->ano < 2010) {
        return self->valor_base * 1.2;
    }
    return self->valor_base * 1.05;
}

static double premio_vida(const Seguro *self) {
    const SeguroVida *v = (const SeguroVida *)self;
    if (v->idade > 60) {
        return self->valor_base * 2.0;
    }
    return self->valor_base * 1.1;
}

static double premio_residencial(const Seguro *self) {
    const SeguroResidencial *r = (const SeguroResidencial *)self;
    if (r->imovel == CASA) {
        return self->valor_base * 1.15;
    }
    return self->valor_base * 1.05;
}

Seguro *seguro_auto_criar(Cliente *titular, double valor_base, int ano, const char *placa) {
    SeguroAuto *a = malloc(sizeof(SeguroAuto));
    if (a == NULL) {
        return NULL;
    }
    a->base.tipo = "AUTO";
    a->base.titular = titular;
    a->base.valor_base = valor_base;
    a->base.calcular_premio = premio_auto;
    a->ano = ano;
    snprintf(a->placa, sizeof(a->placa), "%s", placa);
    return &a->base;
}

Seguro *seguro_vida_criar(Cliente *titular, double valor_base, int idade) {
    SeguroVida *v = malloc(sizeof(SeguroVida));
    if (v == NULL) {
        return NULL;
    }
    v->base.tipo = "VIDA";
    v->base.titular = titular;
    v->base.valor_base = valor_base;
    v->base.calcular_premio = premio_vida;
    v->idade = idade;
    return &v->base;
}

Seguro *seguro_residencial_criar(Cliente *titular, double valor_base, TipoImovel imovel) {
    SeguroResidencial *r = malloc(sizeof(SeguroResidencial));
    if (r == NULL) {
        return NULL;
    }
    r->base.tipo = "RESIDENCIAL";
    r->base.titular = titular;
    r->base.valor_base = valor_base;
    r->base.calcular_premio = premio_residencial;
    r->imovel = imovel;
    return &r->base;
}

void seguro_destruir(Seguro *s) {
    free(s);
}
