 **Projeto Avaliativo 8: Tratamento de Exceções e Sinais - C++**

## **Objetivo**
Este projeto tem como objetivo aprimorar o sistema acadêmico desenvolvido anteriormente, integrando conceitos avançados de tratamento de exceções e sinais para tornar a aplicação mais robusta e tolerante a falhas. A proposta é implementar o carregamento automático de dados a partir de arquivos externos, garantindo que possíveis erros de leitura, escrita e manipulação de arquivos sejam devidamente tratados. Além disso, o sistema deve ser capaz de responder de maneira adequada a sinais do sistema operacional, como encerramento abrupto e falhas de segmentação.

---

## **Tema do Projeto: Gerenciamento Acadêmico Resiliente**

### **Descrição Geral**
Os alunos devem modificar o sistema acadêmico para incluir:
- **Carregamento de dados a partir de arquivos**, garantindo que a aplicação seja capaz de iniciar com dados pré-existentes e salvos anteriormente.
- **Tratamento de exceções** ao tentar abrir, ler e gravar arquivos de dados.
- **Mecanismo de resposta a sinais do sistema operacional**, garantindo que falhas inesperadas sejam tratadas e que a aplicação possa continuar funcionando ou encerrar de maneira segura.

---

### **Requisitos do Projeto**

1. **Tratamento de Exceções em Arquivos:**
   - Criar um **módulo de persistência** para carregar e salvar automaticamente os dados do sistema em arquivos (`.txt` ou `.csv`).
   - Implementar um tratamento adequado para os seguintes erros:
     - Arquivo não encontrado.
     - Permissão negada para abrir ou gravar o arquivo.
     - Falhas na conversão de dados lidos do arquivo.

2. **Uso de Exceções Personalizadas:**
   - Criar classes de exceção personalizadas para diferentes cenários de erro.
   - Exemplo: `ArquivoNaoEncontradoException`, `PermissaoNegadaException`.

3. **Manipulação de Sinais do Sistema Operacional:**
   - Implementar um **tratador de sinais** para capturar:
     - **SIGINT** (Interrupção via Ctrl+C).
     - **SIGSEGV** (Acesso inválido à memória).
     - **SIGTERM** (Finalização solicitada pelo SO).
   - Quando um sinal for capturado:
     - O sistema deve tentar salvar os dados antes de encerrar (se for seguro fazê-lo).
     - O programa deve imprimir uma mensagem informando o motivo do encerramento.

4. **Integração com o Sistema Acadêmico:**
   - O sistema deve carregar automaticamente as listas de:
     - Alunos.
     - Professores.
     - Disciplinas.
   - Sempre que houver uma modificação relevante (como a inclusão de um novo aluno ou disciplina), o sistema deve salvar os dados automaticamente.

---

## **Requisitos Técnicos**

1. **Tratamento de Exceções e Salvamento de Dados:**
   - Criar funções que tentem abrir arquivos e capturem possíveis erros.
   - Exibir mensagens informativas e opções para o usuário quando erros ocorrerem.

2. **Manipulação de Sinais:**
   - Usar a biblioteca `<csignal>` para capturar sinais do sistema.
   - Criar uma função de tratamento global para manipular os sinais.

3. **Estrutura de Arquivos do Projeto:**
   - Modularizar o código com arquivos `.h` e `.cpp` bem organizados:
     - `Persistencia.h` e `Persistencia.cpp`: Manipulação de arquivos.
     - `SinalHandler.h` e `SinalHandler.cpp`: Tratamento de sinais.
     - `main.cpp`: Integração e testes do sistema.

4. **Modelagem UML:**
   - Criar um **diagrama UML** com as novas classes e sua integração com as já existentes no sistema.

---

## **Exemplo de Estrutura de Código**

### Arquivo `Persistencia.h`
```cpp
#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include <fstream>
#include <vector>
#include "Aluno.h"

class Persistencia {
public:

};

#endif // PERSISTENCIA_H
```

### Arquivo `Persistencia.cpp`
```cpp
#include "Persistencia.h"
#include <iostream>

```

### Arquivo `SinalHandler.h`
```cpp
#ifndef SINALHANDLER_H
#define SINALHANDLER_H

#include <csignal>
#include <iostream>

class SinalHandler {
public:
    static void inicializar();
private:
    static void tratador(int sinal);
};

#endif // SINALHANDLER_H
```

### Arquivo `SinalHandler.cpp`
```cpp
#include "SinalHandler.h"

void SinalHandler::inicializar() {

}

void SinalHandler::tratador(int sinal) {
 
    exit(1);
}
```

### Arquivo `main.cpp`
```cpp
#include <iostream>
#include "Persistencia.h"
#include "SinalHandler.h"

int main() {
    SinalHandler::inicializar();

    try {
        
    } catch ( ) {

    }

    return 0;
}
```

---

## **Critérios de Avaliação**

1. **Implementação Técnica (6 pontos):**
   - Correta implementação do carregamento de arquivos e manipulação de sinais.

2. **Robustez do Sistema (2 pontos):**
   - Sistema responde bem a falhas inesperadas e erros de arquivo.

3. **Modelagem UML (1 ponto):**
   - Diagrama UML atualizado, incluindo persistência e tratamento de sinais.

4. **Boas Práticas e Documentação (1 ponto):**
   - Código modular, comentado e organizado.

---

## **Entrega**

1. **Formato:**
   - Os arquivos devem ser enviados para o repositório da turma no diretório `/Projetos/Projeto_8`.
   - O diagrama UML deve ser incluído no formato `.png` ou `.jpg`.

2. **Prazo:**
   - O projeto deve ser entregue até **09/03/2025**.
