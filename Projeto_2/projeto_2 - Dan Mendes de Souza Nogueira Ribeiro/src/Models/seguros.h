#ifndef SEGUROS
#define SEGUROS
#include <iostream>
#include <string>

// Criação da classe seguro
class seguro
{
private:
    double base = -1;

public:
    double getBase();

    void setBase(double baseAdicionar);

    void refatorarBase(double valor);

    bool testarBaseValida();

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
    void calcular_premio();

    int getAno();

    std::string getPlacaCarro();

    void setAno(int anoAdicionar);

    void setPlacaCarro(std::string placaAdicionar);
};

// Criamos o seguro de vida e definimos ele sendo uma classe filha da classe seguro através do ": public seguro".
class seguroVida : public seguro
{

private:
    int idade = -1;
    std::string causa = "";

public:
    // a função de calcular premio do seguro de vida.
    void calcular_premio();

    int getIdade();

    std::string getCausa();

    void setIdade(int idadeAdicionar);

    void setCausa(std::string causaAdicionar);
};

// Criamos o seguro residencial e definimos ele sendo uma classe filha da classe seguro através do ": public seguro".
class seguroResidencial : public seguro
{

private:
    std::string tipoImovel;

    std::string endereco;

public:
    // a função de calcular premio do seguro residencial.
    void calcular_premio();

    std::string getTipoImovel();

    std::string getEndereco();

    void setTipoImovel(std::string tipoImovelAdicionar);

    void setEndereco(std::string enderecoAdicionar);
    
};

#endif