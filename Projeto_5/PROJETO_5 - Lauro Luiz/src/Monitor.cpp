#include "Monitor.h"
#include <algorithm>
#include <iomanip>

// Construtor padrão
Monitor::Monitor() : Usuario(), Aluno(), Professor(), turno(""), horasSemanais(0) {
    // Resolve ambiguidade definindo tipo como "Monitor"
    Usuario::setTipo("Monitor");
}

// Construtor parametrizado
Monitor::Monitor(const std::string& nome, const std::string& email,
                 const std::string& matricula, const std::string& curso,
                 const std::string& areaDeAtuacao, const std::string& turno)
    : Usuario(nome, email, "Monitor"),
      Aluno(nome, email, matricula, curso),
      Professor(nome, email, areaDeAtuacao),
      turno(turno), horasSemanais(12) { // 12 horas padrão para monitoria
}

// Destrutor virtual
Monitor::~Monitor() {}

// Métodos getters específicos do Monitor
std::vector<std::string> Monitor::getDisciplinasMonitoradas() const {
    return disciplinasMonitoradas;
}

std::string Monitor::getTurno() const {
    return turno;
}

int Monitor::getHorasSemanais() const {
    return horasSemanais;
}

// Métodos setters específicos do Monitor
void Monitor::setTurno(const std::string& turno) {
    this->turno = turno;
}

void Monitor::setHorasSemanais(int horas) {
    if (horas >= 0 && horas <= 20) { // Máximo de 20 horas por semana
        this->horasSemanais = horas;
    } else {
        std::cout << "Erro: Horas semanais deve estar entre 0 e 20." << std::endl;
    }
}

// Métodos específicos para gerenciar monitorias
void Monitor::adicionarDisciplinaMonitorada(const std::string& disciplina) {
    if (!monitoraDisciplina(disciplina)) {
        disciplinasMonitoradas.push_back(disciplina);
        std::cout << "Disciplina '" << disciplina << "' adicionada à monitoria." << std::endl;
    } else {
        std::cout << "Disciplina '" << disciplina << "' já está sendo monitorada." << std::endl;
    }
}

void Monitor::removerDisciplinaMonitorada(const std::string& disciplina) {
    auto it = std::find(disciplinasMonitoradas.begin(), disciplinasMonitoradas.end(), disciplina);
    if (it != disciplinasMonitoradas.end()) {
        disciplinasMonitoradas.erase(it);
        std::cout << "Disciplina '" << disciplina << "' removida da monitoria." << std::endl;
    } else {
        std::cout << "Disciplina '" << disciplina << "' não encontrada na monitoria." << std::endl;
    }
}

bool Monitor::monitoraDisciplina(const std::string& disciplina) const {
    return std::find(disciplinasMonitoradas.begin(), disciplinasMonitoradas.end(),
                     disciplina) != disciplinasMonitoradas.end();
}

void Monitor::listarDisciplinasMonitoradas() const {
    std::cout << "\n--- Disciplinas Monitoradas ---" << std::endl;
    if (disciplinasMonitoradas.empty()) {
        std::cout << "Nenhuma disciplina sendo monitorada." << std::endl;
    } else {
        for (size_t i = 0; i < disciplinasMonitoradas.size(); ++i) {
            std::cout << (i + 1) << ". " << disciplinasMonitoradas[i] << std::endl;
        }
    }
}

// Sobrescrita do método gerarRelatorio (resolve ambiguidade de herança múltipla)
void Monitor::gerarRelatorio() const {
    std::cout << "\n========== RELATÓRIO DO MONITOR ==========\n";
    std::cout << "Nome: " << Aluno::getNome() << std::endl; // Usa explicitamente de Aluno
    std::cout << "Email: " << Aluno::getEmail() << std::endl;
    std::cout << "Matrícula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
    std::cout << "Área de Atuação: " << areaDeAtuacao << std::endl;
    std::cout << "Turno: " << turno << std::endl;
    std::cout << "Horas Semanais: " << horasSemanais << "h" << std::endl;

    // Informações acadêmicas como aluno
    if (!disciplinasCursadas.empty()) {
        std::cout << "\nDisciplinas Cursadas (como aluno):" << std::endl;
        for (const auto& disciplina : disciplinasCursadas) {
            std::cout << "- " << disciplina << std::endl;
        }
    }

    // Informações de monitoria
    if (!disciplinasMonitoradas.empty()) {
        std::cout << "\nDisciplinas Monitoradas:" << std::endl;
        for (size_t i = 0; i < disciplinasMonitoradas.size(); ++i) {
            std::cout << (i + 1) << ". " << disciplinasMonitoradas[i] << std::endl;
        }

        double bolsa = calcularBolsaMonitoria();
        std::cout << "\nBolsa de Monitoria: R$ " << std::fixed << std::setprecision(2) << bolsa << std::endl;
    }

    std::cout << "=========================================\n" << std::endl;
}

// Sobrescrita do método exibirInformacoes (resolve ambiguidade)
void Monitor::exibirInformacoes() const {
    std::cout << "\n--- Informações do Monitor ---" << std::endl;
    std::cout << "Nome: " << Aluno::getNome() << std::endl;
    std::cout << "Email: " << Aluno::getEmail() << std::endl;
    std::cout << "Tipo: Monitor" << std::endl;
    std::cout << "Matrícula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
    std::cout << "Área de Atuação: " << areaDeAtuacao << std::endl;
    std::cout << "Turno: " << turno << std::endl;
    std::cout << "Horas Semanais: " << horasSemanais << "h" << std::endl;
    std::cout << "Disciplinas Monitoradas: " << disciplinasMonitoradas.size() << std::endl;
}

// Método específico para exibir relatório de monitoria
void Monitor::gerarRelatorioMonitoria() const {
    std::cout << "\n========== RELATÓRIO DE MONITORIA ==========\n";
    std::cout << "Monitor: " << Aluno::getNome() << std::endl;
    std::cout << "Matrícula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
    std::cout << "Turno de Trabalho: " << turno << std::endl;
    std::cout << "Carga Horária Semanal: " << horasSemanais << " horas" << std::endl;

    if (!disciplinasMonitoradas.empty()) {
        std::cout << "\nAtividades de Monitoria:" << std::endl;
        for (size_t i = 0; i < disciplinasMonitoradas.size(); ++i) {
            std::cout << "• " << disciplinasMonitoradas[i] << std::endl;
            std::cout << "  - Auxílio em exercícios" << std::endl;
            std::cout << "  - Esclarecimento de dúvidas" << std::endl;
            std::cout << "  - Suporte em práticas" << std::endl;
        }

        std::cout << "\nRemuneração:" << std::endl;
        double bolsa = calcularBolsaMonitoria();
        std::cout << "Valor da Bolsa: R$ " << std::fixed << std::setprecision(2) << bolsa << "/mês" << std::endl;
        std::cout << "Valor por Hora: R$ " << std::fixed << std::setprecision(2) << (bolsa / (horasSemanais * 4)) << std::endl;
    }

    std::cout << "==========================================\n" << std::endl;
}

// Método para calcular bolsa de monitoria
double Monitor::calcularBolsaMonitoria() const {
    const double valorPorHora = 15.0; // R$ 15 por hora
    const int semanasPorMes = 4;
    return horasSemanais * valorPorHora * semanasPorMes;
}

// Método para verificar disponibilidade de horário
bool Monitor::verificarDisponibilidade(const std::string& horario) const {
    // Simulação simples de verificação de disponibilidade
    if (turno == "Manhã") {
        return (horario >= "07:00" && horario <= "12:00");
    } else if (turno == "Tarde") {
        return (horario >= "13:00" && horario <= "18:00");
    } else if (turno == "Noite") {
        return (horario >= "19:00" && horario <= "22:00");
    }
    return false;
}
