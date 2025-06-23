#include "Professor.h"

Professor::Professor(std::string nome, std::string cpf, std::string senha, std::string departamento)
    : UsuarioAutenticavel(nome, cpf, TipoUsuario::PROFESSOR, senha), departamento(departamento) {}

void Professor::adicionarDisciplinaLecionada(const std::string& disciplina) {
    disciplinasLecionadas.push_back(disciplina);
}

bool Professor::autenticar(const std::string& senhaFornecida) const {
    return this->senha == senhaFornecida;
}

std::string Professor::gerarRelatorio() const {
    std::stringstream ss;
    ss << "===== Relatorio do Professor =====\n";
    ss << "Nome: " << nome << "\n";
    ss << "CPF: " << cpf << "\n";
    ss << "Departamento: " << departamento << "\n";
    ss << "Disciplinas Lecionadas:\n";
    if (disciplinasLecionadas.empty()) {
        ss << "- Nenhuma disciplina atribuida.\n";
    } else {
        for (const auto& d : disciplinasLecionadas) {
            ss << "- " << d << "\n";
        }
    }
    ss << "================================\n";
    return ss.str();
}