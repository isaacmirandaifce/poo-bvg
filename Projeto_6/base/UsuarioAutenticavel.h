#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>

enum class TipoUsuario {
    ADMIN,
    AUDITOR,
    OPERADOR
};

class UsuarioAutenticavel {
protected:
    int id;
    std::string username;
    std::string senhaHash; // Dado sensível encapsulado
    TipoUsuario tipo;

public:
    UsuarioAutenticavel(int id, std::string username, std::string senha, TipoUsuario tipo);
    virtual ~UsuarioAutenticavel() = default;

    int getId() const;
    std::string getUsername() const;
    TipoUsuario getTipo() const;
    std::string tipoToString() const;

    // Método virtual puro forçando contrato de autenticação nas subclasses
    virtual bool autenticar(std::string senha) = 0;
};

#endif // USUARIO_AUTENTICAVEL_H