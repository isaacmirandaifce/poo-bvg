# Projeto 6 — Sistema Avançado de Gestão Acadêmica

## Descrição
Implementação em C++ de um sistema acadêmico demonstrando:

- **Classes abstratas** (`UsuarioAutenticavel`) para usuários autenticáveis.
- **Interface** (`Relatorio`) para geração de relatórios.
- **Enumeração** (`TipoUsuario`) para classificar usuários.
- **Classe interna** (`HistoricoDisciplinar` em `Aluno`) para histórico de disciplinas.

Permite criar **Alunos**, **Professores** e **Funcionários**, autenticar por senha e gerar relatórios detalhados.

---

## Funcionalidades
- Autenticação por hash de senha (`std::hash`).
- Relatórios de usuários via interface `Relatorio`.
- Histórico disciplinar encapsulado em classe interna.
- Gestão de disciplinas: nome, carga horária, nota e aprovação (nota ≥ 6 → aprovado).

---

## Estrutura de Arquivos
