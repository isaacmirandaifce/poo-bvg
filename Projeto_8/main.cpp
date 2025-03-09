#include <iostream>
#include "Persistencia.h"
#include "SinalHandler.h"
#include "Aluno.h"
#include "Disciplina.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

using namespace std;

int main() {
    SinalHandler::inicializar();

    try {
        // Carregar dados do sistema
        vector<Aluno> alunos = Persistencia::carregarAlunos();
        vector<Disciplina> disciplinas = Persistencia::carregarDisciplinas();
        vector<Professor> professores = Persistencia::carregarProfessores();

        // Exemplo de exibição dos dados carregados
        cout << "Alunos carregados:" << endl;
        for (const auto& aluno : alunos) {
            aluno.exibirInformacoes();
        }

        cout << "\nDisciplinas carregadas:" << endl;
        for (const auto& disciplina : disciplinas) {
            cout << disciplina.getNome() << " - Nota: " << disciplina.getNota() << endl;
        }

        cout << "\nProfessores carregados:" << endl;
        for (const auto& professor : professores) {
            professor.exibirInformacoes();
        }

        // Exemplo de alteração (adicionar novo aluno)
        Aluno novoAluno("Maria Oliveira", "202510003", "Engenharia de Software");
        alunos.push_back(novoAluno);
        Persistencia::salvarAlunos(alunos);  // Salvando os dados atualizados

        // Exemplo de adição de nova disciplina
        Disciplina novaDisciplina("Algoritmos Avançados", 60, 8.5);
        disciplinas.push_back(novaDisciplina);
        Persistencia::salvarDisciplinas(disciplinas);  // Salvando as disciplinas atualizadas

        // Exemplo de adição de novo professor
        Professor novoProfessor("Carlos Silva", "P003", "Algoritmos Avançados");
        professores.push_back(novoProfessor);
        Persistencia::salvarProfessores(professores);  // Salvando os professores atualizados

    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}
