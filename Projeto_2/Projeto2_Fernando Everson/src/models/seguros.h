#include <string>

class Seguro {
    protected:
    std::string titular;
    double valor_base;

    public:
        Seguro(std::string t, double v) : titular(t), valor_base(v) {}

        virtual double calcular_premio()=0;
    

};

class Seguro_auto : public Seguro {
    private:
    int ano;

    public:
        Seguro_auto(std::string t, double v, int a) : Seguro(t, v), ano(a){}

        double calcular_premio() override {
            if (ano<2010) {return valor_base *1.2;
        }

        else{
            return valor_base * 1.05;
        }
        }
};


class Seguro_vida : public Seguro {
    private:
    int idade;

    public:
        Seguro_vida(std::string t, double v, int i) : Seguro(t, v), idade(i){}

        double calcular_premio() override {
            if (idade>60) {return valor_base *2.0;
        }

        else{
            return valor_base * 1.1;
        }
        }
    };
    
class Seguro_imovel:
public Seguro {
    private:
     std::string imovel;

    public:
        Seguro_imovel(std::string t, double v, std::string im) : Seguro(t, v), imovel(im){}

        double calcular_premio() override {
            if (imovel == "casa" ) {return valor_base * 1.15;
        }

        else{
            return valor_base * 1.05;
        }
        }
};