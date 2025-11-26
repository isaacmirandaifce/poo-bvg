#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"

class Monitor : public Aluno, public Professor {
private:
    vector<string> disciplinasMonitoradas;

public:
    Monitor();
    // Construtor que chama ambos os construtores base (aluno e professor) - simplificado
    Monitor(const string &nome, const string &email, const string &matricula, const string &curso, const string &area);

    ~Monitor();

    void adicionarDisciplinaMonitorada(const string &disciplina);
    void listarDisciplinasMonitoradas() const;

    // precisamos providenciar um gerarRelatorio que escolha qual versão exibir (ex.: combinar)
    void gerarRelatorio() const override;
};

#endif // MONITOR_H