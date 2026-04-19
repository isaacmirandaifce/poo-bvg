#include <iostream>
#include <string>
#include "models/funcoes.hpp"
#include "models/cliente.hpp"
#include "models/seguros.hpp"

int main() {

    cliente usuario;
    seguro seguros;

    adicionarInformaçõesClientes("teste", "teste", usuario);

    adicionarInformaçõesSegurosGeral(-1, seguros);

    std::cout << usuario.getNome();

    return 0;
}