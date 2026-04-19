const Cliente = require('./src/models/Cliente');
const SeguroAuto = require('./src/models/SeguroAuto');
const SeguroVida = require('./src/models/SeguroVida');
const SeguroResidencial = require('./src/models/SeguroResidencial');

const cliente = new Cliente("Williams Torres", "123.456.789-00", "williams@email.com");

const auto = new SeguroAuto("Williams Torres", 1000.0, "ABC-1234", 2008);
const vida = new SeguroVida("Williams Torres", 500.0, 65);
const residencial = new SeguroResidencial("Williams Torres", 800.0, "CASA", 120.0);

cliente.adicionarSeguro(auto);
cliente.adicionarSeguro(vida);
cliente.adicionarSeguro(residencial);

console.log(`Cliente: ${cliente.nome}\n`);
for (const seguro of cliente.listarSeguros()) {
  console.log(seguro.toString());
}
