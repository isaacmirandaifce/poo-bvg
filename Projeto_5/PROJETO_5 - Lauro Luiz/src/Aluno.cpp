#include "Aluno.h"
#include <iomanip>
#include <numeric>

// Construtor padrão
Aluno::Aluno() : Usuario("", "", "Aluno"), matricula(""), curso("") {}

// Construtor parametrizado
Aluno::Aluno(const std::string& nome, const std::string& email,
             const std::string& matricula, const std::string& curso)
    : Usuario(nome, email, "Aluno"), matricula(matricula), curso(curso) {}

// Destrutor virtual
Aluno::~Aluno() {}

// Métodos getters
std::string Aluno::getMatricula() const {
    return matricula;
}

std::string Aluno::getCurso() const {
    return curso;
}

std::vector<std::string> Aluno::getDisciplinasCursadas() const {
    return disciplinasCursadas;
}

// Métodos setters
void Aluno::setMatricula(const std::string& matricula) {
    this->matricula = matricula;
}

void Aluno::setCurso(const std::string& curso) {
    this->curso = curso;
}

// Métodos para gerenciar disciplinas e notas
void Aluno::adicionarDisciplina(const std::string& disciplina) {
    disciplinasCursadas.push_back(disciplina);
    notas[disciplina] = 0.0; // Inicializa com nota 0
}

void Aluno::adicionarNota(const std::string& disciplina, double nota) {
    if (nota >= 0.0 && nota <= 10.0) {
        notas[disciplina] = nota;
    } else {
        std::cout << "Erro: Nota deve estar entre 0 e 10." << std::endl;
    }
}

double Aluno::obterNota(const std::string& disciplina) const {
    auto it = notas.find(disciplina);
    return (it != notas.end()) ? it->second : -1.0;
}

// Sobrescrita do método virtual puro da classe base
void Aluno::gerarRelatorio() const {
    std::cout << "\n========== RELATÓRIO DO ALUNO ==========\n";
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Matrícula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;

    if (!disciplinasCursadas.empty()) {
        std::cout << "\nDisciplinas Cursadas:" << std::endl;
        for (const auto& disciplina : disciplinasCursadas) {
            auto it = notas.find(disciplina);
            if (it != notas.end()) {
                std::cout << "- " << disciplina << " (Nota: "
                         << std::fixed << std::setprecision(1) << it->second << ")" << std::endl;
            }
        }

        double media = calcularMediaGeral();
        if (media >= 0) {
            std::cout << "\nMédia Geral: " << std::fixed << std::setprecision(2) << media << std::endl;
        }
    } else {
        std::cout << "\nNenhuma disciplina cursada ainda." << std::endl;
    }
    std::cout << "=======================================\n" << std::endl;
}

// Sobrecarga: exibir informações sem notas
void Aluno::exibirInformacoes() const {
    std::cout << "\n--- Informações do Aluno ---" << std::endl;
    Usuario::exibirInformacoes();
    std::cout << "Matrícula: " << matricula << std::endl;
    std::cout << "Curso: " << curso << std::endl;
}

// Sobrecarga: exibir informações com ou sem notas
void Aluno::exibirInformacoes(bool mostrarNotas) const {
    exibirInformacoes(); // Chama a versão sem notas

    if (mostrarNotas && !disciplinasCursadas.empty()) {
        std::cout << "\nNotas:" << std::endl;
        for (const auto& pair : notas) {
            std::cout << "- " << pair.first << ": "
                     << std::fixed << std::setprecision(1) << pair.second << std::endl;
        }

        double media = calcularMediaGeral();
        if (media >= 0) {
            std::cout << "Média Geral: " << std::fixed << std::setprecision(2) << media << std::endl;
        }
    }
}

// Método para calcular média geral
double Aluno::calcularMediaGeral() const {
    if (notas.empty()) return -1.0;

    double soma = 0.0;
    int count = 0;

    for (const auto& pair : notas) {
        soma += pair.second;
        count++;
    }

    return count > 0 ? soma / count : -1.0;
}
