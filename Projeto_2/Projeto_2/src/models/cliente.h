#ifndef CLIENTE_H
#define CLIENTE_H

struct Seguro;
typedef struct Cliente Cliente;

Cliente *cliente_criar(const char *nome, const char *cpf);

void cliente_destruir(Cliente *c);

int cliente_adicionar_seguro(Cliente *c, struct Seguro *s);

void cliente_mostrar(const Cliente *c);

#endif
