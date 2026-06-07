# Projeto 5 - Subsistema de Processamento de Telemetria IoT

## Descrição
Refatoração do subsistema de captura de dados de sensores veiculares
utilizando Herança, Polimorfismo Dinâmico e Sobrecarga de Métodos em C++.

## Estrutura do Projeto
Projeto_5/
├── docs/
│   └── Telemetria_Fleet_UML.png
├── src/
│   ├── Dispositivo.h / .cpp
│   ├── SensorGPS.h / .cpp
│   ├── SensorDiagnostico.h / .cpp
│   ├── RastreadorAvancado.h / .cpp
│   └── main.cpp
└── README.md

## Como Compilar

### Linux / Mac
```bash
g++ src/main.cpp src/Dispositivo.cpp src/SensorGPS.cpp src/SensorDiagnostico.cpp src/RastreadorAvancado.cpp -o fleettrack
./fleettrack
```

### Windows (PowerShell)
```powershell
g++ src/main.cpp src/Dispositivo.cpp src/SensorGPS.cpp src/SensorDiagnostico.cpp src/RastreadorAvancado.cpp -o fleettrack.exe
.\fleettrack.exe
```

## Conceitos Aplicados

- **Classe Abstrata**: `Dispositivo` com método virtual puro `processarDados()`
- **Herança Simples**: `SensorGPS` e `SensorDiagnostico` herdam de `Dispositivo`
- **Herança Múltipla**: `RastreadorAvancado` herda de `SensorGPS` e `SensorDiagnostico`
- **Polimorfismo Dinâmico**: vetor de `Dispositivo*` itera chamando `processarDados()`
- **Sobrecarga de Métodos**: `transmitirPayload()` e `transmitirPayload(string)`
- **Destrutor Virtual**: evita memory leak ao deletar via ponteiro base
- **Gerenciamento de Memória**: todos os ponteiros liberados com `delete` no `main`
