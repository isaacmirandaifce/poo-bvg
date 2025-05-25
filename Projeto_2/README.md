# Projeto Avaliativo 2 - Paradigma de Orientação a Objetos e UML

## ✅ Exercício 1: Modelagem de Domínio - Seguro de Carro

### 📄 Contexto
O projeto tem objetivo é construir um sistema de seguros de veículos, aplicando conceitos como associação, agregação, herança, encapsulamento e abstração.
A empresa de seguros deseja criar um sistema para gerenciar seguros de carros. Cada seguro envolve informações sobre o cliente e o carro, além de dados específicos do seguro.

### 🧱 Classes e Atributos

- **Carro**: ano, marca, modelo, cor, placa  
- **Modelo** (dentro de Carro): nome  
- **Seguro**: carro, cliente, valor, vigência  
- **Cliente**: nome, cpf

### ✍️ Tarefas

- Criar o diagrama de classes UML com os atributos.
- Indicar os relacionamentos:
  - **Seguro ↔ Carro**: associação.
  - **Seguro ↔ Cliente**: associação.
- Justificar:
  - **Seguro e Carro** têm associação (carro pode existir fora do seguro).
  - **Seguro e Cliente** também é associação.

---

## ✅ Exercício 2: Atributos e Métodos

### 🧱 Métodos por classe

- **Carro**  
  - Métodos: exibir detalhes, atualizar cor

- **Cliente**  
  - Métodos: exibir informações

- **Seguro**  
  - Métodos: calcular valor com base e taxa, verificar validade da vigência

### ✍️ Tarefas

- Atualizar o diagrama UML incluindo os métodos.
- Criar uma estrutura básica do código das classes com esses métodos e atributos.

---

## ✅ Exercício 3: Relacionamentos e Associações

### 📌 Atualização do modelo

Agora, o sistema precisa lidar com clientes que possuem mais de um carro e vários seguros.

### ✍️ Tarefas

- Atualizar o diagrama UML para mostrar que um **Seguro** pode ter mais de um **Carro**.
- Justificar que o relacionamento entre **Seguro e Carro** é **agregação** (carro existe fora do seguro).
- Mostrar que um **Cliente** pode ter vários seguros e carros.

---

## ✅ Exercício 4: Herança

### 🧱 Novas Classes

- **SeguroVeiculo** (classe base)
- **SeguroCarro** (herda de SeguroVeiculo)
- **SeguroMoto** (herda de SeguroVeiculo)

### ✍️ Tarefas

- Criar o diagrama UML mostrando a herança.
- Justificar o uso de herança:
  - Evita repetição de código.
  - Deixa o sistema mais organizado e fácil de expandir.
- Explicar como o método `calcular_valor()` pode ser genérico em **SeguroVeiculo** e específico em **SeguroCarro** ou **SeguroMoto**.

---

## ✅ Exercício 5: Diagrama de Objetos UML

### 🧾 Exemplo de dados

- **Cliente**: João Silva, CPF 123.456.789-00  
- **Carro**: Toyota Corolla, 2020, Branco, Placa XYZ-1234  
- **Seguro**: R$ 1.500,00 – Vigência de 01/01/2024 até 01/01/2025

### ✍️ Tarefas

- Criar um diagrama de objetos UML com os dados reais.
- Mostrar os valores dos atributos no diagrama.
- Explicar que esse tipo de diagrama ajuda a visualizar o sistema funcionando com dados reais.

---

## ✅ Exercício 6: Abstração e Encapsulamento

### ✍️ Tarefas

- Aplicar **encapsulamento** nas classes:
  - Esconder atributos sensíveis como **cpf** e **placa**.
  - Criar métodos públicos para acessá-los.
- Criar um pseudocódigo de um método na classe **Seguro** que verifica se o seguro ainda é válido (com base na data de vigência).
- Explicar a importância do encapsulamento:
  - Protege os dados dos usuários.
  - Garante acesso controlado e seguro.

---

## 📁 Entrega

- Subir todos os arquivos no repositório da turma no GitHub.
- Usar a pasta: `Projeto_2`.
- Incluir:
  - Diagramas UML
  - Código das classes
  - Código de teste
- **Prazo de Entrega**: 7 dias a partir da data de envio do projeto.

---
