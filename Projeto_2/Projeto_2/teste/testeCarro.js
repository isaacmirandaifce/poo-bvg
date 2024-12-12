import Carro from "../src/carro.js";

const testarCarro = () => {
  const carro = new Carro(2020, "Toyota", "Corolla", "Branco", "XYZ-1234");

  console.log("Testando Carro:");
  console.log(
    carro.exibirDetalhes()
  ); /*Espera: "Ano: 2020, Marca: Toyota, Modelo: Corolla, Cor: Branco, Placa: XYZ-1234"*/

  carro.atualizarCor("Preto");
  console.log(
    carro.exibirDetalhes()
  ); /*Espera: "Ano: 2020, Marca: Toyota, Modelo: Corolla, Cor: Preto, Placa: XYZ-1234" */
};

testarCarro();
