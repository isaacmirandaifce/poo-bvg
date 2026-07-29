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
    explicit FileCorruptedException(const std::string& msg) : StorageException("FileCorruptedException: " + msg) {}
};

class DiskWriteException : public StorageException {
public:
    explicit DiskWriteException(const std::string& msg) : StorageException("DiskWriteException: " + msg) {}
};

#endif // STORAGE_EXCEPTION_H