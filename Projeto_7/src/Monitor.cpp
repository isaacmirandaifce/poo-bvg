#include <iostream>
#include <vector>
#include <string>

class Aluno {
public:
    std::string nome;
    int matricula;

    Aluno(std::string nome, int matricula) {
        this->nome = nome;
        this->matricula = matricula;
    }
};

class Monitor {
private:
    std::vector<Aluno> alunosMonitorados;
    std::vector<std::string> disciplinasMonitoradas;

public:
    /* Construtor da classe Monitor */
    Monitor() {}

    /* Método para adicionar aluno */
    void adicionarAluno(std::string nome, int matricula) {
        alunosMonitorados.push_back(Aluno(nome, matricula));
    }

    /* Método para adicionar disciplina */
    void adicionarDisciplina(std::string disciplina) {
        disciplinasMonitoradas.push_back(disciplina);
    }

    /* Método para autenticar monitor */
    bool autenticar(std::string nome) {
        
        return true;
    }

    /* Método para exibir informações */
    void exibirInformacoes() {
        std::cout << "Alunos monitorados:\n";
        for (const auto& aluno : alunosMonitorados) {
            std::cout << "Nome: " << aluno.nome << ", Matrícula: " << aluno.matricula << std::endl;
        }

        std::cout << "\nDisciplinas monitoradas:\n";
        for (const auto& disciplina : disciplinasMonitoradas) {
            std::cout << disciplina << std::endl;
        }
    }

    /* Método para gerar relatório */
    void gerarRelatorio() {
        std::cout << "Relatório dos alunos e disciplinas monitorados:\n";
        exibirInformacoes();
    }
};

int main() {
    Monitor monitor;

    /* Adicionando alunos */
    monitor.adicionarAluno("João", 12345);
    monitor.adicionarAluno("Maria", 67890);

    /* Adicionando disciplinas */
    monitor.adicionarDisciplina("Matemática");
    monitor.adicionarDisciplina("Física");

    /* Exibindo informações */
    monitor.exibirInformacoes();

    /* Gerando relatório */
    monitor.gerarRelatorio();

    return 0;
}
