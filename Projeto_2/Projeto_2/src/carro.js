class Carro {
  #placa;

  constructor(ano, marca, modelo, cor, placa) {
    this.ano = ano;
    this.marca = marca;
    this.modelo = modelo;
    this.cor = cor;
    this.#placa = placa;
  }

  getPlaca() {
    return this.#placa;
  }

  exibirDetalhes() {
    return `Ano: ${this.ano}, Marca: ${this.marca}, Modelo: ${
      this.modelo
    }, Cor: ${this.cor}, Placa: ${this.getPlaca()}`;
  }

  atualizarCor(novaCor) {
    this.cor = novaCor;
  }
}

export default Carro;
