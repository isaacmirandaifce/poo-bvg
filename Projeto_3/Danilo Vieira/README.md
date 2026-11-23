# Projeto Avaliativo 3 - CRM Enterprise

## Objetivo

Desenvolver um modulo de contatos B2B em C++,
utilizando classes, construtor, destrutor e std::vector.

## Arquivos

- src/Contato.h: declaracao da classe.
- src/Contato.cpp: implementacao dos metodos.
- src/main.cpp: programa principal.
- docs/Contato_UML.png: diagrama UML.

## Compilacao

A partir desta pasta, execute:

```powershell
g++ src/main.cpp src/Contato.cpp -o crm_app.exe
```

## Execucao

```powershell
.\crm_app.exe
```

## Conceitos aplicados

- Encapsulamento com atributos privados.
- Separacao entre interface e implementacao.
- Uso de this-> no construtor.
- Destrutor com log no console.
- Armazenamento dinamico com std::vector.
- Insercao com push_back e iteracao range-based for.
