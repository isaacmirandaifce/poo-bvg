#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Usuario.hpp"
#include <string>
#include <vector>

class Professor : virtual public Usuario {
protected:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor();
    Professor(const std::string& nome, const std::string& email,
              const std::string& areaDeAtuacao);

    void adicionarDisciplina(const std::string& disciplina);
    void gerarRelatorio() const override;

    std::string getAreaDeAtuacao() const;
};

#endif // PROFESSOR_HPP
