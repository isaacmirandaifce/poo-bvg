#include <iostream>
#include "SistemaAcademico.h"
#include "SinalHandler.h"
#include "Persistencia.h"

// Função para demonstrar o tratamento de exceções
void demonstrarExcecoes() {
    std::cout << "\n=== DEMONSTRAÇÃO DE TRATAMENTO DE EXCEÇÕES ===" << std::endl;

    try {
        // Tentar carregar um arquivo inexistente
        std::cout << "1. Testando carregamento de arquivo inexistente..." << std::endl;
        Persistencia::carregarAlunos("arquivo_inexistente.csv");
    } catch (const ArquivoNaoEncontradoException& e) {
        std::cout << "   Exceção capturada: " << e.what() << std::endl;
    }

    try {
        // Criar dados de teste com erro de conversão
        std::cout << "2. Testando tratamento de dados corrompidos..." << std::endl;
        std::ofstream arquivo_teste("teste_corrupto.csv");
        arquivo_teste << "id,nome,curso,nota\n";
        arquivo_teste << "abc,João,Eng,8.5\n";  // ID inválido
        arquivo_teste.close();

        Persistencia::carregarAlunos("teste_corrupto.csv");
    } catch (const FalhaConversaoException& e) {
        std::cout << "   Exceção capturada: " << e.what() << std::endl;
    }

    // Limpar arquivo de teste
    std::remove("teste_corrupto.csv");

    std::cout "===============================================" << std::endl;
}

// Função para demonstrar o tratamento de sinais
void demonstrarSinais() {
    std::cout << "\n=== INFORMAÇÕES SOBRE TRATAMENTO DE SINAIS ===" << std::endl;
    std::cout << "O sistema está preparado para tratar os seguintes sinais:" << std::endl;
    std::cout << "- SIGINT (Ctrl+C): Interrupção pelo usuário" << std::endl;
    std::cout << "- SIGSEGV: Violação de segmentação" << std::endl;
    std::cout << "- SIGTERM: Finalização pelo sistema operacional" << std::endl;
    std::cout << "\nQuando um desses sinais for recebido:" << std::endl;
    std::cout << "1. O sistema tentará salvar todos os dados" << std::endl;
    std::cout << "2. Uma mensagem informativa será exibida" << std::endl;
    std::cout << "3. O programa será encerrado de forma controlada" << std::endl;
    std::cout << "\nPara testar: pressione Ctrl+C durante a execução" << std::endl;
    std::cout << "===============================================" << std::endl;
}

// Função para criar dados de exemplo
void criarDadosExemplo() {
    std::cout << "\n=== CRIANDO DADOS DE EXEMPLO ===" << std::endl;

    try {
        // Criar alguns alunos de exemplo
        std::vector<Aluno> alunos = {
            Aluno(1, "Maria Silva", "Engenharia de Software", 8.5),
            Aluno(2, "João Santos", "Ciência da Computação", 7.8),
            Aluno(3, "Ana Costa", "Sistemas de Informação", 9.2)
        };

        // Criar alguns professores de exemplo
        std::vector<Professor> professores = {
            Professor(1, "Dr. Carlos Mendes", "Programação", "Computação"),
            Professor(2, "Dra. Rita Oliveira", "Banco de Dados", "Computação"),
            Professor(3, "Prof. Luis Ferreira", "Matemática", "Exatas")
        };

        // Criar algumas disciplinas de exemplo
        std::vector<Disciplina> disciplinas = {
            Disciplina(101, "Programação Orientada a Objetos", 60, 4),
            Disciplina(102, "Banco de Dados", 80, 4),
            Disciplina(103, "Estruturas de Dados", 80, 6)
        };

        // Salvar os dados
        Persistencia::salvarAlunos(alunos);
        Persistencia::salvarProfessores(professores);
        Persistencia::salvarDisciplinas(disciplinas);

        std::cout << "Dados de exemplo criados com sucesso!" << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Erro ao criar dados de exemplo: " << e.what() << std::endl;
    }

    std::cout << "================================" << std::endl;
}

int main() {
    std::cout << "========== SISTEMA ACADÊMICO RESILIENTE ==========" << std::endl;
    std::cout << "Projeto Avaliativo 8 - Tratamento de Exceções e Sinais" << std::endl;
    std::cout << "===================================================" << std::endl;

    // Inicializar tratamento de sinais
    SinalHandler::inicializar();

    int opcaoInicial = 0;

    std::cout << "\nEscolha uma opção:" << std::endl;
    std::cout << "1. Executar sistema principal" << std::endl;
    std::cout << "2. Demonstrar tratamento de exceções" << std::endl;
    std::cout << "3. Informações sobre tratamento de sinais" << std::endl;
    std::cout << "4. Criar dados de exemplo" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "Opção: ";

    std::cin >> opcaoInicial;

    switch (opcaoInicial) {
        case 1: {
            try {
                SistemaAcademico sistema;
                sistema.executarMenu();
            } catch (const std::exception& e) {
                std::cerr << "Erro crítico no sistema: " << e.what() << std::endl;
                return 1;
            }
            break;
        }

        case 2:
            demonstrarExcecoes();
            break;

        case 3:
            demonstrarSinais();
            break;

        case 4:
            criarDadosExemplo();
            break;

        case 0:
            std::cout << "Saindo..." << std::endl;
            return 0;

        default:
            std::cout << "Opção inválida!" << std::endl;
            return 1;
    }

    return 0;
}
