#include "models/Cliente.h"

/*
Função principal
Cria clientes, realiza operações e exibe relatório*/
int main()
{
    std::vector<Cliente> clientes;

    cadastrar_Cliente(clientes, "Joao", 30, 1000);
    cadastrar_Cliente(clientes, "Maria", 25, 500);
    cadastrar_Cliente(clientes, "Fernando", 19, 200);

    clientes[0].saque(200);
    clientes[1].deposito(300);
    clientes[2].saque(300);

    exibirRelatorio(clientes);

    return 0;
}