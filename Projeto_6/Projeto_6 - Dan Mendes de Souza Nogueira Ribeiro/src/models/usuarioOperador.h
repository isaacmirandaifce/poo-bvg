#ifndef USUARIOOPERADOR
#define USUARIOOPERADOR
#include <iostream>
#include <string>
#include "../base/usuarioAutenticavel.h"
#include "../interfaces/relatorio.h"

class UsuarioOperador : public UsuarioAutenticavel, public Relatorio{

public:
    UsuarioOperador(int id, std::string nome, std::string senha);

    bool autenticar(std::string senha);

    TipoUsuario getTipoUsuario() const;

    void gerarRelatorio() const override;
};

#endif