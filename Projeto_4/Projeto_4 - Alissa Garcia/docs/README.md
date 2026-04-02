README – Projeto de Gerenciamento de Notas

Este projeto foi feito para praticar modularização, modificadores de acesso e função amiga em C++. Eu criei duas classes: Aluno e Disciplina, separadas em arquivos .h e .cpp.

Na classe Aluno, implementei:

Construtor padrão (sem parâmetros).

Construtor parametrizado (recebendo nome, matrícula e curso).

Um método para exibir as informações básicas do aluno.

Na classe Disciplina, implementei:

Construtor padrão.

Construtor parametrizado (nome, carga horária e nota).

Funções setNota() e getNota() para modificar e acessar a nota.

Atributos privados para garantir encapsulamento.

Também usei uma função amiga chamada verificarAprovacao, que acessa diretamente a nota da disciplina e diz se o aluno está aprovado (nota ≥ 6). Essa função precisa ser amiga porque a nota é privada.

No main.cpp, criei um objeto Aluno, associei disciplinas e usei a função amiga para mostrar se ele foi aprovado ou não.