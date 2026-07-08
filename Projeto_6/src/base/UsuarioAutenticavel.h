#ifndef USUARIOAUTENTICAVEL_H
#define USUARIOAUTENTICAVEL_H

#include <string>

// Classe Base simples
class Usuario {
protected:
    int id;
    std::string username;
public:
    Usuario(int id, std::string user) : id(id), username(user) {}
    virtual ~Usuario() = default;
};

// Classe Abstrata de Autenticação
class UsuarioAutenticavel : public Usuario {
public:
    UsuarioAutenticavel(int id, std::string user) : Usuario(id, user) {}
    
    // Método virtual puro que força a sobrescrita nas classes filhas
    virtual bool autenticar(std::string senha) = 0;
};

#endif
