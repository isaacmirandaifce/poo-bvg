# Projeto 03 - Módulo de Contatos B2B (C++)

Módulo de Gestão de Contatos de Clientes (CRM) em C++, com separação entre interface (`.h`) e implementação (`.cpp`) e uso de `std::vector`.
## Estrutura

```text
Projeto_3/
├── docs/
│   └── Contato_UML.png   # Diagrama de Classes
├── src/
│   ├── Contato.h         # Declaração da classe
│   ├── Contato.cpp       # Construtor, destrutor e métodos
│   └── main.cpp          # Uso do std::vector<Contato>
└── README.md
```

## Como compilar

A partir da pasta `Projeto_03`:

```bash
g++ src/main.cpp src/Contato.cpp -o crm_app
```

## Como executar

```bash
./crm_app        #Para Linux / macOS
crm_app.exe      #Para Windows
```

## Observações

- O construtor usa `this->` para diferenciar parâmetros e atributos;
- O destrutor imprime `LOG: Contato [Nome] desalocado da memória.`;
- Ao usar `push_back(Contato(...))`, o objeto temporário é copiado para o
  vector e destruído em seguida, então 3 logs de destrutor aparecem logo
  após as inserções. Os outros 3 logs aparecem no fim do programa, quando
  os contatos do vector saem de escopo.
