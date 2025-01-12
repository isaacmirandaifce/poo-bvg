# - Projeto 4 - POO

Este repositório contém a implementação de um sistema de gerenciamento de notas de alunos utilizando os conceitos de Programação Orientada a Objetos (POO) em C++. O projeto aborda a modularização, encapsulamento, uso de funções amigas e organização em múltiplos arquivos, com foco em boas práticas de desenvolvimento.

# - Estrutura do Projeto

- Aluno.h: Declaração da classe Aluno.
- Aluno.cpp: Implementação dos métodos da classe Aluno.
- Disciplina.h: Declaração da classe Disciplina.
- Disciplina.cpp: Implementação dos métodos da classe Disciplina.
- main.cpp: Programa principal que demonstra a funcionalidade do sistema.

# - Funções

- **Classe Aluno**
- Atributos Privados:

- std::string nome: Nome do aluno.
- std::string matricula: Matrícula do aluno.
- std::string curso: Curso do aluno.
- std::vector<Disciplina> disciplinas: Lista de disciplinas associadas ao aluno.

- Métodos Públicos:

- Construtor Padrão: Inicializa os atributos com valores padrão.
- Construtor Parametrizado: Inicializa os atributos com valores fornecidos.
- void exibirInformacoes(): Exibe as informações básicas do aluno.
- void adicionarDisciplina(const Disciplina& disciplina): Adiciona uma disciplina à lista do aluno.
- std::vector<Disciplina> getDisciplinas() const: Retorna a lista de disciplinas associadas ao aluno.

- **Classe Disciplina**
- Atributos Privados:

- std::string nome: Nome da disciplina.
- int cargaHoraria: Carga horária da disciplina.
- float nota: Nota obtida pelo aluno na disciplina.

- Métodos Públicos:

- Construtor Padrão: Inicializa os atributos com valores padrão.
- Construtor Parametrizado: Inicializa os atributos com valores fornecidos.
- void setNota(float nota): Define o valor da nota, garantindo que esteja no intervalo válido (0.0 a 10.0).
- float getNota() const: Retorna a nota da disciplina.
- std::string getNome() const: Retorna o nome da disciplina.

- Função Amiga:
- bool verificarAprovacao(const Disciplina& disciplina): Verifica se o aluno foi aprovado na disciplina (nota >= 6.0).

- **main.cpp**
- Cria objetos da classe Aluno e associa disciplinas.
- Exibe as informações do aluno.
- Utiliza a função amiga para verificar a aprovação em cada disciplina.
- Demonstra a funcionalidade do sistema com exemplos práticos.

