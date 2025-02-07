class Cliente {
    constructor(nome, cpf) {
        this.nome = nome;
        this.#cpf = cpf; // Encapsulamento
    }

    #cpf;

    exibirInformacoes() {
        return `Nome: ${this.nome}, CPF: ${this.#cpf}`;
    }

    getCpf() {
        return this.#cpf;
    }
}

    export { Cliente };