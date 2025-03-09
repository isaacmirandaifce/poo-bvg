#ifndef USUARIOAUTENTICAVEL_H
#define USUARIOAUTENTICAVEL_H

#include "Usuario.h"

class UsuarioAutenticavel : public Usuario {
private:
    string senha;  // Senha do usuário

public:
    // Construtor que inicializa nome, id e senha
    UsuarioAutenticavel(string nome, string id, string senha);

    // Método para autenticar o usuário comparando a senha tentativa
    bool autenticar(string senhaTentativa) const;
};

#endif
