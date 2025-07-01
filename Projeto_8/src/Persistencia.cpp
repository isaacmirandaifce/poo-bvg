#include "Persistencia.h"
#include "SistemaAcademico.h"
#include "Excecoes.h"
#include <fstream>
#include <vector>

template<typename T>
void salvarLista(const std::vector<T>& lista, const std::string& nomeArquivo) {
    std::ofstream outFile(nomeArquivo);
    if (!outFile.is_open()) {
        throw PermissaoNegadaException(nomeArquivo);
    }
    for (const auto& item : lista) {
        outFile << item << std::endl;
    }
}

template<typename T>
std::vector<T> carregarLista(const std::string& nomeArquivo) {
    std::ifstream inFile(nomeArquivo);
    if (!inFile.is_open()) {

        return {};
    }

    std::vector<T> lista;
    std::string linha;
    while (std::getline(inFile, linha)) {
        if (linha.empty()) continue;

        std::stringstream ss(linha);
        T item;
        ss >> item;

        if (ss.fail() || !ss.eof()) {
            throw FalhaConversaoException(linha);
        }
        lista.push_back(item);
    }
    return lista;
}


void Persistencia::salvarDados(const SistemaAcademico& sistema) {
    std::cout << "\n[PERSISTENCIA] Tentando salvar dados..." << std::endl;
    try {
        salvarLista(sistema.getAlunos(), "dados_alunos.csv");
        salvarLista(sistema.getProfessores(), "dados_professores.csv");
        salvarLista(sistema.getDisciplinas(), "dados_disciplinas.csv");
        std::cout << "[PERSISTENCIA] Dados salvos com sucesso!" << std::endl;
    } catch (const PermissaoNegadaException& e) {
        std::cerr << e.what() << std::endl;
    }
}

void Persistencia::carregarDados(SistemaAcademico& sistema) {
    std::cout << "[PERSISTENCIA] Tentando carregar dados..." << std::endl;
    try {
        sistema.setAlunos(carregarLista<Aluno>("dados_alunos.csv"));
        sistema.setProfessores(carregarLista<Professor>("dados_professores.csv"));
        sistema.setDisciplinas(carregarLista<Disciplina>("dados_disciplinas.csv"));
        std::cout << "[PERSISTENCIA] Dados carregados com sucesso!" << std::endl;
    } catch (const FalhaConversaoException& e) {
        std::cerr << e.what() << std::endl;
    }
}