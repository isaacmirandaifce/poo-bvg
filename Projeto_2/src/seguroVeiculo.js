class SeguroVeiculo {
  constructor(cliente, carro, valor, vigencia) {
      this.cliente = cliente;
      this.carro = carro;
      this.valor = valor;
      this.vigencia = vigencia;
  }

  calcularValor(baseValor, taxa) {
      this.valor = baseValor + (baseValor * taxa);
      return this.valor;
  }

  verificarVigencia() {
      const hoje = new Date();
      const [inicio, fim] = this.vigencia.split(' a ');
      const vigenciaFinal = new Date(fim.split('/').reverse().join('-'));
      return hoje <= vigenciaFinal;
  }
}

class SeguroCarro extends SeguroVeiculo {
  calcularValor(baseValor, taxa) {
      taxa += 0.05;
      return super.calcularValor(baseValor, taxa);
  }
}

class SeguroMoto extends SeguroVeiculo {
  calcularValor(baseValor, taxa) {
      taxa += 0.03;
      return super.calcularValor(baseValor, taxa);
  }
}

export { SeguroVeiculo, SeguroCarro, SeguroMoto };
