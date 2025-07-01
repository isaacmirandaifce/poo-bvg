#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include <iostream>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Aluno : public UsuarioAutenticavel, public Relatorio {
public:
    // Classe Interna: encapsula os detalhes do histórico do aluno.
    // Só faz sentido no contexto de um Aluno.
    class HistoricoDisciplinar {
    private:
        std::string nomeDisciplina;
        int anoCursado;
        float nota;
    
    public:
        HistoricoDisciplinar(std::string nome, int ano, float nota);
        void exibir() const;
    };

private:
    std::string curso;
    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(int id, std::string nome, std::string senha, std::string curso);

    // Implementação dos métodos herdados
    bool autenticar(const std::string& senha) const override;
    void gerarRelatorio() const override;

    // Métodos específicos do Aluno
    void adicionarDisciplina(const std::string& nome, int ano, float nota);
};

#endif // ALUNO_H