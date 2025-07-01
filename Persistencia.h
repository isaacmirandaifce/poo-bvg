#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <vector>
#include <string>

class Persistencia {
public:
    static void salvar(const std::string& arquivo, const std::vector<std::string>& dados);
    static std::vector<std::string> carregar(const std::string& arquivo);
    
    class ErroArquivo : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Erro ao acessar arquivo!";
        }
    };
};

#endif