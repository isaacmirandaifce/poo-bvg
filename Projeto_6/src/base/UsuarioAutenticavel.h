#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include "Usuario.h"
#include <string>

/**
 * @class UsuarioAutenticavel
 * @brief Classe abstrata que herda de Usuario e forca o contrato de
 *        login para qualquer colaborador do sistema.
 *
 * Possui um Metodo Virtual Puro (autenticar), o que impede que esta
 * classe seja instanciada diretamente. Qualquer classe filha que nao
 * implementar autenticar() tambem sera considerada abstrata e o
 * compilador impedira sua instanciacao/compilacao do main.cpp.
 */
class UsuarioAutenticavel : public Usuario {
protected:
    // Armazenamos apenas o HASH da senha, nunca o texto puro em memoria
    // persistente do objeto -- boa pratica de conformidade de seguranca.
    std::string senhaHash;

public:
    UsuarioAutenticavel(int id, const std::string& username, const std::string& senha);

    virtual ~UsuarioAutenticavel() = default;

    // Metodo Virtual Puro: torna a classe abstrata.
    virtual bool autenticar(std::string senha) = 0;

protected:
    // Funcao utilitaria de hashing simples (nivel academico) para nunca
    // comparar/expor a senha em texto puro nos relatorios de auditoria.
    static std::string gerarHash(const std::string& senha);
};

#endif // USUARIO_AUTENTICAVEL_H
