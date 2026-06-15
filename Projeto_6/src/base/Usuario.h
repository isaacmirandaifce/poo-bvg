#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    int id;
    std::string username;

public:
    Usuario(int id, const std::string& username)
        : id(id), username(username) {}

    virtual ~Usuario() = default;

    int getId() const {
        return id;
    }

    std::string getUsername() const {
        return username;
    }
};

#endif