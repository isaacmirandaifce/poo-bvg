#include <iostream>
#include <vector>
#include "../include/Aluno.h"
#include "../include/Professor.h"
#include "../include/Filtro.h"
#include "../include/FuncionarioAdministrativo.h"

int main() {
    // Criando filtro para alunos
    Filtro<Aluno> filtroAlunos;
    
    Aluno aluno1("João Silva", "joao@email.com", "202301", "Engenharia da Computação", "senha123");
    aluno1.adicionarHistorico(Aluno::HistoricoDisciplinar("Matemática", 2023, 7.5f));
    aluno1.adicionarHistorico(Aluno::HistoricoDisciplinar("Física", 2023, 8.2f));
    
    Aluno aluno2("Ana Souza", "ana@email.com", "202302", "Matemática", "senha456");
    aluno2.adicionarHistorico(Aluno::HistoricoDisciplinar("Cálculo", 2023, 6.8f));
    aluno2.adicionarHistorico(Aluno::HistoricoDisciplinar("Álgebra Linear", 2023, 7.2f));

    filtroAlunos.adicionarElemento(aluno1);
    filtroAlunos.adicionarElemento(aluno2);

    // Criando filtro para professores
    Filtro<Professor> filtroProfessores;
    Professor professor("Maria Souza", "maria@email.com", "Ciência da Computação", "senha789");
    professor.adicionarDisciplina("Algoritmos");
    professor.adicionarDisciplina("Estruturas de Dados");
    filtroProfessores.adicionarElemento(professor);

    // Criando funcionário administrativo
    FuncionarioAdministrativo funcionario("Carlos Lima", "carlos@email.com", "RH", "Gerente", "senha789");

    // Vetor de usuários autenticáveis
    std::vector<UsuarioAutenticavel*> usuarios = {&aluno1, &aluno2, &professor, &funcionario};

    // Testando autenticação e relatórios
    for (auto usuario : usuarios) {
        std::string senha;
        std::cout << "Digite a senha de " << typeid(*usuario).name() << ": ";
        std::cin >> senha;

        if (usuario->autenticar(senha)) {
            std::cout << "Autenticação bem-sucedida!\n\n";
            usuario->gerarRelatorio();
        } else {
            std::cout << "Senha incorreta. Acesso negado.\n\n";
        }
    }

    // Filtrando alunos com média maior que 7.0
    auto alunosAprovados = filtroAlunos.filtrarPorCondicao([](const Aluno& aluno) {
        return aluno.getMedia() > 7.0;
    });

    // Imprimindo os alunos aprovados
    std::cout << "\nAlunos com média acima de 7.0:\n";
    for (const auto& aluno : alunosAprovados) {
        std::cout << aluno.getNome() << "\n";
    }

    // Filtrando professores que ministram "Algoritmos"
    auto professoresAlgoritmos = filtroProfessores.filtrarPorCondicao([](const Professor& professor) {
        return professor.ministraDisciplina("Algoritmos");
    });

    // Imprimindo professores de Algoritmos
    std::cout << "\nProfessores que ministram Algoritmos:\n";
    for (const auto& professor : professoresAlgoritmos) {
        std::cout << professor.getNome() << "\n";
    }

    return 0;
}
