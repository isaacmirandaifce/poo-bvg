Projeto Avaliativo 6 – Sistema Avançado de Gestão Acadêmica
Objetivo

O objetivo deste projeto foi ampliar o sistema acadêmico que já tínhamos, usando conceitos mais avançados de Programação Orientada a Objetos:

Classes Abstratas

Interfaces

Classes Enumeradas

Classes Internas

A ideia era integrar autenticação de usuários, geração de relatórios e organização de informações de forma mais estruturada.

Estrutura do Sistema

Usuario: classe base de todos os usuários do sistema.

UsuarioAutenticavel: classe abstrata que herda de Usuario e permite login via senha.

Aluno: herda de UsuarioAutenticavel e implementa a interface Relatorio. Contém a classe interna HistoricoDisciplinar para registrar as disciplinas cursadas.

Professor: herda de UsuarioAutenticavel e implementa a interface Relatorio.

FuncionarioAdm: herda de UsuarioAutenticavel e implementa a interface Relatorio.

Relatorio: interface que obriga todas as classes a implementarem o método gerarRelatorio().

TipoUsuario: enumeração usada para classificar os tipos de usuário (ALUNO, PROFESSOR, FUNCIONARIO_ADMINISTRATIVO).

Funcionalidades

Autenticação de Usuário: Todos os usuários que herdam de UsuarioAutenticavel podem fazer login usando senha.

Geração de Relatórios: Cada usuário pode gerar seu próprio relatório com informações específicas.

Histórico de Disciplinas: Alunos têm um histórico detalhado das disciplinas cursadas com notas e ano.

Considerações

O projeto mostrou como organizar um sistema modular usando POO avançada, mantendo o código limpo e seguro. Aprendi a usar classes internas, interfaces e enumerações, e como elas ajudam a deixar o código mais organizado e fácil de manter.