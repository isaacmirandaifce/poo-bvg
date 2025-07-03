#ifndef MONITOR_H
#define MONITOR_H

#include "../Aluno/Aluno.h"
#include "../Professor/Professor.h"
#include "../Usuarios/TipoUsuario.h"

class Monitor : public Aluno, public Professor {
private:
    TipoUsuario tipoUsuario;

public:
    Monitor();
    Monitor(string nome, string email, string tipo, string senha,
            string matricula, string curso, vector<string> disciplinasAluno,
            string areaDeAtuacao, vector<string> disciplinasMinistradas);

    void gerarRelatorio() const override;
    bool autenticar(string senhaTentativa) override;
};

#endif