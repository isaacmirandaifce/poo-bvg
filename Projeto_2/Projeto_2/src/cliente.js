class Cliente {
  #cpf;

  constructor(nome, cpf) {
    this.nome = nome;
    this.#cpf = cpf;
  }

  getCpf() {
    return this.#cpf;
  }

  exibirInformacoes() {
    return `Nome: ${this.nome}, CPF: ${this.getCpf()}`;
  }
}

export default Cliente;
