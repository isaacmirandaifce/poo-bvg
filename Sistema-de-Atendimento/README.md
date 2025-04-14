
# POOIsaac - Sistema de Atendimento

## Descrição

Este é um sistema simples de atendimento baseado em filas e guichês. A aplicação foi desenvolvida utilizando o framework Flask e implementa conceitos fundamentais de Programação Orientada a Objetos (POO).

O sistema é composto por guichês que atendem clientes, onde a interação com as classes `Guiche` e `Cliente` é fundamental. O projeto foi estruturado de forma modular, utilizando conceitos de **encapsulamento**, **herança** e **polimorfismo**.

## Estrutura de Diretórios

```plaintext
pooIsaac/
│
├── app.py               # Arquivo principal para iniciar a aplicação Flask
├── controllers/         # Contém os controladores para as rotas
├── dados/               # Dados ou banco de dados do sistema
├── models/              # Contém as classes de modelo (ex: Guiche, Cliente)
├── routes/              # Define as rotas para os controladores
├── services/            # Contém serviços que manipulam os dados
├── static/              # Arquivos estáticos como imagens, CSS, JS
├── templates/           # Templates HTML para renderização
├── utils/               # Funções auxiliares
├── venv/                # Ambiente virtual
└── requirements.txt     # Dependências do projeto
```

## Como Usar

1. **Instalar dependências**:

```bash
pip install -r requirements.txt
```

2. **Rodar a aplicação**:

```bash
python app.py
```

A aplicação estará acessível em `http://localhost:5000`.

## Conceitos de POO Implementados

1. **Encapsulamento**: As classes como `Guiche` e `Cliente` mantêm seus atributos privados e interagem entre si apenas através de métodos específicos.
   
2. **Herança**: A classe `ClientePrioritario` herda de `Cliente` e sobrescreve o comportamento do atributo `tipo`, demonstrando como diferentes tipos de clientes podem ser tratados de forma diferenciada.

3. **Polimorfismo**: A sobrescrição de métodos, como o `__init__` em `ClientePrioritario`, permite que o sistema trate clientes de diferentes tipos com o mesmo código base, adaptando-se às necessidades de cada tipo de cliente.

## Conclusão

Este sistema foi desenvolvido para exemplificar o uso de POO em um cenário simples de atendimento ao cliente. A estrutura modular facilita a manutenção e a expansão do sistema.
