#include "Aluno.h"

Aluno::Aluno(string n, string e, string s, string m, string c)
    : UsuarioAutenticavel(n, e, s, TipoUsuario::ALUNO), matricula(m), curso(c) {}

bool Aluno::autenticar(string s) const {
    return senha == s;
}

void Aluno::gerarRelatorio() const {
    cout << "Aluno: " << nome << " - Matricula: " << matricula << " - Curso: " << curso << endl;
    cout << "Disciplinas cursadas:" << endl;
    
    for (const auto& disciplina : historico) {
        cout << disciplina.nomeDisciplina << " - Ano: " << disciplina.ano << " - Nota: " << disciplina.nota << endl;
    }
}

void Aluno::adicionarDisciplina(const string& nome, int ano, float nota) {
    historico.emplace_back(nome, ano, nota);
}

float Aluno::calcularMedia() const {
    if (historico.empty()) return 0.0;

    float soma = 0.0;
    for (const auto& disciplina : historico) {
        soma += disciplina.nota;
    }
    return soma / historico.size();
}
