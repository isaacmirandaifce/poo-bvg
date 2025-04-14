# Sistema de Autenticação e Relatórios

Este projeto é um sistema simples de autenticação e geração de relatórios para usuários do tipo **Professor** e **Aluno**. Ele foi desenvolvido em C++ e utiliza conceitos de **Programação Orientada a Objetos (POO)**, como herança, polimorfismo e interfaces.

## Funcionalidades

- **Autenticação de usuários**: Verifica se a senha fornecida corresponde à senha armazenada.
- **Geração de relatórios**: Exibe informações específicas de cada tipo de usuário (Professor ou Aluno).
- **Classes implementadas**:
  - `Usuario`: Classe base com nome e e-mail.
  - `UsuarioAutenticavel`: Herda de `Usuario` e adiciona funcionalidade de autenticação.
  - `Professor`: Herda de `UsuarioAutenticavel` e implementa a interface `Relatorio`. Gera relatórios com as disciplinas ministradas.
  - `Aluno`: Herda de `UsuarioAutenticavel` e implementa a interface `Relatorio`. Gera relatórios com matrícula, curso e média.
  - `Relatorio`: Interface com o método `gerarRelatorio()`.
