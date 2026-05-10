#include <iostream>
#include <vector>
#include "Contato.h"

int main() {

    std::vector<CRM::Contato> listaContatos;

    listaContatos.push_back(CRM::Contato("Loja 1","00-0000000"));
    listaContatos.push_back(CRM::Contato("Loja 2","11-1111111"));
    listaContatos.push_back(CRM::Contato("Loja 3","22-2222222"));
    
    std::cout << "========== Lista de contatos ========" << std::endl << std::endl;


    for (const auto& contato : listaContatos){
        contato.imprimirNome();
        contato.imprimirTelefone();
        std::cout << "======================" <<std::endl;

    }
    std::cout << std::endl << "Finalizando programa e limpando memoria..." << std::endl;

        
    

    return 0;
}