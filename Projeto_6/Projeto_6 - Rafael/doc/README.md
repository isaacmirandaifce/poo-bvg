## Introdução

Este é um sistema de gerenciamento acadêmico desenvolvido em C++ que explora os principais conceitos da Programação Orientada a Objetos (POO).

O projeto faz parte da disciplina de Programação Orientada a Objetos do curso de Análise e Desenvolvimento de Sistemas (ADS).

## Paradigmas e conceitos aplicados

- **Modularização:**  
Cada classe possui seus próprios arquivos `.h` e `.cpp`, organizados por pastas.

- **Encapsulamento:**  
Os atributos das classes são protegidos e acessados através de métodos.

- **Herança:**  
Estrutura de classes com níveis hierárquicos, como `Usuario`, `Aluno`, `Professor`, `FuncionarioAdministrativo` e `Monitor`.

- **Herança múltipla (Herança dupla):**  
A classe `Monitor` herda de `Aluno` e `Professor`, aplicando herança múltipla controlada com herança virtual.

- **Polimorfismo:**  
Uso de ponteiros para a interface `Relatorio`, permitindo chamar o método `gerarRelatorio()` de forma polimórfica para diferentes tipos de usuários.

- **Classes abstratas e interfaces:**  
Implementação de uma interface (`Relatorio`) e uma classe abstrata (`UsuarioAutenticavel`).

- **Enumeração:**  
Definição de tipos específicos de usuários através da enumeração `TipoUsuario`.

- **Classe Interna (Nested Class):**  
A classe `Aluno` possui uma classe interna chamada `HistoricoDisciplinar`, que armazena o histórico de disciplinas cursadas pelo aluno.