#include <iostream>
#include "Aluno.h"
#include "Disciplina.h"

// Implementação da função amiga para verificar o status de aprovação 
void verificarStatusAprovacao(const Aluno& aluno, const Disciplina& disciplina) {
    std::cout << "Verificando status na disciplina: " << disciplina.getNome() << "..." << std::endl;
    
    // A função acessa diretamente o atributo privado 'nota' da classe Disciplina 
    if (disciplina.nota >= 6.0) {
        std::cout << "  -> Status: APROVADO(A) (Nota: " << disciplina.nota << ")" << std::endl;
    } else {
        std::cout << "  -> Status: REPROVADO(A) (Nota: " << disciplina.nota << ")" << std::endl;
    }
}

int main() {
    // 1. Criar objeto Aluno 
    Aluno aluno1("Joao Silva", "20240102", "Analise e Desenvolvimento de Sistemas");

    // 2. Criar objetos Disciplina 
    Disciplina disciplina1("Algoritmos e Programacao", 80);
    Disciplina disciplina2("Banco de Dados", 60);

    // Configurar as notas do aluno nas disciplinas
    disciplina1.setNota(7.5f);
    disciplina2.setNota(5.9f);

    // 3. Exibir as informações básicas do aluno 
    aluno1.exibirInformacoes();

    // 4. Utilizar a função amiga para verificar a aprovação 
    std::cout << "\nVERIFICACAO DE APROVACAO:" << std::endl;
    verificarStatusAprovacao(aluno1, disciplina1);
    verificarStatusAprovacao(aluno1, disciplina2);

    return 0;
}