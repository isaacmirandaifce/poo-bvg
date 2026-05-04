#include <iostream>
#include <string>
#include "models/funcoes.hpp"
#include "models/cliente.hpp"
#include "models/seguros.hpp"

int main() {

    cliente usuario;
    seguroAuto segAuto;
    seguroVida segVida;
    seguroResidencial segRes;

    adicionarInformaçõesClientes("Fulano", "000.000.000-00", usuario);

    adicionarInformaçõesSegurosAuto(2013, "NDR-3015", 10, segAuto);

    adicionarInformaçõesSegurosVida(61, "sofre de 'A'", 10, segVida);

    adicionarInformaçõesSegurosResidencial("CASA", "RUA X NUMERO ZZZZ, NO BAIRRO Y", 10, segRes);

    mostrarcliente(usuario);

    mostrarSeguroAuto(segAuto);

    mostrarSeguroVida(segVida);

    mostrarSeguroResi(segRes);

    processarSeguroGenerico(&segAuto);

    processarSeguroGenerico(&segVida);

    processarSeguroGenerico(&segRes);

    double baseTotal = segAuto.getBase() + segVida.getBase() + segRes.getBase();

    std::cout << std::endl << "Base do Automovel: " << segAuto.getBase() << std::endl;
    std::cout << std::endl << "Base de Vida: " << segVida.getBase() << std::endl;
    std::cout << std::endl << "Base Residencial: " << segRes.getBase() << std::endl;
    std::cout << std::endl << "base Total: " << baseTotal << std::endl;

    return 0;
}