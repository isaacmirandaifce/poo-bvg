#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

enum class TipoUsuario {
    ADMIN,
    AUDITOR,
    OPERADOR
};

class Usuario {
    protected:
        int id;
        std::string username;
    
    public:
        Usuario(int id, std::string username);
        virtual ~Usuario() = default;

        int getId() const;
        std::string getUsername() const;
};

class UsuarioAutenticavel : public Usuario {
    protected:
        TipoUsuario tipo;

    public:
        UsuarioAutenticavel(int id, std::string username, TipoUsuario tipo);
        virtual ~UsuarioAutenticavel() = default;

        virtual bool autenticar(std::string senha) = 0;

        TipoUsuario getTipo() const;
};

#endif