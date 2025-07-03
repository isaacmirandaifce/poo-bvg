#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>
#include <string>

// Exceção para arquivo não encontrado
class ArquivoNaoEncontradoException : public std::runtime_error {
public:
    ArquivoNaoEncontradoException(const std::string& mensagem)
        : std::runtime_error(mensagem) {}
};

// Exceção para erro de permissão
class PermissaoNegadaException : public std::runtime_error {
public:
    PermissaoNegadaException(const std::string& mensagem)
        : std::runtime_error(mensagem) {}
};

// Exceção para erro de conversão de dados
class ErroConversaoException : public std::runtime_error {
public:
    ErroConversaoException(const std::string& mensagem)
        : std::runtime_error(mensagem) {}
};

#endif // EXCECOES_H