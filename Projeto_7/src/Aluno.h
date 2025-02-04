#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Disciplina.h"
#include <vector>

class Aluno : public UsuarioAutenticavel {
private:
    std::string matricula;
    std::string curso;

    class HistoricoDisciplinar {
    private:
        std::string nomeDisciplina;
        int ano;
        float nota;

    public:
        HistoricoDisciplinar(const std::string& nomeDisciplina, int ano, float nota);
        std::string getDetalhes() const;
    };

    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula, 
          const std::string& curso, const std::string& senha);
    
    void adicionarDisciplina(const std::string& disciplina);
    void adicionarHistorico(const std::string& disciplina, int ano, double nota);
    double calcularMedia() const;
    std::vector<std::string> getDisciplinasPorAno(int ano) const;
    void gerarRelatorio() const override;
    bool autenticar(const std::string& senhaTentativa) const override;
};

#endif
