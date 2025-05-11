class cliente{

    #nome_cliente
    #idade_cliente
    #saldo_cliente        
    constructor (nome_cliente, idade_cliente, saldo_cliente){

        this.#nome_cliente= nome_cliente
        this.#idade_cliente= idade_cliente
        this.#saldo_cliente= saldo_cliente

    }
    mostrarInformacoes(){

        console.log(`o nome do cliente é: ${this.#nome_cliente}`)
        console.log(`a idade é: ${this.#idade_cliente}`)
        console.log(`o saldo é: ${this.#saldo_cliente}`)

    }

    atualizarSaldo(valor){

        if(valor > 0){
        this.#saldo_cliente += valor
        console.log(`o saldo atualizado é: ${this.#saldo_cliente}`)  
        }else{console.log(`valor invalido então o saldo é o mesmo: ${this.#saldo_cliente}`)}
    }
}

const cliente1= new cliente("joão", 30, 1000)
cliente1.mostrarInformacoes()
cliente1.atualizarSaldo(55)
