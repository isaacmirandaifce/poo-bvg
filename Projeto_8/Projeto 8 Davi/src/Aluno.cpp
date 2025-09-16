#include "Aluno.h"
#include <stdexcept>
#include <vector>

static std::vector<std::string> split_str(const std::string& s, char delim) {
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

Aluno Aluno::fromCSV(const std::string& line) {
    auto parts = split_str(line, ';');
    if (parts.size() < 3) {
        throw std::invalid_argument("Linha de aluno inválida: " + line);
    }
    int id = 0;
    try {
        id = std::stoi(parts[0]);
    } catch (...) {
        throw std::invalid_argument("ID inválido em aluno: " + parts[0]);
    }
    return Aluno{id, parts[1], parts[2]};
}
