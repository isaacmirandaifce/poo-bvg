#include <iostream>
#include <string>

class cliente
{
private:
    std::string cpf;
    std::string nome;

    public:

    void setNome(std::string nomeAdicionar) { nome = nomeAdicionar;};
    
    void setCPF(std::string cpfAdicionar) { cpf = cpfAdicionar;};
    
    std::string getCPF() {return cpf;};

    std::string getNome() {return nome;};
    
};

