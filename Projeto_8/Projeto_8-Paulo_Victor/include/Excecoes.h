#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>
#include <string>

class ArquivoNaoEncontradoException : public std::runtime_error {
public:
    ArquivoNaoEncontradoException(const std::string& mensagem)
        : std::runtime_error(mensagem) {}
};

class PermissaoNegadaException : public std::runtime_error {
public:
    PermissaoNegadaException(const std::string& mensagem)
        : std::runtime_error(mensagem) {}
};

#endif