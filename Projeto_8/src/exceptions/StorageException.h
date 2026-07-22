#ifndef STORAGEEXCEPTION_H
#define STORAGEEXCEPTION_H

#include <exception>
#include <string>

// Classe base da hierarquia de erros de armazenamento do Ledger.
class StorageException : public std::exception {
protected:
    std::string mensagem;

public:
    explicit StorageException(const std::string& mensagem)
        : mensagem(mensagem) {}

    virtual const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

// Disparada quando o arquivo existe, mas seu conteudo esta em formato invalido/corrompido.
class FileCorruptedException : public StorageException {
public:
    explicit FileCorruptedException(const std::string& mensagem)
        : StorageException("[FileCorruptedException] " + mensagem) {}
};

// Disparada quando o fluxo de escrita falha (permissao, disco cheio, etc.).
class DiskWriteException : public StorageException {
public:
    explicit DiskWriteException(const std::string& mensagem)
        : StorageException("[DiskWriteException] " + mensagem) {}
};

#endif // STORAGEEXCEPTION_H
