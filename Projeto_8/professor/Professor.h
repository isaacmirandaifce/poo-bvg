#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>

class Professor {
private:
    std::string nome;        
    std::string id;         
    std::string disciplina;  

public:
    // Construtor que inicializa as variáveis membro
    Professor(std::string nome, std::string id, std::string disciplina);

    // Exibe as informações do professor
    void exibirInformacoes() const;

    // Métodos de acesso para obter os dados do professor
    std::string getNome() const { return nome; }
    std::string getId() const { return id; }
    std::string getDisciplina() const { return disciplina; }
};

#endif
