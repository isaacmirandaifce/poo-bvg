#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Usuario.hpp"
#include <string>
#include <vector>

class Aluno : virtual public Usuario {
protected:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinasCursadas;
    std::vector<float> notas;

public:
    Aluno();
    Aluno(const std::string& nome, const std::string& email,
          const std::string& matricula, const std::string& curso);

    void adicionarDisciplina(const std::string& disciplina);
    void adicionarNota(float nota);

    void gerarRelatorio() const override;

    // Sobrecarga
    void exibirInformacoes() const;
    void exibirInformacoes(bool mostrarNotas) const;
};

#endif // ALUNO_HPP
