#ifndef USUARIO_H
#define USUARIO_H

#include <string>

// Classe base com dados globais não sensíveis
class Usuario {
protected:
    int id;
    std::string username;

public:
    Usuario(int id, std::string username) : id(id), username(username) {}
    virtual ~Usuario() = default;

    int getId() const { return id; }
    std::string getUsername() const { return username; }
};

#endif