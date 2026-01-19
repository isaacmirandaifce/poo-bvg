#ifndef USUARIO_H
#define USUARIO_H
#include <string>
class Usuario {
protected:
    std::string nome;
    std::string email;
public:
    Usuario() = default;
    Usuario(std::string n, std::string e): nome(n), email(e) {}
    virtual ~Usuario() = default;
};
#endif
