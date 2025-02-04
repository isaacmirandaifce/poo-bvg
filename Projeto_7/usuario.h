#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
protected:
    string nome;
    string id;

public:
    Usuario(string nome, string id);
    virtual void exibirInformacoes() const;
    
    string getNome() const { return nome; }
    string getId() const { return id; }
};

#endif // USUARIO_H
