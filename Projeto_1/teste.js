import Cliente from "./cliente.js";

// criando uma nova instancia da classe Cliente
const cliente = new Cliente("João Silva", 30, 1000.0);

//mostrando as informacoes
cliente.mostrarInformacoes();

//atualizando o saldo
cliente.atualizarSaldo(500); 
cliente.atualizarSaldo(-200); 

//mostrando de novo depois de atualizar
cliente.mostrarInformacoes();

//alterando usando os setters para acessar os atributos (no js esse _ pra deixar o atributo privado eh mais uma convencao, por isso, usar setters e getters)
cliente.nome = "Maria Oliveira";
cliente.idade = 28;
cliente.saldo = 2000.0;

//mostrando de novo depois de alterar
cliente.mostrarInformacoes();


// COMO RODAR: 
//PRECISA TER O NODEJS INSTALADO
// NO TERMINAL DENTRO DA PASTA PROJETO_1 DIGITE: node teste.js
// ~/poo-bvg/Projeto_1$ node teste.js