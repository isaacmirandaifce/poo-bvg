#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>
#include <string>

class ArquivoNaoEncontradoException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erro: O arquivo de dados nao foi encontrado.";
    }
};

class PermissaoNegadaException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erro: Permissao negada para acessar o arquivo de dados.";
    }
};

class FalhaConversaoException : public std::exception {
private:
    std::string mensagem;

public:
    explicit FalhaConversaoException(const std::string& linhaComErro) {
        mensagem = "Erro: Falha ao converter dados da linha: '" + linhaComErro + "'";
    }

    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

#endif // EXCECOES_H
