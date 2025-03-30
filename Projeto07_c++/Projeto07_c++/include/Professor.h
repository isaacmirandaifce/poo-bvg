#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include <vector>
#include <string>

class Professor : public UsuarioAutenticavel  {
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    // Construtores
    Professor();
    Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao);
    Professor(const std::string& nome, const std::string& email, const std::string& areaDeAtuacao, const std::string& senha);

    // Métodos
    void gerarRelatorio() const override;
    void adicionarDisciplina(const std::string& disciplina);
    bool autenticar(const std::string& senha) const override;
    bool ministraDisciplina(const std::string& disciplina) const;

    // Getters
    const std::vector<std::string>& getDisciplinasMinistradas() const;
    std::string getNome() const;
};

#endif // PROFESSOR_H
