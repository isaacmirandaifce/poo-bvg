# 🎓 Sistema Avançado de Gestão Acadêmica

Projeto Avaliativo 6 da disciplina de Programação Orientada a Objetos (POO).  
Este sistema simula uma aplicação de gestão acadêmica, integrando conceitos avançados como **Classes Abstratas**, **Interfaces**, **Classes Enumeradas** e **Classes Internas** em C++.

## 📌 Objetivo

Ampliar o sistema de gerenciamento acadêmico, implementando autenticação de usuários, geração de relatórios e categorização de perfis, utilizando os principais recursos de POO.

## 🧱 Funcionalidades

- ✅ Autenticação de usuários com senha
- 📄 Geração de relatórios para alunos, professores e funcionários administrativos
- 🧑‍🎓 Histórico disciplinar para alunos com classe interna
- 🧩 Uso de **classe abstrata** `UsuarioAutenticavel`
- 🧪 Uso de **interface** `Relatorio`
- 📚 Uso de **enumeração** `TipoUsuario`
- 🔐 Encapsulamento e proteção de dados sensíveis

## 🧭 Estrutura do Projeto

```
Projeto_6/
│
├── src/ # Código-fonte
│ ├── Usuario.h
│ ├── UsuarioAutenticavel.h / .cpp
│ ├── Relatorio.h
│ ├── TipoUsuario.h
│ ├── Aluno.h / .cpp
│ ├── Professor.h / .cpp
│ ├── FuncionarioAdministrativo.h / .cpp
│ └── main.cpp
│
├── docs/ # Documentação
│ └── diagrama_uml.png
│
└── tests/ # Testes
└── testes_unitarios.cpp
```


## 🧰 Tecnologias Utilizadas

- Linguagem: **C++**
- Paradigma: **Programação Orientada a Objetos**
- Compilador: `g++` (recomendado: `g++ -std=c++11`)
- Plataforma: Terminal/Linux/Windows

## 📌 Detalhes Técnicos

### 🔷 Classe Abstrata
```cpp
class UsuarioAutenticavel : public Usuario {
public:
    virtual bool autenticar(std::string senha) = 0;
};
```

### 🟪 Interface
```cpp
class Relatorio {
public:
    virtual void gerarRelatorio() const = 0;
    virtual ~Relatorio() {}
};
```

### 🟨 Enumeração
```cpp

enum class TipoUsuario {
    ALUNO,
    PROFESSOR,
    FUNCIONARIO_ADMINISTRATIVO
};
```
### ⛺ Classe Interna
```cpp
class Aluno : public UsuarioAutenticavel, public Relatorio {
private:
    class HistoricoDisciplinar {
        std::string nomeDisciplina;
        int ano;
        float nota;
    };
};
```

## 🚀 Como Compilar e Executar
```bash
cd src/
g++ -std=c++11 -o sistema_academico *.cpp
./sistema_academico
```

## 📖 Licença
Este projeto é acadêmico e não possui fins comerciais. Uso livre para fins educacionais.