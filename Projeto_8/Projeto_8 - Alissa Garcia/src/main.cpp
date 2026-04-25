#include <iostream>
#include <string>
#include "Aluno.h"
#include "Professor.h"
#include "Persistencia.h"
#include "SinalHandler.h"

using namespace std;

int main() {

    cout << "Inicializando sistema...\n";

    Persistencia persist("data");

    // registra persistência no tratador de sinais
    SinalHandler::registrarPersistencia(&persist);
    SinalHandler::inicializar();

    try {
        persist.carregar();
        cout << "Dados carregados com sucesso.\n";
    } 
    catch (const ArquivoNaoEncontradoException& e) {
        cout << "Aviso: " << e.what() << "\nSistema iniciado sem dados salvos.\n";
    }
    catch (const PersistenciaException& e) {
        cout << "Erro de persistência: " << e.what() << endl;
        return 1;
    }
    catch (...) {
        cout << "Erro inesperado ao carregar dados.\n";
        return 1;
    }

    // ============================
    // SE NÃO HOUVER DADOS, CRIA ALGUNS
    // ============================
    if (persist.listarAlunos().empty() && persist.listarProfessores().empty()) {

        Aluno a1("Alissa", "alissa@email.com", "123", "202401", "ADS");
        a1.adicionarHistorico("POO", 2025, 9.5);
        a1.adicionarHistorico("ED", 2025, 8.0);

        Aluno a2("João", "joao@email.com", "321", "202402", "ADS");
        a2.adicionarHistorico("POO", 2025, 6.0);
        a2.adicionarHistorico("ED", 2025, 5.5);

        Professor p1("Carlos", "carlos@email.com", "123", "Computação");
        p1.disciplinasAdicionadas("POO");
        p1.disciplinasAdicionadas("Redes");

        Professor p2("Maria", "maria@email.com", "1234", "Matemática");
        p2.disciplinasAdicionadas("Cálculo");

        persist.adicionarAluno(a1);
        persist.adicionarAluno(a2);
        persist.adicionarProfessor(p1);
        persist.adicionarProfessor(p2);

        persist.adicionarDisciplina("POO");
        persist.adicionarDisciplina("ED");
        persist.adicionarDisciplina("Cálculo");

        cout << "Dados iniciais criados e salvos.\n";
    }

    // ============================
    // LOGIN
    // ============================
    int opcao;
    string senha;

    cout << "\n===== SISTEMA ACADEMICO =====\n";
    cout << "1 - Aluno\n2 - Professor\nOpcao: ";
    cin >> opcao;

    cout << "Digite a senha: ";
    cin >> senha;

    auto alunos = persist.listarAlunos();
    auto professores = persist.listarProfessores();

    bool autenticado = false;

    // ============================
    // PERFIL ALUNO
    // ============================
    if (opcao == 1) {
        for (auto &a : alunos) {
            if (a.autenticar(senha)) {
                autenticado = true;

                cout << "\nLogin de ALUNO realizado com sucesso!\n";
                a.gerarRelatorio();

                cout << "\nDISCIPLINAS DE 2025:\n";
                for (auto &h : a.getHistorico()) {
                    if (h.getAno() == 2025) {
                        cout << "- " << h.getDisciplina() << endl;
                    }
                }
                break;
            }
        }
    }

    // ============================
    // PERFIL PROFESSOR
    // ============================
    else if (opcao == 2) {
        for (auto &p : professores) {
            if (p.autenticar(senha)) {
                autenticado = true;

                cout << "\nLogin de PROFESSOR realizado com sucesso!\n";
                p.gerarRelatorio();
                break;
            }
        }
    }

    if (!autenticado) {
        cout << "\nSenha incorreta ou opcao invalida. Acesso negado.\n";
    }

    // ============================
    // FINALIZAÇÃO SEGURA
    // ============================
    try {
        persist.salvar();
        cout << "\nDados salvos com sucesso.\n";
    } catch (const PersistenciaException& e) {
        cout << "Erro ao salvar dados: " << e.what() << endl;
    }

    cout << "Encerrando sistema normalmente.\n";
    return 0;
}
