#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>
#include "Relatorio.h"
#include "TipoUsuario.h"

using namespace std;

class Usuario : public Relatorio {
protected:
    string nome;
    string email;
    TipoUsuario tipo;

public:
    Usuario();
    Usuario(string nome, string email, TipoUsuario tipo);

    virtual void gerarRelatorio() const override = 0;
    virtual ~Usuario() {}
};

#endif
