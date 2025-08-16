#include <iostream>
#include <vector>
#include "src/Aluno/Aluno.h"
#include "src/Professor/Professor.h"
#include "src/FuncionarioAdministrativo/FuncionarioAdministrativo.h"
#include "src/Monitor/Monitor.h"

using namespace std;

int main() {
    vector<Relatorio*> usuarios;

    // Criando os objetos com senhas
    Aluno* aluno = new Aluno("João Lucas", "joao@gmail.com", "Aluno", "1234", "2023001", "Engenharia", {"Matemática", "Física"});
    Professor* professor = new Professor("Maria Fonseca", "maria@gmail.com", "Professor", "abcd", "Matemática", {"Cálculo", "Álgebra"});
    FuncionarioAdministrativo* funcionario = new FuncionarioAdministrativo("João Mendes", "mendes@gmail.com", "Funcionario", "senha123", "RH", "Assistente");
    Monitor* monitor = new Monitor("Ana Carla", "ana@gmail.com", "Monitor", "senha456", "2023002", "Computação", {"Estrutura de Dados"}, "Programação", {"Lógica de Programação"});

    // Adicionando ao vetor de Relatorio (polimorfismo)
    usuarios.push_back(aluno);
    usuarios.push_back(professor);
    usuarios.push_back(funcionario);
    usuarios.push_back(monitor);

    // Exemplo de polimorfismo: Gerando relatórios de todos os usuários
    cout << "====== RELATÓRIOS ======" << endl;
    for (Relatorio* r : usuarios) {
        r->gerarRelatorio();
    }

    // Testando autenticação
    cout << "\n====== AUTENTICAÇÃO ======" << endl;
    string tentativa;
    cout << "Digite a senha do Aluno: ";
    cin >> tentativa;
    if (aluno->autenticar(tentativa)) {
        cout << "Aluno autenticado com sucesso!" << endl;
    } else {
        cout << "Senha incorreta!" << endl;
    }

    // Testando classe interna: Adicionando histórico ao aluno
    aluno->adicionarDisciplinaAoHistorico("Algoritmos", 2024, 8.5);
    aluno->adicionarDisciplinaAoHistorico("Estruturas de Dados", 2025, 9.0);

    cout << "\n====== HISTÓRICO ATUALIZADO DO ALUNO ======" << endl;
    aluno->gerarRelatorio();

    // Liberando memória
    for (Relatorio* r : usuarios) {
        delete r;
    }

    return 0;
}