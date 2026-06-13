#ifndef USUARIOAUTENTICAVEL
#define USUARIOAUTENTICAVEL
#include <iostream>
#include <string>

/**
 * @class Usuario
 * @brief Classe base que contém os dados globais não sensíveis do utilizador.
 */
class Usuario
{
protected:
    int id;
    std::string username;

public:
    Usuario();
    virtual ~Usuario();

    void setID(int novoID);
    void setUsername(std::string novoUser);

    int getID();
    std::string getUsername();
};

/**
 * @enum TipoUsuario
 * @brief Enumeração de escopo fechado para identificar a categoria do usuário.
 */
enum class TipoUsuario
{
    ADMIN,
    AUDITOR,
    OPERADOR
};

/**
 * @class UsuarioAutenticavel
 * @brief Classe abstrata que exige autenticação e define o contrato de tipo.
 */
class UsuarioAutenticavel : public Usuario
{

protected:
    std::string senhaUser;

public:
    UsuarioAutenticavel();
    virtual ~UsuarioAutenticavel();

    std::string getSenha();
    void setSenha(std::string novaSenha);

    /**
     * @brief Método virtual puro para validar a senha do usuário.
     * @param senha Senha informada para tentativa de login.
     * @return true se a senha estiver correta, false caso contrário.
     */
    virtual bool autenticar(std::string senha) = 0;

    /**
     * @brief Método virtual puro para retornar o nível de acesso do usuário.
     * @return O TipoUsuario (enum) correspondente.
     */
    virtual TipoUsuario getTipoUsuario() const = 0;
};

#endif