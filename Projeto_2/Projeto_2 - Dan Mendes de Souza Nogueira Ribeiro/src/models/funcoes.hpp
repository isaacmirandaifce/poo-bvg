#pragma once
#include <iostream>
#include <string>
#include "cliente.hpp"
#include "seguros.hpp"

//funções de adição as classes

void adicionarInformaçõesClientes(std::string nome, std::string cpf, cliente& clienteAdici)
{
     
    clienteAdici.setNome(nome);
    clienteAdici.setCPF(cpf);
};

void adicionarInformaçõesSegurosAuto(int ano, std::string placa, double base, seguroAuto &seguroSetar)
{
    if (ano < 0 || base < 0)
    {
        std::cout << "Erro: Valor inválido para o campo 'Ano'." << '\n';
        return;
    }
    else
    {
        seguroSetar.setAno(ano);
        seguroSetar.setPlacaCarro(placa);
        seguroSetar.setBase(base);
        return;
    }
};

void adicionarInformaçõesSegurosVida(int idade, std::string causa, double base, seguroVida &seguroSetar)
{
    if (idade < 0 || base < 0)
    {
        std::cout << "Erro: Valor inválido para o campo 'idade'." << '\n';
        return;
    }
    else
    {
        seguroSetar.setIdade(idade);
        seguroSetar.setCausa(causa);
        seguroSetar.setBase(base);
        return;
    }
};

void adicionarInformaçõesSegurosResidencial(std::string tipoImovel, std::string endereco, double base, seguroResidencial &seguroSetar)
{
    seguroSetar.setTipoImovel(tipoImovel);
    seguroSetar.setEndereco(endereco);
    seguroSetar.setBase(base);
};

/*
Implementação da função atavés do polimorfismo que aponta para o cálculo o seguro, tirando a necessidade da main saber qual é o tipo de seguro.
Isso é feito a partir de um ponteiro que aponta para o calculo do seguro adequado.
*/
void processarSeguroGenerico(seguro *seg)
{

    if (!seg->testarBaseValida())
    {
        std::cout << "Erro: Base invalida!" << std::endl;
        return;
    }

    seg->calcular_premio();
}

// Funções de imprimir dados ao sistema
void mostrarcliente(cliente &clienteAdici)
{

    if (clienteAdici.getNome() == "" && clienteAdici.getCPF() == "")
    {
        std::cout << std::endl << "O usuário ainda não foi definido." << std::endl;

    } else
    {
        std::cout << std::endl << "O usuário é " << clienteAdici.getNome() << std::endl;

        std::cout << std::endl << "O CPF do usuário " << clienteAdici.getNome() << " é " << clienteAdici.getCPF() << std::endl;
    }
    
}

void mostrarSeguroAuto(seguroAuto &Mostra)
{

    if (Mostra.getAno() < 0 && Mostra.getPlacaCarro() == "")
    {
        std::cout << std::endl << "O veículo ainda não foi definido ao seguro." << std::endl;
    }
    else
    {
        std::cout << std::endl << "O ano do carro é " << Mostra.getAno() << std::endl;
        std::cout << std::endl<< "A placa do carro é " << Mostra.getPlacaCarro() << std::endl;
    }
}

void mostrarSeguroVida(seguroVida &Mostra)
{

    if (Mostra.getIdade() < 0 && Mostra.getCausa() == "")
    {
        std::cout << std::endl << "O seguro de vida ainda não foi definido" << std::endl;
    }
    else
    {
        std::cout << std::endl << "A idade do segurado é " << Mostra.getIdade() << std::endl;
        std::cout << std::endl << "A causa do segurado é " << Mostra.getCausa() << std::endl;
    }
}

void mostrarSeguroResi(seguroResidencial &Mostra)
{

    if (Mostra.getEndereco() == "" && Mostra.getTipoImovel() == "")
    {
        std::cout << std::endl << "A residência ainda não foi definida ao seguro." << std::endl;
    }
    else
    {
        std::cout << std::endl << "O endereço do imovel segurado é " << Mostra.getEndereco() << std::endl;
        std::cout << std::endl << "O tipo de imovel segurado é " << Mostra.getTipoImovel() << std::endl;
    }
}