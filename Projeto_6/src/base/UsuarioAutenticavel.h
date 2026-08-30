#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>

// Enumeração restrita
enum class TipoUsuario {
    ADMIN,
    AUDITOR,
    OPERADOR
};

// Classe Base
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

// Classe Abstrata (Herda de Usuario)
class UsuarioAutenticavel : public Usuario {
protected:
    TipoUsuario tipo;
public:
    UsuarioAutenticavel(int id, std::string username, TipoUsuario tipo) 
        : Usuario(id, username), tipo(tipo) {}
    
    // Método virtual puro: Força as classes filhas a implementarem
    virtual bool autenticar(std::string senha) = 0;
    
    TipoUsuario getTipo() const { return tipo; }
    
    // Utilitário para formatar o nome do Enum no terminal
    std::string getTipoString() const;
};

#endif