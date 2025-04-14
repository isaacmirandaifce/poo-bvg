# 🎬 API de Streaming de Filmes

Bem-vindo à API de **Streaming de Filmes**! 🍿 Esta API foi construída utilizando **FastAPI** e segue a arquitetura **MVC (Model-View-Controller)** com camadas de **DAO** (Data Access Object) e **Service** para garantir uma separação clara de responsabilidades.

## 📦 Tecnologias

- **FastAPI**: Framework rápido e moderno para construir APIs com Python.
- **Pydantic**: Validação de dados e parsing.
- **JSON**: Armazenamento de filmes em formato JSON.
- **Arquitetura MVC**: Separação de responsabilidades entre Models, Views e Controllers.
- **DAO e Service**: Camadas de acesso aos dados e lógica de negócios.

## 📋 Funcionalidades

- **Cadastro de Filmes**: Adicione filmes à sua coleção. 🎥
- **Atualização de Filmes**: Atualize informações de filmes já cadastrados. ✏️
- **Busca por ID**: Encontre filmes pelo ID único. 🔍
- **Remoção de Filmes**: Exclua filmes da sua coleção. ❌
- **Listagem de Filmes**: Obtenha todos os filmes cadastrados. 📜

## 🚀 Rodando a Aplicação

Para rodar esta API localmente, siga os passos abaixo:

### 1. Clone o repositório

```bash
git clone https://github.com/seu-usuario/streaming-filmes-api.git
cd streaming-filmes-api
```

### 2. Crie um ambiente virtual

```bash
python -m venv venv
```

### 3. Ative o ambiente virtual

- Windows:

```
.\venv\Scripts\activate
```

- Linux/MacOS:

```
source venv/bin/activate
```

### 4. Instale as dependências

```
pip install -r requirements.txt
```

### 5. Rode a aplicação

```
uvicorn app.main:app --reload
```

## 📝 Endpoints

### 1. Cadastrar um Filme 🎬

    Endpoint: POST /filmes
    Descrição: Adiciona um novo filme ao catálogo.

```
Exemplo de request:
{
  "titulo": "Matrix",
  "genero": "Ficção Científica",
  "descricao": "Um programador é levado para um mundo de realidades virtuais.",
  "ano": 1999,
  "avaliacao": 8.7
}
```

### 2. Atualizar um Filme ✏️

    Endpoint: PUT /filmes/{filme_id}
    Descrição: Atualiza os dados de um filme existente.

### 3. Buscar Filme por ID 🔍

    Endpoint: GET /filmes/{filme_id}
    Descrição: Busca um filme pelo ID.

### 4. Listar Todos os Filmes 📜

    Endpoint: GET /filmes
    Descrição: Lista todos os filmes cadastrados.

### 5. Excluir um Filme ❌

    Endpoint: DELETE /filmes/{filme_id}
    Descrição: Exclui um filme da coleção.

## 🧑‍💻 Arquitetura

A  API segue a arquitetura MVC com as seguintes camadas:

- Model: Define os dados, no caso, o modelo Filme.
- View: Interface com o usuário (aqui representada pela API, ou seja, os endpoints).
- Controller: Gerencia as interações entre o usuário e o modelo. O controlador (FilmeController) expõe os endpoints da API.
- DAO (Data Access Object): A camada que lida diretamente com a persistência de dados. No nosso caso, ela lê e escreve os filmes em um arquivo JSON.
- Service: Contém a lógica de negócios. A camada de serviço (FilmeService) gerencia a lógica de adição, atualização e exclusão de filmes.

## 💡 Contribuindo

Se você tem sugestões ou melhorias para este projeto, fique à vontade para fazer um fork e submeter um pull request! 🤝
