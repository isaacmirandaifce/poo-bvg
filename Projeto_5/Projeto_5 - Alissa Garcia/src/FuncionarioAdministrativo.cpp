//Código de Alissa Garcia ADS S3

#include "FuncionarioAdministrativo.h"

//Implementação da Classe

// Construtor padrão
    Funcionario_adm::Funcionario_adm() :  Usuario() { //herança
        this->departamento  = "NULL";
        this->cargo = "NULL";
        //Deixei tudo nulo por default
    }

// Construtor parametrizado
    Funcionario_adm::Funcionario_adm(string nome, string email, string tipo, string departamento, string cargo) : Usuario(nome, email, tipo){ //herança
        this->departamento  = departamento;
        this->cargo = cargo;
        
    }


// Metodo de impressao das informações com sobrescrita:
    void Funcionario_adm::gerarRelatorio(){
        Usuario::gerarRelatorio(); //chamando a classe base
        std::cout << "O departamento do Funcionário Administrativo é: " << this->departamento<< endl;
        std::cout << "O cargo é: " << this->cargo << endl;

        
    }

