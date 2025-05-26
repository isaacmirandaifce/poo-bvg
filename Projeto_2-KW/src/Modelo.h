#include <string>
using namespace std;

class Modelo {
private:
string nome;
public:
Modelo(string nome) {
this->nome = nome;
}
string getNome() const {
return nome;
}
void setNome(string nome) {
this->nome = nome;
}
};