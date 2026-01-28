//Código de Alissa Garcia ADS S3

#include "Professor.h"

//Implementação da Classe

// Construtor padrão
    Professor::Professor() :  Usuario() { //herança
        this->areadeAtuacao  = "NULL";
        //Deixei tudo nulo por default
    }

// Construtor parametrizado
    Professor::Professor(string nome, string email, string tipo, string areadeAtuacao) : Usuario(nome, email, tipo){ //herança
        this->areadeAtuacao  = areadeAtuacao;
        
    }

// M´etodo de adição de disciplinas
    void Professor::disciplinasAdicionadas(string disciplina){
        disciplinasMinistradas.push_back(disciplina);
    }


// Metodo de impressao das informações com sobrescrita:
    void Professor::gerarRelatorio(){
        Usuario::gerarRelatorio(); //chamando a classe base
        std::cout << "A área de atuação desse professor é: " << this->areadeAtuacao << endl;
        std::cout << "As disciplinas ministradas por esse professor são: " << endl;

        for (string d : disciplinasMinistradas){
            cout << "--"<< d << endl;
        }
        cout << endl;
    }
