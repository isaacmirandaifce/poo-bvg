#ifndef ALUNO_H
#define ALUNO_H
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"
#include <vector>

class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
    string matricula, curso;
    
    // Classe interna para o histórico de disciplinas
    class HistoricoDisciplinar {
    public:
        string nomeDisciplina;
        int ano;
        float nota;
        
        HistoricoDisciplinar(string nome, int ano, float nota)
            : nomeDisciplina(nome), ano(ano), nota(nota) {}
    };

    vector<HistoricoDisciplinar> historico;

public:
    Aluno(string n, string e, string s, string m, string c);
    
    void gerarRelatorio() const override;
    bool autenticar(string s) const override;
    void adicionarDisciplina(const string& nome, int ano, float nota);
    float calcularMedia() const;
};

#endif // ALUNO_H
