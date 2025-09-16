#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

class Disciplina {
public:
    std::string codigo;
    std::string nome;

    Disciplina(const std::string& codigo = "", const std::string& nome = "");
    std::string to_csv() const;
    static Disciplina from_csv(const std::string& csv_line);
};

#endif // DISCIPLINA_H