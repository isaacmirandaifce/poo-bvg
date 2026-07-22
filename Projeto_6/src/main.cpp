#include <iostream>
#include <vector>
#include "TipoUsuario.h"
#include "Relatorio.h"
#include "UsuarioAutenticavel.h"
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

using namespace std;

int main() {
    cout << "===== Sistema Academico Avancado - Autenticacao e Relatorios =====" << endl << endl;

    Aluno aluno("Ana Souza", "ana.souza@escola.com", "senha123", "2025001", "Engenharia de Software");
    aluno.adicionarHistorico("Programacao Orientada a Objetos", 2024, 8.5);
    aluno.adicionarHistorico("Estrutura de Dados", 2024, 9.0);

    Professor professor("Carlos Lima", "carlos.lima@escola.com", "prof@2024", "Ciencia da Computacao");
    professor.adicionarDisciplinaMinistrada("Algoritmos");
    professor.adicionarDisciplinaMinistrada("Banco de Dados");

    FuncionarioAdministrativo funcionario("Marta Silva", "marta.silva@escola.com", "admin321",
                                           "Secretaria Academica", "Coordenadora");

    // ----- Classes enumeradas -----
    cout << "--- Categorias de usuario (TipoUsuario) ---" << endl;
    cout << aluno.getNome() << " -> " << tipoUsuarioParaTexto(aluno.getTipo()) << endl;
    cout << professor.getNome() << " -> " << tipoUsuarioParaTexto(professor.getTipo()) << endl;
    cout << funcionario.getNome() << " -> " << tipoUsuarioParaTexto(funcionario.getTipo()) << endl << endl;

    // ----- Classe abstrata: autenticacao polimorfica via UsuarioAutenticavel* -----
    cout << "--- Autenticacao (UsuarioAutenticavel*) ---" << endl;
    vector<UsuarioAutenticavel*> usuariosAutenticaveis;
    usuariosAutenticaveis.push_back(&aluno);
    usuariosAutenticaveis.push_back(&professor);
    usuariosAutenticaveis.push_back(&funcionario);

    vector<string> tentativasDeSenha = {"senha123", "senhaErrada", "admin321"};
    for (size_t i = 0; i < usuariosAutenticaveis.size(); ++i) {
        bool ok = usuariosAutenticaveis[i]->autenticar(tentativasDeSenha[i]);
        cout << usuariosAutenticaveis[i]->getNome() << ": "
             << (ok ? "autenticacao bem-sucedida" : "falha na autenticacao") << endl;
    }
    cout << endl;

    // ----- Interface Relatorio: geracao polimorfica de relatorios -----
    cout << "--- Relatorios via polimorfismo (Relatorio*) ---" << endl << endl;
    vector<Relatorio*> relatorios;
    relatorios.push_back(&aluno);
    relatorios.push_back(&professor);
    relatorios.push_back(&funcionario);

    for (Relatorio* r : relatorios) {
        r->gerarRelatorio();
        cout << endl;
    }

    // ----- Classe interna HistoricoDisciplinar -----
    cout << "--- Classe interna Aluno::HistoricoDisciplinar ---" << endl;
    Aluno::HistoricoDisciplinar registro("Programacao Avancada", 2025, 9.5);
    registro.exibir();
    cout << endl;

    // ----- Sobrecarga de metodo em Aluno -----
    cout << "--- Sobrecarga de metodo em Aluno ---" << endl;
    cout << "Sem historico:" << endl;
    aluno.exibirInformacoes();
    cout << endl << "Com historico:" << endl;
    aluno.exibirInformacoes(true);

    return 0;
}
