#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Usuario.h"
#include <vector>
#include <string>
class Professor : public Usuario {
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;
public:
    Professor() {}
    Professor(std::string n, std::string e, std::string t, std::string a) : Usuario(n,e,t), areaDeAtuacao(a) {}
    void gerarRelatorio() override;
};
#endif
