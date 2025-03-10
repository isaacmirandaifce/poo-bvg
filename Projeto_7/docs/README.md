# Projeto 7: Métodos e Classes Genéricas - C++

## Descrição
Este projeto implementa um sistema genérico de filtragem e relatórios acadêmicos utilizando métodos e classes genéricas em C++. A classe `Filtro<T>` permite filtrar e manipular objetos relacionados ao sistema acadêmico, como alunos, professores e disciplinas.

## Funcionalidades
### Classe Genérica `Filtro<T>`
- `adicionarElemento(T elemento)`: Adiciona um elemento ao filtro.
- `filtrarPorCondicao(std::function<bool(const T&)> condicao)`: Filtra os elementos com base em uma condição.
- `imprimirTodos(std::function<void(const T&)> acao)`: Aplica uma ação a cada elemento (como imprimir informações no console).

### Classes do Sistema Acadêmico
- `Aluno`: Representa um aluno com nome e média.
- `Professor`: Representa um professor com nome e disciplina.
- `FuncionarioAdministrativo`: Representa um funcionário administrativo com nome e departamento.
- `Disciplina`: Representa uma disciplina com nome e ano.

### Exemplos de Uso
- Filtrar alunos com média acima de 7.0.
- Listar professores que ministram uma disciplina específica.
- Listar disciplinas cursadas por um aluno em um determinado ano.

## Estrutura do Projeto
```
Projeto_7/
├── include/  # Arquivos de cabeçalho (.h)
│   ├── Filtro.h
│   ├── Aluno.h
│   ├── Professor.h
│   ├── FuncionarioAdministrativo.h
│   └── Disciplina.h
├── src/  # Arquivos de implementação (.cpp)
│   ├── Filtro.cpp
│   ├── Aluno.cpp
│   ├── Professor.cpp
│   ├── FuncionarioAdministrativo.cpp
│   ├── Disciplina.cpp
│   └── main.cpp
├── docs/  # Documentação do projeto
│   ├── README.md
│   └── diagrama_uml.png
├── tests/  # Testes automatizados
│   └── test_Filtro.cpp
```

## Como Executar
1. Clone o repositório:
   ```bash
   git clone https://github.com/MatheusCarneir0/poo-bvg/tree/main/Projeto_7
   ```
2. Navegue até a pasta do projeto:
   ```bash
   cd Projeto_7
   ```
3. Compile o projeto:
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```
4. Execute o programa:
   ```bash
   ./Projeto_7.exe
   ```

## Testes
Para executar os testes automatizados, navegue até a pasta `tests/` e execute:
   ```bash
   cd tests
   cmake ..
   cmake --build .
   ctest
   ```

## Diagrama UML
Abaixo está o diagrama UML que representa a estrutura do projeto:

![Diagrama UML](../Diagrama_Projeto7.png)

## Requisitos
- Compilador C++ (g++ ou clang).
- CMake (versão 3.10 ou superior).

## Contribuições
Contribuições são bem-vindas! Siga as diretrizes de contribuição no arquivo `CONTRIBUTING.md`.
