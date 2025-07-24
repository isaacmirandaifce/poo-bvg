#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "../Usuarios/UsuarioAutenticavel.h"
#include "../Relatorio/Relatorio.h"
#include "../Usuarios/TipoUsuario.h"
#include <vector>

class Professor : public virtual UsuarioAutenticavel, public virtual Relatorio {
protected:
    string areaDeAtuacao;
    vector<string> disciplinasMinistradas;
    TipoUsuario tipoUsuario;

public:
    Professor();
    Professor(string nome, string email, string tipo, string senha, string areaDeAtuacao, vector<string> disciplinasMinistradas);

    void gerarRelatorio() const override;
    bool autenticar(string senhaTentativa) override;

    // Métodos para filtragem
    string getNome() const;
    string getAreaDeAtuacao() const;
    vector<string> getDisciplinasMinistradas() const;
    bool ministraDisciplina(const string& disciplina) const;
};

#endif