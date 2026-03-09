#include <iostream>
#include <string>

#include "Persistencia.h"
#include "SinalHandler.h"

int main() {
    Persistencia persistencia("Projeto_8/data");
    DadosAcademicos dados;

    SinalHandler::registrarSalvar([&]() {
        persistencia.salvarTudo(dados);
    });
    SinalHandler::inicializar();

    try {
        persistencia.carregarTudo(dados);
        std::cout << "Dados carregados com sucesso.\n";
    } catch (const ArquivoNaoEncontradoException& e) {
        std::cerr << e.what() << "\nCriando base inicial...\n";
    } catch (const PermissaoNegadaException& e) {
        std::cerr << e.what() << "\n";
        return 1;
    } catch (const FalhaConversaoException& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    if (dados.alunos.empty() && dados.professores.empty() && dados.disciplinas.empty()) {
        Aluno a1("Joao", "joao@email.com", "123");
        a1.adicionarDisciplina("POO", 2024, 9.0f);
        dados.alunos.push_back(a1);
        persistencia.salvarTudo(dados);

        Professor p1("Isaac", "isaac@email.com", "123", "Computacao");
        p1.adicionarDisciplinaMinistrada("POO");
        dados.professores.push_back(p1);
        persistencia.salvarTudo(dados);

        dados.disciplinas.push_back("POO");
        persistencia.salvarTudo(dados);

        std::cout << "Base inicial salva automaticamente.\n";
    }

    std::cout << "Alunos: " << dados.alunos.size() << "\n";
    std::cout << "Professores: " << dados.professores.size() << "\n";
    std::cout << "Disciplinas: " << dados.disciplinas.size() << "\n";

    if (!dados.alunos.empty()) {
        std::cout << "Primeiro aluno: " << dados.alunos[0].getNome() << "\n";
    }

    return 0;
}
