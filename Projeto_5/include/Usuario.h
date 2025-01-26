#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
protected:
    string nome;
    string email;
    string tipo;

public:
    // Construtor padrão e parametrizado
    Usuario(const string& nome = "", const string& email = "", const string& tipo = "Usuario");
    virtual ~Usuario() = default;

    // Método virtual puro
    virtual void gerarRelatorio() const = 0; // Sobrescrito nas classes derivadas
};

#endif
