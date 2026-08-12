#ifndef USUARIO_H
#define USUARIO_H

#include <string>

/**
 * @class Usuario
 * @brief Classe base concreta contendo apenas dados globais e nao
 *        sensiveis, compartilhados por todo colaborador cadastrado
 *        no ecossistema de seguranca (SecureBank Pro).
 *
 * Dados sensiveis (como senha) NAO pertencem a esta classe: eles sao
 * responsabilidade exclusiva de UsuarioAutenticavel, que os protege
 * atras de um hash e de encapsulamento adequado.
 */
class Usuario {
protected:
    int id;
    std::string username;

public:
    Usuario(int id, const std::string& username)
        : id(id), username(username) {}

    // Destrutor virtual: esta classe e base de uma hierarquia polimorfica.
    virtual ~Usuario() = default;

    int getId() const { return id; }
    const std::string& getUsername() const { return username; }
};

#endif // USUARIO_H
