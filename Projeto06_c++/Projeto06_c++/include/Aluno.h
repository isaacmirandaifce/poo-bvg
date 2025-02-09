#ifndef ALUNO_H
#define ALUNO_H

#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include "TipoUsuario.h"
#include <vector>
#include <string>

class Aluno : public UsuarioAutenticavel, public Relatorio {
public:
    class HistoricoDisciplinar {
    private:
        std::string nomeDisciplina;
        int anoCursado;
        float nota;

    public:
        HistoricoDisciplinar(const std::string& nomeDisciplina, int anoCursado, float nota)
            : nomeDisciplina(nomeDisciplina), anoCursado(anoCursado), nota(nota) {}
        
        void exibirHistorico() const;
    };

private:
    std::string matricula;
    std::string curso;
    std::vector<HistoricoDisciplinar> historico;

public:
    // Construtores
    Aluno();
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula, const std::string& curso, const std::string& senha);

    // Métodos
    bool autenticar(const std::string& senha) const override;
    void gerarRelatorio() const override;
    void adicionarHistorico(const HistoricoDisciplinar& historico);
};

#endif // ALUNO_H
