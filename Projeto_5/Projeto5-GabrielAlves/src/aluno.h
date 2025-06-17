#ifndef ALUNO_H
#define ALUNO_H

#include "Usuario.h"
#include <vector>

// Herda virtualmente de Usuario para evitar problemas de herança múltipla na classe Monitor.
class Aluno : public virtual Usuario {
private:
    std::string matricula;
    std::string curso;
    std::vector<std::string> disciplinasCursadas;

public:
    // Construtor
    Aluno(std::string nome, std::string email, std::string matricula, std::string curso);

    // Sobrescrita do método virtual puro da classe base. 
    void gerarRelatorio() const override;

    // Método sobrecarregado para exibir informações detalhadas. 
    // Versão 1: sem notas.
    void exibirInformacoesDetalhadas() const;
    // Versão 2: com notas.
    void exibirInformacoesDetalhadas(bool comNotas) const;
    
    // Método para adicionar disciplina para o aluno
    void adicionarDisciplina(std::string disciplina);
};

#endif // ALUNO_H