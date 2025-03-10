#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>
#include <string>

class ArquivoNaoEncontradoException : public std::exception {
public:
    ArquivoNaoEncontradoException(const std::string& mensagem) : mensagem(mensagem) {}
    const char* what() const noexcept override {
        return mensagem.c_str();
    }
private:
    std::string mensagem;
};

class PermissaoNegadaException : public std::exception {
public:
    PermissaoNegadaException(const std::string& mensagem) : mensagem(mensagem) {}
    const char* what() const noexcept override {
        return mensagem.c_str();
    }
private:
    std::string mensagem;
};

#endif // EXCECOES_H