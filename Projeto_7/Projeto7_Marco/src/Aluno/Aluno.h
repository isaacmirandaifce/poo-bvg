#ifndef ALUNO_H
#define ALUNO_H

#include "../Usuarios/UsuarioAutenticavel.h"
#include "../Relatorio/Relatorio.h"
#include "../Usuarios/TipoUsuario.h"
#include <vector>

class Aluno : public virtual UsuarioAutenticavel, public virtual Relatorio {
protected:
    string matricula;
    string curso;
    vector<string> disciplinas;
    TipoUsuario tipoUsuario;

    class HistoricoDisciplinar {
    public:
        string disciplina;
        int ano;
        float nota;

        HistoricoDisciplinar(string disciplina, int ano, float nota);
        void exibir() const;
        float getNota() const;
    };

    vector<HistoricoDisciplinar> historico;

public:
    Aluno();
    Aluno(string nome, string email, string tipo, string senha, string matricula, string curso, vector<string> disciplinas);

    void gerarRelatorio() const override;
    bool autenticar(string senhaTentativa) override;

    void adicionarDisciplinaAoHistorico(string disciplina, int ano, float nota);

    // Métodos auxiliares para filtragem/ordenação
    float getMedia() const;
    string getNome() const;
    string getMatricula() const;
    string getCurso() const;
};

#endif