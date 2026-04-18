class Cliente {
  #nome;
  #idade;
  #saldo;
  #ativo;

  constructor(nome, idade, saldoInicial = 0) {
    this.#nome = nome;
    this.#idade = idade;
    this.#saldo = saldoInicial;
    this.#ativo = true;
  }

  get nome() {
    return this.#nome;
  }

  get idade() {
    return this.#idade;
  }

  get saldo() {
    return this.#saldo;
  }

  get ativo() {
    return this.#ativo;
  }

  depositar(valor) {
    if (valor <= 0) {
      throw new Error("Valor de depósito inválido.");
    }

    this.#saldo += valor;
    return `Depósito de R$${valor.toFixed(2)} realizado. Novo saldo: R$${this.#saldo.toFixed(2)}`;
  }

  sacar(valor) {
    if (valor <= 0) {
      throw new Error("Valor de saque inválido.");
    }

    if (!this.#ativo) {
      throw new Error("Conta inativa.");
    }

    if (valor > this.#saldo) {
      throw new Error("Saldo insuficiente. Operação recusada.");
    }

    this.#saldo -= valor;
    return `Saque de R$${valor.toFixed(2)} realizado. Novo saldo: R$${this.#saldo.toFixed(2)}`;
  }

  toString() {
    return `Nome: ${this.#nome} | Idade: ${this.#idade} | Saldo: R$${this.#saldo.toFixed(2)} | Ativo: ${this.#ativo}`;
  }
}

class SistemaClientes {
  #clientes;
  #proximoId;
  #limiteClientes;

  constructor(limiteClientes = 100) {
    this.#clientes = new Map();
    this.#proximoId = 0;
    this.#limiteClientes = limiteClientes;
  }

  cadastrarCliente(nome, idade, saldoInicial = 0) {
    if (this.#clientes.size >= this.#limiteClientes) {
      throw new Error("Erro Crítico: Limite de memória atingido.");
    }

    const cliente = new Cliente(nome, idade, saldoInicial);
    const id = this.#proximoId++;

    this.#clientes.set(id, cliente);

    console.log(`Sucesso: Cliente ${nome} cadastrado com ID ${id}`);
    return id;
  }

  movimentarConta(idCliente, valor, isSaque) {
    const cliente = this.#clientes.get(idCliente);

    if (!cliente) {
      throw new Error("Cliente não encontrado.");
    }

    if (isSaque) {
      console.log(cliente.sacar(valor));
    } else {
      console.log(cliente.depositar(valor));
    }
  }

  exibirRelatorio() {
    console.log("--- RELATÓRIO GERAL ---");

    for (const [id, cliente] of this.#clientes.entries()) {
      console.log(`ID: ${id} | ${cliente.toString()}`);
    }
  }
}

module.exports = { Cliente, SistemaClientes };