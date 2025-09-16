#include "Disciplina.h"
#include <stdexcept>
#include <vector>

static std::vector<std::string> split_str3(const std::string& s, char delim) {
    std::vector<std::string> out;
    std::string tmp;
    for(char c: s){
        if(c==delim){
            out.push_back(tmp);
            tmp.clear();
        } else {
            tmp.push_back(c);
        }
    }
    out.push_back(tmp);
    return out;
}

Disciplina Disciplina::fromCSV(const std::string& line) {
    auto parts = split_str3(line, ';');
    if (parts.size() < 3) {
        throw std::invalid_argument("Linha de disciplina inválida: " + line);
    }
    int codigo = 0;
    int carga = 0;
    try {
        codigo = std::stoi(parts[0]);
        carga = std::stoi(parts[2]);
    } catch (...) {
        throw std::invalid_argument("Valores numéricos inválidos em disciplina");
    }
    return Disciplina{codigo, parts[1], carga};
}
