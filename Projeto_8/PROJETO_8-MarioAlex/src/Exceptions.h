#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H


#include <exception>
#include <string>


class ArquivoException : public std::exception {
protected:
std::string mensagem;
public:
explicit ArquivoException(const std::string &m): mensagem(m) {}
const char* what() const noexcept override { return mensagem.c_str(); }
};


class ArquivoNaoEncontradoException : public ArquivoException {
public:
explicit ArquivoNaoEncontradoException(const std::string &f): ArquivoException("Arquivo nao encontrado: " + f) {}
};


class PermissaoNegadaException : public ArquivoException {
public:
explicit PermissaoNegadaException(const std::string &f): ArquivoException("Permissao negada: " + f) {}
};


class ConversaoDadosException : public ArquivoException {
public:
explicit ConversaoDadosException(const std::string &m): ArquivoException("Erro conversao dados: " + m) {}
};


#endif // EXCEPTIONS_H