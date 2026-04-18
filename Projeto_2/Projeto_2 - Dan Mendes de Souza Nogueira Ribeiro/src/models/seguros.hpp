#include <iostream>
#include <string>


class seguro 
{
    private:

    double base;

    public:
        
    double getBase() {return base;}
    void setBase(double baseAdicionar) {base = baseAdicionar;}

    double refatorarBase(double valor) {

        return base *= valor;
    }
};

class seguroAuto : public seguro
{
    private:

    int ano;
    std::string placaCarro;
    double baseTotal;
    
    public:
        
    double calcular_premio(){

        if (ano < 2010)
        {
            return refatorarBase(1.2);
        };

        return refatorarBase(1.5);
    };

    int getAno() {return ano;}

    std::string getPlacaCarro(){return placaCarro;}

    void setAno(int anoAdicionar){ano = anoAdicionar;};

    void setPlacaCarro(std::string placaAdicionar) {placaCarro = placaAdicionar;};
};

class seguroVida : public seguro
{

private:
    
    int idade;
    std::string causa;
    double baseTotal;

public:
    double calcular_premio()
    {

        if (idade > 60)
        {
            return refatorarBase(2.0);
        };

        return refatorarBase(1.1);
    }

    int getIdade() { return idade; }

    std::string getCausa() { return causa; }

    void setIdade(int idadeAdicionar) { idade = idadeAdicionar; };

    void setCausa(std::string causaAdicionar) { causa = causaAdicionar; };
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
                return refatorarBase(1.15) ;
            };

            return refatorarBase(1.05);
        };

        std::string getTipoImovel() { return tipoImovel; }

        std::string getEndereco() { return endereco; }

        void setTipoImovel(std::string tipoImovelAdicionar) { tipoImovel = tipoImovelAdicionar; };

        void setEndereco(std::string enderecoAdicionar) { endereco = enderecoAdicionar; };
};
