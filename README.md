# Sistema Acadêmico com Tratamento de Exceções e Sinais

## Descrição
Este projeto implementa um sistema acadêmic, utilizando **tratamento de exceções** e **manipulação de sinais** em Python. Ele permite cadastrar alunos, listar alunos e salvar os dados em um arquivo CSV.

## Funcionalidades
- **Cadastro de Alunos**: Permite adicionar novos alunos com nome e média.
- **Listagem de Alunos**: Exibe a lista de alunos cadastrados.
- **Persistência de Dados**: Os dados são armazenados em um arquivo CSV.
- **Tratamento de Exceções**: Garante a segurança na leitura e escrita de arquivos.
- **Manipulação de Sinais**: Captura sinais como `SIGINT` (Ctrl + C) para finalizar o programa de forma segura.

## Requisitos
- Python 3.x
- Biblioteca `csv` (nativa do Python)
- Biblioteca `signal` (nativa do Python)


## Exemplo de Uso
```
Bem-vindo ao Sistema Acadêmico
1. Cadastrar aluno
2. Listar alunos
3. Sair
Escolha uma opção: 1
Digite o nome do aluno: Maria
Digite a matrícula do aluno: 20256697974
Aluno cadastrado com sucesso!
```

## Tratamento de Exceções
- Se o arquivo `alunos.csv` não existir, ele será criado automaticamente.
- Se ocorrer um erro ao abrir o arquivo, o programa exibe uma mensagem amigável.
- Se o usuário pressionar `Ctrl + C`, o programa encerra de forma segura.

## Autor
Maria Fernanda

## Licença
Este projeto está licenciado sob a [MIT License](LICENSE).