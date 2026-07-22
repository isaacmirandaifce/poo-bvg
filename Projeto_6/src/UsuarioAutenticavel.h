#ifndef USUARIOAUTENTICAVEL_H
#define USUARIOAUTENTICAVEL_H

#include <string>
#include "Usuario.h"

// Classe abstrata: representa usuarios do sistema capazes de autenticar-se.
// Nao pode ser instanciada diretamente (possui metodo virtual puro autenticar()).
class UsuarioAutenticavel : public Usuario {
private:
    std::string senhaHash; // senha nunca fica em texto puro

    static std::string hashSenha(const std::string& senha);

protected:
    void definirSenha(const std::string& senha);

public:
    UsuarioAutenticavel();
    UsuarioAutenticavel(std::string nome, std::string email, TipoUsuario tipo, const std::string& senha);
    virtual ~UsuarioAutenticavel();

    // Metodo abstrato: cada tipo de usuario pode customizar a regra de autenticacao
    virtual bool autenticar(std::string senha) = 0;

protected:
    // Auxiliar reutilizavel pelas subclasses para validar a senha informada
    bool validarSenha(const std::string& senha) const;
};

#endif // USUARIOAUTENTICAVEL_H
