#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Aluno : public UsuarioAutenticavel, public Relatorio {
public:
    class HistoricoDisciplinar {
    public:
        std::string nomeDisciplina;
        int anoCursado;
        double nota;

        HistoricoDisciplinar(std::string disciplina, int ano, double nota)
            : nomeDisciplina(disciplina), anoCursado(ano), nota(nota) {}
    };

private:
    std::string matricula;
    std::string curso;
    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno(std::string nome, std::string email, std::string senha, std::string matricula, std::string curso);
    void adicionarDisciplinaAoHistorico(const std::string& disciplina, int ano, double nota);

    // Getters
    const std::string& getMatricula() const;
    const std::string& getCurso() const;
    const std::vector<HistoricoDisciplinar>& getHistorico() const;
    double getMediaGeral() const;

    // Overrides
    bool autenticar(const std::string& senha) override;
    void gerarRelatorio() override;
};

#endif // ALUNO_H
