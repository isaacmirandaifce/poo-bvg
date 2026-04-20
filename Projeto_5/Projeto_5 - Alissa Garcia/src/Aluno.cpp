//Código de Alissa Garcia ADS S3

#include "Aluno.h"

//Implementação da Classe

// Construtor padrão
    Aluno::Aluno() :  Usuario() { //herança
        this->matricula  = "NULL";
        this->curso = "NULL";
        //Deixei tudo nulo por default
    }

// Construtor parametrizado
    Aluno::Aluno(string nome, string email, string tipo, string matricula, string curso) : Usuario(nome, email, tipo){ //herança
        this->matricula  = matricula;
        this->curso = curso;
        
    }

    void Aluno::adicionarNota(float nota) {
    notas.push_back(nota);
}


// Metodo de impressao das informações com sobrecarga:
    void Aluno::gerarRelatorio(){
        Usuario::gerarRelatorio(); //chamando a classe base
        std::cout << "A matrícula do Usuário é: " << this->matricula << endl;
        std::cout << "O curso é: " << this->curso << endl;

        
    }
 void Aluno::gerarRelatorio(bool comNota){
        Usuario::gerarRelatorio(); //chamando a classe base
        std::cout << "A matrícula do Usuário é: " << this->matricula << endl;
        std::cout << "O curso é: " << this->curso << endl;
        std::cout << "As notas são" << endl;
         if (comNota) {
        for (float n : notas) {
            cout << "- " << n << endl;
        }
    }

        
    }
