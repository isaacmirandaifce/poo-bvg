# Sistema de Gestão de Usuários e Relatórios

Este é um sistema de gestão de usuários com autenticação e geração de relatórios detalhados para diferentes tipos de usuários. O projeto segue os princípios de herança, abstração e autenticação baseados em senha, com categorias de usuários como Aluno, Professor e FuncionarioAdministrativo. Ele também implementa a geração de relatórios utilizando a interface `Relatorio`.

## Funcionalidades

- **Autenticação de Usuários**: Cada usuário pode ser autenticado usando uma senha.
- **Geração de Relatórios**: Relatórios detalhados podem ser gerados para cada tipo de usuário.
- **Categorias de Usuários**: O sistema utiliza uma enumeração `TipoUsuario` para categorizar os tipos de usuários como `ALUNO`, `PROFESSOR`, `FUNCIONARIO`, etc.
- **Herança Múltipla**: Algumas classes, como `Monitor`, herdam comportamentos tanto de `Aluno` quanto de `Professor`.
