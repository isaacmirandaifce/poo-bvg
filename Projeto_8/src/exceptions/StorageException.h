#ifndef STORAGEEXCEPTION_H
#define STORAGEEXCEPTION_H

#include <exception>
#include <string>

class StorageException : public std::exception {
protected:
    std::string message;
public:
    explicit StorageException(const std::string& msg) : message(msg) {}
    
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class FileCorruptedException : public StorageException {
public:
    explicit FileCorruptedException(const std::string& details) 
        : StorageException("FileCorruptedException: Ocorreu uma inconsistencia nos dados lidos. Detalhes: " + details) {}
};

class DiskWriteException : public StorageException {
public:
    explicit DiskWriteException(const std::string& details) 
        : StorageException("DiskWriteException: Falha critica de I/O na gravacao. Detalhes: " + details) {}
};

#endif // STORAGEEXCEPTION_H