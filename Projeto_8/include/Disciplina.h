#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

class Disciplina {
public:
    Disciplina(int id, const std::string& nome, int professorId);
    int getId() const;
    std::string getNome() const;
    int getProfessorId() const;

private:
    int id;
    std::string nome;
    int professorId;
};

#endif // DISCIPLINA_H