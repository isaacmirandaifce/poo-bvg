/* Definição da classe */
class Cliente {
    /* Inicialização dos atributos */
    constructor (nome, idade, saldo) {
        this._nome = nome;
        this._idade = idade;
        this._saldo = saldo;
    }
/* Método para exibir as informações e Método para atualizar o saldo*/
    mostrarInformações() {
        console.log(`Cliente: ${this._nome}, Idade: ${this._idade}, Saldo: ${this._saldo}`);
    }

    atualizarSaldo(valor) {
        this._saldo += valor;
    }
}
/* Exportação da classe para utilizar em outros arquivos */
export {Cliente};