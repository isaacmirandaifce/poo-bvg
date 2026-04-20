#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>
#include <string>

class ArquivoNaoEncontradoException : public std::runtime_error {
public:
    ArquivoNaoEncontradoException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class PermissaoNegadaException : public std::runtime_error {
public:
    PermissaoNegadaException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class ErroConversaoException : public std::runtime_error {
public:
    ErroConversaoException(const std::string& msg)
        : std::runtime_error(msg) {}
};

#endif