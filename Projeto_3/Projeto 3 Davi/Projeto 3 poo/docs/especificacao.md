🧾 Especificações da Classe Pessoa
📦 Atributos
Atributo	Tipo	Acesso	Descrição
nome	string	privado	Armazena o nome da pessoa
telefone	string	privado	Armazena o número de telefone da pessoa

🧠 Métodos
🔹 Construtor

Pessoa(string nome, string telefone);
Recebe o nome e telefone como parâmetros.

Inicializa os atributos com os valores recebidos.

Exibe uma mensagem informando que a pessoa foi criada.

🔹 Destrutor

~Pessoa();
Exibe uma mensagem informando que a pessoa foi destruída (útil para controle e debug).

🔹 imprimirNome

void imprimirNome() const;
Exibe o nome da pessoa no console.

Método constante: garante que não altera os atributos do objeto.

🔹 imprimirTelefone

void imprimirTelefone() const;
Exibe o telefone da pessoa no console.

Também é constante.

🖥️ Especificações da Função main
📚 Objetivo:
Gerenciar uma lista de objetos Pessoa armazenados em um vetor, exibindo seus dados.

⚙️ Passos Executados:
Criação do vetor:


vector<Pessoa> pessoas;
Vetor dinâmico que armazena objetos da classe Pessoa.

Adição de pessoas:



pessoas.emplace_back("Davi", "(88)98152-2318");
pessoas.emplace_back("Henrique", "(88)99182-7348");
pessoas.emplace_back("Pedro", "(88)98854-9348");
Cria e adiciona objetos diretamente ao vetor usando emplace_back.

Exibição das informações:


for(const auto& pessoa : pessoas) {
    pessoa.imprimirNome();
    pessoa.imprimirTelefone();
}
Loop para percorrer o vetor e imprimir nome e telefone de cada pessoa.

Encerramento:

Ao final da função main, o destrutor de cada objeto é chamado automaticamente, na ordem inversa de criação.

🧪 Observações Técnicas
emplace_back vs push_back: emplace_back é mais eficiente pois constrói o objeto diretamente dentro do vetor.

Destrutores são úteis para depuração e liberação de recursos (como arquivos, memória dinâmica etc.).

Uso de const nas funções indica boas práticas de encapsulamento, garantindo que elas não modificam o objeto.

