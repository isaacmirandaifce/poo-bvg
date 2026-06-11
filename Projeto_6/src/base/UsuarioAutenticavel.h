#ifndef USUARIOAUTENTICAVEL_H
#define USUARIOAUTENTICAVEL_H

#include <string>

using namespace std;

enum class TipoUsuario
{
    ADMIN,
    AUDITOR,
    OPERADOR
};

class Usuario
{
protected:
    int id;
    string username;

public:
    Usuario(int id, string username);

    virtual ~Usuario();

    string getUsername() const;
    int getId() const;
};

class UsuarioAutenticavel : public Usuario
{
protected:
    string senha;

public:
    UsuarioAutenticavel(
        int id,
        string username,
        string senha);

    virtual bool autenticar(string senha) = 0;

    virtual TipoUsuario getTipo() const = 0;

    virtual ~UsuarioAutenticavel();
};

#endif