#include <iostream>
#include <string>

class Usuario {
    protected:
    std::string nome;
    std::string email;
    std::string tipo;

    public:
    Usuario();

    Usuario(std::string n, std::string e, std::string t);
    virtual ~Usuario(){};
    
    virtual void gerarRelatorio() =0;
    
    /*{
        std::cout << "Dados do Usuario" << std::endl;
        std::cout << "Nome" << nome << std::endl;
        std::cout << "Email" << email << std::endl;
        std::cout << "Tipo" << tipo << std::endl;
    };*/
};
