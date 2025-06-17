#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"

// Classe Monitor herda de Aluno e Professor (Herança Múltipla). 
class Monitor : public Aluno, public Professor {
private:
    std::vector<std::string> disciplinasMonitoradas;

public:
    // Construtor precisa inicializar a classe base única Usuario e as classes intermediárias Aluno e Professor.
    Monitor(std::string nome, std::string email, std::string matricula, std::string curso, std::string areaAtuacao);
    
    void adicionarDisciplinaMonitorada(std::string disciplina);
    
    // Método específico da classe Monitor. 
    void listarDisciplinasMonitoradas() const;

    // Sobrescreve gerarRelatorio para fornecer uma visão consolidada.
    void gerarRelatorio() const override;
};

#endif // MONITOR_H