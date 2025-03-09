#include "aluno.h"
#include <iostream>
using namespace std;
// constructor
Aluno::Aluno() : nome(""), matricula(""), curso("") {}
Aluno::Aluno(const std::string& nome, const std::string& matricula, const std::string& curso) : nome(nome), matricula(matricula), curso(curso) {}

// exibir informacoes
void Aluno::exibirInformacoes() const {
    cout << "Nome: " << nome << endl;
    cout << "\nMatricula: " << matricula << endl;
    cout << "\nCurso: " << curso << endl << "\n";
}

string Aluno::getNome() const {
    return nome;
}