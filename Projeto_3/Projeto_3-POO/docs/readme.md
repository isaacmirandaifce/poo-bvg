# - Projeto 3 - POO

Este repositório contém uma implementação simples de uma classe C++ chamada Pessoa, que armazena e exibe informações básicas como nome e telefone.

# - Estrutura do Projeto

- Pessoa.h: Arquivo de cabeçalho contendo a declaração da classe Pessoa.
- Pessoa.cpp: Implementação dos métodos da classe Pessoa.
- main.cpp: Programa principal que demonstra o uso da classe Pessoa.


# - Funções

- **Classe Pessoa**
- Atributos Privados:
- std::string nome; - Nome da pessoa.
- std::string telefone; - Telefone da pessoa.

- **Métodos Públicos:**
- Construtor Padrão: Inicializa nome e telefone como strings vazias.
- Construtor Parametrizado: Inicializa nome e telefone com valores fornecidos.
- Destrutor: Exibe uma mensagem ao destruir um objeto Pessoa.
- void imprimirNome(); - Exibe o nome da pessoa.
- void imprimirTelefone(); - Exibe o telefone da pessoa.