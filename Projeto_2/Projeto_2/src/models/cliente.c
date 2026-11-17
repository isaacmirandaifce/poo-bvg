#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

#define MAX_SEGUROS 10

struct Cliente {
    char nome[50];
    char cpf[15];
    struct Seguro *seguros[MAX_SEGUROS];
    int qtd_seguros;
};

Cliente *cliente_criar(const char *nome, const char *cpf) {
    Cliente *c = malloc(sizeof(Cliente));
    if (c == NULL) {
        return NULL;
    }

    snprintf(c->nome, sizeof(c->nome), "%s", nome);
    snprintf(c->cpf, sizeof(c->cpf), "%s", cpf);
    c->qtd_seguros = 0;
    return c;
}

void cliente_destruir(Cliente *c) {
    free(c);
}

int cliente_adicionar_seguro(Cliente *c, struct Seguro *s) {
    if (c->qtd_seguros >= MAX_SEGUROS) {
        return 0;
    }
    c->seguros[c->qtd_seguros] = s;
    c->qtd_seguros++;
    return 1;
}

void cliente_mostrar(const Cliente *c) {
    printf("Cliente: %s | CPF: ***.***.***-%s | Seguros: %d\n",
           c->nome, c->cpf + strlen(c->cpf) - 2, c->qtd_seguros);
}
