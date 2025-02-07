#include "Professor.h"
#include <cassert>

void test_professor() {
    Professor professor("Maria", "senha456");
    assert(professor.autenticar("senha456"));
    assert(!professor.autenticar("senha_errada"));
    professor.gerarRelatorio();
}

int main() {
    test_professor();
    return 0;
}