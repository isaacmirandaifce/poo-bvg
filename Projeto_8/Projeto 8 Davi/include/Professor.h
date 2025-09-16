#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <sstream>

class Professor {
    int id;
    std::string nome;
    std::string area;
public:
    Professor() : id(0) {}
    Professor(int id, const std::string& nome, const std::string& area)
        : id(id), nome(nome), area(area) {}

    int getId() const { return id; }
    const std::string& getNome() const { return nome; }
    const std::string& getArea() const { return area; }

    void setId(int v) { id = v; }
    void setNome(const std::string& v) { nome = v; }
    void setArea(const std::string& v) { area = v; }

    std::string toCSV() const {
        std::ostringstream oss;
        oss << id << ';' << nome << ';' << area;
        return oss.str();
    }

    static Professor fromCSV(const std::string& line);
};

#endif // PROFESSOR_H
