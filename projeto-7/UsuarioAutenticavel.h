#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>
#include "Usuario.h"

// Classe abstrata que herda de Usuario
class UsuarioAutenticavel : public Usuario {
private:
    std::string senha;

public:
    // O construtor precisa receber os dados para a classe base e para si mesmo
    UsuarioAutenticavel(std::string nome, std::string email, TipoUsuario tipo, std::string senha);

    // Destrutor virtual
    virtual ~UsuarioAutenticavel() {}

    // Método abstrato (virtual puro) que força as classes filhas a implementarem a autenticação
    virtual bool autenticar(const std::string& senha) = 0;

protected:
    // Método para que as classes filhas possam acessar a senha para validação
    const std::string& getSenha() const;
};

#endif // USUARIO_AUTENTICAVEL_H
