#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>
#include <string>

class ArquivoNaoEncontradoException : public std::runtime_error {
public:
    ArquivoNaoEncontradoException(const std::string& arquivo)
        : std::runtime_error("Erro: Arquivo nao encontrado - " + arquivo) {}
};

class PermissaoNegadaException : public std::runtime_error {
public:
    PermissaoNegadaException(const std::string& arquivo)
        : std::runtime_error("Erro: Permissao negada para acessar o arquivo - " + arquivo) {}
};

class FalhaConversaoException : public std::runtime_error {
public:
    FalhaConversaoException(const std::string& linha)
        : std::runtime_error("Erro: Falha ao converter dados da linha - " + linha) {}
};

#endif 