#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include <sstream>

class Aluno {
public:
    int matricula;
    std::string nome;

    // Construtor padrão
    Aluno() : matricula(0), nome("") {}
    
    // Construtor com parâmetros
    Aluno(int matricula, const std::string& nome);

    // Converte o objeto para uma string no formato CSV
    std::string to_csv() const;

    // Cria um objeto a partir de uma string no formato CSV
    static Aluno from_csv(const std::string& csv_line);
};

#endif // ALUNO_H