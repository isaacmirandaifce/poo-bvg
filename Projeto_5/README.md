# Projeto 5 - Sistema de Processamento de Telemetria IoT

## Descrição
Implementação de um subsistema de telemetria utilizando conceitos de **Programação Orientada a Objetos** em C++. O sistema utiliza uma hierarquia de classes para processar dados de sensores de forma polimórfica, garantindo extensibilidade e segurança na gestão de memória.

## Funcionalidades
- **Herança Múltipla:** Implementação do `RastreadorAvancado` herdando de `SensorGPS` e `SensorDiagnostico`.
- **Polimorfismo Dinâmico:** Processamento de sensores heterogêneos via ponteiros da classe base `Dispositivo`.
- **Sobrecarga de Métodos:** Polimorfismo estático aplicado na transmissão de payloads.
- **Gestão de Memória:** Implementação rigorosa de destrutores virtuais para evitar *memory leaks*.
- **Herança Virtual:** Solução do "Problema do Diamante" utilizando `virtual inheritance`.

## Como Compilar e Executar
O projeto foi estruturado para compilação direta via terminal. Certifique-se de estar na pasta raiz do projeto.

1. Navegue até a pasta do projeto:
   `cd Projeto_5`

2. Compile utilizando o `g++`:
   `g++ src/*.cpp -o telemetria`

3. Execute o binário:
   `./telemetria`

## Notas Técnicas
- **Problema do Diamante:** Resolvido através da herança virtual (`virtual public Dispositivo`), garantindo que apenas uma instância da classe base exista na hierarquia de `RastreadorAvancado`.
- **Memory Management:** A liberação de memória no `main.cpp` é feita manualmente via `delete` em cada ponteiro armazenado no `std::vector`, disparando a cascata de destrutores virtuais.
