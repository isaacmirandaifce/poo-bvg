# **Projeto Avaliativo 5: Herança, Polimorfismo, Sobrecarga e Sobrescrita - C++**

## **Objetivo**
Desenvolver um projeto prático em C++ que complemente o sistema de gerenciamento de notas de alunos e disciplinas, explorando os conceitos avançados de Herança, Polimorfismo, Sobrecarga, Sobrescrita e Tipos de Sobrescrita. O projeto deve reforçar a compreensão dos alunos sobre a aplicação desses conceitos no desenvolvimento de software organizado e escalável.

---

## **Tema do Projeto: Gerenciamento Ampliado de Sistema Acadêmico**

### **Descrição Geral**
Ampliar o sistema desenvolvido anteriormente para incluir funcionalidades relacionadas ao cadastro de funcionários e à emissão de relatórios. A ideia é criar uma hierarquia de classes para representar diferentes tipos de usuários do sistema (Alunos, Professores e Funcionários Administrativos) e explorar polimorfismo para gerar relatórios diferenciados com base no tipo de usuário.

### **Requisitos**

1. **Classes e Herança:**
   - **Classe base `Usuario`:**
     - Atributos: `nome` (string), `email` (string), `tipo` (string).
     - Métodos: 
       - Construtor padrão e parametrizado.
       - Método virtual puro `gerarRelatorio()`: Exibe informações gerais sobre o usuário. Deve ser sobrescrito nas classes derivadas.

   - **Classe derivada `Aluno` (herda de `Usuario`):**
     - Atributos adicionais: `matricula` (string), `curso` (string).
     - Métodos: 
       - Construtor e sobrescrita de `gerarRelatorio()` para exibir nome, matrícula, curso e disciplinas cursadas.

   - **Classe derivada `Professor` (herda de `Usuario`):**
     - Atributos adicionais: `areaDeAtuacao` (string), `disciplinasMinistradas` (vetor de strings).
     - Métodos:
       - Construtor e sobrescrita de `gerarRelatorio()` para exibir nome, área de atuação e disciplinas ministradas.

   - **Classe derivada `FuncionarioAdministrativo` (herda de `Usuario`):**
     - Atributos adicionais: `departamento` (string), `cargo` (string).
     - Métodos:
       - Construtor e sobrescrita de `gerarRelatorio()` para exibir nome, departamento e cargo.

2. **Herança Múltipla:**
   - Criar uma classe `Monitor` que herda de `Aluno` e `Professor`. Esta classe deve implementar um método adicional que liste as disciplinas monitoradas pelo aluno.

3. **Polimorfismo:**
   - Utilizar ponteiros ou referências para manipular objetos de diferentes tipos (`Usuario`, `Aluno`, `Professor`, etc.) de forma polimórfica e chamar os métodos sobrescritos.

4. **Sobrecarga e Sobrescrita:**
   - Implementar um método sobrecarregado na classe `Aluno` para exibir informações detalhadas com e sem notas.

---

## **Requisitos Técnicos**

1. **Modularização:**
   - Separe as implementações em arquivos diferentes:
     - `Usuario.h` e `Usuario.cpp`.
     - `Aluno.h` e `Aluno.cpp`.
     - `Professor.h` e `Professor.cpp`.
     - `FuncionarioAdministrativo.h` e `FuncionarioAdministrativo.cpp`.
     - `Monitor.h` e `Monitor.cpp`.
     - `main.cpp`.

2. **Herança e Polimorfismo:**
   - Utilize herança para compartilhar atributos e métodos comuns.
   - Explore polimorfismo com ponteiros/referências.

3. **Sobrecarga e Sobrescrita:**
   - Implementar os métodos com sobrecarga e sobrescrita, destacando as diferenças.

4. **Diagrama UML:**
   - Crie um diagrama UML completo que ilustre todas as classes e seus relacionamentos (herança, associação, composição).

---

## **Exemplo de Estrutura do Código**

### Arquivo `Usuario.h`
```cpp
#ifndef USUARIO_H
#define USUARIO_H


#endif // USUARIO_H
```

### Arquivo `main.cpp`
```cpp
#include <iostream>
#include <vector>
#include "Aluno.h"
#include "Professor.h"
#include "FuncionarioAdministrativo.h"

int main() {

    return 0;
}
```

---

## **Critérios de Avaliação**

1. **Implementação Técnica (6 pontos):**
   - Correção e organização da hierarquia de classes.
   - Uso de polimorfismo e herança múltipla.

2. **Utilização de Sobrecarga e Sobrescrita (2 pontos):**
   - Correta implementação dos métodos solicitados.

3. **Modelagem UML (1 ponto):**
   - Diagrama UML bem detalhado e claro.

4. **Boas Práticas e Documentação (1 ponto):**
   - Código legível e com comentários explicativos.

---

## **Entrega**

1. **Formato:**
   - Carregue os arquivos no repositório no diretório `/Projetos/Projeto_5`.
   - Inclua o diagrama UML no formato `png` ou `jpg`.

2. **Prazo:**
   - A entrega deve ser feita até **19/01/2025**.
