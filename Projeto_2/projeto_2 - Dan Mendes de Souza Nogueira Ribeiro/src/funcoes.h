#ifndef FUNCOES
#define FUNCOES
#include<iostream>
#include <string>
#include "Models/cliente.h"
#include "Models/seguros.h"

// funções de adição as classes

void adicionarInformaçõesClientes(std::string nome, std::string cpf, cliente &clienteAdici);

void adicionarInformaçõesSegurosAuto(int ano, std::string placa, double base, seguroAuto &seguroSetar);

void adicionarInformaçõesSegurosVida(int idade, std::string causa, double base, seguroVida &seguroSetar);

void adicionarInformaçõesSegurosResidencial(std::string tipoImovel, std::string endereco, double base, seguroResidencial &seguroSetar);

/*
Implementação da função atavés do polimorfismo que aponta para o cálculo o seguro, tirando a necessidade da main saber qual é o tipo de seguro.
Isso é feito a partir de um ponteiro que aponta para o calculo do seguro adequado.
*/
void processarSeguroGenerico(seguro *seg);

// Funções de imprimir dados ao sistema
void mostrarcliente(cliente &clienteAdici);

void mostrarSeguroAuto(seguroAuto &Mostra);

void mostrarSeguroVida(seguroVida &Mostra);

void mostrarSeguroResi(seguroResidencial &Mostra);

#endif