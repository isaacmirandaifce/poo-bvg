#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <sstream>

class Aluno {
    int id;
    std::string nome;
    std::string curso;
public:
    Aluno() : id(0) {}
    Aluno(int id, const std::string& nome, const std::string& curso)
        : id(id), nome(nome), curso(curso) {}

    int getId() const { return id; }
    const std::string& getNome() const { return nome; }
    const std::string& getCurso() const { return curso; }

    void setId(int v) { id = v; }
    void setNome(const std::string& v) { nome = v; }
    void setCurso(const std::string& v) { curso = v; }

    std::string toCSV() const {
        std::ostringstream oss;
        oss << id << ';' << nome << ';' << curso;
        return oss.str();
    }

    static Aluno fromCSV(const std::string& line);
};

#endif // ALUNO_H
