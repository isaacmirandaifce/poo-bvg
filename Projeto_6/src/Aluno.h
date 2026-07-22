#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

class Aluno : public UsuarioAutenticavel, public Relatorio {
public:
    // Classe interna: encapsula o historico de uma disciplina cursada pelo aluno.
    class HistoricoDisciplinar {
    private:
        std::string disciplina;
        int ano;
        double nota;

    public:
        HistoricoDisciplinar();
        HistoricoDisciplinar(std::string disciplina, int ano, double nota);

        std::string getDisciplina() const;
        int getAno() const;
        double getNota() const;

        void exibir() const;
    };

private:
    std::string matricula;
    std::string curso;
    std::vector<HistoricoDisciplinar> historico;

public:
    Aluno();
    Aluno(std::string nome, std::string email, const std::string& senha,
          std::string matricula, std::string curso);

    void adicionarHistorico(const std::string& disciplina, int ano, double nota);

    // Sobrescrita: implementacao do metodo abstrato herdado de UsuarioAutenticavel
    bool autenticar(std::string senha) override;

    // Sobrescrita: implementacao do metodo virtual puro da interface Relatorio
    void gerarRelatorio() const override;

    // Sobrecarga: mesma acao, assinaturas diferentes
    void exibirInformacoes() const;               // sem historico
    void exibirInformacoes(bool comHistorico) const; // com historico, se solicitado
};

#endif // ALUNO_H
