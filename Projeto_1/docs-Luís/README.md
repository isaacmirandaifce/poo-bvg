Sistema de Clientes Bancários
Este projeto simula a criação e manipulação de clientes bancários. Ele permite armazenar informações como nome, idade e saldo bancário, bem como atualizar o saldo de um cliente.

Estrutura do Projeto
O projeto é composto por dois arquivos principais:

classes.py: Contém a definição da classe cliente, que armazena informações do cliente e possui métodos para mostrar e atualizar essas informações.

main.py: Arquivo principal que cria instâncias de clientes e interage com os métodos da classe cliente.

Como Utilizar
1. Configuração do Ambiente
Certifique-se de ter o Python instalado na sua máquina. Você pode baixar a versão mais recente do Python em python.org.

2. Arquivos do Projeto
O projeto contém os seguintes arquivos:

classes.py: Define a classe cliente, que possui os seguintes métodos:

__init__(self, nome, idade, saldo): Inicializa um novo cliente com o nome, idade e saldo.

mostrar_informacoes(self): Exibe as informações do cliente.

atualizar_saldo(self, valor): Atualiza o saldo do cliente com o valor fornecido.

main.py: Exemplo de como utilizar a classe cliente para criar clientes e atualizar seus saldos.

3. Execução do Projeto
Passo 1: Certifique-se de que ambos os arquivos (classes.py e main.py) estão na mesma pasta.

Passo 2: Execute o arquivo main.py no terminal ou ambiente de desenvolvimento Python:

bash
Copiar
Editar
python main.py
Exemplo de Saída
plaintext
Copiar
Editar
Cliente: Marcos, Idade: 37, Saldo: 5800
Cliente: Juliana, Idade: 24, Saldo: 10200

Cliente: Marcos, Idade: 37, Saldo: 8100
Cliente: Juliana, Idade: 24, Saldo: 10880
Descrição do Código
Arquivo classes.py
A classe cliente é responsável por armazenar as informações de cada cliente e realizar ações como mostrar e atualizar o saldo.

Métodos da classe cliente:
__init__(nome, idade, saldo): Inicializa um novo cliente com os dados fornecidos.

mostrar_informacoes(): Exibe as informações do cliente, incluindo nome, idade e saldo bancário.

atualizar_saldo(valor): Atualiza o saldo bancário do cliente, somando o valor fornecido, mas somente se o valor for positivo.

Arquivo main.py
O arquivo main.py serve para instanciar os objetos cliente e demonstrar como interagir com os métodos da classe cliente.

O que o código faz:
Cria dois clientes (Cliente1 e Cliente2), fornecendo nome, idade e saldo inicial.

Exibe as informações de cada cliente.

Atualiza o saldo dos clientes e exibe as novas informações.

Licença
Este projeto está licenciado sob a MIT License.
