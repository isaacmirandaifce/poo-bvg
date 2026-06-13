#ifndef USUARIOADMIN
#define USUARIOADMIN
#include <iostream>
#include <string>
#include "../base/usuarioAutenticavel.h"
#include "../interfaces/relatorio.h"


class usuarioAdmin : public UsuarioAutenticavel, public Relatorio{

    public:
        
    usuarioAdmin(int id, std::string nome, std::string senha);

    bool autenticar(std::string senha);
    
    void gerarRelatorio() const;
};

#endif