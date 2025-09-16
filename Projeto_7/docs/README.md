# Projeto 7 - Sistema Genérico de Filtragem e Relatórios Acadêmicos (Python)
Aluno: **Francisco Vitor**

## Objetivo
Expandir um sistema acadêmico com a introdução de **métodos e classes genéricas** para manipular dados de alunos, professores, funcionários administrativos, etc., utilizando conceitos de programação genérica para otimizar e tornar o sistema mais reutilizável e escalável.

---

## Estrutura do Projeto

```bash
Projeto_7/
│
├── src/                                 # Código-fonte do projeto
│   ├── filtro.py                        # Classe genérica Filtro
│   ├── usuario.py                       # Classes base de Usuario
│   ├── aluno.py                         # Implementação da classe Aluno
│   ├── professor.py                     # Implementação da classe Professor
│   ├── funcionario_administrativo.py    # Implementação da classe FuncionarioAdministrativo
│   └── main.py                           # Arquivo principal para execução
│
└── tests/                               # Arquivos de testes
    └── test_filtro.py                   # Testes unitários da classe Filtro


# Objetivos do Projeto

1. **Classes Genéricas**: Utilizar classes genéricas para implementar operações de filtragem, ordenação e manipulação de dados de maneira reutilizável.
2. **Métodos Genéricos**: Implementar métodos genéricos para permitir filtrar e manipular objetos de diferentes tipos de dados (alunos, professores, funcionários, etc.).
3. **Aplicação Acadêmica**: Integrar as classes genéricas com um sistema acadêmico, permitindo:
    - Filtrar alunos com média acima de 7.0.
    - Filtrar professores que ministram uma disciplina específica.
    - Filtrar disciplinas cursadas por um aluno em um determinado ano.
4. **Testes Automatizados**: Implementar testes para garantir que a filtragem e manipulação de dados funcionem corretamente.


#Classes Principais

### `Usuario`
- **Atributos**:
  - `nome` (str)
  - `id_usuario` (int)
- **Métodos**:
  - Construtor
  - Getter para `nome` e `id_usuario`

### `Aluno` (Herda de `Usuario`)
- **Atributos**:
  - `curso` (str)
  - `notas` (List[float])
- **Métodos**:
  - Construtor
  - Método `media()` para calcular a média das notas

### `Professor` (Herda de `Usuario`)
- **Atributos**:
  - `departamento` (str)
- **Métodos**:
  - Construtor

### `FuncionarioAdministrativo` (Herda de `Usuario`)
- **Atributos**:
  - `cargo` (str)
- **Métodos**:
  - Construtor

### `Filtro` (Classe Genérica)
- **Métodos**:
  - `adicionar_elemento(elemento: T)` - Adiciona um objeto ao filtro.
  - `filtrar_por_condicao(condicao: Callable[[T], bool])` - Filtra os elementos com base em uma condição.
  - `imprimir_todos(acao: Callable[[T], None])` - Aplica uma ação a cada elemento (como imprimir informações).

#Como Executar o Projeto
1. **Clone ou baixe o repositório.**
2. **Instale o Python 3.9+** (se necessário).
3. **Execute o arquivo principal**:

   No terminal, execute:

   ```bash
   python main.py
4. **Para rodar os testes**:
    
      No terminal, execute: 

      python -m unittest discover tests


---

## Diagrama UML

```markdown
O diagrama UML do sistema está incluído na documentação do projeto, ilustrando as classes `Usuario`, `Aluno`, `Professor`, `FuncionarioAdministrativo`, e a classe genérica `Filtro`, com seus atributos, métodos e interações.
