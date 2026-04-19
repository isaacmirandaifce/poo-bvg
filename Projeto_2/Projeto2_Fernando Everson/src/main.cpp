#include <iostream>
#include <vector>
#include "models/cliente.h"
#include "models/seguros.h"

int main(){
    Cliente c1("Fernando", "123.456.789-0");

    std::vector<Seguro*> listaSeguros;
    
    listaSeguros.push_back(new Seguro_auto(c1.getCliente(), 1000.0, 2005));

    for(Seguro* s : listaSeguros){
        std::cout << "O titular do seguro é: " <<c1.getCliente() << " O valor do premio é: R$ " << s->calcular_premio() <<std::endl;
    }

    return 0;
}