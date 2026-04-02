//Código de Alissa Garcia ADS S3

#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Aluno : virtual public Usuario {
    private:
        string matricula;
        string curso; //atributos adicionais
        vector<float> notas;
    public:
    Aluno(); //construtor padrão
    Aluno(string nome, string email, string tipo, string matricula, string curso); //Cosntrutor parametrizado

      void adicionarNota(float nota); 
    void gerarRelatorio() override; //método sobrescrita
    void gerarRelatorio(bool comNota); //método sobrecarga

  

};

#endif //ALUNO_H
