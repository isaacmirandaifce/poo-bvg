Especificações da Classe Pessoa e do Programa Principal (C++)

Classe Pessoa

Atributos Privados:

nome (string): Nome da pessoa.

telefone (string): Número de telefone da pessoa.

Construtor:

Pessoa(string nome, string telefone);

Inicializa os atributos com os valores recebidos.

Exibe mensagem no console indicando que a pessoa foi criada.

Destrutor:

~Pessoa();

Exibe mensagem no console indicando que a pessoa foi destruída.

Métodos Públicos:

void imprimirNome() const:

Exibe o nome da pessoa.

void imprimirTelefone() const:

Exibe o telefone da pessoa.

Todos os métodos "const" garantem que o objeto não será alterado ao serem chamados.

Função main()

Objetivo:

Demonstrar o uso da classe Pessoa armazenando objetos em um vector e exibindo seus dados.

Fluxo:

Cria um vetor de Pessoa:

vector<Pessoa> pessoas;

Adiciona três objetos Pessoa usando emplace_back:

pessoas.emplace_back("Davi", "(88)98152-2318");
pessoas.emplace_back("Henrique", "(88)99182-7348");
pessoas.emplace_back("Pedro", "(88)98854-9348");

Percorre o vetor e imprime os dados:

for(const auto& pessoa : pessoas) {
    pessoa.imprimirNome();
    pessoa.imprimirTelefone();
}

Ao final da execução, os destrutores são chamados automaticamente.

Considerações:

Uso de vector permite gestão dinâmica da lista de pessoas.

emplace_back é preferível ao push_back para performance.

O destrutor ajuda a rastrear a destruição dos objetos e é útil para liberação de recursos.

O uso de const nos métodos garante boas práticas de encapsulamento e imutabilidade de leitura.

