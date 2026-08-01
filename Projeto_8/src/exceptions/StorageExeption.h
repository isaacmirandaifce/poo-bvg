#ifndef STORAGE_EXCEPTION_H
#define STORAGE_EXCEPTION_H

#include <exception>
#include <string>


class StorageException : public std::exception {
protected:
    std::string mensagem;

public:
    explicit StorageException(const std::string& msg) : mensagem(msg) {}
    
    const char* what() const noexcept override {
        return mensagem.c_str();
    }
};


class FileCorruptedException : public StorageException {
public:
    explicit FileCorruptedException(const std::string& detalhes)
        : StorageException("[Corrupcao de Arquivo] " + detalhes) {}
};


class DiskWriteException : public StorageException {
public:
    explicit DiskWriteException(const std::string& detalhes)
        : StorageException("[Erro de Escrita no Disco] " + detalhes) {}
};

#endif