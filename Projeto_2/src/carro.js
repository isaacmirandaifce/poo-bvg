class Carro {
  constructor(ano, marca, modelo, cor, placa) {
      this.ano = ano;
      this.marca = marca;
      this.modelo = modelo;
      this.cor = cor;
      this.#placa = placa; // Encapsulamento
  }

  #placa;

  exibirDetalhes() {
      return `Ano: ${this.ano}, Marca: ${this.marca}, Modelo: ${this.modelo}, Cor: ${this.cor}, Placa: ${this.#placa}`;
  }

  atualizarCor(novaCor) {
      this.cor = novaCor;
  }

  getPlaca() {
      return this.#placa;
  }
}
  
  export { Carro };
  