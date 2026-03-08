#include "Aluno.h"

Aluno::Aluno(std::string nome, std::string email, std::string senha)
    : UsuarioAutenticavel(nome, email, TipoUsuario::ALUNO, senha) {}

bool Aluno::autenticar(std::string senha) const {
    return this->senha == senha;
}

void Aluno::adicionarDisciplina(std::string disciplina, int ano, float nota) {
    historico.emplace_back(disciplina, ano, nota);
}

void Aluno::gerarRelatorio() const {
    std::cout << "Relatorio do Aluno\n";
    std::cout << "Nome: " << nome << "\nEmail: " << email << "\n";
    std::cout << "Historico:\n";
    for (const auto& item : historico) item.exibir();
}

float Aluno::calcularMedia() const {
    if (historico.empty()) return 0.0f;
    float soma = 0.0f;
    for (const auto& h : historico) soma += h.getNota();
    return soma / static_cast<float>(historico.size());
}

const std::vector<Aluno::HistoricoDisciplinar>& Aluno::getHistorico() const {
    return historico;
}
