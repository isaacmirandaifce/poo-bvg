#include <iostream>
#include <vector>
#include "Persistencia.h"
#include "SinalHandler.h"

int main() {
    SinalHandler::inicializar();
    std::vector<Aluno> alunos;

    try {
        alunos = Persistencia::carregarAlunos("alunos.txt");
    } catch (ArquivoNaoEncontradoException&) {
        std::cout << "Arquivo nao encontrado. Iniciando vazio.\n";
    } catch (ConversaoDadosException&) {
        std::cout << "Erro ao converter dados do arquivo.\n";
    }

    alunos.push_back(Aluno(1, "Joao"));
    alunos.push_back(Aluno(2, "Maria"));

    try {
        Persistencia::salvarAlunos("alunos.txt", alunos);
    } catch (PermissaoNegadaException&) {
        std::cout << "Sem permissao para salvar arquivo.\n";
    }

    std::cout << "Sistema finalizado com sucesso.\n";
    return 0;
}
