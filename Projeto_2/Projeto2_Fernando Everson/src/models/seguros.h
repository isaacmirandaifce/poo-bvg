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