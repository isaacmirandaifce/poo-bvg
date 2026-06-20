#ifndef USUARIOAUTENTICAVEL_H
#define USUARIOAUTENTICAVEL_H

#include "Usuario.h"
#include <string>

// Classe abstrata: herda de Usuario e força contrato de autenticação
// Não pode ser instanciada diretamente por ter método virtual puro
class UsuarioAutenticavel : public Usuario {
public:
    UsuarioAutenticavel(int id, std::string username) : Usuario(id, username) {}
    virtual ~UsuarioAutenticavel() = default;

    virtual bool autenticar(std::string senha) = 0; // Método virtual puro
};

#endif