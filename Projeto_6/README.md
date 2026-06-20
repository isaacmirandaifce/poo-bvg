# Projeto 6 — SecureBank Pro: Módulo IAM (Identity and Access Management)

## 📋 Descrição
Implementação do core de autenticação e auditoria do sistema SecureBank Pro,
desenvolvido como parte do curso de Programação Orientada a Objetos em C++.

O projeto aplica os conceitos de Classes Abstratas, Interfaces, Classes Enumeradas
e Classes Internas para construir um sistema seguro e modular de gestão de identidades.

---

## 🏗️ Arquitetura

### Hierarquia de Classes
Usuario

└── UsuarioAutenticavel (abstrata)

├── UsuarioAdmin      (implementa Relatorio)

├── UsuarioAuditor    (implementa Relatorio)

└── UsuarioOperador   (implementa Relatorio)

└── HistoricoAcessos (classe interna privada)
<<interface>>

Relatorio

├── gerarRelatorio() = 0

### Enum Class
TipoUsuario { ADMIN, AUDITOR, OPERADOR }

---

## 📁 Estrutura de Arquivos
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

│   │   ├── UsuarioAdmin.h / .cpp

│   │   ├── UsuarioAuditor.h / .cpp

│   │   └── UsuarioOperador.h / .cpp

│   └── main.cpp

└── README.md

---

## 🔑 Conceitos Aplicados

| Conceito | Onde foi aplicado |
|---|---|
| Classe Base | `Usuario` — armazena id e username |
| Classe Abstrata | `UsuarioAutenticavel` — método virtual puro `autenticar()` |
| Interface | `Relatorio` — contrato com método virtual puro `gerarRelatorio()` |
| Herança Múltipla | Classes concretas herdam de `UsuarioAutenticavel` e `Relatorio` |
| Enum Class | `TipoUsuario` — categoriza perfis de acesso |
| Classe Interna | `HistoricoAcessos` dentro de `UsuarioOperador` |
| Polimorfismo | Loop com `std::vector<Relatorio*>` chamando `gerarRelatorio()` |

---

## ⚙️ Como Compilar e Executar

```bash
# Dentro da pasta Projeto_6/src/
g++ main.cpp base/UsuarioAutenticavel.cpp models/UsuarioAdmin.cpp models/UsuarioAuditor.cpp models/UsuarioOperador.cpp -o securebank

./securebank
```

---