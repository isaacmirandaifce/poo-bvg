#include "UsuarioAutenticavel.h"


UsuarioAutenticavel::UsuarioAutenticavel(std::string nome, std::string email, TipoUsuario tipo, std::string senha)
    // Chama o construtor da classe mãe (Usuario) e inicializa o atributo 'senha'
    : Usuario(nome, email, tipo), senha(senha) {
}

// Implementação do getter para a senha
const std::string& UsuarioAutenticavel::getSenha() const {
    return this->senha;
}
