# Projeto 7: Motor Genérico de Filtragem - SecureBank Pro 

**Ticket:** #815  
**Projeto:** SecureBank Pro  
**Autor:** Letícia Silva

---

## Sobre o Projeto

Este projeto implementa um **Motor Genérico de Filtragem (`DataFilter<T>`)** utilizando **Templates em C++**. O objetivo principal é otimizar a manipulação de dados no sistema, eliminando a redundância de código ao permitir que a mesma lógica de filtragem e processamento seja aplicada a diferentes domínios, como `Transacao` e `LogSeguranca`.

---

## Estrutura de Arquivos

A organização do código segue o padrão de desacoplamento, com a particularidade arquitetural de que o *template* deve conter sua implementação no próprio cabeçalho:

```text
Projeto_7/
│
├── docs/
│   └── Diagrama_DataFilter_UML.png  # Diagrama com notação de template <T>
├── src/
│   ├── DataFilter.h                 # Implementação do Template (Motor Genérico)
│   ├── Transacao.h / .cpp           # Domínio 1: Dados de Transações
│   ├── LogSeguranca.h / .cpp        # Domínio 2: Dados de Logs
│   └── main.cpp                     # Instanciação dos templates e lambdas
└── README.md                        # Documentação e justificativas de arquitetura
```

---

---



## Como compilar o projeto

1. **Compilar:**



```bash

g++ -std=c++11 src/main.cpp src/Transacao.cpp src/LogSeguranca.cpp -o motor_filtragem
```



2. **Executar:**

- Windows:



```bash

.\motor_filtragem.exe

```



- Linux:



```bash

./motor_filtragem.exe

```

---



## Justificativas de Arquitetura e Boas Práticas

1. Por que utilizar Template `<typename T>`?
A implementação de uma classe genérica permite que o sistema suporte qualquer tipo de objeto sem a necessidade de criar múltiplas classes redundantes (ex: `FiltroTransacao`, `FiltroLog`). Isso garante que o sistema siga estritamente o princípio DRY (Don't Repeat Yourself), tornando o código altamente reutilizável e fácil de manter conforme novas entidades são adicionadas ao `SecureBank Pro`.



2. Por que a implementação está no `DataFilter.h`?
Em C++, a compilação de templates é feita no momento da instanciação. Se a implementação estivesse em um arquivo `.cpp` separado, o compilador não seria capaz de gerar o código específico para o tipo `T` passado no `main.cpp`. Seguindo a recomendação técnica, a implementação foi mantida no `.h` para garantir a correta geração do código-objeto durante o processo de build.

3. Uso de `std::function` e Lambdas:
Para manter o `DataFilter<T>` agnóstico em relação à regra de negócio, utilizamos std::function como parâmetro para os métodos `filtrar` e ``processar``. Isso permite a injeção de comportamento através de expressões lambda modernas. Essa abordagem separa a responsabilidade de iteração/armazenamento (do ``DataFilter``) da responsabilidade de lógica de negócio (definida no ``main``), garantindo um design de software flexível e desacoplado.

--- 