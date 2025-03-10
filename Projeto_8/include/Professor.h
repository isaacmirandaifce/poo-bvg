#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>

class Professor {
public:
    Professor(int id, const std::string& nome);
    int getId() const;
    std::string getNome() const;

private:
    int id;
    std::string nome;
};

#endif // PROFESSOR_H