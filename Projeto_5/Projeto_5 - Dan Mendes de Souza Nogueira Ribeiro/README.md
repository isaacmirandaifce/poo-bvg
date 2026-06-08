## Como rodar o código:
g++ dispositivo.cpp sensorDiagnostico.cpp sensorGPS.cpp rastreadorAvancado.cpp main.cpp -o rodarCodigo

---

## Explicação do projeto

O projeto foi feito com a implementação de herança de classes. A classe abstrata `Dispositivo` atua como a classe base, ou pai, para todas as outras classes que o programa possui. Ela contém um método virtual puro, o que significa que esse método serve como um contrato obrigatório e não possui implementação na classe base, forçando as classes filhas a sobrescrevê-lo.

Este método, chamado de `processarDados()`, é sobrescrito por todas as classes derivadas, e cada uma processa e exibe os dados à sua maneira. Por exemplo, a classe `SensorGPS` utiliza os dados de longitude e latitude para formatar a localização, enquanto a classe `SensorDiagnostico` verifica os dados do motor e informa sobre a situação atual dele. Por fim, a classe RastreadorAvancado herda de ambas as classes (`SensorGPS` e `SensorDiagnostico`), unificando as chamadas do método `processarDados()` dessas duas últimas.

Vale citar também que o projeto possui um sistema de sobrecarga de métodos, também chamado de polimorfismo estático. Na classe `SensorGPS`, existem dois métodos com o mesmo nome: `transmitirPayload`. Não ocorre erro de compilação porque eles possuem assinaturas diferentes; um dos métodos exige a passagem de um parâmetro de texto (ficando como `transmitirPayload(std::string chaveCripto)`). Isso permite que dois métodos com o mesmo nome coexistam sem conflitos no código.