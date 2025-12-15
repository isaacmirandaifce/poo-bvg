#ifndef FUNCIONARIOADM_H
#define FUNCIONARIOADM_H

#include "Usuario.h"

class FuncionarioAdm : public Usuario {
    private:
        string departamento;
        string cargo;

    public:
        FuncionarioAdm();
        FuncionarioAdm(string nome, string email, string departamento, string cargo);

        void gerarRelatorio() const override;
};

#endif