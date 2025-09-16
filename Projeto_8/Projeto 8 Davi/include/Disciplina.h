#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <sstream>

class Disciplina {
    int codigo; // inteiro para simplificar
    std::string nome;
    int cargaHoraria;
public:
    Disciplina() : codigo(0), cargaHoraria(0) {}
    Disciplina(int codigo, const std::string& nome, int cargaHoraria)
        : codigo(codigo), nome(nome), cargaHoraria(cargaHoraria) {}

    int getCodigo() const { return codigo; }
    const std::string& getNome() const { return nome; }
    int getCargaHoraria() const { return cargaHoraria; }

    void setCodigo(int v) { codigo = v; }
    void setNome(const std::string& v) { nome = v; }
    void setCargaHoraria(int v) { cargaHoraria = v; }

    std::string toCSV() const {
        std::ostringstream oss;
        oss << codigo << ';' << nome << ';' << cargaHoraria;
        return oss.str();
    }

    static Disciplina fromCSV(const std::string& line);
};

#endif // DISCIPLINA_H
