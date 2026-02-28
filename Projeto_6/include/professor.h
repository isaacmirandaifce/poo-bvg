#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include <vector>
#include <string>

// Classe derivada Professor
class Professor : public UsuarioAutenticavel {
private:
    std::string areaDeAtuacao;
    std::vector<std::string> disciplinasMinistradas;

public:
    // Construtores
    Professor();
    Professor(const std::string nome, const std::string email, TipoUsuario tipo, std::string senha, const std::string areaDeAtuacao);

    // Método para adicionar uma disciplina ministrada
    void adicionarDisciplina(const std::string& disciplina);
    

    // Sobrescrita de gerarRelatorio
    void gerarRelatorio() const override;
    bool autenticar(const std::string& senha) const override;
};

#endif // PROFESSOR_H
