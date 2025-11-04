# Projeto 3 — Introdução a C++

Descrição
---------
Este projeto demonstra conceitos básicos de C++: classes, construtores/destrutores, encapsulamento, uso de `std::vector` e entrada/saída. A classe principal é `Pessoa`. O arquivo [`main.cpp`] cria várias instâncias de `Pessoa` e imprime seus dados.

Estrutura do projeto
-------------------
- Projeto_3/
  - src/
    - Pessoa.h          (declaração da classe `Pessoa`)
    - Pessoa.cpp        (implementação da classe)
    - main.cpp          (ponto de entrada do programa)
  - docs/
    - README.md
    - Pessoa_UML.png

Como compilar e executar
---------------------------------------------
Abra o terminal integrado do VS Code e execute os comandos abaixo a partir da raiz do projeto:

```sh
# entrar na pasta do projeto
cd /workspaces/poo-bvg/Projeto_3

# (opcional) compilar se ainda não compilou
mkdir -p bin
g++ -std=c++17 -Wall -Wextra src/*.cpp -o bin/projeto3

# executar o binário
./bin/projeto3
```

Se o binário já existir, apenas execute:
```sh
./bin/projeto3
```