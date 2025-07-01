#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <string>
#include <vector>

class Professor : public UsuarioAutenticavel, public Relatorio {
private:
    std::string departamento;
    std::vector<std::string> disciplinasLecionadas;

public:
    Professor(int id, std::string nome, std::string senha, std::string departamento);

    // Implementação dos métodos herdados
    bool autenticar(const std::string& senha) const override;
    void gerarRelatorio() const override;
    
    void adicionarDisciplina(const std::string& disciplina);
};

#endif // PROFESSOR_H