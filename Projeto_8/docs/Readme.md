## **Compilar e executar (standalone em Projeto_8)**

Siga estes passos para compilar o `Projeto_8` sem depender de `Projeto_7` (todo o sistema está em `Projeto_8/src`):

- Compile os fontes localmente:

```bash
cd /workspaces/poo-bvg/Projeto_8
g++ -std=c++17 src/*.cpp -Isrc -o projeto8
```

- Execute o binário:

```bash
./projeto8
```

Arquivos de dados (opcionais, criados automaticamente quando salvar):
- `dados_alunos.txt` — cada linha: `nome;email;matricula;curso`
- `dados_professores.txt` — cada linha: `nome;email;area;disc1|disc2|disc3`
- `dados_disciplinas.txt` — cada linha: `nome;cargaHoraria;nota`

Testando sinais:
- Pressione `Ctrl+C` para enviar `SIGINT` e acionar o salvamento pelo tratador de sinais.
- Em outro terminal, use `kill -TERM <pid>` para enviar `SIGTERM`.
- `SIGSEGV` pode ser simulada via `kill -SEGV <pid>`; observe que salvar após `SIGSEGV` pode não ser totalmente seguro.