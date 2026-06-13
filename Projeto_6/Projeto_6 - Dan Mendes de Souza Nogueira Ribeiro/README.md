# Projeto Avaliativo 6: Classes Abstratas, Interfaces, Classes Enumeradas e Classes Internas

**Nome**: Dan Mendes de Soouza Nogueira Ribeiro
**Curso**: ADS - 3º Semestre - 2026

---

## 1. Conceitos Utilizados

| Arquitetura / Estrutura | Descrição do Componente | Observações Técnicas |
| --- | --- | --- |
| **Contratos Globais** | Classes base `Usuario` (estado encapsulado) e a interface puramente abstrata `Relatorio`. | `UsuarioAutenticavel` e `Relatorio` impedem instanciação isolada por possuírem métodos virtuais puros (`= 0`). |
| **Perfis de Acesso** | Classes concretas: `usuarioAdmin`, `UsuarioAuditor` e `UsuarioOperador`. | Herdam de `UsuarioAutenticavel` e assinam a interface `Relatorio`, implementando comportamentos e logs polimórficos distintos. |
| **Categorização (Enum)** | Utilização do enumerador de escopo fechado `enum class TipoUsuario`. | Exposto polimorficamente via `getTipoUsuario() const`, garantindo triagem em tempo de execução sem risco de vazamento de senhas ou colisões. |
| **Isolamento Interno** | Aninhamento da classe privada `HistoricoAcessos` dentro de `UsuarioOperador`. | Atributos e estado confinados no escopo da classe mãe. Inserção gerida internamente por `registrarAcesso()` e exibição restrita ao `.gerarRelatorio()`. |

---

## 2. Compilar e Executar

### Compilação

```bash
g++ -std=c++11 main.cpp base/usuarioAutenticavel.cpp models/usuarioAdmin.cpp models/usuarioAuditor.cpp models/usuarioOperador.cpp -o sistema_acesso

```

### Execução

```bash
./sistema_acesso

```
