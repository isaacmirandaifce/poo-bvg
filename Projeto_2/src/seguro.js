class Seguro{
    
    constructor(carro, cliente, valor, vigencia){
        this.carro = carro
        this.cliente = cliente
        this.valor = valor
        this.vigencia = vigencia
    }

    calcularValor(baseValor, taxa) {
        return baseValor + (baseValor * taxa);
      }
    
      verificarVigencia() {
        const hoje = new Date();
        const [inicio, fim] = this.vigencia.split(" a ").map(data => new Date(data));
        return hoje >= inicio && hoje <= fim;
      }
}

export default Seguro;
