# **Projeto Avaliativo 7: Métodos e Classes Genéricas - C++**

## **Objetivo**

Ampliar o sistema acadêmico existente com a introdução de métodos e classes genéricas, otimizando a manipulação de dados no sistema e reforçando conceitos importantes para o desenvolvimento de sistemas escaláveis e reutilizáveis. Este projeto busca aplicar conceitos fundamentais de generics de forma prática e contextualizada.

---

## **Tema do Projeto: Sistema Genérico de Filtragem e Relatórios Acadêmicos**

### **Descrição Geral**

Os alunos devem expandir o sistema acadêmico para incluir um componente genérico que permita filtrar e manipular objetos relacionados ao sistema acadêmico (alunos, disciplinas, relatórios, etc.). Essa nova funcionalidade deve utilizar métodos e classes genéricas para fornecer uma maneira eficiente e reutilizável de realizar operações comuns, como busca, ordenação e filtragem de dados.

---

### **Requisitos do Projeto**

1. **Classes Genéricas:**
   - Criar uma classe genérica `Filtro<T>` que forneça métodos genéricos para manipular coleções de objetos.
     - Métodos genéricos:
       - `adicionarElemento(T elemento)`: Adiciona um objeto ao filtro.
       - `filtrarPorCondicao(std::function<bool(const T&)> condicao)`: Filtra os elementos com base em uma condição.
       - `imprimirTodos(std::function<void(const T&)> acao)`: Aplica uma ação a cada elemento (como imprimir informações no console).

2. **Aplicação de Métodos Genéricos:**
   - Implementar métodos genéricos que funcionem sobre as classes do sistema, como `Aluno`, `Professor`, `FuncionarioAdministrativo`, ou até mesmo elementos do histórico disciplinar.

3. **Integração com o Sistema Acadêmico:**
   - Adicionar funcionalidades que utilizem a classe `Filtro` para:
     - Filtrar alunos com média acima de 7.0.
     - Listar professores que ministram uma disciplina específica.
     - Listar disciplinas cursadas por um aluno em um determinado ano.

4. **Funcionalidades Adicionais:**
   - Implementar um sistema de ordenação genérica que permita ordenar listas de objetos com base em diferentes critérios (por exemplo, nome ou nota).

5. **Diagrama UML:**
   - Criar um diagrama UML detalhando as classes existentes, incluindo a classe genérica `Filtro` e suas interações com as classes do sistema.

---

## **Requisitos Técnicos**

1. **Classes Genéricas:**
   - Utilizar templates para criar uma classe genérica que opere com diferentes tipos de dados.
   - Incorporar o uso de `std::function` para criar métodos altamente configuráveis e reutilizáveis.

2. **Boas Práticas:**
   - Garantir encapsulamento e modularidade.
   - Utilizar métodos bem documentados e organizados.

3. **Estrutura de Arquivos:**
   - Modularizar o código, garantindo que cada classe genérica, método e funcionalidade esteja corretamente estruturada em arquivos `.h` e `.cpp`.

4. **Documentação:**
   - Adicionar comentários explicando a lógica de implementação e o uso de templates.
