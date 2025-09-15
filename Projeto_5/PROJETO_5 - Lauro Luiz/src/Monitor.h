#ifndef MONITOR_H
#define MONITOR_H

#include "Aluno.h"
#include "Professor.h"
#include <vector>

/**
 * Classe Monitor - Herança Múltipla
 * Representa um aluno que também atua como monitor de disciplinas
 * Herda tanto de Aluno quanto de Professor
 */
class Monitor : public Aluno, public Professor {
private:
    std::vector<std::string> disciplinasMonitoradas;
    std::string turno; // Manhã, Tarde, Noite
    int horasSemanais;

public:
    // Construtor padrão
    Monitor();

    // Construtor parametrizado
    Monitor(const std::string& nome, const std::string& email,
            const std::string& matricula, const std::string& curso,
            const std::string& areaDeAtuacao, const std::string& turno);

    // Destrutor virtual
    virtual ~Monitor();

    // Métodos getters específicos do Monitor
    std::vector<std::string> getDisciplinasMonitoradas() const;
    std::string getTurno() const;
    int getHorasSemanais() const;

    // Métodos setters específicos do Monitor
    void setTurno(const std::string& turno);
    void setHorasSemanais(int horas);

    // Métodos específicos para gerenciar monitorias
    void adicionarDisciplinaMonitorada(const std::string& disciplina);
    void removerDisciplinaMonitorada(const std::string& disciplina);
    bool monitoraDisciplina(const std::string& disciplina) const;
    void listarDisciplinasMonitoradas() const;

    // Sobrescrita do método gerarRelatorio (resolve ambiguidade de herança múltipla)
    virtual void gerarRelatorio() const override;

    // Sobrescrita do método exibirInformacoes (resolve ambiguidade)
    void exibirInformacoes() const;

    // Método específico para exibir relatório de monitoria
    void gerarRelatorioMonitoria() const;

    // Método para calcular bolsa de monitoria
    double calcularBolsaMonitoria() const;

    // Método para verificar disponibilidade de horário
    bool verificarDisponibilidade(const std::string& horario) const;
};

#endif // MONITOR_H
