#include <iostream>
#include <vector>

#include "models/UsuarioAdmin.h"
#include "models/UsuarioAuditor.h"
#include "models/UsuarioOperador.h"

using namespace std;

int main()
{
    UsuarioAdmin admin(
        1,
        "admin",
        "123");

    UsuarioAuditor auditor(
        2,
        "auditor",
        "456");

    UsuarioOperador operador(
        3,
        "operador",
        "789");

    operador.adicionarAcesso(
        "Caixa",
        "11/06/2026 10:00",
        200);

    operador.adicionarAcesso(
        "Transferencia",
        "11/06/2026 10:15",
        201);

    cout << "Teste de autenticacao\n\n";

    cout << "Admin: ";

    if(admin.autenticar("123"))
        cout << "Login OK\n";
    else
        cout << "Falha\n";

    cout << "Auditor: ";

    if(auditor.autenticar("111"))
        cout << "Login OK\n";
    else
        cout << "Falha\n";

    cout << "Operador: ";

    if(operador.autenticar("789"))
        cout << "Login OK\n";
    else
        cout << "Falha\n";

    vector<Relatorio*> relatorios;

    relatorios.push_back(&admin);
    relatorios.push_back(&auditor);
    relatorios.push_back(&operador);

    cout << "\n===== RELATORIOS =====\n";

    for(Relatorio* r : relatorios)
    {
        r->gerarRelatorio();
    }

    return 0;
}