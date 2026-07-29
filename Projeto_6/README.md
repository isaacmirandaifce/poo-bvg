# Projeto 6 - Core de Autenticação e Auditoria (IAM) - SecureBank Pro

Este repositório contém a implementação do **Projeto Avaliativo 6 / Ticket #602**, focado no desenvolvimento do subsistema de Gestão de Identidades e Acessos em C++.

O sistema implementa conceitos avançados de **Classes Abstratas**, **Interfaces**, **Classes Enumeradas (`enum class`)** e **Classes Internas (Nested Classes)** com isolamento total de dados sensíveis.

---

## Estrutura do Repositório

```text
Projeto_6/
│
├── docs/
│   └── Arquitetura_IAM_UML.png        # Diagrama UML detalhando interfaces, herança e classe interna
│
├── src/
│   ├── interfaces/
│   │   └── Relatorio.h                # Contrato de interface para relatórios de compliance
│   ├── base/
│   │   ├── UsuarioAutenticavel.h      # Classe abstrata base e enum TipoUsuario
│   │   └── UsuarioAutenticavel.cpp    # Implementação dos dados base
│   ├── models/
│   │   ├── UsuarioAdmin.h / .cpp      # Perfil Admin e logs de modificação
│   │   ├── UsuarioAuditor.h / .cpp    # Perfil Auditor e chaves de segurança
│   │   └── UsuarioOperador.h / .cpp   # Perfil Operador contendo a classe interna HistoricoAcessos
│   └── main.cpp                       # Orquestração do fluxo de login e loop polimórfico
│
└── README.md                          # Documentação técnica do projeto


## Como Compilar e Executar

1. **Abra o terminal no diretório raiz do Projeto_6:**
   ```bash
   cd Projeto_6
   ```

2. **Compile todos os arquivos do módulo `src/` utilizando o `g++`:**
   ```bash
   g++ src/main.cpp src/base/UsuarioAutenticavel.cpp src/models/UsuarioAdmin.cpp src/models/UsuarioAuditor.cpp src/models/UsuarioOperador.cpp -o iam_app
   ```

3. **Execute o programa gerado:**

   * **Linux / macOS:**
     ```bash
     ./iam_app
     ```

   * **Windows:**
     ```cmd
     iam_app.exe
     ```