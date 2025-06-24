# Sistema Acadêmico - Aluno e Disciplina

Este projeto implementa um sistema acadêmico básico em C++ com as classes `Aluno` e `Disciplina`, demonstrando conceitos de programação orientada a objetos, incluindo construtores, métodos, encapsulamento e funções amigas.

## Estrutura do Projeto

```
projeto/
├── aluno.h            # Arquivo de cabeçalho da classe Aluno
├── aluno.cpp          # Implementação da classe Aluno
├── disciplina.h       # Arquivo de cabeçalho da classe Disciplina
├── disciplina.cpp     # Implementação da classe Disciplina
└── README.md          # Este arquivo
```

## Classes Implementadas

### Classe Aluno

Representa um estudante com suas informações básicas.

#### Atributos Privados
- `nome`: String que armazena o nome do aluno
- `matricula`: String que armazena a matrícula do aluno
- `curso`: String que armazena o curso do aluno

#### Métodos Públicos
- `Aluno()`: Construtor padrão que inicializa os atributos como strings vazias
- `Aluno(string nome, string matricula, string curso)`: Construtor parametrizado
- `exibirInformacoes()`: Método const que exibe as informações do aluno

### Classe Disciplina

Representa uma disciplina acadêmica com suas características e nota do aluno.

#### Atributos Privados
- `nome`: String que armazena o nome da disciplina
- `cargaHoraria`: Inteiro que armazena a carga horária em horas
- `nota`: Float que armazena a nota do aluno na disciplina

#### Métodos Públicos
- `Disciplina()`: Construtor padrão (nota inicializada como 0.0)
- `Disciplina(string nome, int cargaHoraria)`: Construtor parametrizado
- `setNota(float nota)`: Define a nota da disciplina
- `getNota()`: Retorna a nota da disciplina (método const)
- `exibirDados()`: Exibe informações completas da disciplina (método const)

#### Função Amiga
- `verificarAprovacao(const Disciplina& d)`: Verifica se o aluno foi aprovado na disciplina (nota >= 6.0)

## Funcionalidades Demonstradas

1. **Encapsulamento**: Atributos privados com acesso controlado via métodos
2. **Construtores**: Padrão e parametrizado para inicialização flexível
3. **Métodos const**: Garantem que o objeto não seja modificado durante consultas
4. **Função amiga**: Permite acesso aos atributos privados de forma controlada
5. **Validação de aprovação**: Sistema de verificação baseado em nota mínima

## Como Compilar

### Pré-requisitos
- Compilador C++ (g++, clang++, etc.)
- Padrão C++11 ou superior

### Compilação Básica
```bash
g++ -o programa aluno.cpp disciplina.cpp main.cpp
```

### Com flags de otimização
```bash
g++ -std=c++11 -Wall -Wextra -O2 -o programa aluno.cpp disciplina.cpp main.cpp
```

## Exemplo de Uso

```cpp
#include "Aluno.h"
#include "Disciplina.h"

int main() {
    // Criando um aluno
    Aluno aluno("João Silva", "2023001", "Engenharia de Software");
    aluno.exibirInformacoes();
    
    // Criando uma disciplina
    Disciplina disciplina("Programação Orientada a Objetos", 60);
    disciplina.setNota(8.5f);
    disciplina.exibirDados();
    
    // Verificando aprovação
    verificarAprovacao(disciplina);
    
    return 0;
}
```

## Exemplo de Saída

```
Nome: João Silva
Matricula: 2023001
Curso: Engenharia de Software

Disciplina: Programação Orientada a Objetos
Carga Horária: 60h
Nota: 8.5

Status da disciplina "Programação Orientada a Objetos": Aprovado
```

## Diagrama de Classes

O projeto segue a estrutura apresentada no diagrama UML:

- **Disciplina**: Contém informações da disciplina e nota
- **Aluno**: Contém informações pessoais e acadêmicas do estudante
- **Relação**: Um aluno pode estar matriculado em várias disciplinas

## Conceitos de POO Abordados

- **Encapsulamento**: Atributos privados com acesso controlado
- **Construtores**: Inicialização adequada de objetos
- **Métodos const**: Garantia de imutabilidade em consultas
- **Função amiga**: Acesso controlado a membros privados
- **Separação de responsabilidades**: Cada classe tem uma responsabilidade específica

## Critérios de Aprovação

- **Aprovado**: Nota >= 6.0
- **Reprovado**: Nota < 6.0

## Melhorias Possíveis

- Implementar uma classe `SistemaAcademico` para gerenciar múltiplos alunos e disciplinas
- Adicionar validação de entrada (nota entre 0-10, matrícula única)
- Implementar operadores de comparação e ordenação
- Adicionar persistência de dados em arquivo
- Criar sistema de histórico escolar
- Implementar cálculo de média geral e coeficiente de rendimento
- Adicionar diferentes tipos de avaliação (prova, trabalho, etc.)

## Estrutura de Dados Recomendada

Para expansão do sistema, considere:
- `vector<Aluno>` para lista de alunos
- `vector<Disciplina>` para lista de disciplinas
- `map<string, vector<Disciplina>>` para histórico por aluno