#ifndef MOTO_H
#define MOTO_H
#include <string>

class Moto {
protected:
    int ano;
    std::string marca;
    std::string modelo;
    std::string cor;
    std::string placa;

public:
    Moto(int a, std::string m, std::string mo, std::string c, std::string p);

    // Getters
    std::string getModelo() const; // Retorna o modelo
    int getAno() const;           // Retorna o ano
    std::string getMarca() const; // Retorna o modelo
    
    void exibirDetalhes();

};
#endif

