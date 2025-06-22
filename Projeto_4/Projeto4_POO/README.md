
# README.md completo para seu projeto

````markdown
# Sistema Básico de Alunos e Disciplinas em C++

Este projeto é um exemplo simples de aplicação orientada a objetos em C++, que modela alunos e disciplinas, permitindo atribuir notas e verificar aprovação dos alunos nas disciplinas.

---

## Descrição do Projeto

O sistema cria objetos das classes `Aluno` e `Disciplina`, permitindo:

- Cadastrar um aluno com nome, matrícula e curso.
- Criar disciplinas com nome e carga horária.
- Definir a nota obtida pelo aluno em cada disciplina.
- Exibir as informações do aluno.
- Verificar se o aluno foi aprovado ou reprovado em cada disciplina (nota mínima para aprovação: 6.0).

---

## Estrutura dos Arquivos

- **main.cpp**  
  Arquivo principal que contém a função `main()`. Cria objetos das classes `Aluno` e `Disciplina`, atribui notas e exibe informações e status de aprovação.

- **Aluno.h / Aluno.cpp**  
  Definição e implementação da classe `Aluno`, que armazena informações do aluno (nome, matrícula, curso) e método para exibir essas informações.

- **Disciplina.h / Disciplina.cpp**  
  Definição e implementação da classe `Disciplina`, que representa uma disciplina com nome, carga horária e nota. Inclui métodos para definir e obter a nota, e uma função amiga para verificar aprovação.

---

## Como Compilar e Executar

### Requisitos

- Compilador C++ (exemplo: `g++`, parte do MinGW no Windows ou GCC no Linux/Mac).

### Passos para compilar

1. Abra o terminal (Prompt de comando, PowerShell, Bash, etc).

2. Navegue até a pasta do projeto (substitua `<caminho_do_projeto>` pelo caminho da sua pasta):

```bash
cd <caminho_do_projeto>
````

3. Compile todos os arquivos `.cpp` juntos para que o linker encontre todas as implementações:

```bash
g++ -Wall -Wextra -g3 main.cpp Aluno.cpp Disciplina.cpp -o output/main.exe
```

> **Nota:**
>
> * `-Wall -Wextra` ativam avisos para ajudar a detectar problemas no código.
> * `-g3` inclui informações para facilitar a depuração (debug).
> * `output/main.exe` é o caminho e nome do executável gerado. Você pode modificar para outro nome ou pasta.
> * Se a pasta `output` não existir, crie-a antes de compilar (exemplo: `mkdir output`).

4. Execute o programa:

* No Windows:

```bash
output\main.exe
```

* No Linux/Mac:

```bash
./output/main.exe
```

---

## Exemplo de saída esperada

```plaintext
Nome: Maria Silva
Matricula: 2023001
Curso: ADS

Status nas Disciplinas:
Disciplina: Matemática - Nota: 7.5 -> Aprovado
Disciplina: Programação - Nota: 5 -> Reprovado
```

---

## Explicação das Classes

### Aluno

Representa um aluno com os seguintes atributos:

* Nome
* Matrícula
* Curso

Métodos principais:

* Construtores padrão e parametrizado.
* `exibirInformacoes()` — exibe os dados do aluno.

---

### Disciplina

Representa uma disciplina com:

* Nome
* Carga horária
* Nota (atributo privado)

Métodos principais:

* Construtores padrão e parametrizado.
* `setNota(float)` — define a nota da disciplina.
* `getNota()` — retorna a nota.
* Função amiga `verificarAprovacao` — verifica e exibe se o aluno foi aprovado (nota >= 6.0).

---

## Possíveis melhorias

* Implementar cadastro e gerenciamento de vários alunos e disciplinas.
* Adicionar cálculo de média geral do aluno.
* Permitir entrada de dados pelo usuário (input).
* Criar menus interativos para facilitar o uso.

---

## Licença

Este projeto é aberto para fins educacionais e pode ser modificado livremente.

---

## Autor

Projeto criado para fins didáticos.

---

