#include <iostream>
#include <ctime>
#include "../Projeto_2/src/Carro.h"
#include "../Projeto_2/src/Cliente.h"
#include "../Projeto_2/src/Modelo.h"
#include "../Projeto_2/src/Seguro.h"

using namespace std;


tm criarData(int dia, int mes, int ano) {
    tm data = {};
    data.tm_mday = dia;
    data.tm_mon = mes - 1;  
    data.tm_year = ano - 1900;
    return data;
}

int main() {
    Modelo modeloCorolla("Corolla");

    Carro carro(2020, "Toyota", modeloCorolla, "Branco", "XYZ-1234");

    Cliente cliente("João Silva", "123.456.789-00");


    tm inicio = criarData(1, 1, 2024);
    tm fim = criarData(1, 1, 2025);


    Seguro seguro(carro, cliente, 1500.00, inicio, fim);


    cliente.exibirInformacoes();
    carro.exibirDetalhes();
    cout << "Valor do seguro: R$ " << seguro.calcularValor(1500.00, 0.0) << endl;

    if (seguro.verificarVigencia()) {
        cout << "Status: Seguro válido." << endl;
    } else {
        cout << "Status: Seguro vencido." << endl;
    }

    return 0;
}
