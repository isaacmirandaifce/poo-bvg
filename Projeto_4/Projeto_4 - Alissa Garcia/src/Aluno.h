//Código de Alissa Garcia ADS S3

#ifndef ALUNO_H
#define ALUNO_H
#include <string>
#include <iostream>

using namespace std;

//Declaração da Classe 

class Aluno {
private:

    std::string nome, matricula, curso;
// Utilização de atributos privados

public:

     Aluno(); // Construtor Padrão
     Aluno(string nome, string matricula, string curso); // Construtor com os parâmetros de entrada nome, matricula e curso
    ~Aluno(); // Destrutor
// Utilização de métodos públicos

//Método de impressão de dados.
    void exibirInformacoes();
};


#endif // ALUNO_H