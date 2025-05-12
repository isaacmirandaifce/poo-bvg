#include "../src/Cliente.h"

int main (){
    Cliente c1 ("Kayron Warlen", 19, 60.0);
    c1.mostrarInformacoes();
    c1.atualizarSaldo (500.0);
    c1.mostrarInformacoes();


    return 0;
}