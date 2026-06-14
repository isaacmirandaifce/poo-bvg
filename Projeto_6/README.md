# **Projeto Avaliativo 6: Classes Abstratas, Interfaces, Classes Enumeradas e Classes Internas**

### **Como Rodar o código?**
Para Executar esse Código é Nescessário ter o Compilador g++

g++ src/*.cpp src/base/*.cpp src/models/*.cpp -o programa

## **Ticket: Módulo de Segurança e Auditoria (IAM) - SecureBank Pro**

---

### **Descrição Geral**

Este projeto foi desenvolvido com foco na aplicação rigorosa de princípios de Programação Orientada a Objetos em C++, simulando o núcleo do módulo de Gerenciamento de Identidade e Acesso (IAM) para uma instituição financeira fictícia, o SecureBank Pro.

O sistema trabalha com diferentes perfis de usuários (Administradores, Auditores e Operadores), garantindo que cada um tenha um nível de acesso restrito e um formato específico de geração de logs e relatórios.

O objetivo principal do projeto é aplicar os conceitos de abstração (interfaces e classes abstratas), encapsulamento extremo (classes internas), classes enumeradas (enum classes) para tipagem segura, e polimorfismo dinâmico na geração de relatórios de auditoria.

---

### **Contexto**

O SecureBank Pro precisa garantir que as ações realizadas em seu sistema sejam devidamente logadas e auditadas. Perfis diferentes, como TI (Admin), Conformidade (Auditor) e Caixa (Operador), acessam o sistema e geram rastros distintos. 

Para evitar vazamento de dados de navegação e garantir a obrigatoriedade de autenticação, o sistema foi desenhado utilizando contratos estritos (Interfaces) e blindagem de dados (Inner Classes). A solução permite que o motor de auditoria processe todos os relatórios de forma polimórfica, iterando sobre uma interface comum para gerar a trilha de auditoria completa em cascata.

---

