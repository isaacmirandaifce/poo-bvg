# Projeto Pessoa

Este projeto implementa uma classe `Pessoa` em C++ para demonstrar conceitos básicos de programação orientada a objetos, incluindo construtores, destrutores e gerenciamento de memória dinâmica.

## Estrutura do Projeto

```
projeto/
├── main.cpp           # Arquivo principal com função main
├── src/
│   ├── Pessoa.h       # Arquivo de cabeçalho da classe Pessoa
│   └── pessoa.cpp     # Implementação da classe Pessoa
└── README.md          # Este arquivo
```

## Classe Pessoa

A classe `Pessoa` possui os seguintes atributos e métodos:

### Atributos Privados
- `nome`: String que armazena o nome da pessoa
- `telefone`: String que armazena o telefone da pessoa

### Métodos Públicos
- `Pessoa()`: Construtor padrão que inicializa os atributos como strings vazias
- `Pessoa(string nome, string telefone)`: Construtor parametrizado que inicializa os atributos com valores fornecidos
- `~Pessoa()`: Destrutor que exibe uma mensagem ao destruir o objeto
- `imprimirDados()`: Método que exibe o nome e telefone da pessoa

## Funcionalidades Demonstradas

O programa principal (`main.cpp`) demonstra:

1. **Criação de objetos**: Instanciação usando construtor padrão e parametrizado
2. **Gerenciamento de memória**: Alocação dinâmica com `new` e liberação com `delete`
3. **Uso de containers STL**: Armazenamento de ponteiros em `vector`
4. **Iteração**: Percorrendo o vector para exibir dados e liberar memória

## Como Compilar e Executar

### Pré-requisitos
- Compilador C++ (g++, clang++, etc.)
- Sistema operacional compatível (Windows, Linux, macOS)

### Compilação
```bash
g++ -o programa main.cpp src/pessoa.cpp
```

### Execução
```bash
./programa
```

## Exemplo de Saída

```
Objeto pessoa inicializado sem parâmetros
Nome: 
Telefone: 

Nome: Rafael
Telefone: (88) 99804-3347

Nome: Pessoa2
Telefone: (88) 99999-9999

Nome: Pessoa3
Telefone: (88) 90000-0000

Destruindo objeto da pessoa: Pessoa3
Destruindo objeto da pessoa: Pessoa2
Destruindo objeto da pessoa: Rafael
Destruindo objeto da pessoa: 
```

## Conceitos Abordados

- **Programação Orientada a Objetos**: Encapsulamento, construtores e destrutores
- **Gerenciamento de Memória**: Alocação e liberação dinâmica de memória
- **Containers STL**: Uso de `vector` para armazenar ponteiros
- **Boas Práticas**: Liberação adequada de memória para evitar vazamentos

## Observações

- O programa demonstra o uso correto de `new` e `delete` para gerenciamento manual de memória
- O destrutor é chamado automaticamente quando `delete` é executado
- É importante sempre liberar a memória alocada dinamicamente para evitar vazamentos

## Melhorias Possíveis

- Implementar métodos getter e setter para os atributos
- Adicionar validação de entrada para telefones
- Usar smart pointers (`unique_ptr`, `shared_ptr`) para gerenciamento automático de memória
- Implementar operadores de comparação e atribuição