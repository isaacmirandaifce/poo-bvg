#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
protected:
    string nome;  
    string id;  

public:
    // Construtor para inicializar as variáveis nome e id
    Usuario(string nome, string id);

    // Método virtual para exibir informações do usuário
    virtual void exibirInformacoes() const;

    // Métodos de acesso para nome e id
    string getNome() const { return nome; }
    string getId() const { return id; }
};

#endif
