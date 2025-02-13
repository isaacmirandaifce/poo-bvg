#include "FuncionarioAdministrativo.h"
#include <cassert>

void test_funcionario() {
    FuncionarioAdministrativo funcionario("Carlos", "senha789");
    assert(funcionario.autenticar("senha789"));
    assert(!funcionario.autenticar("senha_errada"));
    funcionario.gerarRelatorio();
}

int main() {
    test_funcionario();
    return 0;
}