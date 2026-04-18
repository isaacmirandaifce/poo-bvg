#pragma once
#include <iostream>
#include <string>
#include "cliente.hpp"
#include "seguros.hpp"

void adicionarInformaçõesClientes(std::string nome, std::string cpf, cliente clienteAdici)
{
     
    clienteAdici.setNome(nome);
    clienteAdici.setCPF(cpf);
};

void adicionarInformaçõesSegurosGeral(double base, seguro seguroSetar)
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

void adicionarInformaçõesSegurosAuto(int ano, std::string placa, seguroAuto seguroSetar)
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

void adicionarInformaçõesSegurosVida(int idade, std::string causa, seguroVida seguroSetar)
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

void adicionarInformaçõesSegurosResidencial(std::string tipoImovel, std::string endereco, seguroResidencial seguroSetar)
{
    seguroSetar.setTipoImovel(tipoImovel);
    seguroSetar.setEndereco(endereco);
};