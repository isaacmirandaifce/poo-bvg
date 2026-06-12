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

class UsuarioAutenticavel : public Usuario {

    public:
    virtual bool autenticar(std::string senha) = 0;
};


#endif