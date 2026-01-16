# **Projeto Avaliativo 6: Classes Abstratas, Interfaces, Classes Enumeradas e Classes Internas**

## **Objetivo**

Ampliar o sistema de gerenciamento acadêmico para incluir conceitos avançados de Programação Orientada a Objetos: Classes Abstratas, Interfaces, Classes Enumeradas e Classes Internas. Este projeto consolida o aprendizado da disciplina, integrando novas funcionalidades úteis para a vivência dos alunos de Análise e Desenvolvimento de Sistemas.

---

## **Tema do Projeto: Sistema Avançado de Gestão Acadêmica**

### **Descrição Geral**

Os alunos devem expandir o sistema acadêmico já desenvolvido para incluir funcionalidades como autenticação de usuários e geração de relatórios baseados em tipos de autenticação. Além disso, o sistema deve utilizar conceitos como classes enumeradas para categorizar usuários, classes internas para encapsular lógicas específicas e interfaces para padronizar comportamentos entre classes distintas.

---

### **Requisitos do Projeto**

1. **Classes Abstratas:**
   - Criar uma classe abstrata `UsuarioAutenticavel`, que herda de `Usuario` e representa os usuários do sistema que podem realizar login.
     - Método abstrato: `bool autenticar(std::string senha)`.

2. **Interfaces:**
   - Criar uma interface `Relatorio` com um método virtual puro `gerarRelatorio()`, que será implementada por classes como `Aluno`, `Professor` e `FuncionarioAdministrativo`.

3. **Classes Enumeradas:**
   - Criar uma enumeração `TipoUsuario` que define os tipos de usuários no sistema:
     - `ALUNO`, `PROFESSOR`, `FUNCIONARIO_ADMINISTRATIVO`.

4. **Classes Internas:**
   - Adicionar uma classe interna à classe `Aluno` chamada `HistoricoDisciplinar`. 
     - A classe interna deve conter informações sobre o histórico de disciplinas cursadas, incluindo:
       - Nome da disciplina, ano cursado e nota.

5. **Funcionalidades do Sistema:**
   - Implementar autenticação baseada em senha.
   - Gerar relatórios detalhados para os diferentes tipos de usuários, com base na interface `Relatorio`.
   - Exibir informações categorizadas utilizando a enumeração `TipoUsuario`.

---

## **Requisitos Técnicos**

1. **Estrutura de Arquivos:**
   - Modularizar o projeto em arquivos `.h` e `.cpp`:
     - `UsuarioAutenticavel.h`, `Relatorio.h`, `Aluno.h`, `Professor.h`, `FuncionarioAdministrativo.h`, etc.
     - `main.cpp` para a função principal.

2. **Diagrama UML:**
   - Incluir um diagrama UML detalhando a hierarquia do sistema, os métodos abstratos, a interface e os relacionamentos entre as classes.

3. **Encapsulamento e Segurança:**
   - Garantir que todos os atributos estejam devidamente encapsulados.
   - Proteger informações sensíveis como senhas, utilizando boas práticas de segurança no código.

---

## **Exemplo de Estrutura de Código**

### Arquivo `UsuarioAutenticavel.h`
```cpp
#ifndef USUARIO_AUTENTICAVEL_H
#define USUARIO_AUTENTICAVEL_H

#include <string>

#endif // USUARIO_AUTENTICAVEL_H
```

### Arquivo `Relatorio.h`
```cpp
#ifndef RELATORIO_H
#define RELATORIO_H

class Relatorio {
public:
    virtual ~Relatorio() = default;

    virtual void gerarRelatorio() const = 0; // Método virtual puro
};

#endif // RELATORIO_H
```

### Arquivo `Aluno.h`
```cpp
#ifndef ALUNO_H
#define ALUNO_H

#include <string>
#include <vector>
#include "UsuarioAutenticavel.h"
#include "Relatorio.h"

#endif // ALUNO_H
```

---

## **Critérios de Avaliação**

1. **Implementação Técnica (6 pontos):**
   - Implementação correta de classes abstratas, interfaces, enums e classes internas.

2. **Uso de Funcionalidades (2 pontos):**
   - Geração de relatórios, autenticação e uso de categorias com a enumeração.

3. **Modelagem UML (1 ponto):**
   - Diagrama UML completo e preciso.

4. **Boas Práticas de Programação (1 ponto):**
   - Código modular e legível, seguindo os padrões de segurança e encapsulamento.

---

## **Entrega**

1. **Formato:**
   - Os arquivos devem ser enviados para o repositório da turma no diretório `/Projetos/Projeto_6`.
   - O diagrama UML deve ser incluído no formato `.png` ou `.jpg`.

2. **Prazo:**
   - O projeto deve ser entregue até **26/01/2025**.
