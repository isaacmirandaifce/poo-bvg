#ifndef EXCECOESPERSONALIZADAS_H
#define EXCECOESPERSONALIZADAS_H

#include <exception>
#include <string>

class ArquivoNaoEncontradoException : public std::exception {
    std::string mensagem;
public:
    ArquivoNaoEncontradoException(const std::string& caminho) {
        mensagem = "Arquivo nao encontrado: " + caminho;
    }
    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

class PermissaoNegadaException : public std::exception {
    std::string mensagem;
public:
    PermissaoNegadaException(const std::string& caminho) {
        mensagem = "Permissao negada: " + caminho;
    }
    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

class ErroConversaoException : public std::exception {
    std::string mensagem;
public:
    ErroConversaoException(const std::string& detalhe) {
        mensagem = "Erro na conversao de dados: " + detalhe;
    }
    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

#endif // EXCECOESPERSONALIZADAS_H