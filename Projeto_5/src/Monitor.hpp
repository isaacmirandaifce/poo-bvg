#ifndef MONITOR_HPP
#define MONITOR_HPP

#include "Aluno.hpp"
#include "Professor.hpp"
#include <vector>
#include <string>

class Monitor : public Aluno, public Professor {
private:
    std::vector<std::string> disciplinasMonitoradas;

public:
    Monitor();
    Monitor(const std::string& nome, const std::string& email,
            const std::string& matricula, const std::string& curso,
            const std::string& areaDeAtuacao);

    void adicionarDisciplinaAluno(const std::string& disciplina);
    void adicionarDisciplinaProfessor(const std::string& disciplina);

    void adicionarDisciplinaMonitorada(const std::string& disciplina);
    void listarDisciplinasMonitoradas() const;

    void gerarRelatorio() const override;
};

#endif // MONITOR_HPP
