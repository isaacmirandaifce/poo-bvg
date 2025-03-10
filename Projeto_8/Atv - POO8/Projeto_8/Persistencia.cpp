#include "Persistencia.h"
#include <fstream>
#include <iostream>

void Persistencia::salvarDados(const std::vector<Aluno>& alunos, const std::vector<Professor>& professores, const std::vector<Disciplina>& disciplinas) {
    std::ofstream arquivo("dados.txt");
    if (!arquivo) throw std::runtime_error("Erro ao abrir o arquivo para escrita.");
    
    arquivo << alunos.size() << "\n";
    for (const auto& aluno : alunos) {
        arquivo << aluno.getNome() << " " << aluno.getIdade() << "\n";
    }
    
    arquivo << professores.size() << "\n";
    for (const auto& professor : professores) {
        arquivo << professor.getNome() << " " << professor.getEspecializacao() << "\n";
    }
    
    arquivo << disciplinas.size() << "\n";
    for (const auto& disciplina : disciplinas) {
        arquivo << disciplina.getNome() << " " << disciplina.getCargaHoraria() << "\n";
    }
}

void Persistencia::carregarDados(std::vector<Aluno>& alunos, std::vector<Professor>& professores, std::vector<Disciplina>& disciplinas) {
    std::ifstream arquivo("dados.txt");
    if (!arquivo) return; // Se não existe, inicia com lista vazia
    
    size_t tamanho;
    alunos.clear();
    professores.clear();
    disciplinas.clear();
    
    arquivo >> tamanho;
    for (size_t i = 0; i < tamanho; ++i) {
        std::string nome;
        int idade;
        arquivo >> nome >> idade;
        alunos.emplace_back(nome, idade);
    }
    
    arquivo >> tamanho;
    for (size_t i = 0; i < tamanho; ++i) {
        std::string nome, especializacao;
        arquivo >> nome >> especializacao;
        professores.emplace_back(nome, especializacao);
    }
    
    arquivo >> tamanho;
    for (size_t i = 0; i < tamanho; ++i) {
        std::string nome;
        int cargaHoraria;
        arquivo >> nome >> cargaHoraria;
        disciplinas.emplace_back(nome, cargaHoraria);
    }
}