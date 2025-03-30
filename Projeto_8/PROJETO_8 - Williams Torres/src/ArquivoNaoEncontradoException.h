#ifndef ARQUIVO_NAO_ENCONTRADO_EXCEPTION_H
#define ARQUIVO_NAO_ENCONTRADO_EXCEPTION_H

#include <exception>
#include <string>

class ArquivoNaoEncontradoException : public std::exception {
    std::string mensagem;
public:
    ArquivoNaoEncontradoException(const std::string& mensagem) : mensagem(mensagem) {}
    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

#endif // ARQUIVO_NAO_ENCONTRADO_EXCEPTION_H