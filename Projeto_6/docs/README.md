Projeto 6 - Sistema Avançado de Gestão Acadêmica (Python)

Aluno: Francisco Vitor

Objetivo

Este projeto tem como objetivo consolidar os conceitos avançados de Programação Orientada a Objetos em Python, com ênfase em:

Classes Abstratas e Interfaces

Classes Enumeradas e Classes Internas

Herança e Polimorfismo

Encapsulamento e Modificadores de Acesso (convenção)

Modularização de Código (em arquivos .py)

Estruturação do Projeto (com pastas src, docs, tests)

Estrutura do Projeto
Projeto_6/
│
├── docs/                                # Documentação do projeto
│   └── README.md                        # Documentação principal com diagrama UML
│
├── src/                                 # Código-fonte do projeto
│   ├── tipo_usuario.py                  # Define a enumeração TipoUsuario
│   ├── relatorio.py                     # Define a interface Relatorio
│   ├── usuario.py                       # Classe base Usuario
│   ├── usuario_autenticavel.py          # Classe abstrata UsuarioAutenticavel
│   ├── aluno.py                         # Implementação da classe Aluno
│   ├── professor.py                     # Implementação da classe Professor
│   └── funcionario_administrativo.py    # Implementação da classe FuncionarioAdministrativo
│
├── tests/                               # Arquivos de testes automatizados
│   └── test_autenticacao.py             # Testes unitários de autenticação
│
└── main.py                              # Ponto de entrada principal da aplicação

Classes Principais
Usuario

Atributos privados:

_nome (str)

_id_usuario (int)

_tipo (TipoUsuario)

Métodos:

Construtor

Propriedades: nome, id_usuario e tipo_usuario

UsuarioAutenticavel (Classe Abstrata)

Atributos privados:

_senha (str)

Métodos:

Construtor

Método abstrato: autenticar(senha)

Aluno

Atributos privados:

_curso (str)

_historico (list[HistoricoDisciplinar])

Métodos:

Construtor

Método: adicionar_disciplina_historico(nome_disciplina, ano, nota)

Método: autenticar(senha)

Método: gerar_relatorio()

Professor

Atributos privados:

_departamento (str)

Métodos:

Construtor

Método: autenticar(senha)

Método: gerar_relatorio()

FuncionarioAdministrativo

Atributos privados:

_cargo (str)

Métodos:

Construtor

Método: autenticar(senha)

Método: gerar_relatorio()

Como Executar o Projeto

Para rodar a aplicação principal:

No terminal, navegue até a raiz do projeto e execute:

python main.py


Para rodar os testes automatizados:

No terminal, execute os testes com o seguinte comando:

python -m unittest discover tests

Diagrama UML

O diagrama UML do sistema está incluído na documentação do projeto. Ele ilustra a estrutura das classes e suas interações, como a herança entre as classes, a implementação da interface Relatorio e o uso da classe interna HistoricoDisciplinar na classe Aluno.