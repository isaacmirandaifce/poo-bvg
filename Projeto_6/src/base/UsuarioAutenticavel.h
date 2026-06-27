#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>

enum class TipoUsuario {
    ADMIN,
    AUDITOR,
    OPERADOR
};

class Usuario {
protected:
    int id;
    std::string username;
public:
    Usuario(int _id, std::string _username);
    virtual ~Usuario() = default; 
};

class UsuarioAutenticavel : public Usuario {
public:
    UsuarioAutenticavel(int _id, std::string _username);
    virtual bool autenticar(std::string senha) = 0;
};

#endif