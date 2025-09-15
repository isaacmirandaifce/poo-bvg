#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>

class Professor {
private:
    std::string nome;
    std::string email;
    std::string senha;
    std::string disciplinaPrincipal;

public:
    Professor(const std::string& n, const std::string& e, const std::string& s, const std::string& disc)
        : nome(n), email(e), senha(s), disciplinaPrincipal(disc) {}

    std::string getNome() const { return nome; }
    std::string getDisciplinaPrincipal() const { return disciplinaPrincipal; }
};

#endif