#pragma once
#include <iostream>
#include <string>
#include "cliente.hpp"
#include "seguros.hpp"

void adicionarInformaçõesClientes(std::string nome, std::string cpf, cliente& clienteAdici)
{
     
    clienteAdici.setNome(nome);
    clienteAdici.setCPF(cpf);
};

void adicionarInformaçõesSegurosGeral(double base, seguro& seguroSetar)
{
    if (base < 0)
    {
        std::cout << "Erro! Valor Inadequado" << '\n';
        return;
    } else 
    {
        seguroSetar.setBase(base);
        return;
    }
};

void adicionarInformaçõesSegurosAuto(int ano, std::string placa, seguroAuto& seguroSetar)
{
    if (ano < 0)
    {
        std::cout << "Erro! Valor Inadequado em ano" << '\n';
        return;
    }
    else
    {
        seguroSetar.setAno(ano);
        seguroSetar.setPlacaCarro(placa);
        return;
    }
};

void adicionarInformaçõesSegurosVida(int idade, std::string causa, seguroVida& seguroSetar)
{
    if (idade < 0)
    {
        std::cout << "Erro! Valor Inadequado em idade" << '\n';
        return;
    }
    else
    {
        seguroSetar.setIdade(idade);
        seguroSetar.setCausa(causa);
        return;
    }
};

void adicionarInformaçõesSegurosResidencial(std::string tipoImovel, std::string endereco, seguroResidencial& seguroSetar)
{
    seguroSetar.setTipoImovel(tipoImovel);
    seguroSetar.setEndereco(endereco);
};

void mostrarcliente(cliente &clienteAdici)
{

    if (clienteAdici.getNome() == "" && clienteAdici.getCPF() == "")
    {
        std::cout << std::endl << "O usuário é ainda não foi definido" << std::endl;

    } else
    {
        std::cout << std::endl << "O usuário é " << clienteAdici.getNome() << std::endl;

        std::cout << std::endl << "O usuário é " << clienteAdici.getCPF() << std::endl;
    }
    
}


void mostrarSeguroBase(seguro& Mostra)
{

    if (Mostra.getBase() < 0)
    {
        std::cout << std::endl << "O seguro ainda não foi definido" << std::endl;
    }
    else
    {
        std::cout << std::endl << "O valor do seguro é " << Mostra.getBase() << std::endl;
    }
}

void mostrarSeguroAuto(seguroAuto &Mostra)
{

    if (Mostra.getAno() < 0 && Mostra.getPlacaCarro() == "")
    {
        std::cout << std::endl << "O seguro do veículo ainda não foi definido" << std::endl;
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
        std::cout << std::endl << "A idade do assegurado é " << Mostra.getIdade() << std::endl;
        std::cout << std::endl << "A causa do assegurado é " << Mostra.getCausa() << std::endl;
    }
}

void mostrarSeguroResi(seguroResidencial &Mostra)
{

    if (Mostra.getEndereco() == "" && Mostra.getTipoImovel() == "")
    {
        std::cout << std::endl << "O seguro de residencia ainda não foi definido" << std::endl;
    }
    else
    {
        std::cout << std::endl << "O endereço é " << Mostra.getEndereco() << std::endl;
        std::cout << std::endl << "O tipo de imovel é " << Mostra.getTipoImovel() << std::endl;
    }
}