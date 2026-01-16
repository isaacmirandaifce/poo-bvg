Projeto 4: Gerenciamento de Notas de Alunos

Descrição
Sistema para gerenciamento de notas de alunos com funcionalidades para cálculo de médias e verificação de status de aprovação.

Estrutura do Projeto

Projeto_4/
├── src/ # Código fonte principal
├── testes/ # Testes unitários
├── diagramas/ # Diagramas UML
└── README.md # Documentação

## Como Compilar e Executar

Programa Principal
```bash
g++ -std=c++11 src/*.cpp -o bin/programa
./bin/programa
Testes Unitários
bash
g++ -std=c++11 testes/testes.cpp src/Aluno.cpp src/Disciplina.cpp -o bin/testes
./bin/testes
Requisitos
Compilador C++11 ou superior

CMake (opcional)

Diagrama UML
https://diagramas/Diagrama_UML.png

Funcionalidades Implementadas
Classe Aluno com informações básicas

Classe Disciplina com notas e carga horária

Função amiga para verificação de aprovação

Testes unitários para validação




Como Compilar e Executar

1. Crie a estrutura de pastas conforme mostrado
2. Compile o programa principal:
   ```bash
   mkdir -p bin
   g++ -std=c++11 src/*.cpp -o bin/programa
   ./bin/programa
Para executar os testes:

bash
g++ -std=c++11 testes/testes.cpp src/Aluno.cpp src/Disciplina.cpp -o bin/testes
./bin/testes
Funcionalidades Implementadas
Classe Aluno:

Atributos privados para nome, matrícula e curso

Construtores padrão e parametrizado

Métodos para exibir informações e getters/setters

Classe Disciplina:

Atributos privados para nome, carga horária e nota

Construtores padrão e parametrizado

Métodos para manipulação de notas

Função amiga verificarAprovacao

Função Amiga:

Acessa diretamente o atributo privado nota da classe Disciplina

Implementa a lógica de aprovação (nota >= 6.0)

Testes Unitários:

Validação dos construtores

Verificação da função de aprovação

Testes de comportamento esperado

Organização do Projeto:

Separação clara entre código fonte, testes e documentação

Modularização em arquivos .h e .cpp

Uso adequado de modificadores de acesso