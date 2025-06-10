## Gabriel Alves de Sales


# Projeto Avaliativo 4: Gerenciamento de Notas de Alunos em C++

[cite\_start]Este projeto é uma atividade avaliativa focada em consolidar conhecimentos de C++, especialmente em modularização, modificadores de acesso e o uso de funções amigas[cite: 1].

## 📝 Descrição Geral

[cite\_start]O sistema foi desenvolvido para realizar o gerenciamento de notas de alunos em diferentes disciplinas[cite: 3]. [cite\_start]Ele permite cadastrar um aluno, associá-lo a disciplinas, atribuir notas e, por fim, verificar seu status de aprovação ou reprovação em cada uma delas[cite: 4, 11].

O principal objetivo pedagógico é aplicar de forma prática os seguintes conceitos:

  * [cite\_start]**Modularização**: Separação do código em arquivos de cabeçalho (`.h`) e implementação (`.cpp`) para melhor organização[cite: 12].
  * [cite\_start]**Encapsulamento**: Uso de modificadores de acesso (`public`, `private`) para proteger os dados das classes[cite: 13].
  * [cite\_start]**Funções Amigas**: Implementação de uma função externa (`friend`) para acessar membros privados de uma classe de forma controlada[cite: 14].

-----

## 🚀 Funcionalidades e Requisitos Atendidos

  * **Classe `Aluno`**:
      * [cite\_start]Atributos privados: `nome`, `matricula`, `curso`[cite: 5].
      * [cite\_start]Métodos públicos para construção e para exibir as informações do aluno[cite: 5, 6].
  * **Classe `Disciplina`**:
      * [cite\_start]Atributos privados: `nome`, `cargaHoraria`, `nota`[cite: 6].
      * [cite\_start]Métodos públicos para construção e para manipular a nota (`setNota` e `getNota`)[cite: 7].
  * **Função Amiga `verificarStatusAprovacao`**:
      * [cite\_start]Acessa o atributo privado `nota` da classe `Disciplina` para checar a condição de aprovação[cite: 8].
      * [cite\_start]Aprova o aluno com nota igual ou superior a 6.0[cite: 9].
  * **Modularização**:
      * [cite\_start]O código foi separado nos arquivos `Aluno.h`, `Aluno.cpp`, `Disciplina.h`, `Disciplina.cpp` e `main.cpp`[cite: 12].
  * **Diagrama UML**:
      * [cite\_start]Um diagrama UML completo, representando as classes, atributos, métodos e relacionamentos, foi incluído no projeto[cite: 15, 20, 22].

-----

## 📂 Estrutura de Arquivos

O repositório está organizado da seguinte forma:

```
/Projeto_4/
│
├── Aluno.h             # Declaração da classe Aluno
├── Aluno.cpp           # Implementação da classe Aluno
├── Disciplina.h        # Declaração da classe Disciplina
├── Disciplina.cpp      # Implementação da classe Disciplina
├── main.cpp            # Função principal e execução do programa
└── diagrama-uml.png    # Diagrama UML do sistema
```

-----

## 🛠️ Como Compilar e Executar

Para compilar e executar o projeto, você precisará de um compilador C++ (como o g++).

1.  **Navegue até o diretório do projeto**
    Abra o terminal e navegue até a pasta onde os arquivos foram salvos.

2.  **Compile os arquivos**
    Execute o seguinte comando para compilar todos os arquivos `.cpp` e gerar um executável chamado `programa`:

    ```bash
    g++ main.cpp Aluno.cpp Disciplina.cpp -o programa
    ```

3.  **Execute o programa**

      * No Windows:
        ```bash
        programa.exe
        ```
      * No Linux ou macOS:
        ```bash
        ./programa
        ```

4.  **Saída Esperada**
    A saída do programa exibirá as informações do aluno e seu status de aprovação em cada uma das duas disciplinas.

-----

## 📊 Diagrama UML

O diagrama abaixo ilustra a arquitetura do sistema, incluindo o relacionamento de amizade entre a função global `verificarStatusAprovacao` e a classe `Disciplina`.
