# Gerenciamento de Notas de Alunos

Este projeto é um sistema em C++ para o gerenciamento de notas de alunos, permitindo calcular médias, verificar status de aprovação e exibir informações organizadas.

## Funcionalidades
- Gerenciar alunos com informações de nome, matrícula e curso.
- Associar disciplinas a cada aluno, com suas respectivas notas.
- Verificar aprovação em disciplinas (nota mínima: 6.0).
- Exibir todas as informações do aluno e suas disciplinas, incluindo status de aprovação.

## Estrutura do Projeto

A estrutura do código é modularizada, com arquivos organizados da seguinte forma:

```
.
├── include
│   ├── Aluno.h
│   └── Disciplina.h
├── src
│   ├── Aluno.cpp
│   ├── Disciplina.cpp
│   └── main.cpp
└── build
```

## Requisitos

Certifique-se de ter instalado:
- Um compilador compatível com C++ (como `g++` ou `clang++`).
- Sistema operacional com suporte para compilar e executar código C++ (Linux, Windows, macOS).

## Como Compilar e Executar

1. Clone este repositório para sua máquina:
   ```bash
   git clone <URL_DO_REPOSITORIO>
   cd <NOME_DO_REPOSITORIO>
   ```

2. Compile o código fonte:
   ```bash
   g++ -std=c++17 -I include -o build/gerenciamento_notas src/*.cpp
   ```

3. Execute o programa:
   ```bash
   ./build/gerenciamento_notas
   ```

## Exemplo de Saída

Ao executar o programa, você verá uma saída como esta:

```
Aluno: Joao Silva
Matricula: 20230001
Curso: Ciencia da Computacao

Disciplinas:
- Matematica: Nota = 7.5 (Aprovado)
- Programacao: Nota = 5.8 (Reprovado)
```

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir uma issue ou enviar um pull request com melhorias.

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).

