#ifndef EXCECOES_H
#define EXCECOES_H

#include <stdexcept>
#include <string>

class PersistenciaException : public std::runtime_error {
public:
    explicit PersistenciaException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class ArquivoNaoEncontradoException : public PersistenciaException {
public:
    explicit ArquivoNaoEncontradoException(const std::string& path)
        : PersistenciaException("Arquivo não encontrado: " + path) {}
};

class PermissaoNegadaException : public PersistenciaException {
public:
    explicit PermissaoNegadaException(const std::string& path)
        : PersistenciaException("Permissão negada: " + path) {}
};

class ConversaoDadosException : public PersistenciaException {
public:
    explicit ConversaoDadosException(const std::string& detalhe)
        : PersistenciaException("Falha na conversão dos dados: " + detalhe) {}
};

#endif // EXCECOES_H
