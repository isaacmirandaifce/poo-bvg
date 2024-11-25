class Cliente{
    constructor(nome, idade, saldo){
        this.nome = nome;
        this.idade = idade;
        this.saldo = saldo;
    
    }
    mostrarInformacoes() {
        console.log(`NOME: ${this.nome}\nIDADE: ${this.idade}\n SALDO: ${this.nome}\n`);
    }
    AlterarSaldo(valor) {
        this.saldo += valor;
    }
}
