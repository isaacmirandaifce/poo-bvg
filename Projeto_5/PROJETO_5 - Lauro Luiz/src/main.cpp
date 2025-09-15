#include <iostream>
#include <vector>
#include <memory>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"
#include "Monitor.h"

using namespace std;

// Função para demonstrar polimorfismo
void demonstrarPolimorfismo(const vector<shared_ptr<Usuario>>& usuarios) {
    cout << "\n================== DEMONSTRAÇÃO DE POLIMORFISMO ==================" << endl;
    cout << "Gerando relatórios de todos os usuários usando polimorfismo:" << endl;

    for (const auto& usuario : usuarios) {
        usuario->gerarRelatorio(); // Chamada polimórfica
    }
}

// Função para demonstrar sobrecarga
void demonstrarSobrecarga(Aluno& aluno) {
    cout << "\n================== DEMONSTRAÇÃO DE SOBRECARGA ==================" << endl;
    cout << "Método exibirInformacoes() sobrecarregado na classe Aluno:" << endl;

    cout << "\n1. Versão sem notas:" << endl;
    aluno.exibirInformacoes();

    cout << "\n2. Versão com notas:" << endl;
    aluno.exibirInformacoes(true);

    cout << "\n3. Versão sem mostrar notas (parâmetro false):" << endl;
    aluno.exibirInformacoes(false);
}

// Função para demonstrar herança múltipla
void demonstrarHerancaMultipla(Monitor& monitor) {
    cout << "\n================== DEMONSTRAÇÃO DE HERANÇA MÚLTIPLA ==================" << endl;
    cout << "Monitor herda de Aluno E Professor:" << endl;

    // Demonstrar funcionalidades herdadas de Aluno
    cout << "\nFuncionalidades herdadas de ALUNO:" << endl;
    cout << "Matrícula: " << monitor.getMatricula() << endl;
    cout << "Curso: " << monitor.getCurso() << endl;

    // Demonstrar funcionalidades herdadas de Professor
    cout << "\nFuncionalidades herdadas de PROFESSOR:" << endl;
    cout << "Área de Atuação: " << monitor.getAreaDeAtuacao() << endl;
    cout << "Disciplinas Ministradas: " << monitor.contarDisciplinasMinistradas() << endl;

    // Funcionalidades específicas do Monitor
    cout << "\nFuncionalidades ESPECÍFICAS do MONITOR:" << endl;
    monitor.listarDisciplinasMonitoradas();
    monitor.gerarRelatorioMonitoria();
}

int main() {
    cout << "========== SISTEMA ACADÊMICO - PROJETO AVALIATIVO 5 ==========" << endl;
    cout << "Demonstração de Herança, Polimorfismo, Sobrecarga e Sobrescrita" << endl;

    // ==================== CRIAÇÃO DOS OBJETOS ====================

    // Criando Aluno
    Aluno aluno1("Ana Silva", "ana.silva@universidade.edu.br", "2023001", "Engenharia de Software");
    aluno1.adicionarDisciplina("Programação Orientada a Objetos");
    aluno1.adicionarDisciplina("Estruturas de Dados");
    aluno1.adicionarDisciplina("Banco de Dados");
    aluno1.adicionarNota("Programação Orientada a Objetos", 9.5);
    aluno1.adicionarNota("Estruturas de Dados", 8.7);
    aluno1.adicionarNota("Banco de Dados", 9.2);

    // Criando Professor
    Professor prof1("Dr. Carlos Santos", "carlos.santos@universidade.edu.br", "Ciência da Computação");
    prof1.adicionarDisciplinaMinistrada("Programação Orientada a Objetos");
    prof1.adicionarDisciplinaMinistrada("Algoritmos Avançados");
    prof1.adicionarDisciplinaMinistrada("Inteligência Artificial");

    // Criando Funcionário Administrativo
    FuncionarioAdministrativo func1("Maria Oliveira", "maria.oliveira@universidade.edu.br",
                                    "Secretaria Acadêmica", "Coordenador");

    // Criando Monitor (Herança Múltipla)
    Monitor monitor1("João Pedro", "joao.pedro@universidade.edu.br",
                     "2022005", "Ciência da Computação",
                     "Programação", "Manhã");
    monitor1.adicionarDisciplina("Cálculo I");
    monitor1.adicionarDisciplina("Programação I");
    monitor1.adicionarNota("Cálculo I", 9.8);
    monitor1.adicionarNota("Programação I", 9.6);
    monitor1.adicionarDisciplinaMinistrada("Programação Básica");
    monitor1.adicionarDisciplinaMonitorada("Programação I");
    monitor1.adicionarDisciplinaMonitorada("Lógica de Programação");

    // ==================== DEMONSTRAÇÕES ====================

    // 1. Demonstração de Polimorfismo
    vector<shared_ptr<Usuario>> usuarios;
    usuarios.push_back(make_shared<Aluno>(aluno1));
    usuarios.push_back(make_shared<Professor>(prof1));
    usuarios.push_back(make_shared<FuncionarioAdministrativo>(func1));
    usuarios.push_back(make_shared<Monitor>(monitor1));

    demonstrarPolimorfismo(usuarios);

    // 2. Demonstração de Sobrecarga
    demonstrarSobrecarga(aluno1);

    // 3. Demonstração de Herança Múltipla
    demonstrarHerancaMultipla(monitor1);

    // ==================== FUNCIONALIDADES EXTRAS ====================

    cout << "\n================== FUNCIONALIDADES EXTRAS ==================" << endl;

    // Teste de funcionalidades específicas
    cout << "\n--- Teste de Permissões do Funcionário ---" << endl;
    vector<string> sistemas = {"Acadêmico", "Financeiro", "Recursos Humanos", "Relatórios"};
    for (const string& sistema : sistemas) {
        cout << "Sistema " << sistema << ": "
             << (func1.podeAcessarSistema(sistema) ? "PERMITIDO" : "NEGADO") << endl;
    }

    cout << "\n--- Hierarquia Organizacional ---" << endl;
    func1.exibirHierarquia();

    cout << "\n--- Informações do Monitor ---" << endl;
    cout << "Bolsa mensal: R$ " << fixed << setprecision(2) << monitor1.calcularBolsaMonitoria() << endl;
    cout << "Disponível às 10:00? " << (monitor1.verificarDisponibilidade("10:00") ? "Sim" : "Não") << endl;
    cout << "Disponível às 20:00? " << (monitor1.verificarDisponibilidade("20:00") ? "Sim" : "Não") << endl;

    // ==================== DEMONSTRAÇÃO DE SOBRESCRITA ====================

    cout << "\n================== DEMONSTRAÇÃO DE SOBRESCRITA ==================" << endl;
    cout << "Métodos sobrescritos em cada classe derivada:" << endl;

    cout << "\n1. Método gerarRelatorio() - Cada classe implementa de forma diferente:" << endl;
    aluno1.gerarRelatorio();     // Versão do Aluno
    prof1.gerarRelatorio();      // Versão do Professor
    func1.gerarRelatorio();      // Versão do Funcionário
    monitor1.gerarRelatorio();   // Versão do Monitor (resolve ambiguidade)

    cout << "\n2. Método exibirInformacoes() - Sobrescrito em cada classe:" << endl;
    aluno1.exibirInformacoes();
    prof1.exibirInformacoes();
    func1.exibirInformacoes();
    monitor1.exibirInformacoes();

    cout << "\n================== FINALIZAÇÃO DO SISTEMA ==================" << endl;
    cout << "Demonstração concluída com sucesso!" << endl;
    cout << "Conceitos explorados:" << endl;
    cout << "✓ Herança simples e múltipla" << endl;
    cout << "✓ Polimorfismo com métodos virtuais" << endl;
    cout << "✓ Sobrecarga de métodos" << endl;
    cout << "✓ Sobrescrita de métodos virtuais" << endl;
    cout << "✓ Classe abstrata com método virtual puro" << endl;
    cout << "=============================================================" << endl;

    return 0;
}
