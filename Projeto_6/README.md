# Projeto Avaliativo 6 - SecureBank Pro

## Ticket #602 - Implementação do Core de Autenticação e Auditoria

Este projeto implementa um sistema simples de gerenciamento de identidades e acessos em C++, simulando o módulo IAM do SecureBank Pro.

O objetivo é aplicar os conceitos de:

* Classes abstratas
* Interfaces
* Classes enumeradas
* Classes internas
* Herança
* Polimorfismo
* Encapsulamento

---

## Estrutura do Projeto

```txt
Projeto_6/
├── docs/
│   └── Arquitetura_IAM_UML.png
├── src/
│   ├── interfaces/
│   │   └── Relatorio.h
│   ├── base/
│   │   ├── Usuario.h
│   │   ├── UsuarioAutenticavel.h
│   │   └── UsuarioAutenticavel.cpp
│   ├── models/
│   │   ├── TipoUsuario.h
│   │   ├── UsuarioAdmin.h
│   │   ├── UsuarioAdmin.cpp
│   │   ├── UsuarioAuditor.h
│   │   ├── UsuarioAuditor.cpp
│   │   ├── UsuarioOperador.h
│   │   └── UsuarioOperador.cpp
│   └── main.cpp
└── README.md
```

---

## Classes Principais

### Usuario

A classe `Usuario` é a classe base do sistema.

Ela armazena dados globais não sensíveis dos usuários, como:

* `id`
* `username`

Esses dados são protegidos e podem ser acessados pelas classes filhas.

---

### UsuarioAutenticavel

A classe `UsuarioAutenticavel` herda de `Usuario` e funciona como uma classe abstrata.

Ela possui o atributo protegido:

* `senha`

Também define os métodos virtuais puros:

```cpp
virtual bool autenticar(const std::string& senhaInformada) const = 0;
virtual std::string getNivelAcesso() const = 0;
virtual TipoUsuario getTipo() const = 0;
```

Por possuir métodos virtuais puros, essa classe não pode ser instanciada diretamente.

---

### Relatorio

A classe `Relatorio` funciona como uma interface do sistema.

Ela possui o método virtual puro:

```cpp
virtual void gerarRelatorio() const = 0;
```

As classes concretas precisam implementar esse método, garantindo que cada tipo de usuário tenha sua própria forma de gerar relatório.

---

## Enumeração

O projeto utiliza uma classe enumerada chamada `TipoUsuario`.

```cpp
enum class TipoUsuario {
    ADMIN,
    AUDITOR,
    OPERADOR
};
```

Ela é usada para categorizar os usuários do sistema em:

* Administrador
* Auditor
* Operador

---

## Usuários Implementados

### UsuarioAdmin

A classe `UsuarioAdmin` representa o administrador do sistema.

Ela herda de `UsuarioAutenticavel` e implementa a interface `Relatorio`.

Responsabilidades:

* autenticar o administrador;
* retornar o nível de acesso;
* retornar o tipo `ADMIN`;
* gerar relatório administrativo;
* gerenciar usuários.

---

### UsuarioAuditor

A classe `UsuarioAuditor` representa o auditor do sistema.

Ela herda de `UsuarioAutenticavel` e implementa a interface `Relatorio`.

Responsabilidades:

* autenticar o auditor;
* retornar o nível de acesso;
* retornar o tipo `AUDITOR`;
* gerar relatório de auditoria;
* consultar logs de segurança.

---

### UsuarioOperador

A classe `UsuarioOperador` representa o funcionário operacional do sistema.

Ela herda de `UsuarioAutenticavel` e implementa a interface `Relatorio`.

Responsabilidades:

* autenticar o operador;
* retornar o nível de acesso;
* retornar o tipo `OPERADOR`;
* executar operações;
* registrar histórico de acessos;
* gerar relatório operacional.

---

## Classe Interna

Dentro da classe `UsuarioOperador`, foi criada a classe interna privada `HistoricoAcessos`.

Essa classe é responsável por registrar os acessos feitos pelo operador.

Cada registro possui:

* `recursoAcessado`
* `dataHora`
* `statusCodigo`

A classe interna fica encapsulada dentro de `UsuarioOperador`, impedindo acesso direto externo aos dados do histórico.

Isso ajuda a proteger informações internas e respeita o princípio de encapsulamento.

---

## Polimorfismo

O polimorfismo é demonstrado no arquivo `main.cpp`.

Foi criado um vetor de ponteiros para a interface `Relatorio`:

```cpp
std::vector<Relatorio*> relatorios;
```

Depois, objetos de classes diferentes são adicionados ao mesmo vetor:

```cpp
relatorios.push_back(&admin);
relatorios.push_back(&auditor);
relatorios.push_back(&operador);
```

Em seguida, o sistema percorre o vetor e chama o método `gerarRelatorio()`:

```cpp
for (const Relatorio* relatorio : relatorios) {
    relatorio->gerarRelatorio();
}
```

Mesmo usando o mesmo método, cada classe executa sua própria versão de `gerarRelatorio()`.

---

## Diagrama UML

O diagrama UML do sistema está localizado em:

```txt
docs/Arquitetura_IAM_UML.png
```

Ele representa a relação entre:

* classe base;
* classe abstrata;
* interface;
* enumeração;
* classes concretas;
* classe interna privada.

---

## Como Compilar

No terminal, dentro da pasta do projeto, execute:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -I src src/main.cpp src/base/UsuarioAutenticavel.cpp src/models/UsuarioAdmin.cpp src/models/UsuarioAuditor.cpp src/models/UsuarioOperador.cpp -o projeto_6
```

---

## Como Executar

No MSYS2 ou Git Bash:

```bash
./projeto_6.exe
```

No Windows PowerShell:

```powershell
.\projeto_6.exe
```

---

## Exemplo de Saída

```txt
=== TESTE DE AUTENTICACAO ===
Administrador autenticado com sucesso.
Auditor autenticado com sucesso.
Operador autenticado com sucesso.

=== ACOES ESPECIFICAS DOS USUARIOS ===
admin_master esta gerenciando usuarios do sistema.
auditor_logs esta consultando logs de seguranca.
operador_caixa acessou o recurso: Consulta de conta
operador_caixa acessou o recurso: Atualizacao de cadastro

=== RELATORIOS GERADOS COM POLIMORFISMO ===
-----------------------------
Relatorio do Administrador
ID: 1
Usuario: admin_master
Nivel de acesso: Acesso total ao sistema
-----------------------------
Relatorio do Auditor
ID: 2
Usuario: auditor_logs
Nivel de acesso: Acesso de auditoria e consulta de logs
-----------------------------
Relatorio do Operador
ID: 3
Usuario: operador_caixa
Nivel de acesso: Acesso operacional limitado
Historico de acessos:
- Recurso acessado: Consulta de conta
  Data/Hora: 15/06/2026 01:36:07
  Status: 200
- Recurso acessado: Atualizacao de cadastro
  Data/Hora: 15/06/2026 01:36:07
  Status: 200
```

---

## Conceitos Aplicados

### Classes Abstratas

A classe `UsuarioAutenticavel` define comportamentos obrigatórios, mas não pode ser instanciada diretamente.

### Interfaces

A classe `Relatorio` define um contrato para geração de relatórios.

### Enum Class

A enumeração `TipoUsuario` categoriza os perfis de acesso do sistema.

### Classes Internas

A classe `HistoricoAcessos` está dentro de `UsuarioOperador` e registra acessos de forma encapsulada.

### Polimorfismo

O sistema usa ponteiros para `Relatorio` para chamar `gerarRelatorio()` em diferentes tipos de usuários.

### Encapsulamento

Os dados internos do histórico do operador ficam protegidos dentro da classe interna privada.

---

## Autor

Ivamilton Ferreira da Silva Junior
