#include <iostream>
#include "models/cliente.h"

int main(){
    Cliente c1("Fernando", "123.456.789-0");

    std::cout << "O cliente cadastrado é: " << c1.getCliente() << std::endl;

    return 0;
}