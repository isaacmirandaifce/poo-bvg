# 🎮 Geeklog IGDB

> Plataforma para pesquisar jogos, visualizar detalhes e deixar reviews, com login via conta Google.

---

![Logo do Projeto][def]
## 🔧 Tecnologias
- Python 3.12
- Django 5.1.7
- Django Allauth (Login com Google)
- API IGDB via Twitch
- SQLite

---

## 🚀 Como rodar o projeto

```bash
# Clone o repositório
git clone https://github.com/seu-usuario/geeklog-igdb.git
cd geeklog-igdb

# Crie e ative o ambiente virtual
python -m venv .venv
.venv\Scripts\Activate.ps1

# Instale as dependências
pip install -r requirements.txt

# Aplique as migrações
python manage.py migrate

# Rode o servidor local
python manage.py runserver
```

---


## 👤 Login local (usuário/senha)

Você também pode criar uma conta tradicional acessando:
```
http://localhost:8000/accounts/signup/
```

---

## 🕹 Funcionalidades

- 🔍 Busca de jogos pelo nome
- 🧠 Detalhes com imagem, descrição, gênero e data de lançamento
- 📝 Sistema de reviews por usuários logados
- 🎮 Integração completa com a IGDB API

---

## 📂 Estrutura de pastas

```
Geeklog IGDB/
├── games/                # App principal
├── igdb_project/         # Configurações do projeto Django
├── static/               # Imagens e estilos
├── templates/            # Templates HTML globais
├── db.sqlite3            # Banco de dados local
├── manage.py             # CLI do Django
└── requirements.txt      # Dependências do projeto
```

---

## 🤝 Feito com carinho por

- [@Mario Jamisson](https://github.com/MarioJamisson)
- [@Maria Carolina](https://github.com/carolina03-ui)
- [@Taissa Moreira](https://github.com/T-more-create)
- [@Amanda Morais](https://github.com/Mandysan123)
- [@Gabrielly Morais](https://github.com/gabrielymorais)

---

[def]: logo.png