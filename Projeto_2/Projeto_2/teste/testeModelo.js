import Modelo from "../src/modelo.js";

const testarModelo = () => {
  const modelo = new Modelo("Corolla");

  console.log("Testando Modelo:");
  console.log(modelo.exibirModelo()); /*Saída: Corolla*/
};

testarModelo(); /*Saída: Modelo(nome='Corolla')*/
