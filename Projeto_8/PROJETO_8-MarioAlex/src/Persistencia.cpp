#include "Persistencia.h"
#include "Exceptions.h"
#include <fstream>
#include <iostream>
#include <filesystem>


namespace fs = std::filesystem;


Persistencia::Persistencia(const std::string &dir): pasta(dir) {
// cria a pasta se não existir
try {
if (!fs::exists(pasta)) {
fs::create_directories(pasta);
}
} catch (const fs::filesystem_error &e) {
// não podemos lançar aqui porque chamador pode estar em try/catch
std::cerr << "Aviso: nao foi possivel criar pasta de dados: " << e.what() << std::endl;
}
}

Persistencia::~Persistencia() {}


std::string Persistencia::caminhoAlunos() { return pasta + "alunos.csv"; }
std::string Persistencia::caminhoProfessores() { return pasta + "professores.csv"; }
std::string Persistencia::caminhoDisciplinas() { return pasta + "disciplinas.csv"; }


void Persistencia::carregarArquivo(const std::string &caminho, std::vector<std::string> &linhas) {
std::ifstream ifs(caminho);
if (!ifs.is_open()) {
if (!fs::exists(caminho)) throw ArquivoNaoEncontradoException(caminho);
else throw PermissaoNegadaException(caminho);
}


std::string linha;
while (std::getline(ifs, linha)) {
if (!linha.empty()) linhas.push_back(linha);
}


if (ifs.bad()) {
throw ArquivoException(std::string("Erro de leitura: ") + caminho);
}
}

void Persistencia::salvarArquivo(const std::string &caminho, const std::vector<std::string> &linhas) {
std::ofstream ofs(caminho, std::ios::trunc);
if (!ofs.is_open()) {
if (!fs::exists(caminho)) {
// tentar criar
std::ofstream trycreate(caminho);
if (!trycreate.is_open()) throw PermissaoNegadaException(caminho);
trycreate.close();
} else {
throw PermissaoNegadaException(caminho);
}
}


for (const auto &l : linhas) ofs << l << '\n';
if (!ofs) throw ArquivoException(std::string("Erro ao gravar: ") + caminho);
}

void Persistencia::carregarTudo(std::vector<Aluno> &alunos, std::vector<Professor> &profs, std::vector<Disciplina> &discs) {
// Carrega alunos
try {
std::vector<std::string> linhas;
carregarArquivo(caminhoAlunos(), linhas);
for (const auto &l : linhas) {
alunos.push_back(Aluno::fromCSV(l));
}
} catch (ArquivoNaoEncontradoException &e) {
std::cerr << "Arquivo de alunos nao encontrado. Iniciando lista vazia." << std::endl;
}


// Carrega professores
try {
std::vector<std::string> linhas;
carregarArquivo(caminhoProfessores(), linhas);
for (const auto &l : linhas) {
profs.push_back(Professor::fromCSV(l));
}
} catch (ArquivoNaoEncontradoException &e) {
std::cerr << "Arquivo de professores nao encontrado. Iniciando lista vazia." << std::endl;
}

// Carrega disciplinas
try {
std::vector<std::string> linhas;
carregarArquivo(caminhoDisciplinas(), linhas);
for (const auto &l : linhas) {
discs.push_back(Disciplina::fromCSV(l));
}
} catch (ArquivoNaoEncontradoException &e) {
std::cerr << "Arquivo de disciplinas nao encontrado. Iniciando lista vazia." << std::endl;
}
}


void Persistencia::salvarAlunos(const std::vector<Aluno> &alunos) {
std::vector<std::string> linhas;
for (const auto &a : alunos) linhas.push_back(a.toCSV());
salvarArquivo(caminhoAlunos(), linhas);
}

void Persistencia::salvarTudo(const std::vector<Aluno> &alunos, const std::vector<Professor> &profs, const std::vector<Disciplina> &discs) {
// salvar cada arquivo dentro de try/catch para dar resiliencia
try {
salvarAlunos(alunos);
} catch (const ArquivoException &e) {
std::cerr << "Erro ao salvar alunos: " << e.what() << std::endl;
}


try {
std::vector<std::string> linhas;
for (const auto &p : profs) linhas.push_back(p.toCSV());
salvarArquivo(caminhoProfessores(), linhas);
} catch (const ArquivoException &e) {
std::cerr << "Erro ao salvar professores: " << e.what() << std::endl;
}


try {
std::vector<std::string> linhas;
for (const auto &d : discs) linhas.push_back(d.toCSV());
salvarArquivo(caminhoDisciplinas(), linhas);
} catch (const ArquivoException &e) {
std::cerr << "Erro ao salvar disciplinas: " << e.what() << std::endl;
}
}