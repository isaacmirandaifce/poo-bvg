#ifndef RELATORIO_H
#define RELATORIO_H

#include "Usuario.h"
#include <vector>

class Relatorio {
public:
    // Gera o relatório com base nos dados dos usuários
    static void gerarRelatorio(const std::vector<Usuario>& usuarios);
};

#endif
