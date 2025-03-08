#include "SinalHandler.h"
#include <cstdlib>
#include "Persistencia.h"

void SinalHandler::inicializar() {
    signal(SIGINT, tratador);  
    signal(SIGSEGV, tratador);  
    signal(SIGTERM, tratador);
}

void SinalHandler::tratador(int sinal) {
    std::cout << "O sistema recebeu o sinal " << sinal << ". Encerrando de forma segura...\n";
    
    // Aqui você pode salvar os dados antes de finalizar o programa
    std::vector<Aluno> alunos = Persistencia::carregarAlunos();
    std::vector<Disciplina> disciplinas = Persistencia::carregarDisciplinas();
    std::vector<Professor> professores = Persistencia::carregarProfessores();

    Persistencia::salvarAlunos(alunos);
    Persistencia::salvarDisciplinas(disciplinas);
    Persistencia::salvarProfessores(professores);
    
    exit(0); 
}
