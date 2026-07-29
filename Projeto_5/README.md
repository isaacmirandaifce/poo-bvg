# Projeto 5 - Subsistema de Telemetria IoT (FleetTrack Pro)

Este repositório contém a implementação do **Projeto Avaliativo 5 / Ticket #550**, focado no desenvolvimento do subsistema de processamento de telemetria IoT em C++.

O objetivo principal é aplicar conceitos avançados de **Herança**, **Polimorfismo Dinâmico e Estático (Sobrecarga)**, **Herança Múltipla** e **Classes Abstratas**.

---

## Estrutura do Repositório

```text
Projeto_5/
│
├── docs/
│   └── Telemetria_Fleet_UML.png      # Diagrama de Classes UML (Herança simples e múltipla)
│
├── src/
│   ├── Dispositivo.h                 # Interface da classe base abstrata
│   ├── Dispositivo.cpp               # Implementação da classe base
│   ├── SensorGPS.h                   # Interface da classe SensorGPS (com sobrecarga)
│   ├── SensorGPS.cpp                 # Implementação de GPS e transmissão
│   ├── SensorDiagnostico.h           # Interface da classe SensorDiagnostico (OBD-II)
│   ├── SensorDiagnostico.cpp         # Implementação de diagnóstico de motor
│   ├── RastreadorAvancado.h          # Interface da classe combinada (Herança Múltipla)
│   ├── RastreadorAvancado.cpp        # Implementação da fusão de dados IoT
│   └── main.cpp                      # Orquestração do vetor polimórfico e limpeza de memória
│
└── README.md                         # Documentação técnica do projeto

## Como Compilar e Executar

1. **Abra o terminal no diretório raiz do Projeto_5:**
   ```bash
   cd Projeto_5
   ```

2. **Compile todos os arquivos do módulo `src/` utilizando o `g++`:**
   ```bash
   g++ src/main.cpp src/Dispositivo.cpp src/SensorGPS.cpp src/SensorDiagnostico.cpp src/RastreadorAvancado.cpp -o telemetria_app
   ```

3. **Execute o programa gerado:**

   * **Linux / macOS:**
     ```bash
     ./telemetria_app
     ```

   * **Windows:**
     ```cmd
     telemetria_app.exe
     ```