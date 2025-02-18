#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "TipoUsuario.h" // Incluindo a enumeração TipoUsuario
using namespace std;

class Usuario {
protected:
    string nome;
    string email;
    TipoUsuario tipo; // Enum para representar o tipo de usuário

public:
    Usuario(const string& nome, const string& email, TipoUsuario tipo);
    virtual ~Usuario() = default;

    // Métodos básicos
    string getNome() const;
    string getEmail() const;
    TipoUsuario getTipo() const; // Retorna o tipo do usuário
};

#endif
