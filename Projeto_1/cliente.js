class Cliente {
    
    constructor(nome, idade, saldo) {
      this._nome = nome; 
      this._idade = idade; 
      this._saldo = saldo; 
    }
  
    //metodo pra mostrar as informacoes do cliente

    mostrarInformacoes() {
      console.log(`Cliente: ${this._nome}, Idade: ${this._idade}, Saldo: R$${this._saldo.toFixed(2)}`)
    }
  
    // metodo que atualiza as info do cliente

    atualizarSaldo(valor) {
      this._saldo += valor;
      console.log(`Saldo atualizado! Novo saldo: R$${this._saldo.toFixed(2)}`);
    }
  
    // os getters pra pode acessar os atributos privados 
    get nome() {
      return this._nome;
    }
  
    get idade() {
      return this._idade;
    }
  
    get saldo() {
      return this._saldo;
    }
  
    // os setters pra poder alterar os atributos privados
    set nome(novoNome) {
      this._nome = novoNome;
    }
  
    set idade(novaIdade) {
      if (novaIdade > 0) {
        this._idade = novaIdade;
      } else {
        console.error("Idade inválida!");
      }
    }
  
    set saldo(novoSaldo) {
      if (novoSaldo >= 0) {
        this._saldo = novoSaldo;
      } else {
        console.error("Saldo nao pode ser negativo");
      }
    }
  }
  
export default Cliente;