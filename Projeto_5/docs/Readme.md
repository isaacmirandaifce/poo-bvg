## Projeto 5 — Herança, Polimorfismo, Sobrecarga e Sobrescrita (C++)

**Objetivo:** Projeto avaliativo que implementa uma hierarquia de usuários de um sistema acadêmico usando herança, polimorfismo, sobrecarga e herança múltipla em C++.

**Descrição curta:**
- **Sistema:** representa vários tipos de `Usuario` (Aluno, Professor, FuncionarioAdministrativo) e uma classe `Monitor` que combina `Aluno` e `Professor` (herança múltipla).
- **Foco:** demonstrar sobrescrita de métodos virtuais (`gerarRelatorio()`), sobrecarga (método em `Aluno` para exibir com/sem notas) e uso de ponteiros/referências para polimorfismo.

**Principais classes e responsabilidades**
- **`Usuario`**: classe base abstrata com atributos comuns (`nome`, `email`, `tipo`) e o método virtual puro `gerarRelatorio()`.
- **`Aluno`**: herda de `Usuario` e contém `matricula`, `curso` e associação com `Disciplina`. Implementa `gerarRelatorio()` e sobrecarga `exibirInformacoes()` com parâmetro `bool comNotas`.
- **`Professor`**: herda de `Usuario`, tem `areaDeAtuacao` e vetor de `disciplinasMinistradas`, e sobrescreve `gerarRelatorio()`.
- **`FuncionarioAdministrativo`**: herda de `Usuario`, possui `departamento` e `cargo`, e sobrescreve `gerarRelatorio()`.
- **`Monitor`**: herança múltipla de `Aluno` e `Professor`, adiciona `disciplinasMonitoradas` e método para listá-las.
- **`Disciplina`**: classe auxiliar com `nome`, `cargaHoraria` e `nota`. Inclui função amiga `verificarAprovacao`.

**Estrutura do projeto**
- `Projeto_5/src/` : código-fonte (arquivos `.h` e `.cpp`).
	- `Usuario.h`, `Usuario.cpp`
	- `Aluno.h`, `Aluno.cpp`
	- `Professor.h`, `Professor.cpp`
	- `FuncionarioAdministrativo.h`, `FuncionarioAdministrativo.cpp`
	- `Monitor.h`, `Monitor.cpp`
	- `Disciplina.h`, `Disciplina.cpp`
	- `Main.cpp` (exemplo de uso que demonstra polimorfismo e sobrecarga)
- `Projeto_5/docs/Readme.md` : este arquivo.

**Como compilar (Linux / Bash)**
1. Abra um terminal na raíz do workspace ou use paths absolutos abaixo.
2. Compile todos os fontes com `g++` (padrão C++17):

```bash
mkdir -p /workspaces/poo-bvg/Projeto_5/bin
g++ -std=c++17 /workspaces/poo-bvg/Projeto_5/src/*.cpp -o /workspaces/poo-bvg/Projeto_5/bin/projeto5
```

Observações:
- Se você estiver dentro de `/workspaces/poo-bvg/Projeto_5`, pode usar `g++ -std=c++17 src/*.cpp -o bin/projeto5`.
- Se ocorrerem erros de link relacionados à ordem, compile separadamente ou adicione todos os `.cpp` explicitamente.

**Como executar**

```bash
/workspaces/poo-bvg/Projeto_5/bin/projeto5
```

ou, se estiver no diretório do projeto:

```bash
./bin/projeto5
```

**O que esperar na saída**
- O `Main.cpp` fornece um cenário de exemplo onde são criados:
	- um `Aluno` com disciplinas (notas)
	- um `Professor`
	- um `FuncionarioAdministrativo`
	- um `Monitor` (herança múltipla)
- A execução imprime relatórios polimórficos chamando `gerarRelatorio()` via ponteiros para `Usuario`, exibe informações do aluno com e sem notas (sobrecarga) e lista disciplinas monitoradas.