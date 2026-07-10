#ifndef STORAGEEXCEPTION_H
#define STORAGEEXCEPTION_H

#include <exception>
#include <string>

// Classe Base: StorageException
// Raiz da hierarquia de erros de armazenamento do Transaction Ledger.
class StorageException : public std::exception {
protected:
    std::string mensagem;

public:
    explicit StorageException(const std::string& msg)
        : mensagem("[StorageException] " + msg) {}

    virtual const char* what() const noexcept override {
        return mensagem.c_str();
    }
};

// Classe Derivada: FileCorruptedException
// Disparada quando o arquivo existe mas está corrompido:
// colunas ausentes, linhas vazias inesperadas ou formato inválido.
class FileCorruptedException : public StorageException {
public:
    explicit FileCorruptedException(const std::string& detalhe)
        : StorageException("[FileCorrupted] " + detalhe) {}
};

// Classe Derivada: DiskWriteException
// Disparada quando o fluxo de escrita (ofstream) falha ao abrir
// ou persistir dados — falta de permissão, disco cheio, etc
class DiskWriteException : public StorageException {
public:
    explicit DiskWriteException(const std::string& detalhe)
        : StorageException("[DiskWrite] " + detalhe) {}
};

#endif