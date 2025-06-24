#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

class Disciplina {
private:
    std::string nome;
    std::string codigo;
    int ano;

public:
    Disciplina(const std::string& nome, const std::string& codigo, int ano);

    std::string getNome() const;
    std::string getCodigo() const;
    int getAno() const;

    void imprimir() const;
};

#endif 