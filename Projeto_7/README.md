# Projeto 7 - Motor Genérico de Filtragem e Processamento

## Descrição
Implementação de uma classe template genérica `DataFilter<T>` para unificar
a lógica de filtragem e processamento de dados no sistema SecureBank Pro,
eliminando duplicação de código (princípio DRY).

## Estrutura do Projeto
Projeto_7/
├── docs/
│   └── Diagrama_DataFilter_UML.png
├── src/
│   ├── DataFilter.h
│   ├── Transacao.h / .cpp
│   ├── LogSeguranca.h / .cpp
│   └── main.cpp
└── README.md

## Como Compilar

### Linux / Mac
```bash
g++ src/main.cpp src/Transacao.cpp src/LogSeguranca.cpp -o securebank
./securebank
```

### Windows (PowerShell)
```powershell
g++ src/main.cpp src/Transacao.cpp src/LogSeguranca.cpp -o securebank.exe
.\securebank.exe
```

> `DataFilter.h` não precisa de `.cpp` pois templates devem ter
> declaração e implementação no mesmo arquivo `.h`.

## Conceitos Aplicados

- **Template Class**: `DataFilter<T>` funciona com qualquer tipo de objeto
- **std::function**: permite passar lambdas como regras de negócio
- **Expressões Lambda**: filtros declarados inline no `main.cpp`
- **Princípio DRY**: uma única classe substitui múltiplos filtros repetidos