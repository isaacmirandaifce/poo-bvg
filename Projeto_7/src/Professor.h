#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <string>
#include "Usuario.h"
#include <vector>
class Professor : public Usuario {
public:
    std::vector<std::string> disciplinasMinistradas;
    Professor(std::string n, std::string e): Usuario(n,e) {}
};
#endif
