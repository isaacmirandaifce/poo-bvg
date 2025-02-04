# - Projeto 7 - POO

Este repositório contém a implementação de um sistema acadêmico completo, com funcionalidades voltadas para o cadastro, autenticação e gerenciamento de diferentes tipos de usuários (Alunos, Professores, Funcionários Administrativos e Monitores). O projeto explora conceitos avançados de Programação Orientada a Objetos (POO) em C++, como herança, polimorfismo, herança múltipla, sobrecarga e sobrescrita, além de seguir boas práticas de encapsulamento e modularização. Além disso, o sistema conta com um componente genérico para filtragem e manipulação de objetos, permitindo operações como busca, ordenação e filtragem de dados.

# - Estrutura do Projeto

- **Usuario.h**: Declaração da classe base abstrata `Usuario`.
- **Usuario.cpp**: Implementação dos métodos da classe base `Usuario`.
- **UsuarioAutenticavel.h**: Declaração da interface `UsuarioAutenticavel` para autenticação.
- **UsuarioAutenticavel.cpp**: Implementação dos métodos de autenticação.
- **Aluno.h**: Declaração da classe derivada `Aluno`.
- **Aluno.cpp**: Implementação dos métodos da classe `Aluno`.
- **Professor.h**: Declaração da classe derivada `Professor`.
- **Professor.cpp**: Implementação dos métodos da classe `Professor`.
- **FuncionarioAdministrativo.h**: Declaração da classe derivada `FuncionarioAdministrativo`.
- **FuncionarioAdministrativo.cpp**: Implementação dos métodos da classe `FuncionarioAdministrativo`.
- **Monitor.h**: Declaração da classe derivada `Monitor` (herança múltipla).
- **Monitor.cpp**: Implementação dos métodos da classe `Monitor`.
- **Filtro.h**: Declaração e implementação da classe genérica `Filtro<T>` para filtragem, ordenação e manipulação de coleções.
- **main.cpp**: Programa principal que demonstra a funcionalidade do sistema.

# - Funcionalidades

- **Classe Usuario**
  - **Atributos privados:**
    - `std::string nome`: Nome do usuário.
    - `std::string email`: Email do usuário.
    - `std::string tipo`: Tipo do usuário (ex: Aluno, Professor, etc.).
  - **Métodos públicos:**
    - Construtor padrão e parametrizado.
    - `virtual void gerarRelatorio() const`: Método virtual puro para exibição de informações gerais, sobrescrito pelas classes derivadas.

- **Classe UsuarioAutenticavel**
  - **Métodos públicos:**
    - `bool autenticar(const std::string& senha)`: Verifica se a senha fornecida está correta.

- **Classe Aluno**
  - **Atributos privados:**
    - `std::string matricula`: Matrícula do aluno.
    - `std::string curso`: Curso do aluno.
    - `std::vector<std::string> disciplinasCursadas`: Lista de disciplinas cursadas.
    - `std::vector<HistoricoDisciplinar> historico`: Histórico de disciplinas cursadas, com informações de ano e nota.
  - **Métodos públicos:**
    - Construtor padrão e parametrizado.
    - `void gerarRelatorio() const`: Exibe informações como nome, matrícula, curso e disciplinas cursadas.
    - `void gerarRelatorio(bool incluirNotas) const`: Exibe o relatório completo, incluindo o histórico disciplinar com notas.
    - `void adicionarDisciplina(const std::string& disciplina)`: Adiciona uma disciplina cursada.
    - `void adicionarHistorico(const std::string& nomeDisciplina, int ano, double nota)`: Registra o histórico disciplinar.
    - `double calcularMedia() const`: Calcula a média das notas do aluno.
    - `std::vector<std::string> getDisciplinasPorAno(int ano) const`: Retorna as disciplinas cursadas em um determinado ano.

- **Classe Professor**
  - **Atributos privados:**
    - `std::string areaDeAtuacao`: Área de atuação do professor.
    - `std::vector<std::string> disciplinasMinistradas`: Lista de disciplinas ministradas.
  - **Métodos públicos:**
    - Construtor padrão e parametrizado.
    - `void gerarRelatorio() const`: Exibe informações como nome, área de atuação e disciplinas ministradas.
    - `void adicionarDisciplina(const std::string& disciplina)`: Adiciona uma disciplina ministrada.
    - `bool lecionaDisciplina(const std::string& disciplina) const`: Verifica se o professor ministra uma disciplina específica.

- **Classe FuncionarioAdministrativo**
  - **Atributos privados:**
    - `std::string departamento`: Departamento do funcionário.
    - `std::string cargo`: Cargo ocupado pelo funcionário.
  - **Métodos públicos:**
    - Construtor padrão e parametrizado.
    - `void gerarRelatorio() const`: Exibe informações como nome, departamento e cargo.

- **Classe Monitor**
  - Herda atributos e métodos de `Aluno` e `Professor` (herança múltipla).
  - **Atributos adicionais:**
    - `std::vector<std::string> disciplinasMonitoradas`: Lista de disciplinas monitoradas.
  - **Métodos públicos:**
    - Construtor parametrizado que inicializa atributos de ambas as classes base.
    - `void listarDisciplinasMonitoradas() const`: Lista as disciplinas monitoradas.
    - `void gerarRelatorio() const`: Exibe informações completas de `Aluno` e `Professor`, além das disciplinas monitoradas.

- **Classe Filtro<T>**
  - **Atributos privados:**
    - `std::vector<T> elementos`: Coleção de elementos do tipo `T`.
  - **Métodos públicos:**
    - `void adicionarElemento(const T& elemento)`: Adiciona um elemento à coleção.
    - `std::vector<T> filtrarPorCondicao(std::function<bool(const T&)> condicao) const`: Retorna os elementos que satisfazem uma determinada condição.
    - `void imprimirTodos(std::function<void(const T&)> acao) const`: Aplica uma ação a cada elemento (ex: imprimir informações).
    - `void ordenar(std::function<bool(const T&, const T&)> comparador)`: Ordena os elementos com base em um comparador.
    - `const std::vector<T>& getElementos() const`: Retorna a coleção de elementos.

- **main.cpp**
  - Criação de objetos das classes `Aluno`, `Professor`, `FuncionarioAdministrativo` e `Monitor`.
  - Demonstração do polimorfismo ao chamar o método `gerarRelatorio()` para diferentes tipos de usuários.
  - Exemplo de autenticação de usuários.
  - Utilização da classe genérica `Filtro<T>` para realizar operações de filtragem, ordenação e exibição de dados.

# - Observações

- O projeto foi desenvolvido em C++ e segue as melhores práticas de POO.
- A implementação utiliza conceitos como herança, polimorfismo, herança múltipla, e sobrecarga/sobrescrita de métodos para promover a reutilização e a modularização do código.
- A classe genérica `Filtro<T>` permite aplicar operações comuns sobre coleções de objetos, facilitando a manipulação e o relatório dos dados do sistema acadêmico.
