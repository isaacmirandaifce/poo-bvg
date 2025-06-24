# 📊 Sistema Genérico de Filtragem e Relatórios Acadêmicos

Projeto Avaliativo 7 da disciplina de Programação Orientada a Objetos (POO).  
Este sistema expande a aplicação acadêmica existente utilizando **métodos e classes genéricas em C++**, permitindo manipulação, filtragem e ordenação de dados de forma reutilizável e escalável.

---

## 🎯 Objetivo

Aplicar os conceitos de **programação genérica (templates)** para criar ferramentas reutilizáveis de manipulação de dados em sistemas acadêmicos, reforçando a modularidade e reutilização de código.

---

## 📌 Funcionalidades Implementadas

- ✅ Classe genérica `Filtro<T>` para armazenar e manipular objetos de qualquer tipo.
- 🔍 Filtragem com expressões lambda (`std::function`) em listas de objetos:
  - Alunos com média > 7.0
  - Professores que lecionam determinada disciplina
  - Disciplinas cursadas em um ano específico
- 📋 Impressão e ordenação genérica com critérios definidos em tempo de execução
- ♻️ Métodos reutilizáveis para qualquer tipo de dado

---

## 🧠 Conceitos Aplicados

- ✅ **Templates (Generics)** com C++
- ✅ **Funções Lambda** e **std::function**
- ✅ **Programação Funcional aplicada a containers**
- ✅ **Modularização e Encapsulamento**
- ✅ **Integração com sistema legado**

---

## 🧱 Estrutura do Projeto

```
Projeto_7/
│
├── src/ # Código-fonte principal
│ ├── Filtro.h # Classe genérica
│ ├── Aluno.h / Aluno.cpp # Classe Aluno (exemplo)
│ ├── Professor.h / Professor.cpp # Classe Professor (exemplo)
│ ├── FuncionarioAdministrativo.h / .cpp
│ ├── main.cpp # Arquivo principal de execução
│
├── docs/
│ └── diagrama_uml_generics.png # UML com Filtro<T> integrado
│
└── tests/
└── testes_filtro.cpp # Testes unitários
```
---

## 🔧 Como Compilar

Requisitos:
- C++11 ou superior
- Compilador `g++` (Linux/Windows)

```bash
cd src/
g++ -std=c++11 -o sistema_generico *.cpp
./sistema_generico

```

## 📚 Exemplo de Uso

```yaml
Filtro<Aluno> filtroAlunos;

filtroAlunos.adicionarElemento(Aluno("Ana", 8.2));
filtroAlunos.adicionarElemento(Aluno("Bruno", 6.7));

filtroAlunos.filtrarPorCondicao([](const Aluno& a) {
    return a.getMedia() > 7.0;
});

filtroAlunos.imprimirTodos([](const Aluno& a) {
    std::cout << a.getNome() << " - " << a.getMedia() << std::endl;
});

```

## 📚 Exemplo de Uso

```cpp
Filtro<Aluno> filtroAlunos;

filtroAlunos.adicionarElemento(Aluno("Ana", 8.2));
filtroAlunos.adicionarElemento(Aluno("Bruno", 6.7));

filtroAlunos.filtrarPorCondicao([](const Aluno& a) {
    return a.getMedia() > 7.0;
});

filtroAlunos.imprimirTodos([](const Aluno& a) {
    std::cout << a.getNome() << " - " << a.getMedia() << std::endl;
});

```

## 🧩 Estrutura da Classe Filtro<T>

```cpp
template <typename T>
class Filtro {
private:
    std::vector<T> elementos;

public:
    void adicionarElemento(T elemento);
    std::vector<T> filtrarPorCondicao(std::function<bool(const T&)> condicao);
    void imprimirTodos(std::function<void(const T&)> acao);
    void ordenarPor(std::function<bool(const T&, const T&)> criterio);
};

```

## 📊 Diagrama UML
Disponível em: `docs/diagrama_uml_generics.png`.
Inclui a classe genérica `Filtro<T>` e sua relação com `Aluno`, `Professor`, etc.

## 📑 Documentação e Comentários
Cada método está documentado diretamente no código com comentários explicando:

* A finalidade

* Como utilizar

* Exemplo prático

## 📖 Licença
Este projeto é acadêmico e de uso livre para fins educacionais.
Contribuições e melhorias são bem-vindas!