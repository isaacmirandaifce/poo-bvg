#include <iostream>
#include <iomanip>
#include <vector>
#include "src/Sinais/SinalHandler.h"
#include "src/Persistencia/Persistencia.h"
#include "src/Filtro/Filtro.h"
#include "src/Aluno/Aluno.h"
#include "src/Professor/Professor.h"
#include "src/Excecoes/Excecoes.h"

using namespace std;

vector<Aluno> alunos;
vector<Professor> professores;

void salvarAntesDeSair() {
    cout << "\n[ Salvando dados antes de encerrar... ]" << endl;
    try {
        Persistencia::salvarAlunos("data/alunos.csv", alunos);
        Persistencia::salvarProfessores("data/professores.csv", professores);
        cout << "[ Dados salvos com sucesso. ]\n" << endl;
    } catch (const exception& e) {
        cerr << "[Erro ao salvar arquivos] " << e.what() << endl;
    }
}

void gerarDadosMockados() {
    // ==== Alunos ====
    alunos.clear();
    alunos.push_back(Aluno("Guilherme alves", "guilherme.vale1@ifce.edu.br", "Aluno", "123", "2023123", "ADS", {"POO", "IHC"}));
    alunos.push_back(Aluno("rafael nougueria", "rafa.maciel@ifce.edu.br", "Aluno", "456", "2023124", "ADS", {"POO", "Redes"}));
    alunos.push_back(Aluno("Michel junior", "michel.fifa@ifce.edu.br", "Aluno", "789", "2023125", "Zootecnia", {"Calc", "Fisica"}));

    // ==== Professores ====
    professores.clear();
    professores.push_back(Professor("Isaac Miranda", "isaac@ifce.edu.br", "Professor", "pass123", "Computação", {"POO", "LP"}));
    professores.push_back(Professor("Magno Prudencio", "magno@ifce.edu.br", "Professor", "pass456", "Computação", {"Redes", "BD"}));
    professores.push_back(Professor("joao mendes", "joao.mendes80@ifce.edu.br", "Professor", "pass789", "Matemática", {"Calc"}));

    // Salvamento imediato
    salvarAntesDeSair();
}

void listarAlunos() {
    cout << "\n--- LISTAGEM DE ALUNOS ---\n";
    for (const auto& a : alunos)
        a.gerarRelatorio();
}

void listarProfessores() {
    cout << "\n--- LISTAGEM DE PROFESSORES ---\n";
    for (const auto& p : professores)
        p.gerarRelatorio();
}

int main() {
    SinalHandler::inicializar();
    SinalHandler::definirCallbackDeSaida(salvarAntesDeSair);

    try {
        cout << "[Carregando dados...]\n";
        alunos = Persistencia::carregarAlunos("data/alunos.csv");
        professores = Persistencia::carregarProfessores("data/professores.csv");
        cout << "[Dados carregados com sucesso.]\n";
    } catch (const exception& e) {
        cerr << "[Erro ao carregar arquivos] " << e.what() << endl;
        cout << "[Gerando dados mockados...]\n";
        gerarDadosMockados();
    }

    listarAlunos();
    listarProfessores();

    salvarAntesDeSair();
    return 0;
}