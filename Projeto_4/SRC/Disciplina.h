#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>

// Classe Disciplina: representa uma matéria com nome, carga horária e nota do aluno
class Disciplina {
private:
// Atributos privados para manter o encapsulamento
std::string nome; // Nome da disciplina (ex: Programação I)
int cargaHoraria; // Carga horária total da disciplina (em horas)
float nota; // Nota obtida pelo aluno na disciplina


public:
// Construtor padrão: inicializa a disciplina com valores padrão
Disciplina();


// Construtor parametrizado: permite definir nome, carga horária e nota inicial (opcional)
Disciplina(std::string nome, int cargaHoraria, float nota = 0.0f);
// Métodos para manipular a nota
void setNota(float nota); // Define uma nova nota
float getNota() const; // Retorna a nota atual
// Métodos getters: retornam as informações básicas da disciplina
std::string getNome() const; // Retorna o nome da disciplina
int getCargaHoraria() const; // Retorna a carga horária
// Função amiga: tem permissão para acessar atributos privados da classe
// Usada para verificar se o aluno está aprovado (nota >= 6.0)
friend bool verificarAprovacao(const Disciplina& disciplina);
};


// Declaração da função amiga fora da classe (implementada em Disciplina.cpp)
bool verificarAprovacao(const Disciplina& disciplina);

#endif // DISCIPLINA_H