#ifndef ALUNO_H
#define ALUNO_H
#include <vector>
#include <string>
#include "Usuario.h"
class Aluno : public Usuario {
public:
    class HistoricoDisciplinar {
    public:
        std::string disciplina;
        int ano;
        double nota;
        HistoricoDisciplinar(std::string d, int a, double n): disciplina(d), ano(a), nota(n) {}
    };
    std::vector<HistoricoDisciplinar> historico;
    Aluno(std::string n, std::string e): Usuario(n,e) {}
};
#endif
