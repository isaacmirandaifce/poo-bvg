#include "Persistencia.h"
#include <fstream>
#include <stdexcept>

void Persistencia::salvar(const std::string& arquivo, const std::vector<std::string>& dados) {
    std::ofstream file(arquivo);
    if (!file) throw ErroArquivo();
    
    for (const auto& linha : dados) {
        file << linha << "\n";
    }
}

std::vector<std::string> Persistencia::carregar(const std::string& arquivo) {
    std::ifstream file(arquivo);
    if (!file) throw ErroArquivo();
    
    std::vector<std::string> dados;
    std::string linha;
    
    while (std::getline(file, linha)) {
        dados.push_back(linha);
    }
    
    return dados;
}