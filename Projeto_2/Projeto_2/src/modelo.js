class Modelo {
  constructor(nome) {
    this._nome = nome;
  }

  get nome() {
    return this._nome;
  }

  exibirModelo() {
    return `Modelo(nome='${this._nome}')`;
  }
}

export default Modelo;
