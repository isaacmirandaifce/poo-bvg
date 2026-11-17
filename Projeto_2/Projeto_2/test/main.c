#include <stdio.h>
#include "C:/Users/Discente/Downloads/Projeto_2/Projeto_2/src/models/cliente.h"
#include "C:/Users/Discente/Downloads/Projeto_2/Projeto_2/src/models/seguros.h"

#define QTD 3

int main(void) {
    Cliente *cliente = cliente_criar("Maria Silva", "123.456.789-09");
    if (cliente == NULL) {
        return 1;
    }

    Seguro *seguros[QTD];
    seguros[0] = seguro_auto_criar(cliente, 1000.0, 2005, "ABC1D23");
    seguros[1] = seguro_vida_criar(cliente, 2000.0, 65);
    seguros[2] = seguro_residencial_criar(cliente, 1500.0, CASA);

    for (int i = 0; i < QTD; i++) {
        if (seguros[i] == NULL) {
            printf("Erro ao criar seguro.\n");
            return 1;
        }
        cliente_adicionar_seguro(cliente, seguros[i]);
    }

    cliente_mostrar(cliente);
    printf("\n");

    double total = 0;
    for (int i = 0; i < QTD; i++) {
        double premio = seguros[i]->calcular_premio(seguros[i]);
        printf("Seguro %-11s -> Prêmio: R$ %.2f\n", seguros[i]->tipo, premio);
        total += premio;
    }
    printf("\nTotal: R$ %.2f\n", total);

    for (int i = 0; i < QTD; i++) {
        seguro_destruir(seguros[i]);
    }
    cliente_destruir(cliente);
    return 0;
}
