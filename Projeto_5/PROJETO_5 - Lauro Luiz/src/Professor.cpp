#include "Professor.h"
#include <algorithm>

// Construtor padrão
Professor::Professor() : Usuario("", "", "Professor"), areaDeAtuacao("") {}

// Construtor parametrizado
Professor::Professor(const std::string& nome, const std::string& email,
                     const std::string& areaDeAtuacao)
    : Usuario(nome, email, "Professor"), areaDeAtuacao(areaDeAtuacao) {}

// Destrutor virtual
Professor::~Professor() {}

// Métodos getters
std::string Professor::getAreaDeAtuacao() const {
    return areaDeAtuacao;
}

std::vector<std::string> Professor::getDisciplinasMinistradas() const {
    return disciplinasMinistradas;
}

// Métodos setters
void Professor::setAreaDeAtuacao(const std::string& areaDeAtuacao) {
    this->areaDeAtuacao = areaDeAtuacao;
}

// Métodos para gerenciar disciplinas
void Professor::adicionarDisciplinaMinistrada(const std::string& disciplina) {
    // Verifica se a disciplina já não foi adicionada
    if (!ministraDisciplina(disciplina)) {
        disciplinasMinistradas.push_back(disciplina);
        std::cout << "Disciplina '" << disciplina << "' adicionada com sucesso." << std::endl;
    } else {
        std::cout << "Disciplina '" << disciplina << "' já está sendo ministrada." << std::endl;
    }
}

void Professor::removerDisciplinaMinistrada(const std::string& disciplina) {
    auto it = std::find(disciplinasMinistradas.begin(), disciplinasMinistradas.end(), disciplina);
    if (it != disciplinasMinistradas.end()) {
        disciplinasMinistradas.erase(it);
        std::cout << "Disciplina '" << disciplina << "' removida com sucesso." << std::endl;
    } else {
        std::cout << "Disciplina '" << disciplina << "' não encontrada." << std::endl;
    }
}

bool Professor::ministraDisciplina(const std::string& disciplina) const {
    return std::find(disciplinasMinistradas.begin(), disciplinasMinistradas.end(),
                     disciplina) != disciplinasMinistradas.end();
}

// Sobrescrita do método virtual puro da classe base
void Professor::gerarRelatorio() const {
    std::cout << "\n========== RELATÓRIO DO PROFESSOR ==========\n";
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Área de Atuação: " << areaDeAtuacao << std::endl;

    if (!disciplinasMinistradas.empty()) {
        std::cout << "\nDisciplinas Ministradas (" << disciplinasMinistradas.size() << "):" << std::endl;
        for (size_t i = 0; i < disciplinasMinistradas.size(); ++i) {
            std::cout << (i + 1) << ". " << disciplinasMinistradas[i] << std::endl;
        }
    } else {
        std::cout << "\nNenhuma disciplina sendo ministrada atualmente." << std::endl;
    }
    std::cout << "==========================================\n" << std::endl;
}

// Sobrescrita do método exibirInformacoes
void Professor::exibirInformacoes() const {
    std::cout << "\n--- Informações do Professor ---" << std::endl;
    Usuario::exibirInformacoes();
    std::cout << "Área de Atuação: " << areaDeAtuacao << std::endl;
    std::cout << "Número de disciplinas: " << disciplinasMinistradas.size() << std::endl;
}

// Método específico para contar disciplinas
int Professor::contarDisciplinasMinistradas() const {
    return static_cast<int>(disciplinasMinistradas.size());
}
