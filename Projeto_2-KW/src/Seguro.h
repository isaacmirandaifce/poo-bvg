#include <../Projeto_2/src/Carro.h>
#include <../Projeto_2/src/Cliente.h>
#include <ctime>
#include <iostream>

class Seguro {
private:
Carro carro;
Cliente cliente;
double valor;
tm vigenciaInicio;
tm vigenciaFim;
public:
Seguro(Carro carro, Cliente cliente, double valor, tm inicio, tm fim)
: carro(carro), cliente(cliente), valor(valor),
vigenciaInicio(inicio), vigenciaFim(fim) {}
double calcularValor(double baseValor, double taxa) const {
return baseValor * (1 + taxa);
}
bool verificarVigencia() const {
time_t agora = time(nullptr);
tm* hoje = localtime(&agora);
return difftime(mktime(hoje), mktime((tm*)&vigenciaInicio)) >= 0 &&
difftime(mktime((tm*)&vigenciaFim), mktime(hoje)) >= 0;
}
};