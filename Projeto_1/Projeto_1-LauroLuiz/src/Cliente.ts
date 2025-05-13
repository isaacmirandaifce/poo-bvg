// Classe que representa um cliente da loja
export class Cliente{
    // Atributos privados
    private nome: string;
    private idade: number;
    private saldo: number;

    // Construtor para inicializar os atributos
    constructor(nome:string, idade:number, saldo:number){
        this.nome = nome;
        this.idade = idade;
        this.saldo = saldo;
    }

// Método para exibir as informações do cliente
public mostrar_informacoes(){
    console.log(`Cliente: ${this.nome}, Idade: ${this.idade}, Saldo: ${this.saldo}`);
}

    // Método para atualizar o saldo do cliente
    public atualizar_saldo(valor:number){
        this.saldo += valor
    }
}

