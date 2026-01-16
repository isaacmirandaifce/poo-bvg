#include "Disciplina.h"
#include <iostream>

// Construtor padrão: inicializa a disciplina com valores padrão
Disciplina::Disciplina() : nome(""), cargaHoraria(0), nota(0.0f) {}


// Construtor parametrizado: permite inicializar a disciplina com valores definidos
Disciplina::Disciplina(std::string nome, int cargaHoraria, float nota)
: nome(nome), cargaHoraria(cargaHoraria), nota(nota) {}


// Método setter: define a nota do aluno na disciplina
void Disciplina::setNota(float nota) {
this->nota = nota; // usa 'this' para diferenciar o atributo do parâmetro
}


// Método getter: retorna a nota da disciplina
float Disciplina::getNota() const {
return nota;
}


// Getters: retornam informações básicas da disciplina
std::string Disciplina::getNome() const { return nome; }
int Disciplina::getCargaHoraria() const { return cargaHoraria; }


// Função amiga: acessa o atributo privado 'nota' para verificar aprovação
// Critério: aprovado se a nota for maior ou igual a 6.0
bool verificarAprovacao(const Disciplina& disciplina) {
return disciplina.nota >= 6.0f;
}