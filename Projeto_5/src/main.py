from aluno import Aluno
from professor import Professor
from monitor import Monitor

def main():
    # Criando um aluno
    aluno = Aluno(nome="João Silva", email="joao@email.com", matricula="20230101", curso="ADS")
    
    # Criando um professor
    professor = Professor(nome="Carlos Oliveira", email="carlos@email.com", 
                          area_de_atuacao="Matemática", disciplinas_ministradas=["Cálculo", "Álgebra"])

    # Criando um monitor
    monitor = Monitor(nome="Pedro Alves", email="pedro@email.com", 
                      matricula="20220123", curso="ADS", 
                      area_de_atuacao="Matemática", disciplinas_ministradas=["Cálculo"])

    # Gerando relatórios
    aluno.gerar_relatorio()
    professor.gerar_relatorio()
    monitor.listar_disciplinas_monitoradas()

if __name__ == "__main__":
    main()
