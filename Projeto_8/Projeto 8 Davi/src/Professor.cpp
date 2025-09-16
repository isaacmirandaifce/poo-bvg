#include "Professor.h"
#include <stdexcept>
#include <vector>

static std::vector<std::string> split_str2(const std::string& s, char delim) {
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

Professor Professor::fromCSV(const std::string& line) {
    auto parts = split_str2(line, ';');
    if (parts.size() < 3) {
        throw std::invalid_argument("Linha de professor inválida: " + line);
    }
    int id = 0;
    try {
        id = std::stoi(parts[0]);
    } catch (...) {
        throw std::invalid_argument("ID inválido em professor: " + parts[0]);
    }
    return Professor{id, parts[1], parts[2]};
}
