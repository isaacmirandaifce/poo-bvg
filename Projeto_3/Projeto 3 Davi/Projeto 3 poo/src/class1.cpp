#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Pessoa{

    private:
    string telefone;
    string nome;

    public:
    Pessoa(string nome, string telefone){
        this->nome = nome;
        this->telefone = telefone;
        cout << "Pessoa criada: " << nome << endl;
    }

    ~Pessoa(){
        cout << "Pessoa Destruida: " << nome << endl;
    }

    void imprimirNome() const {
        cout << "Nome: " << nome << endl;
    }

    void imprimirTelefone() const {
        cout << "Telefone: " << telefone << endl;
    }
};


int main(){
   vector<Pessoa> pessoas;

   pessoas.emplace_back("Davi", "(88)98152-2318");
   pessoas.emplace_back("Henrique", "(88)99182-7348");
   pessoas.emplace_back("Pedro", "(88)98854-9348");

   for(const auto& pessoa: pessoas) {
    pessoa.imprimirNome();
    pessoa.imprimirTelefone();
    cout << "                             " << endl;
   }

   return 0;
   
}