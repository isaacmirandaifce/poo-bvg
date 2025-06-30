## Introdução

Aluno: Erlano Benevides de Sousa

Este é um sistema de gerenciamento acadêmico desenvolvido em C++ para Programação Orientada a Objetos (POO).

## Conceitos aplicados

- **Modularização:**  
Cada classe possui seus próprios arquivos `.h` e `.cpp`, organizados por pastas.

- **Encapsulamento:**  
Os atributos das classes são protegidos e acessados através de métodos.

- **Herança:**  
Estrutura de classes com níveis hierárquicos, como `Usuario`, `Aluno`, `Professor`, `FuncionarioAdministrativo` e `Monitor`.

- **Herança múltipla**  
A classe `Monitor` herda de `Aluno` e `Professor`, aplicando herança múltipla controlada com herança virtual.

- **Enumeração:**  
Definição de tipos específicos de usuários através da enumeração `TipoUsuario`.

- **Classe Interna (Nested Class):**  
A classe `Aluno` possui uma classe interna chamada `HistoricoDisciplinar`, que armazena o histórico de disciplinas cursadas pelo aluno.