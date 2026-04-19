#pragma once
#include <iostream>
#include <string>


class seguro 
{
    private:

    double base = -1;

    public:
        
    double getBase() {return base < 0 ? -1 : base;}

    void setBase(double baseAdicionar) {base = baseAdicionar;}

    void refatorarBase(double valor) {base *= valor;}

    bool testarBaseValida(){return base >= 0;}

    virtual void calcular_premio() = 0;
};

class seguroAuto : public seguro
{
    private:

    int ano = -1;
    std::string placaCarro = "";

    public:
        
    void calcular_premio(){ano < 2010 ? refatorarBase(1.2) : refatorarBase(1.5);};

    int getAno() { return ano < 0 ? -1 : ano;}

    std::string getPlacaCarro(){return placaCarro;}

    void setAno(int anoAdicionar){ano = anoAdicionar;};

    void setPlacaCarro(std::string placaAdicionar) {placaCarro = placaAdicionar;};
};

class seguroVida : public seguro
{

private:
    
    int idade = -1;
    std::string causa = "";

public:
    void calcular_premio(){idade > 60 ? refatorarBase(2.0) : refatorarBase(1.1);}

    int getIdade() {return idade < 0 ? -1 : idade;}

    std::string getCausa() {return causa;}
        

    void setIdade(int idadeAdicionar) { idade = idadeAdicionar; };

    void setCausa(std::string causaAdicionar) { causa = causaAdicionar; };
};

class seguroResidencial : public seguro
{

    private:
        std::string tipoImovel;

        std::string endereco;
    

    public:
        
        void calcular_premio() {tipoImovel == "CASA" ? refatorarBase(1.15) : refatorarBase(1.05);};

        std::string getTipoImovel(){return tipoImovel;}

        std::string getEndereco() {return endereco;}

        void setTipoImovel(std::string tipoImovelAdicionar) { tipoImovel = tipoImovelAdicionar; };

        void setEndereco(std::string enderecoAdicionar) { endereco = enderecoAdicionar; };
};
