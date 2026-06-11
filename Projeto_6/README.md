# Projeto 6 - Classes Abstratas, Interfaces, Enum Class e Classe Interna

**Autor:** Gabriel Uaren
**Curso:** ADS - 3º Semestre - 2026

## Descrição

Sistema de autenticação e auditoria desenvolvido em C++, simulando o módulo IAM (Identity and Access Management) do SecureBank Pro.

## Conceitos Utilizados

* Classe Abstrata
* Interface
* Herança
* Polimorfismo
* Enum Class
* Classe Interna (Nested Class)
* Encapsulamento

## Classes Implementadas

* Usuario
* UsuarioAutenticavel (abstrata)
* UsuarioAdmin
* UsuarioAuditor
* UsuarioOperador
* Relatorio (interface)
* HistoricoAcessos (classe interna)

## Enumeração

```cpp
enum class TipoUsuario
{
    ADMIN,
    AUDITOR,
    OPERADOR
};
```

## Funcionalidades

* Autenticação de usuários
* Geração de relatórios
* Controle de perfis de acesso
* Registro de histórico de acessos do operador
* Demonstração de polimorfismo com ponteiros para interface

## Compilação

```bash
g++ src/base/*.cpp src/models/*.cpp src/main.cpp -o Projeto6
```

## Execução

```bash
./Projeto6
```
