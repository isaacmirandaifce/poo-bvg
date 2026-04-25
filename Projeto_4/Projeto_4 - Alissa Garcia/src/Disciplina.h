//Código de Alissa Garcia ADS S3

#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include <string>
#include <iostream>

using namespace std;

//Declaração da Classe 
using namespace std;


class Disciplina {
private:

    std::string nome;
    int cargaHoraria;
    float nota;
// Utilização de atributos privados

public:

     Disciplina(); // Construtor Padrão
     Disciplina(string nome, int cargaHoraria, float nota); // Construtor com os parâmetros de entrada nome, matricula e curso
    ~Disciplina(); // Destrutor
// Utilização de métodos públicos

//Métodos de impressão de dados.
    void setNota(float nota);
    float getNota();
    friend bool verificarAprovacao(const Disciplina& n);
    //Implementação da função amiga
};


#endif // DISCIPLINA_H