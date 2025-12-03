#ifndef ALUNO_H
#define ALUNO_H

#include "usuario.h"
#include <vector>


// Declaração da classe Aluno que herda de Usuario
class Aluno : virtual public Usuario {
protected:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinas;

    // Outros atributos específicos de Aluno podem ser adicionados aqui
public:
    Aluno();
    Aluno(std::string nome, std::string email, std::string matricula, std::string curso);

    void adicionarDisciplina(std::string d);

    // SOBRESCRITA
    void gerarRelatorio() const override;

    // SOBRECARGA (exibir com ou sem notas)
    void exibirInfo() const;
    void exibirInfo(bool mostrarNotas) const;
};

#endif
