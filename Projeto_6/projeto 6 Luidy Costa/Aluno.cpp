#include "Aluno.h"

using namespace std;

Aluno::Aluno(string nome, string email, string senha, string matricula)
    : UsuarioAutenticavel(nome, email, TipoUsuario::ALUNO, senha), matricula(matricula) {}

void Aluno::adicionarDisciplina(string disciplina, int ano, float nota) {
    // Instanciando a classe interna e adicionando ao vetor
    historico.push_back(HistoricoDisciplinar(disciplina, ano, nota));
}

bool Aluno::autenticar(string senhaDigitada) {
    return this->senha == senhaDigitada;
}

void Aluno::gerarRelatorio() const {
    cout << "=== Relatorio de Aluno ===" << endl;
    cout << "Nome: " << nome << " | Matricula: " << matricula << endl;
    cout << "Historico Academico:" << endl;

    if (historico.empty()) {
        cout << "- Nenhuma disciplina cursada." << endl;
    } else {
        for (const auto& h : historico) {
            cout << "  * " << h.disciplina << " (" << h.ano << ") - Nota: " << h.nota << endl;
        }
    }
    cout << "==========================" << endl;
}
