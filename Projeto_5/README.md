# FleetTrack Pro — Módulo Core de Telemetria (Projeto_5)

Subsistema de processamento de telemetria IoT refatorado para utilizar
**Herança**, **Polimorfismo Dinâmico** e **Sobrecarga de Métodos** em C++,
substituindo o antigo modelo estrutural baseado em `switch-case` e bytes
genéricos (Ticket #550).

## Estrutura do Projeto

```
Projeto_5/
│
├── docs/
│   └── Telemetria_Fleet_UML.png   # Diagrama de Classes UML
│
├── src/
│   ├── Dispositivo.h / .cpp          # Classe Abstrata Base
│   ├── SensorGPS.h / .cpp            # Módulo de Geolocalização
│   ├── SensorDiagnostico.h / .cpp    # Módulo de Telemetria de Motor
│   ├── RastreadorAvancado.h / .cpp   # Fusão via Herança Múltipla
│   └── main.cpp                      # Iteração polimórfica
│
└── README.md
```

## Como compilar

Requisitos: compilador com suporte a C++17 (g++ ou clang++).

```bash
cd src
g++ -std=c++17 -Wall -Wextra -Wpedantic -Werror -O2 -o fleettrack_pro \
    Dispositivo.cpp SensorGPS.cpp SensorDiagnostico.cpp RastreadorAvancado.cpp main.cpp
```

O projeto compila **sem nenhum warning ou erro** sob essas flags estritas.

## Como executar

```bash
./fleettrack_pro
```

## Arquitetura da Hierarquia

- **`Dispositivo`** — classe base abstrata. Possui `virtual void processarDados() = 0`,
  o que impede sua instanciação direta, e um **destrutor virtual** (`virtual ~Dispositivo()`),
  obrigatório para que `delete` via ponteiro de classe base libere corretamente o objeto
  derivado mais específico, evitando vazamento de memória.
- **`SensorGPS`** e **`SensorDiagnostico`** — herança simples de `Dispositivo`, cada uma
  sobrescrevendo `processarDados()` com sua própria lógica.
- **`RastreadorAvancado`** — herança múltipla de `SensorGPS` **e** `SensorDiagnostico`,
  combinando geolocalização e diagnóstico de motor num único dispositivo.

## O "Problema do Diamante" e como foi resolvido

Como `SensorGPS` e `SensorDiagnostico` herdam de `Dispositivo` de forma **não-virtual**,
`RastreadorAvancado` acaba contendo **dois subobjetos `Dispositivo` distintos** (um por
ramo de herança). Isso gera ambiguidade caso se tente acessar membros herdados de
`Dispositivo` (ou chamar `getId()`) diretamente a partir de `RastreadorAvancado`.

A solução adotada, deliberadamente, **não** usa herança virtual (`virtual public`), e sim:

1. **Resolução de escopo explícita** (`Classe::membro`) — por exemplo,
   `SensorGPS::getId()` dentro de `RastreadorAvancado::processarDados()`, indicando
   claramente de qual ramo da hierarquia queremos o dado.
2. **`static_cast` explícito** — ao armazenar um `RastreadorAvancado*` dentro do
   `std::vector<Dispositivo*>` em `main.cpp`, a conversão implícita seria ambígua
   (existem dois caminhos possíveis até `Dispositivo`). Por isso o código escolhe
   explicitamente um caminho:

   ```cpp
   frota.push_back(static_cast<Dispositivo*>(static_cast<SensorGPS*>(rastreador)));
   ```

   Como `Dispositivo` possui destrutor virtual, o `delete` feito posteriormente via
   `Dispositivo*` continua funcionando corretamente — o compilador ajusta o offset do
   ponteiro automaticamente (mecanismo de *thunk*) para invocar o destrutor mais
   derivado (`~RastreadorAvancado()`), que por sua vez destrói ambos os subobjetos
   `Dispositivo` herdados.

## Polimorfismo Dinâmico

Em `main.cpp`, um `std::vector<Dispositivo*>` armazena instâncias de todas as
subclasses. Um único laço percorre o vetor chamando `d->processarDados()` — o método
correto é despachado em tempo de execução (v-table) conforme o tipo real de cada objeto.

## Sobrecarga de Métodos (Polimorfismo Estático)

A classe `SensorGPS` define duas versões de `transmitirPayload`:

```cpp
void transmitirPayload();                              // texto puro
void transmitirPayload(const std::string& chaveCripto); // transmissão segura
```

A escolha entre as duas é resolvida em tempo de **compilação**, com base na assinatura
usada na chamada.

## Gerenciamento de Memória

Todos os objetos são alocados com `new` e liberados com `delete` em `main.cpp` ao final
da execução, dentro de um laço sobre o mesmo `std::vector<Dispositivo*>`. Graças ao
destrutor virtual em `Dispositivo`, não há vazamento de memória mesmo com o uso de
ponteiros brutos e herança múltipla.
