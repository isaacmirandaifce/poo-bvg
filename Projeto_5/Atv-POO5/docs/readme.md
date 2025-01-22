# - Projeto 5 - POO

Este repositório contém a implementação de um sistema acadêmico ampliado, com funcionalidades para cadastro e gerenciamento de diferentes tipos de usuários (Alunos, Professores, Funcionários Administrativos e Monitores). O projeto explora conceitos avançados de Programação Orientada a Objetos (POO) em C++, como herança, polimorfismo, herança múltipla, sobrecarga e sobrescrita, além de seguir boas práticas de modularização e encapsulamento.

# - Estrutura do Projeto

- Usuario.h: Declaração da classe base Usuario.
- Usuario.cpp: Implementação dos métodos da classe Usuario.
- Aluno.h: Declaração da classe derivada Aluno.
- Aluno.cpp: Implementação dos métodos da classe Aluno.
- Professor.h: Declaração da classe derivada Professor.
- Professor.cpp: Implementação dos métodos da classe Professor.
- FuncionarioAdministrativo.h: Declaração da classe derivada FuncionarioAdministrativo.
- FuncionarioAdministrativo.cpp: Implementação dos métodos da classe FuncionarioAdministrativo.
- Monitor.h: Declaração da classe derivada Monitor (herança múltipla).
- Monitor.cpp: Implementação dos métodos da classe Monitor.
- main.cpp: Programa principal que demonstra a funcionalidade do sistema.

# - Funções


- **Classe Usuario**
- Atributos Privados:

- std::string nome: Nome do usuário.
- std::string email: Email do usuário.
- std::string tipo: Tipo do usuário (Aluno, Professor, etc.).

- Métodos Públicos:

- Construtor padrão e parametrizado.
- virtual void gerarRelatorio() const: Método virtual puro para exibição de informações gerais, sobrescrito pelas classes derivadas.

- **Classe Aluno**
- Atributos Privados:

- std::string matricula: Matrícula do aluno.
- std::string curso: Curso do aluno.
- std::vector<Disciplina> disciplinas: Lista de disciplinas associadas ao aluno.

- Métodos Públicos:

- Construtor padrão e parametrizado.
- void gerarRelatorio() const: Exibe informações como nome, matrícula, curso e lista de disciplinas.
- void adicionarDisciplina(const Disciplina& disciplina): Adiciona uma disciplina ao aluno.
- std::vector<Disciplina> getDisciplinas() const: Retorna a lista de disciplinas associadas ao aluno.

- **Classe Professor**
- Atributos Privados:

- std::string areaDeAtuacao: Área de atuação do professor.
- std::vector<std::string> disciplinasMinistradas: Lista de disciplinas ministradas.

- Métodos Públicos:

- Construtor padrão e parametrizado.
- void gerarRelatorio() const: Exibe informações como nome, área de atuação e disciplinas ministradas.

- **Classe FuncionarioAdministrativo**
- Atributos Privados:

- std::string departamento: Departamento do funcionário.
- std::string cargo: Cargo ocupado pelo funcionário.

- Métodos Públicos:

- Construtor padrão e parametrizado.
- void gerarRelatorio() const: Exibe informações como nome, departamento e cargo.

- **Classe Monitor**
- Atributos Privados:

- Herda os atributos de Aluno e Professor.
- std::vector<std::string> disciplinasMonitoradas: Lista de disciplinas monitoradas.

- Métodos Públicos:

- Construtor parametrizado que inicializa atributos de ambas as classes base.
- void gerarRelatorio() const: Exibe informações completas de Aluno e Professor, além das disciplinas monitoradas.

- **main.cpp**
- Cria objetos das classes Aluno, Professor, FuncionarioAdministrativo e Monitor.
- Demonstra polimorfismo chamando o método gerarRelatorio() para diferentes tipos de usuários.
- Adiciona disciplinas a alunos e monitores.
- Exibe exemplos práticos de funcionalidades do sistema.


