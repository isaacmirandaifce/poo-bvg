#ifndef ALUNO_H
#define ALUNO_H
#include "Usuario.h"
#include <vector>
#include <string>
class Aluno : public Usuario {
private:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinas;
public:
    Aluno() {}
    Aluno(std::string n, std::string e, std::string t, std::string m, std::string c)
    : Usuario(n,e,t), matricula(m), curso(c) {}
    void gerarRelatorio() override;
};
#endif
