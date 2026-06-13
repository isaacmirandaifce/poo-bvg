#ifndef USUARIOAUDITOR
#define USUARIOAUDITOR
#include <iostream>
#include <string>
#include "../base/usuarioAutenticavel.h"
#include "../interfaces/relatorio.h"

class UsuarioAuditor : public UsuarioAutenticavel, public Relatorio{

public:
    UsuarioAuditor(int id, std::string nome, std::string senha);

    bool autenticar(std::string senha);

    void gerarRelatorio() const override;
};

#endif