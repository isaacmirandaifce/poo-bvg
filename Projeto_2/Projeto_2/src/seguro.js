class Seguro {
  constructor(carros, cliente, valor, vigencia) {
    this.carros = Array.isArray(carros) ? carros : [carros];
    this.cliente = cliente;
    this.valor = valor;
    this.vigencia = vigencia;
  }

  calcularValor(baseValor, taxa) {
    return baseValor + baseValor * taxa;
  }

  verificarVigencia() {
    const hoje = new Date();
    const dataFim = new Date(this.vigencia);
    return hoje <= dataFim;
  }

  exibirCarros() {
    return this.carros.map((carro) => carro.exibirDetalhes()).join("\n");
  }
}

export default Seguro;
