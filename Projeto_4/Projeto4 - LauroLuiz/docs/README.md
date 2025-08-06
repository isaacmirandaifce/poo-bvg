Sistema de Gerenciamento de Notas - Projeto 4

Nome: Lauro Luiz Gomes Magalhães Pontes
Disciplina: Análise e Desenvolvimento de Sistemas S3
Matéria: Programação Orientada a Objetos
Tema: Modularização, Modificadores de Acesso e Funções Amigas em C++
📋 Descrição do Projeto
Sistema desenvolvido em C++ para gerenciamento de notas de alunos, implementando conceitos fundamentais de POO como modularização, encapsulamento e funções amigas. O sistema permite cadastrar alunos, adicionar disciplinas com notas e verificar status de aprovação.
🏗️ Estrutura do Projeto
Projeto_4/
│
├── src/                    # Código-fonte
│   ├── Aluno.h            # Header da classe Aluno
│   ├── Aluno.cpp          # Implementação da classe Aluno
│   ├── Disciplina.h       # Header da classe Disciplina
│   ├── Disciplina.cpp     # Implementação da classe Disciplina
│   └── main.cpp           # Programa principal
│
├── docs/                  # Documentação do projeto
│   ├── diagrama_uml.png   # Diagrama UML das classes
│   └── README.md          # Este arquivo
│
└── Makefile              # Arquivo de compilação
🎯 Funcionalidades Implementadas
Classe Aluno

Atributos privados: nome, matrícula, curso
Construtores: padrão e parametrizado
Métodos públicos:

Getters e Setters para todos os atributos
exibirInformacoes() - exibe dados formatados do aluno



Classe Disciplina

Atributos privados: nome, cargaHoraria, nota
Construtores: padrão, parametrizado (com/sem nota)
Métodos públicos:

Getters e Setters com validação
exibirInformacoes() - exibe dados da disciplina


Funções Amigas:

verificarAprovacao() - verifica se nota >= 6.0
validarCriteriosAprovacao() - valida critérios personalizados



Funcionalidades do Sistema

Cadastro de Aluno - registra informações básicas
Gerenciamento de Disciplinas - adiciona disciplinas com notas
Relatórios Completos - exibe todas as informações
Verificação de Aprovações - usa funções amigas para análise
Dados de Exemplo - carrega exemplos para teste

🔧 Conceitos Técnicos Aplicados
Modularização

Separação em headers (.h) e implementação (.cpp)
Uso de #ifndef, #define, #endif para evitar inclusões múltiplas
Organização clara de responsabilidades

Modificadores de Acesso

Private: Todos os atributos são privados (encapsulamento)
Public: Métodos de interface e construtores/destrutores
Friend: Funções amigas para acesso controlado aos dados privados

Funções Amigas

verificarAprovacao() - acessa diretamente o atributo privado nota
validarCriteriosAprovacao() - acessa múltiplos atributos privados
Demonstra acesso controlado sem quebrar encapsulamento