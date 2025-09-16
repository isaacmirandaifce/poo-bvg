#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>
#include <string>

// Exceção para quando o arquivo não é encontrado
class ArquivoNaoEncontradoException : public std::runtime_error {
public:
    explicit ArquivoNaoEncontradoException(const std::string& message)
        : std::runtime_error(message) {}
};

// Exceção para falha de permissão de acesso ao arquivo
class PermissaoNegadaException : public std::runtime_error {
public:
    explicit PermissaoNegadaException(const std::string& message)
        : std::runtime_error(message) {}
};

// Exceção para dados em formato inválido no arquivo
class FormatoInvalidoException : public std::runtime_error {
public:
    explicit FormatoInvalidoException(const std::string& message)
        : std::runtime_error(message) {}
};

#endif // EXCECOES_H