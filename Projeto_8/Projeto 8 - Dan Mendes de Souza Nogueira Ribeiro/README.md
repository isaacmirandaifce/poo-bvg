# Projeto Avaliativo 8: Tratamento de Exceções e Sinais - C++

**Nome**: Dan Mendes de Souza Nogueira Ribeiro
**Curso**: ADS - 3º Semestre - 2026

---

## 1. Conceitos Utilizados

| Arquitetura / Estrutura | Descrição do Componente | Observações Técnicas |
| --- | --- | --- |
| **Hierarquia de Exceções** | Classes customizadas `StorageException`, `FileCorruptedException` e `DiskWriteException`. | Herdam de `std::exception`. O polimorfismo é garantido sobrescrevendo o método virtual `what() const noexcept override`, mantendo as classes filhas enxutas apenas com construtores encadeados. |
| **Persistência de Dados (I/O)** | Classe `LedgerPersistence` responsável pelo acesso ao disco via biblioteca `<fstream>`. | Isola a manipulação de leitura (`ifstream`) e escrita (`ofstream`). Utiliza `std::vector<string>` como cache em memória e o `std::flush` para forçar a gravação física (segurança contra perda de dados). |
| **Captura de Sinais (OS Hooks)** | Classe `SignalHandler` responsável por monitorar sinais do Sistema Operacional (`<csignal>`). | Utiliza métodos estáticos (`inicializar` e `interceptar`) para capturar `SIGINT` (Ctrl+C) e `SIGTERM`. Impede o encerramento abrupto, salvando um log de emergência antes de acionar `exit(sinal)`. |
| **Resiliência e Isolamento** | Utilização de blocos `try-catch` locais e globais dentro do motor do sistema (`main.cpp`). | Separa erros críticos no boot (que encerram o sistema) de falhas locais (ex: disco sem permissão momentânea), permitindo que o loop `while` absorva o erro e continue rodando ininterruptamente. |

---

## 2. Testes de Resiliência Realizados

| Cenário de Teste | Método de Simulação | Resultado Obtido e Comportamento do Sistema |
| --- | --- | --- |
| **Falha de Inicialização** | Injeção intencional de dados malformados e linhas em branco no arquivo `ledger.csv` antes do boot do sistema. | A classe de persistência detectou a anomalia e disparou a `FileCorruptedException`. O bloco `try-catch` de inicialização (global) interceptou o erro, impediu o carregamento de dados em memória e encerrou o programa com segurança (código de saída 1), exibindo alerta de erro crítico. |
| **Falha de I/O em Tempo de Execução (Erro de Disco)** | Durante a execução do laço principal, as permissões do arquivo `ledger.csv` foram alteradas para "Somente Leitura" via Sistema Operacional. | A classe disparou a `DiskWriteException`. O erro foi contido pelo bloco `try-catch` **local** dentro do motor principal. O sistema exibiu o alerta e continuou rodando, tentando salvar novamente no próximo ciclo sem causar o "crash" da aplicação. |
| **Interrupção Abrupta (OS Hooking / SIGINT)** | Envio manual do sinal de interrupção do Sistema Operacional pressionando `Ctrl+C` no terminal durante o processamento ativo. | O `SignalHandler` sequestrou a rotina de encerramento, impediu a morte bruta do processo, gerou/atualizou o arquivo `log_emergencia.txt` (preservando o histórico com `std::ios::app`) e finalizou a execução via `std::exit(sinal)`. |

---

## 3. Compilar e Executar

### Compilação

```bash
g++ -I . infrastructure/ledgerPersistence.cpp infrastructure/signalHandler.cpp main.cpp -o sistema_projeto8
```

### Execução

```bash
./sistema_projeto8

```
