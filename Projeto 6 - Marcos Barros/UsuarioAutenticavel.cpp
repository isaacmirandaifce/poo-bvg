#include "UsuarioAutenticavel.h"

UsuarioAutenticavel::UsuarioAutenticavel(int id, std::string nome, TipoUsuario tipo, std::string senha)
    : Usuario(id, nome, tipo), senha(senha) {}

// Implementação base que as classes filhas podem usar.
// Isso centraliza a lógica de comparação de senhas.
bool UsuarioAutenticavel::verificarSenha(const std::string& tentativa) const {
    return this->senha == tentativa;
}