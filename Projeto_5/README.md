# **Projeto Avaliativo 5: Herança, Polimorfismo, Sobrecarga e Sobrescrita - C++**


# 🎟️ Ticket #550: Subsistema de Processamento de Telemetria IoT (Herança & Polimorfismo)

**De:** Engenheiro de Software Principal / Arquiteto (Professor)

**Para:** Desenvolvedor C++ Backend (Alunos)

**Projeto:** FleetTrack Pro (Módulo Core de Telemetria)

**Status:** `To Do` | **Prioridade:** `Crítica`

##  Contexto

Olá, equipe! Nossa plataforma de gerenciamento de frotas precisa integrar novos tipos de dispositivos de coleta de dados instalados nos veículos (sensores de GPS, diagnóstico de motor OBD-II e câmeras inteligentes).

O código legado foi construído de forma estruturada e processa os dados de maneira centralizada através de uma estrutura genérica de bytes e um `switch-case` massivo. Isso está gerando vazamento de memória e impede a adição de novos sensores sem quebrar o sistema de produção inteiro.

Sua missão nesta sprint é refatorar o subsistema de captura utilizando a infraestrutura de **Herança, Polimorfismo Dinâmico e Sobrecarga de Métodos em C++**. Isso permitirá que nosso motor de processamento receba qualquer tipo de sensor e execute sua lógica sem precisar saber os detalhes de implementação de cada hardware.

---

##  Critérios de Aceitação (Acceptance Criteria)

### 1. Arquitetura da Hierarquia (Herança e Classes Abstratas)

Você deve criar um modelo polimórfico rigoroso respeitando a visibilidade e encapsulamento dos atributos:

* **Classe Base Abstrata `Dispositivo**`:
* `protected`: Atributos comuns como `std::string idDispositivo` e `int timestamp`.
* `public`: Construtores e um **Método Virtual Puro** chamado `virtual void processarDados() = 0;` (Esta classe não pode ser instanciada diretamente).


* **Classe Derivada `SensorGPS**` (Herança Simples):
* Atributos privados: `double latitude` e `double longitude`.
* Sobrescrita (`override`) do método `processarDados()` para exibir e formatar as coordenadas geográficas.


* **Classe Derivada `SensorDiagnostico**` (Herança Simples):
* Atributos privados: `int rpmMotor` e `double temperaturaFluido`.
* Sobrescrita do método `processarDados()` para avaliar a saúde do motor.



### 2. Composição por Herança Múltipla

Para coletar dados consolidados de alta performance, precisamos de um hardware combinado:

* **Classe Derivada `RastreadorAvancado**` (Herda publicamente de `SensorGPS` **e** de `SensorDiagnostico`):
* Deve herdar as capacidades de geolocalização e telemetria de motor de ambas as classes pai.
* Deve sobrescrever `processarDados()` unificando a saída de diagnóstico e localização.



### 3. Polimorfismo de Tempo de Execução e Sobrecarga

* **Polimorfismo Dinâmico**: No arquivo `main.cpp`, gerencie uma coleção utilizando um vetor de ponteiros da classe base: **`std::vector<Dispositivo*>`**. Instancie dinamicamente (`new`) objetos de todas as subclasses, armazene-os no vetor e use um laço de repetição para disparar o método `processarDados()` polimorficamente.
* **Sobrecarga de Métodos (Polimorfismo Estático)**: Na classe `SensorGPS`, implemente uma sobrecarga do método de envio de dados:
1. `void transmitirPayload()` -> Transmite os dados abertos em texto puro.
2. `void transmitirPayload(std::string chaveCripto)` -> Simula a transmissão segura utilizando uma assinatura ou criptografia.



---

##  Estrutura de Arquivos Exigida (Projeto_5)

Para garantir o isolamento e modularização de compilação em C++, o projeto deve seguir estritamente o layout corporativo abaixo:

```text
Projeto_5/
│
├── docs/
│   └── Telemetria_Fleet_UML.png     # Diagrama de Classes UML (Herança múltipla)
│
├── src/
│   ├── Dispositivo.h / .cpp         # Interface/Classe Abstrata Base
│   ├── SensorGPS.h / .cpp           # Módulo de Geolocalização
│   ├── SensorDiagnostico.h / .cpp   # Módulo de Telemetria de Motor
│   ├── RastreadorAvancado.h / .cpp  # Fusão via Herança Múltipla
│   └── main.cpp                     # Iteração polimórfica com std::vector de ponteiros
│
└── README.md                        # Documentação de compilação e notas técnicas

```

---

##  Fluxo de Entrega (Git Workflow)

1. **Modelagem UML**: Desenhe o diagrama utilizando as setas vazias apontando para as classes pai para documentar a Herança Simples e a Herança Múltipla. Salve em `docs/`.
2. **Gerenciamento de Memória**: Como estamos lidando com ponteiros brutos (`Dispositivo*`), lembre-se de criar um **Destrutor Virtual** (`virtual ~Dispositivo()`) na classe base e garantir que o `main.cpp` libere a memória usando `delete` após a execução do laço para evitar *Memory Leaks*.
3. **Pull Request**: Abra a PR no repositório oficial da disciplina com o título `Projeto_5 - [Seu Nome Completo]`.

---

##  Rubrica de Avaliação (Code Review)

| Critério | Descrição | Pontuação |
| --- | --- | --- |
| **Abstração e Polimorfismo** | A classe base impede a instanciação direta por conter um método virtual puro? O laço no `main.cpp` executa os métodos corretos via ponteiros da classe base? | 3.5 pts |
| **Herança Múltipla** | A classe `RastreadorAvancado` foi implementada utilizando a sintaxe correta de herança múltipla e resolve os escopos adequadamente? | 2.5 pts |
| **Sobrecarga de Métodos** | O polimorfismo estático (sobrecarga de assinaturas) foi aplicado corretamente na classe de GPS? | 2.0 pts |
| **Arquitetura C++ e UML** | O projeto está totalmente modularizado em `.h`/`.cpp`? O diagrama UML descreve precisamente os modificadores de acesso e a estrutura implementada? | 2.0 pts |

**Aviso do Tech Lead:** Ao trabalhar com Herança Múltipla em C++, fiquem atentos à ordem de chamada dos construtores na lista de inicialização e garantam que não haja colisões de nomes de atributos. Se o código não compilar ou apresentar ambiguidade não tratada, a PR receberá a flag *`changes requested`*. Mantenham o código limpo, limitem o escopo e boa refatoração!
