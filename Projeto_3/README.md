# Projeto Avaliativo 3: Introdução a C++

## Objetivo
Este projeto introduz conceitos fundamentais de C++ — criação de classes, uso de métodos,
containers (`vector`), manipulação de strings, namespaces e estruturação de código — através
do desenvolvimento do Módulo de Contatos B2B do CRM Enterprise (Ticket #612).

## Estrutura de Arquivos

```
Projeto_3/
│
├── docs/
│   └── Contato_UML.png   # Diagrama de Classes
│
├── src/
│   ├── Contato.h         # Header: declaração da classe e atributos
│   ├── Contato.cpp       # Source: construtores, destrutor e métodos
│   └── main.cpp          # Ponto de entrada: uso do std::vector<Contato>
│
└── README.md
```

## Classe `Contato`
- Atributos privados: `std::string nome`, `std::string telefone`.
- Construtor padrão e construtor parametrizado (usa o ponteiro `this` para diferenciar
  parâmetros de atributos).
- Destrutor que imprime um log informando a desalocação do objeto da memória.
- Métodos `imprimirNome()` e `imprimirTelefone()`.

## `main.cpp`
Utiliza `std::vector<Contato>` para armazenar pelo menos 3 contatos (adicionados via
`push_back`) e percorre o vetor em um laço, exibindo nome e telefone de cada um.

## Como Compilar e Executar

Com o GCC (`g++`), a partir da pasta `Projeto_3`:

```bash
g++ src/main.cpp src/Contato.cpp -o crm_app
./crm_app
```

No Windows (PowerShell), o executável gerado terá extensão `.exe`:

```powershell
g++ src/main.cpp src/Contato.cpp -o crm_app.exe
./crm_app.exe
```

## Diagrama UML
O diagrama de classes (`docs/Contato_UML.png`) representa a classe `Contato`, seus atributos
e métodos, com a visibilidade (`-` privado, `+` público) e os tipos de dados em C++.
