# Projeto 7 - Motor Genérico de Filtragem (DataFilter<T>)

## Descrição
Implementação de uma classe genérica (Template) em C++ para unificar a lógica de filtragem e processamento de dados, eliminando redundância de código (DRY).

## Funcionalidades
- Classe `DataFilter<T>` utilizando templates C++.
- Uso de `std::function` e expressões lambda para injeção de regras de negócio.
- Suporte a múltiplos domínios (`Transacao` e `LogSeguranca`).

## Como Compilar
1. Navegue até a pasta: `cd Projeto_7`
2. Compile: `g++ src/*.cpp -o analytics`
3. Execute: `./analytics`

## Notas Técnicas
- A implementação do template está contida inteiramente no arquivo `DataFilter.h` para garantir a correta instanciação pelo compilador.
