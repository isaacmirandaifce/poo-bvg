Sistema de Gerenciamento Universitário
Descrição
Este projeto implementa um sistema de gerenciamento universitário em C++ que permite o cadastro e controle de diferentes tipos de usuários em uma instituição de ensino. O sistema utiliza conceitos de programação orientada a objetos, incluindo herança, polimorfismo e encapsulamento.
Funcionalidades
O sistema gerencia os seguintes tipos de usuários:

Alunos: Estudantes com matrícula, curso e histórico disciplinar
Professores: Docentes com área de atuação e disciplinas ministradas
Monitores: Alunos que também exercem função de monitoria
Funcionários Administrativos: Colaboradores com funções administrativas

Arquitetura
Hierarquia de Classes
Usuario (classe base)
├── UsuarioAutenticavel (classe abstrata)
│   ├── FuncionarioAdministrativo
│   ├── Professor
│   └── Monitor
└── Aluno
Classes Principais

Usuario: Classe base com informações básicas (nome, email, tipo)
UsuarioAutenticavel: Classe abstrata para usuários que necessitam autenticação
Aluno: Representa estudantes da instituição
Professor: Representa docentes com suas especializações
Monitor: Combina características de aluno e função de monitoria
FuncionarioAdministrativo: Representa funcionários administrativos

Classes Utilitárias

FiltroGenerico: Sistema de filtros para busca e seleção de usuários
Relatorio: Interface para geração de relatórios
TipoUsuario: Enumeração dos tipos de usuários do sistema

Estrutura de Arquivos
├── Usuario.h / Usuario.cpp                     # Classe base
├── UsuarioAutenticavel.h / UsuarioAutenticavel.cpp  # Classe abstrata para autenticação
├── Aluno.h / Aluno.cpp                        # Classe Aluno
├── Professor.h / Professor.cpp                # Classe Professor
├── Monitor.h / Monitor.cpp                    # Classe Monitor
├── FuncionarioAdministrativo.h / .cpp         # Classe Funcionário Administrativo
├── Filtro.h                                   # Sistema de filtros
├── Relatorio.h                                # Interface de relatórios
├── TipoUsuario.h                              # Enumeração de tipos
└── README.md                                  # Este arquivo
Características Técnicas
Conceitos de POO Utilizados

Herança: Hierarquia de classes com Usuario como classe base
Polimorfismo: Métodos virtuais para comportamentos específicos
Encapsulamento: Atributos privados com getters e setters
Abstração: Classes abstratas para definir contratos

Funcionalidades Implementadas

✅ Cadastro de diferentes tipos de usuários
✅ Sistema de autenticação para usuários específicos
✅ Histórico disciplinar para alunos
✅ Gerenciamento de disciplinas para professores
✅ Sistema de filtros genérico
✅ Interface para geração de relatórios

Como Compilar
Pré-requisitos

Compilador C++ (g++, clang++, etc.)
C++11 ou superior

Compilação
bash# Compilar todos os arquivos
g++ -std=c++11 -o sistema *.cpp

# Ou compilar individualmente
g++ -std=c++11 -c Usuario.cpp
g++ -std=c++11 -c UsuarioAutenticavel.cpp
g++ -std=c++11 -c Aluno.cpp
g++ -std=c++11 -c Professor.cpp
g++ -std=c++11 -c Monitor.cpp
g++ -std=c++11 -c FuncionarioAdministrativo.cpp

# Linkar
g++ -o sistema *.o
Execução
bash./sistema
Exemplo de Uso
cpp#include "Aluno.h"
#include "Professor.h"
#include "Monitor.h"

int main() {
    // Criando um aluno
    Aluno aluno("João Silva", "joao@email.com", "12345678", "Ciência da Computação");
    
    // Criando um professor
    Professor professor("Dr. Maria Santos", "maria@email.com", "senha123", "Algoritmos");
    
    // Criando um monitor
    Monitor monitor("Pedro Costa", "pedro@email.com", "senha456", "98765432", "Estruturas de Dados");
    
    return 0;
}
Funcionalidades por Tipo de Usuário
Aluno

Matrícula única
Curso de graduação
Histórico de disciplinas
Notas e aprovações

Professor

Área de atuação
Disciplinas ministradas
Sistema de autenticação
Geração de relatórios

Monitor

Herda características de aluno
Disciplinas de monitoria
Sistema de autenticação
Função dual (aluno + monitor)

Funcionário Administrativo

Departamento de trabalho
Cargo específico
Sistema de autenticação
Acesso administrativo

Sistema de Filtros
O sistema inclui um mecanismo genérico de filtros que permite:

Busca por diferentes critérios
Filtragem de elementos
Operações de seleção avançada
Interface flexível para diferentes tipos

Relatórios
Interface para geração de relatórios com:

Dados de usuários
Estatísticas do sistema
Informações acadêmicas
Relatórios administrativos

Contribuição
Para contribuir com o projeto:

Faça um fork do repositório
Crie uma branch para sua feature
Implemente as mudanças
Execute os testes
Faça um pull request

Licença
Este projeto é desenvolvido para fins educacionais e está disponível sob licença acadêmica.
Contato
Para dúvidas ou sugestões sobre o projeto, entre em contato através dos canais apropriados da instituição.

Desenvolvido como projeto acadêmico utilizando C++ e conceitos de Programação Orientada a Objetos.