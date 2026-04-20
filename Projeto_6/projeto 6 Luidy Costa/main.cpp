#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

using namespace std;

int main() {
    // Vetor polimórfico para Relatorios
    vector<Relatorio*> relatorios;
    // Vetor polimórfico para Autenticação
    vector<UsuarioAutenticavel*> usuarios;

    // Instanciando objetos
    Aluno* a1 = new Aluno("Luidy", "luidy@email.com", "123456", "2026-ADS");
    // Adicionando histórico via classe interna
    a1->adicionarDisciplina("POO Avancada", 2025, 9.5);
    a1->adicionarDisciplina("Estrutura de Dados", 2025, 8.0);

    Professor* p1 = new Professor("Dr. Mendes", "mendes@faculdade.com", "senhaProf", "Computacao");
    FuncionarioAdministrativo* f1 = new FuncionarioAdministrativo("Ana", "ana@adm.com", "admin123", "Secretaria");

    // Armazenando nos vetores
    usuarios.push_back(a1);
    relatorios.push_back(a1);

    usuarios.push_back(p1);
    relatorios.push_back(p1);

    usuarios.push_back(f1);
    relatorios.push_back(f1);

    cout << ">>> Teste de Autenticacao <<<" << endl;
    for (UsuarioAutenticavel* u : usuarios) {
        string senhaTeste;
        cout << "Login para " << u->getNome() << ": ";
        // Para simulação rápida, vamos "forçar" a senha correta ou incorreta via código
        // Em produção usariamos 'cin >> senhaTeste'

        if (u->getTipo() == TipoUsuario::ALUNO) senhaTeste = "123456"; // Senha correta
        else senhaTeste = "senhaErrada"; // Senha incorreta proposital

        cout << "(Tentativa: " << senhaTeste << ") -> ";
        if (u->autenticar(senhaTeste)) {
            cout << "Acesso PERMITIDO." << endl;
        } else {
            cout << "Acesso NEGADO." << endl;
        }
    }

    cout << "\n>>> Geracao de Relatorios do Sistema <<<" << endl;
    for (Relatorio* r : relatorios) {
        r->gerarRelatorio();
        cout << endl;
    }

    // Limpeza de memória
    delete a1;
    delete p1;
    delete f1;

    return 0;
}
