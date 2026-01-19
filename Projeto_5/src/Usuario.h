#ifndef USUARIO_H
#define USUARIO_H
#include <string>
class Usuario {
protected:
    std::string nome;
    std::string email;
    std::string tipo;
public:
    Usuario() {}
    Usuario(std::string n, std::string e, std::string t) : nome(n), email(e), tipo(t) {}
    virtual void gerarRelatorio() = 0;
    virtual ~Usuario() {}
};
#endif
