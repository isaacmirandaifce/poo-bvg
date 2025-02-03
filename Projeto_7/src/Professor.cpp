#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Professor {
private:
    string nome;
    string email;
    string areaDeAtuacao;
    vector<string> disciplinasMinistradas;

public:
    /* Construtor */
    Professor(string nome, string email, string areaDeAtuacao) {
        this->nome = nome;
        this->email = email;
        this->areaDeAtuacao = areaDeAtuacao;
    }

    /* Método para autenticar */
    bool autenticar(string email) {
        return this->email == email;
    }

    /* Método para exibir informações do professor */
    void exibirInformacoes() {
        cout << "Nome: " << nome << endl;
        cout << "Email: " << email << endl;
        cout << "Área de Atuação: " << areaDeAtuacao << endl;

        cout << "Disciplinas Ministradas: " << endl;
        for (const string& disciplina : disciplinasMinistradas) {
            cout << "- " << disciplina << endl;
        }
    }

    /* Método para gerar relatório */
    void gerarRelatorio() {
        /* Exemplo de relatório simples */
        cout << "Relatório do Professor: " << nome << endl;
        cout << "Email: " << email << endl;
        cout << "Área de Atuação: " << areaDeAtuacao << endl;
        cout << "Disciplinas Ministradas: " << endl;
        for (const string& disciplina : disciplinasMinistradas) {
            cout << "- " << disciplina << endl;
        }
    }

    /* Método para adicionar uma disciplina */
    void adicionarDisciplina(string disciplina) {
        disciplinasMinistradas.push_back(disciplina);
    }
};

int main() {
    /* Criando um objeto Professor */
    Professor prof1("Larissa Vieira", "larissa@exemplo.com", "Matemática");

    /* Adicionando disciplinas */
    prof1.adicionarDisciplina("Cálculo I");
    prof1.adicionarDisciplina("Álgebra Linear");

    /* Exibindo informações */
    prof1.exibirInformacoes();

    /* Gerando relatório */
    prof1.gerarRelatorio();

    return 0;
}
