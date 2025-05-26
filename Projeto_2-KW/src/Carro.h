#include "../Projeto_2/src/modelo.h"

#include <iostream>
using namespace std;

class Carro {
private:
int ano;
string marca;
Modelo modelo;
string cor;
string placa;
public:
Carro(int ano, string marca, Modelo modelo, string cor, string placa)
: ano(ano), marca(marca), modelo(modelo), cor(cor), placa(placa) {}
void exibirDetalhes() const {
cout << marca << " " << modelo.getNome() << " (" << ano << "), "
<< cor << ", Placa: " << placa << endl;
}
void atualizarCor(string novaCor) {
cor = novaCor;
}
};