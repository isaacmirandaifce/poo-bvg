#ifndef USUARIOAUTENTICAVEL
#define USUARIOAUTENTICAVEL
#include <iostream>
#include <string>

class Usuario {
    protected:
    int id;
    std::string username;

    public:

    Usuario();
    virtual ~Usuario();

    void setID(int novoID);
    void setUsername(std::string novoUser);

    int getID();
    std::string getUsername();
};

enum class TipoUsuario{
    ADMIN,
    AUDITOR,
    OPERADOR
};

class UsuarioAutenticavel : public Usuario
{

protected:

    std::string senhaUser;

    public:
        UsuarioAutenticavel();
        virtual ~UsuarioAutenticavel();

        std::string getSenha();
        void setSenha(std::string novaSenha);

        virtual bool autenticar(std::string senha) = 0;

        virtual TipoUsuario getTipoUsuario() const = 0;
};

#endif