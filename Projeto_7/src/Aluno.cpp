#include <iostream>
#include <string>
#include <vector>

class Aluno {
private:
    std::string nome;
    std::string email;
    std::string matricula;
    std::string curso;
    std::vector<std::string> historico;
    
public:
    /* Construtor da classe */
    Aluno(std::string n, std::string e, std::string m, std::string c) 
        : nome(n), email(e), matricula(m), curso(c) {}

    /* Função para adicionar disciplina ao histórico */
    void adicionarDisciplina(const std::string& nomeDisciplina, int ano, float nota) {
        std::string disciplina = nomeDisciplina + " - " + std::to_string(ano) + " - Nota: " + std::to_string(nota);
        historico.push_back(disciplina);
    }

    /* Função para exibir informações do aluno */
    void exibirInformacoes() {
        std::cout << "Nome: " << nome << std::endl;
        std::cout << "Email: " << email << std::endl;
        std::cout << "Matrícula: " << matricula << std::endl;
        std::cout << "Curso: " << curso << std::endl;
        std::cout << "Histórico de disciplinas:" << std::endl;
        for (const auto& disciplina : historico) {
            std::cout << disciplina << std::endl;
        }
    }

    /* Função para gerar relatório */
    void gerarRelatorio() {
        std::cout << "Relatório do aluno " << nome << ":" << std::endl;
        exibirInformacoes();
    }
};

int main() {
    /* Criando um aluno */
    Aluno aluno1("Jhonata", "jhonata@example.com", "12345", "Engenharia de Software");

    /* Adicionando disciplinas ao histórico do aluno */
    aluno1.adicionarDisciplina("Matemática", 2023, 8.5);
    aluno1.adicionarDisciplina("Algoritmos", 2023, 9.0);

    /* Exibindo as informações do aluno */
    aluno1.gerarRelatorio();

    return 0;
}
