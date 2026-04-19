#pragma once
#include <iostream>
#include <string>

// Criação da classe seguro
class seguro 
{
    private:

    double base = -1;

    public:
        
    double getBase() {return base < 0 ? -1 : base;}

    void setBase(double baseAdicionar) {base = baseAdicionar;}

    void refatorarBase(double valor) {base *= valor;}

    bool testarBaseValida(){return base >= 0;}

    /*
    A implementação do polimorfismo ocorre a partir do uso de 'virtual', que permite que as classes filhas sobrescrevam métodos da classe pai.

    A abstração é aplicada ao definir o método como '= 0', tornando a classe Seguro abstrata e obrigando todas as classes filhas a implementarem 
    sua própria função de cálculo.
    */

    virtual void calcular_premio() = 0;
};

// Criamos o seguro do automovel e definimos ele sendo uma classe filha da classe seguro através do ": public seguro".
class seguroAuto : public seguro
{
    private:

    int ano = -1;
    std::string placaCarro = "";

    public:
        
    // a função de calcular premio do seguro do automovel.
    void calcular_premio(){ano < 2010 ? refatorarBase(1.2) : refatorarBase(1.5);};

    int getAno() { return ano < 0 ? -1 : ano;}

    std::string getPlacaCarro(){return placaCarro;}

    void setAno(int anoAdicionar){ano = anoAdicionar;};

    void setPlacaCarro(std::string placaAdicionar) {placaCarro = placaAdicionar;};
};

// Criamos o seguro de vida e definimos ele sendo uma classe filha da classe seguro através do ": public seguro".
class seguroVida : public seguro
{

private:
    
    int idade = -1;
    std::string causa = "";

public:
    // a função de calcular premio do seguro de vida.
    void calcular_premio(){idade > 60 ? refatorarBase(2.0) : refatorarBase(1.1);}

    int getIdade() {return idade < 0 ? -1 : idade;}

    std::string getCausa() {return causa;}
        

    void setIdade(int idadeAdicionar) { idade = idadeAdicionar; };

    void setCausa(std::string causaAdicionar) { causa = causaAdicionar; };
};

// Criamos o seguro residencial e definimos ele sendo uma classe filha da classe seguro através do ": public seguro".
class seguroResidencial : public seguro
{

    private:
        std::string tipoImovel;

        std::string endereco;
    

    public:
        // a função de calcular premio do seguro residencial.
        void calcular_premio() {tipoImovel == "CASA" ? refatorarBase(1.15) : refatorarBase(1.05);};

        std::string getTipoImovel(){return tipoImovel;}

        std::string getEndereco() {return endereco;}

        void setTipoImovel(std::string tipoImovelAdicionar) { tipoImovel = tipoImovelAdicionar; };

        void setEndereco(std::string enderecoAdicionar) { endereco = enderecoAdicionar; };
};
