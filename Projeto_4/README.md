# Projeto_4 - William Axel: Gerenciamento de notas com modularização e função amiga

## Objetivo
Desenvolver um projeto em C++ para gerenciar notas de alunos, utilizando modularização, modificadores de acesso e funções amigas.

## Classes
### Aluno
- **Atributos**: `nome` (string), `matricula` (string), `curso` (string)
- **Métodos**:
  - Construtor padrão e parametrizado
  - `void exibirInformacoes()`: exibe informações do aluno

### Disciplina
- **Atributos**: `nome` (string), `cargaHoraria` (int), `nota` (float)
- **Métodos**:
  - Construtor padrão e parametrizado
  - `void setNota(float)`, `float getNota()`
  - Função amiga `verificarAprovacao(Aluno, Disciplina)` que retorna se o aluno foi aprovado (nota >= 6.0)

## Função Principal
- Criar objetos `Aluno`
- Associar a pelo menos duas `Disciplina` para cada aluno
- Exibir informações do aluno
- Usar a função amiga para verificar aprovação

## Estrutura de Arquivos
## Critérios de Avaliação
- Implementação técnica correta
- Uso adequado de modificadores de acesso e encapsulamento
- Função amiga implementada corretamente
- Diagrama UML completo e bem representado
- Código limpo, organizado e comentado