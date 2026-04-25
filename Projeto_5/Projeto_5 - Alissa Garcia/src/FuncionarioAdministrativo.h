//Código de Alissa Garcia ADS S3

#ifndef FUNCIONARIO_ADM_H
#define FUNCIONARIO_ADM_H

#include "Usuario.h"
#include <string>
#include <iostream>

using namespace std;

class Funcionario_adm : public Usuario {
    private:
        string departamento;
        string cargo; //atributos adicionais
    public:
    Funcionario_adm(); //construtor padrão
    Funcionario_adm(string nome, string email, string tipo, string departamento, string cargo); //Cosntrutor parametrizado

    void gerarRelatorio() override; //método sobrescrito

};

#endif //FUNCIONARIO_ADM_H