#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <vector>
#include <string>
#include "Aluno.h"

class ArquivoNaoEncontradoException {};
class PermissaoNegadaException {};
class ConversaoDadosException {};

class Persistencia {
public:
    static std::vector<Aluno> carregarAlunos(const std::string& arquivo);
    static void salvarAlunos(const std::string& arquivo, const std::vector<Aluno>& alunos);
};

#endif
