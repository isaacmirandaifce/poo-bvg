#include "Aluno.h"
#include <iostream>

// Implementação do construtor de Aluno
Aluno::Aluno(std::string nome, std::string email, std::string senha, std::string matricula, std::string curso)
    // Chama o construtor da classe mãe imediata (UsuarioAutenticavel)
    : UsuarioAutenticavel(nome, email, TipoUsuario::ALUNO, senha), matricula(matricula), curso(curso) {
}

// Implementação do método para adicionar ao histórico
void Aluno::adicionarDisciplinaAoHistorico(const std::string& disciplina, int ano, double nota) {
    // Cria um objeto da classe interna e o adiciona ao vetor
    historico.emplace_back(disciplina, ano, nota);
}

// Implementação do método de autenticação
bool Aluno::autenticar(const std::string& senha) {
    // Compara a senha fornecida com a senha armazenada na classe base
    return this->getSenha() == senha;
}

// Implementação do método de relatório
void Aluno::gerarRelatorio() {
    std::cout << "--- Relatorio Academico do Aluno ---" << std::endl;
    std::cout << "Nome: " << this->nome << std::endl;
    std::cout << "Matricula: " << this->matricula << std::endl;
    std::cout << "Curso: " << this->curso << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Historico Disciplinar:" << std::endl;

    if (historico.empty()) {
        std::cout << "Nenhuma disciplina cursada." << std::endl;
    } else {
        for (const auto& disciplina : historico) {
            std::cout << "  - Disciplina: " << disciplina.nomeDisciplina
                      << ", Ano: " << disciplina.anoCursado
                      << ", Nota: " << disciplina.nota << std::endl;
        }
    }
}
