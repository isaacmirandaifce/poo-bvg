#ifndef ALUNO_H
#define ALUNO_H

#include <string>

// Classe que representa um aluno com informações básicas como nome, matrícula e curso
class Aluno {
private:
// Atributos privados para garantir o encapsulamento
std::string nome; // Nome completo do aluno
std::string matricula; // Número de matrícula do aluno
std::string curso; // Nome do curso em que o aluno está matriculado


public:
// Construtor padrão: inicializa o aluno com valores vazios
Aluno();


// Construtor parametrizado: inicializa o aluno com valores definidos
Aluno(std::string nome, std::string matricula, std::string curso);
// Método para exibir todas as informações do aluno no console
void exibirInformacoes() const;
// Métodos getters: retornam os valores dos atributos privados
std::string getNome() const;
std::string getMatricula() const;
std::string getCurso() const;
// Métodos setters: permitem alterar os valores dos atributos privados
void setNome(std::string nome);
void setMatricula(std::string matricula);
void setCurso(std::string curso);
};

#endif // ALUNO_H