#include <iostream>
#include <vector>
#include "Usuario.h"
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

using namespace std;

int main() {
    cout << "===== Sistema Academico - Gerenciamento Ampliado =====" << endl << endl;

    Aluno aluno("Ana Souza", "ana.souza@escola.com", "2025001", "Engenharia de Software");
    aluno.adicionarDisciplina("Programacao Orientada a Objetos");
    aluno.adicionarDisciplina("Estrutura de Dados");
    aluno.adicionarNota(8.5);
    aluno.adicionarNota(9.0);

    Professor professor("Carlos Lima", "carlos.lima@escola.com", "Ciencia da Computacao");
    professor.adicionarDisciplinaMinistrada("Algoritmos");
    professor.adicionarDisciplinaMinistrada("Banco de Dados");

    FuncionarioAdministrativo funcionario("Marta Silva", "marta.silva@escola.com", "Secretaria Academica", "Coordenadora");

    Monitor monitor("Bruno Alves", "bruno.alves@escola.com", "2023045", "Ciencia da Computacao", "Programacao");
    monitor.adicionarDisciplinaMonitorada("Programacao Orientada a Objetos");

    // Polimorfismo: manipulando diferentes tipos de usuario via ponteiro para a classe base
    vector<Usuario*> usuarios;
    usuarios.push_back(&aluno);
    usuarios.push_back(&professor);
    usuarios.push_back(&funcionario);

    cout << "--- Relatorios via polimorfismo (Usuario*) ---" << endl << endl;
    for (Usuario* u : usuarios) {
        u->gerarRelatorio();
        cout << endl;
    }

    cout << "--- Relatorio do Monitor (heranca multipla de Aluno e Professor) ---" << endl << endl;
    monitor.gerarRelatorio();
    cout << endl;

    cout << "--- Sobrecarga de metodo em Aluno ---" << endl;
    cout << "Sem notas:" << endl;
    aluno.exibirInformacoes();
    cout << endl << "Com notas:" << endl;
    aluno.exibirInformacoes(true);

    return 0;
}
