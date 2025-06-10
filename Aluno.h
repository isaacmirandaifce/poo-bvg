#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <string>
#include <vector>
#include <iostream>

class Aluno : public Usuario {
private:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinasCursadas;
    std::vector<float> notas; // Para sobrecarga com notas

public:
    Aluno();
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula,
          const std::string& curso, const std::vector<std::string>& disciplinas);

    void gerarRelatorio() const override;

    // Sobrecarga: com notas
    void gerarRelatorio(const std::vector<float>& notas) const;
};

#endif // ALUNO_H
