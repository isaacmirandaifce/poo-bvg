const { SistemaClientes } = require("./models/cliente");

const sistema = new SistemaClientes();

try {
  const idJoao = sistema.cadastrarCliente("João Silva", 30, 1000.0);
  const idMaria = sistema.cadastrarCliente("Maria Souza", 25, 500.0);

  sistema.movimentarConta(idJoao, 1500.0, true);

  sistema.exibirRelatorio();
} catch (erro) {
  console.error("Erro:", erro.message);
}