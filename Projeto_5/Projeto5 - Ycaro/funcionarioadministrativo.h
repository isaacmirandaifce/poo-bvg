#ifndef FUNCIONARIOADMINISTRATIVO_H
#define FUNCIONARIOADMINISTRATIVO_H

#include "usuario.h"

class funcionarioadministrativo : public usuario {
private:
    std::string departamento;
    std::string cargo;

public:
    funcionarioadministrativo();
    funcionarioadministrativo(std::string nome, std::string email, std::string departamento, std::string cargo);

    void gerarRelatorio() const override;
};

#endif