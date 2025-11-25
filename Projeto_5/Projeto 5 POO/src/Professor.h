#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <vector>
#include "Usuario.h"

class Professor : virtual public Usuario {
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    Professor();
    Professor(const std::string& nome,
              const std::string& email,
              const std::string& areaDeAtuacao,
              const std::vector<std::string>& disciplinas);

    void gerarRelatorio() const override;
    void adicionarDisciplinaMinistrada(const std::string& nomeDisciplina);
};

#endif // PROFESSOR_H
