#include <iostream>
#include <string>

class seguro 
{
    private:
    std::string tipo;
    double base;

    public:
        double getBase()
        {

            return base;
        }
};

class seguroAuto : public seguro
{
    private:

    int ano;
    std::string placaCarro;
    
    public:
        
    double calcular_premio(){

        

        if (ano < 2010)
        {

            return getBase() * 1.2;
        };

        return getBase() * 1.5;
    }
};

class seguroVida : public seguro
{

private:
    
    int idade;
    std::string causa;

public:
    double calcular_premio()
    {

        if (idade > 60)
        {
            return getBase() * 2.0;
        };

        return getBase() * 1.1;
    }
};

class seguroResidencial : public seguro
{

    private:
        std::string tipoImovel;
        std::string endereco;


    public:
        
        double calcular_premio()
        {

            if (tipoImovel > "CASA")
            {
                return getBase() * 1.15;
            };

            return getBase() * 1.05;
        };

};
