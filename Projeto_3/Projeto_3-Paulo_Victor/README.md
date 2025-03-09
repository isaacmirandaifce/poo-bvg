# 🧑‍💼 Sistema de Gerenciamento de Pessoas

Este é um projeto em C++ que implementa uma classe `Pessoa` com informações básicas de uma pessoa, como nome e telefone, e demonstra como criar, armazenar e exibir essas informações usando um vetor de ponteiros. O código também implementa a destruição dinâmica dos objetos criados.

## 🚀 Funcionalidade

O código cria três objetos da classe `Pessoa` com informações fictícias (nome e telefone) e os armazena em um vetor. Em seguida, ele exibe o nome e o telefone de cada pessoa e, ao final, desaloca a memória utilizada por esses objetos. O código faz uso de destruição dinâmica, liberando a memória alocada para os objetos `Pessoa` com o operador `delete`.

### Funções Principais:
- **Construtores**: Um construtor padrão e um construtor que recebe nome e telefone.
- **Destruidor**: Um destruidor que exibe uma mensagem ao destruir o objeto.
- **Métodos**: 
  - `imprimirNome()`: Exibe o nome da pessoa.
  - `imprimirTelefone()`: Exibe o telefone da pessoa.

## 🖥️ Como Executar

### Pré-requisitos
- Certifique-se de ter um compilador C++ instalado. Por exemplo, `g++` ou `clang++`.

### Passos para Executar

1. Clone o repositório para sua máquina local:
   ```bash
   git clone https://github.com/seu-usuario/Projeto_3-Paulo_Victor.git
   ```

2. Navegue até o diretório do projeto:
   ```bash
   cd Projeto_3-Paulo_Victor
   ```

3. Compile o código com o comando:
   ```bash
   g++ -Iinclude src/*.cpp -o build/programa.exe
   ```

4. Execute o programa compilado:
   ```bash
   ./build/programa.exe
   ```

Ao rodar o programa, você verá a saída exibindo os nomes e telefones das pessoas criadas e, em seguida, uma mensagem indicando que o objeto foi destruído.

## 📄 Arquivos do Projeto

- `Pessoa.h`: Declaração da classe `Pessoa`, com os atributos e métodos.
- `Pessoa.cpp`: Definição dos métodos da classe `Pessoa`.
- `main.cpp`: Código principal que cria os objetos, exibe suas informações e gerencia a memória.

## ⚙️ Como Funciona

- A classe `Pessoa` possui dois atributos privados: `nome` e `telefone`, que são definidos via construtor. 
- O código principal (no arquivo `main.cpp`) cria três objetos da classe `Pessoa` dinamicamente usando `new` e os armazena em um vetor.
- Em seguida, o programa itera sobre o vetor e chama os métodos `imprimirNome()` e `imprimirTelefone()` para exibir as informações.
- Após a exibição, o programa destrói os objetos e libera a memória alocada.

## 📦 Dependências

Nenhuma dependência externa é necessária para este projeto.