
## Pré-requisitos
- Um compilador C++ como g++.
- Sistema operacional Windows, Linux ou macOS.
- Terminal para rodar os comandos.

## Como compilar e executar
*Acesse o diretório raiz do projeto e compile o projeto com o seguinte comando:*

```bash
g++ -I./include src/Carro.cpp src/Cliente.cpp src/Moto.cpp src/SeguroCarro.cpp src/SeguroMoto.cpp src/SeguroVeiculo.cpp src/main.cpp -o output/main.exe
```
Esse comando utiliza os arquivos de cabeçalho na pasta include/ e os arquivos fonte na pasta src/ para gerar o executável na pasta output/.

*Navegue até a pasta output:*

```bash
cd output
```

*Execute o programa:*
```bash
./main.exe
```

### Exemplo de saída esperada
*Ao executar o programa, você verá algo como:*

```yaml
Cliente: Kaella Sales
CPF: 123.456.789-00

Moto: Yamaha R6 (2024)
Cor: Preta | Placa: XYZ-5678

Carro: Toyota Corolla LE 1.8 (1996)
Cor: Rosa | Placa: ABC-1234

Seguro
Tipo: Motocicleta
Veículo: Yamaha R6 (2024)
Valor do seguro: 1775
Vigência: 12 meses

Seguro
Tipo: Automovel
Veículo: Toyota Corolla LE 1.8 (1996)
Valor do seguro: 2000
Vigência: 12 meses
```
Autor
Kaella Rodrigues de Sales