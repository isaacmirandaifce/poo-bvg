#include <iostream>
using namespace std;

class Cliente {
private:

string nome;
string cpf;
public:
Cliente(string nome, string cpf) {
this->nome = nome;
this->cpf = cpf;
}
void exibirInformacoes() const {
cout << "Cliente: " << nome << ", CPF: " << cpf << endl;
}
};