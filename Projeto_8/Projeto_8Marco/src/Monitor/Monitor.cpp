#include "Monitor.h"
#include <iostream>
using namespace std;

Monitor::Monitor() : UsuarioAutenticavel(), Aluno(), Professor(), tipoUsuario(TipoUsuario::MONITOR) {}

Monitor::Monitor(string nome, string email, string tipo, string senha,
                 string matricula, string curso, vector<string> disciplinasAluno,
                 string areaDeAtuacao, vector<string> disciplinasMinistradas)
    : UsuarioAutenticavel(nome, email, tipo, senha),
      Aluno(nome, email, tipo, senha, matricula, curso, disciplinasAluno),
      Professor(nome, email, tipo, senha, areaDeAtuacao, disciplinasMinistradas),
      tipoUsuario(TipoUsuario::MONITOR) {}

void Monitor::gerarRelatorio() const {
    cout << "=== RELATORIO DE MONITOR ===" << endl;
    cout << "Nome: " << nome << ", Email: " << email << ", Tipo: " << tipo << endl;
    cout << "Matrícula: " << matricula << ", Curso: " << curso << endl;
    cout << "Área: " << areaDeAtuacao << ", Disciplinas Ministradas: ";
    for (const auto& d : disciplinasMinistradas) cout << d << " ";
    cout << endl << endl;
}

bool Monitor::autenticar(string senhaTentativa) {
    return senhaTentativa == senha;