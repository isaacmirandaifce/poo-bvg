
# 🍽️ Sistema de Reserva para Restaurante "Mesa do Chef"

Este é um sistema web completo, desenvolvido com Django, para gerenciar reservas de mesas em um restaurante. O projeto conta com uma interface moderna para o cliente e um painel administrativo funcional para o gerenciamento do estabelecimento.

##  Funcionalidades

### Página do Cliente

  * **Formulário de Reserva Moderno:** Interface de usuário "chamativa" com imagem de fundo, fontes profissionais e layout responsivo.
  * **Criação de Reservas:** O cliente pode preencher seus dados (Nome, CPF, Telefone), escolher a data, hora e quantidade de pessoas.
  * **Visualização de Cardápio:** Um botão abre um pop-up (modal) com a imagem do cardápio do restaurante.
  * **Confirmação de Sucesso:** Após a reserva, o cliente é direcionado para uma página de confirmação com o mesmo design visual, criando uma experiência coesa.
  * **Disponibilidade de Mesas:** O sistema verifica automaticamente a disponibilidade de mesas com base na data e capacidade, alocando a primeira mesa livre que atenda aos requisitos.

### Painel Administrativo

  * **Gerenciamento de Mesas:** O administrador pode criar, editar e excluir as mesas do restaurante, definindo seu número e capacidade.
  * **Visualização de Reservas:** Lista todas as reservas feitas, com filtros por data e por mesa, além de uma barra de busca por nome, CPF ou telefone do cliente.
  * **Interface Personalizada:** O painel de administração padrão do Django foi personalizado para se adequar melhor às necessidades do projeto.

## 🛠️ Tecnologias Utilizadas

  * **Backend:** Python 3, Django 5+
  * **Frontend:** HTML5, CSS3 (customizado, sem frameworks)
  * **Banco de Dados:** SQLite 3 (padrão do Django para desenvolvimento)
  * **Gerenciamento de Ambiente:** Python `venv`

## 🚀 Como Executar o Projeto

Siga os passos abaixo para configurar e executar o projeto em seu ambiente local.

### 1\. Pré-requisitos

  * Python 3.10 ou superior instalado.
  * `pip` (gerenciador de pacotes do Python).

### 2\. Instalação

**a. Clone ou baixe este repositório:**

```bash
# Se estiver usando git
git clone .git
cd projeto_reserva_restaurante
```

**b. Crie e ative o ambiente virtual:**

```bash
# Crie o ambiente
python -m venv .venv

# Ative o ambiente (Windows PowerShell)
.\.venv\Scripts\Activate.ps1
```

**c. Crie o arquivo `requirements.txt` (se ainda não existir):**
Este arquivo lista as dependências do projeto.

```bash
(.venv) > pip freeze > requirements.txt
```

**d. Instale as dependências:**

```bash
(.venv) > pip install -r requirements.txt
```

### 3\. Configuração do Banco de Dados

**a. Crie as migrações e o banco de dados:**

```bash
(.venv) > python manage.py makemigrations
(.venv) > python manage.py migrate
```

**b. Crie um superusuário para acessar o painel administrativo:**

```bash
(.venv) > python manage.py createsuperuser
```

Siga as instruções para criar seu nome de usuário, e-mail e senha.

### 4\. Executando o Servidor

Com tudo configurado, inicie o servidor de desenvolvimento:

```bash
(.venv) > python manage.py runserver
```

O sistema estará no ar\!

## 🌐 Acessando o Sistema

  * **Página do Cliente (Reservas):** [http://127.0.0.1:8000/]
  (http://127.0.0.1:8000/)
  * **Painel Administrativo:** [http://127.0.0.1:8000/admin/]
  (https://www.google.com/search?q=http://127.0.0.1:8000/admin/)

