#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <vector>

class Professor {
private:
    std::string nome;
    std::string departamento;
    std::vector<std::string> disciplinasLecionadas;

public:
    Professor(const std::string& nome, const std::string& departamento);

    std::string getNome() const;
    std::string getDepartamento() const;
    void adicionarDisciplinaLecionada(const std::string& disciplina);
    const std::vector<std::string>& getDisciplinasLecionadas() const;

    void imprimir() const;
};

#endif