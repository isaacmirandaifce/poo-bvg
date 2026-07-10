# Projeto 5 - FleetTrack Pro: Subsistema de Telemetria IoT

Implementação do módulo de processamento de telemetria utilizando **Herança**, **Polimorfismo Dinâmico**, **Herança Múltipla** e **Sobrecarga de Métodos** em C++.

---

## Estrutura do Projeto

```
Projeto_5/
├── docs/
│   └── Telemetria_Fleet_UML.png     # Diagrama de Classes UML
├── src/
│   ├── Dispositivo.h / .cpp         # Classe Base Abstrata
│   ├── SensorGPS.h / .cpp           # Módulo GPS com Sobrecarga
│   ├── SensorDiagnostico.h / .cpp   # Módulo OBD-II
│   ├── RastreadorAvancado.h / .cpp  # Herança Múltipla (GPS + Diagnóstico)
│   └── main.cpp                     # Iteração polimórfica
└── README.md
```

---

## Como Compilar

### Compilação Manual (g++)

```bash
cd src/
g++ -std=c++17 -Wall -Wextra -o ../fleettrack \
    Dispositivo.cpp SensorGPS.cpp SensorDiagnostico.cpp \
    RastreadorAvancado.cpp main.cpp
```

### Executar

```bash
cd Projeto_5/
./fleettrack
```

---

## Conceitos Implementados

### 1. Classe Base Abstrata (`Dispositivo`)
- Contém `virtual void processarDados() = 0` — método virtual puro que impede a instanciação direta da classe.
- Possui `virtual ~Dispositivo()` — destrutor virtual necessário para garantir que o `delete` via ponteiro de classe base chame os destrutores corretos de toda a hierarquia.
- Atributos `protected`: acessíveis pelas subclasses, mas ocultos do código externo.

### 2. Polimorfismo Dinâmico (`main.cpp`)
- Um `std::vector<Dispositivo*>` armazena ponteiros de diferentes subclasses.
- O laço `for` chama `d->processarDados()` e o compilador resolve, em **tempo de execução** via **vtable**, qual implementação executar — sem nenhum `switch-case`.

### 3. Sobrecarga de Métodos — Polimorfismo Estático (`SensorGPS`)
- `void transmitirPayload()` — transmissão aberta em texto puro.
- `void transmitirPayload(std::string chaveCripto)` — transmissão com assinatura simulada.
- A resolução acontece em **tempo de compilação** com base na assinatura da função.

### 4. Herança Múltipla (`RastreadorAvancado`)
- Herda publicamente de `SensorGPS` e `SensorDiagnostico`.
- Como ambas as classes pai herdam de `Dispositivo`, ocorre o **Problema do Diamante**: `Dispositivo` é incluído duas vezes na hierarquia.
- **Solução adotada**: uso de `static_cast<SensorGPS*>` no `main.cpp` ao inserir no vetor, e qualificação explícita de escopo (`SensorGPS::getId()`, `SensorDiagnostico::getRpm()`) dentro de `processarDados()`.
- **Alternativa acadêmica**: `virtual public` nas classes intermediárias resolveria o diamante de forma mais elegante, mas foi mantida a abordagem sem herança virtual conforme o escopo da sprint.

---

## Gerenciamento de Memória

Todos os objetos são criados com `new` (heap). O `main.cpp` realiza `delete` em cada ponteiro após o laço de processamento:

```cpp
for (Dispositivo* d : frota) {
    delete d;  // Chama destrutores em cadeia graças ao virtual ~Dispositivo()
}
frota.clear();
```

O destrutor virtual garante que mesmo ao deletar via ponteiro da classe base, os destrutores de todas as classes derivadas sejam chamados na ordem correta (do mais derivado para o mais base).