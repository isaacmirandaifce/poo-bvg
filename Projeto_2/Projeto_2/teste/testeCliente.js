import Cliente from "../src/cliente.js";

const testarCliente = () => {
  const cliente = new Cliente("João Silva", "123.456.789-00");

  console.log("Testando Cliente:");
  console.log(
    cliente.exibirInformacoes()
  ); /*Exibir: "Nome: João Silva, CPF: 123.456.789-00"*/
};

testarCliente();
