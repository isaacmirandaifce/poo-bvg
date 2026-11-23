#include "Contato.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
 std::vector<Contato> contatos;
 contatos.reserve(3);

contatos.push_back(Contato("Sertão Digital Ltda", "(88) 3421-1020"));
contatos.push_back(Contato("Nordeste Logística S.A.", "(85) 3200-4455"));
contatos.push_back(Contato("Boa Viagem Soluções B2B", "(88) 3421-9080"));

std::cout<<"\n\n*-*-*-*-Lista de contatos B2B*-*-*-*-"<<std::endl;
   for (int i = 0; i < static_cast<int>(contatos.size()); i++){
   std::cout << "\nCliente " << (i + 1) << ":" << std::endl;
   contatos[i].imprimirNome();
    contatos[i].imprimirTelefone();
    std::cout<<"-----------------------"<<std::endl;
}

 std::cout<<"\n*-*-*-*-Fim da lista*-*-*-*-\n"<<std::endl;

    return 0;
}

