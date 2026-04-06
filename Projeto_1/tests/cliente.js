const { SistemaClientes } = require("../src/models/cliente");

const sistema = new SistemaClientes();

try {
  const idJoao = sistema.cadastrarCliente("João Silva", 30, 1000);
  const idMaria = sistema.cadastrarCliente("Maria Souza", 25, 500);

  sistema.movimentarConta(idMaria, 200, false);
  sistema.movimentarConta(idJoao, 300, true);

  try {
    sistema.movimentarConta(idMaria, 1000, true);
  } catch (erro) {
    console.log("Teste de saldo negativo funcionando:", erro.message);
  }

  sistema.exibirRelatorio();

} catch (erro) {
  console.error("Erro no teste:", erro.message);
}