#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>
#include "Usuario.h"

// Classe Abstrata: representa um usuário que pode se autenticar.
// Ninguém pode criar um objeto do tipo "UsuarioAutenticavel", apenas de suas classes filhas.
class UsuarioAutenticavel : public Usuario {
private:
    std::string senha;

public:
    UsuarioAutenticavel(int id, std::string nome, TipoUsuario tipo, std::string senha);
    virtual ~UsuarioAutenticavel() = default;

    // Método abstrato: toda classe filha será OBRIGADA a implementar sua própria versão deste método.
    // O 'const' no final indica que o método não altera o estado do objeto.
    virtual bool autenticar(const std::string& senha) const = 0;

protected:
    // Método protegido para que as classes filhas possam usá-lo para validar a senha.
    bool verificarSenha(const std::string& tentativa) const;
};

#endif // USUARIO_AUTENTICAVEL_H