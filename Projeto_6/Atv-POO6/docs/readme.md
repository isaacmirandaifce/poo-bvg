# - Projeto 6 - POO

Este repositório contém a implementação de um sistema acadêmico completo, com funcionalidades voltadas para o cadastro, autenticação e gerenciamento de diferentes tipos de usuários (Alunos, Professores, Funcionários Administrativos e Monitores). O projeto explora conceitos avançados de Programação Orientada a Objetos (POO) em C++, como herança, polimorfismo, herança múltipla, sobrecarga e sobrescrita, além de seguir boas práticas de encapsulamento e modularização.

# - Estrutura do Projeto

- Usuario.h: Declaração da classe base abstrata Usuario.
- Usuario.cpp: Implementação dos métodos da classe base Usuario.
- UsuarioAutenticavel.h: Declaração da interface UsuarioAutenticavel para autenticação.
- UsuarioAutenticavel.cpp: Implementação dos métodos de autenticação.
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
  - Atributos privados:
    - `std::string nome`: Nome do usuário.
    - `std::string email`: Email do usuário.
  - Métodos públicos:
    - Construtor padrão e parametrizado.
    - `virtual void gerarRelatorio() const`: Método virtual puro para exibição de informações gerais, sobrescrito pelas classes derivadas.

- **Classe UsuarioAutenticavel**
  - Método público:
    - `bool autenticar(const std::string& senha)`: Verifica se a senha fornecida está correta.

- **Classe Aluno**
  - Atributos privados:
    - `std::string matricula`: Matrícula do aluno.
    - `std::string curso`: Curso do aluno.
    - `std::vector<std::string> disciplinas`: Lista de disciplinas matriculadas.
    - `std::vector<Historico> historico`: Histórico de disciplinas cursadas e notas obtidas.
  - Métodos públicos:
    - Construtor padrão e parametrizado.
    - `void gerarRelatorio() const`: Exibe informações como nome, matrícula, curso, disciplinas e histórico acadêmico.
    - `void adicionarDisciplina(const std::string& disciplina, const Historico& historico)`: Adiciona uma disciplina ao aluno e registra seu desempenho.

- **Classe Professor**
  - Atributos privados:
    - `std::string areaDeAtuacao`: Área de atuação do professor.
    - `std::vector<std::string> disciplinasMinistradas`: Lista de disciplinas ministradas.
  - Métodos públicos:
    - Construtor padrão e parametrizado.
    - `void gerarRelatorio() const`: Exibe informações como nome, área de atuação e disciplinas ministradas.

- **Classe FuncionarioAdministrativo**
  - Atributos privados:
    - `std::string departamento`: Departamento do funcionário.
    - `std::string cargo`: Cargo ocupado pelo funcionário.
  - Métodos públicos:
    - Construtor padrão e parametrizado.
    - `void gerarRelatorio() const`: Exibe informações como nome, departamento e cargo.

- **Classe Monitor**
  - Herda atributos e métodos de `Aluno` e `Professor`.
  - Atributos adicionais:
    - `std::vector<std::string> disciplinasMonitoradas`: Lista de disciplinas monitoradas.
  - Métodos públicos:
    - Construtor parametrizado que inicializa atributos de ambas as classes base.
    - `void gerarRelatorio() const`: Exibe informações completas de Aluno e Professor, além das disciplinas monitoradas.

- **main.cpp**
  - Criação de objetos das classes `Aluno`, `Professor`, `FuncionarioAdministrativo` e `Monitor`.
  - Demonstração do polimorfismo ao chamar o método `gerarRelatorio()` para diferentes tipos de usuários.
  - Adição de disciplinas a alunos e monitores.
  - Validação de autenticação para usuários.
