#include <iostream>
#include "Aluno.h"
#include "Professor.h"
#include "Filtro.h"
#include "Persistencia.h"
#include "SinalHandler.h"

int main() {
    SinalHandler::inicializar();

    try {
        // Carregar dados de arquivos
        auto alunos = Persistencia::carregarAlunos("alunos.txt");
        auto professores = Persistencia::carregarProfessores("professores.txt");

        // Configurar dados para o tratador de sinais
        SinalHandler::setDados(alunos, professores);

        // Exemplo de uso do Filtro<T>
        Filtro<Aluno> filtroAlunos;
        for (const auto& aluno : alunos) {
            filtroAlunos.adicionarElemento(aluno);
        }

        std::cout << "Alunos com media acima de 7.0:\n";
        auto alunosFiltrados = filtroAlunos.filtrarPorCondicao([](const Aluno& aluno) {
            return aluno.getMedia() > 7.0;
        });
        for (const auto& aluno : alunosFiltrados) {
            aluno.exibirInformacoes();
        }

        // Adicionar novo aluno e salvar automaticamente
        Aluno novoAluno("Carlos Souza", "67890", "Engenharia de Software", "senha789", 8.0);
        alunos.push_back(novoAluno);
        Persistencia::salvarAlunos(alunos, "alunos.txt");

    } catch (const ArquivoNaoEncontradoException& e) {
        std::cerr << "Erro: " << e.what() << "\n";
    } catch (const PermissaoNegadaException& e) {
        std::cerr << "Erro: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << "\n";
    }

    return 0;
}