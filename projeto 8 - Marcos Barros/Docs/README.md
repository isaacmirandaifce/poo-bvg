# Projeto 8: Gerenciamento Acadêmico Resiliente

**Autor:** Marcos Barros
**Disciplina:** Programação Orientada a Objetos

## Descrição Geral

Este projeto aprimora um sistema de gerenciamento acadêmico, focando na robustez e resiliência da aplicação. Foram implementados mecanismos avançados de tratamento de exceções e sinais do sistema operacional, garantindo que a aplicação lide de forma segura com erros de arquivo e encerramentos inesperados.

O sistema agora possui um módulo de persistência que carrega e salva automaticamente os dados de alunos, professores e disciplinas em arquivos `.csv`, garantindo a continuidade dos dados entre as sessões.

## Funcionalidades Principais

* **Persistência de Dados:** Todos os dados de alunos, professores e disciplinas são salvos em arquivos `.csv`.
* **Carregamento Automático:** Ao iniciar, o sistema carrega automaticamente todos os dados previamente salvos.
* **Salvamento Automático:** Qualquer alteração relevante (como a adição de um novo aluno, professor ou disciplina) aciona o salvamento automático de todos os dados.
* **Tratamento de Exceções de Arquivo:** O sistema lida com os seguintes erros de forma controlada:
    * Arquivo de dados não encontrado (cria um novo ao salvar).
    * Permissão de escrita/leitura negada.
    * Dados em formato inválido dentro dos arquivos `.csv`.
* **Exceções Personalizadas:** Classes de exceção específicas (`ArquivoNaoEncontradoException`, `PermissaoNegadaException`, `FormatoInvalidoException`) foram criadas para um tratamento de erro mais claro.
* **Tratamento de Sinais do Sistema:** A aplicação captura os seguintes sinais do sistema operacional:
    * `SIGINT` (interrupção via `Ctrl+C`).
    * `SIGTERM` (finalização solicitada pelo SO, ex: comando `kill`).
    * `SIGSEGV` (acesso inválido à memória / falha de segmentação).
    * Em caso de `SIGINT` ou `SIGTERM`, o sistema tenta salvar os dados antes de encerrar. Em caso de `SIGSEGV`, ele informa que um salvamento não é seguro e encerra.

## Estrutura do Projeto

O código foi modularizado para garantir a organização e a manutenibilidade:

* **`main.cpp`**: Ponto de entrada da aplicação, responsável pelo menu de interação com o usuário.
* **`SistemaAcademico.h/.cpp`**: Classe principal que orquestra toda a lógica do sistema, gerenciando as listas de dados e as operações.
* **`Persistencia.h/.tpp`**: Módulo genérico (template) responsável por serializar e desserializar os dados de/para os arquivos `.csv`.
* **`SinalHandler.h/.cpp`**: Classe estática responsável por configurar e tratar os sinais do sistema operacional.
* **`Aluno.h/.cpp`, `Professor.h/.cpp`, `Disciplina.h/.cpp`**: Classes de modelo que representam os dados do sistema.
* **`Excecoes.h`**: Define as classes de exceção personalizadas.

## Como Compilar e Executar

O projeto foi compilado utilizando g++ (MinGW) no Windows. Para garantir que o executável seja autossuficiente (não dependa de DLLs externas), utilize o seguinte comando de compilação:

```bash
g++ -std=c++17 -Wall main.cpp Aluno.cpp Professor.cpp Disciplina.cpp SistemaAcademico.cpp SinalHandler.cpp -o sistema_academico -static-libgcc -static-libstdc++
```

Para executar o programa no terminal (PowerShell), utilize o comando:

```powershell
.\sistema_academico.exe
```

## Como Testar as Funcionalidades de Resiliência

* **`Ctrl+C`:** Com o programa rodando, adicione um novo dado e pressione `Ctrl+C`. Ao reabrir, o novo dado deverá estar salvo.
* **Falha de Segmentação:** Utilize a opção do menu para simular uma falha (`SIGSEGV`) e observe a mensagem de encerramento seguro.
* **Exceções de Arquivo:**
    * Delete um dos arquivos `.csv` para ver o aviso de "arquivo não encontrado" na inicialização.
    * Altere as permissões de um arquivo `.csv` para "somente leitura" para forçar um erro de permissão ao tentar salvar.
    * Edite manualmente um arquivo `.csv` com dados inválidos para forçar um erro de formato na inicialização.

---
