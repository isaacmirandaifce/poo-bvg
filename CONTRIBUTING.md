
# Guia de Contribuição para o Repositório de POO

Bem-vindo ao repositório da disciplina de Programação Orientada a Objetos (POO)! Este documento descreve as diretrizes de contribuição para mantermos consistência e qualidade no código. Siga atentamente as orientações abaixo ao submeter suas atividades e projetos.

## Estrutura de Diretórios

Cada projeto deve ser organizado na seguinte estrutura de diretórios:

```
Projeto_X/
│
├── src/               # Código-fonte
├── docs/              # Documentação do projeto
└── tests/             # Testes automatizados (quando aplicável)
```

## Regras para Nomeação de Arquivos

- **Classes e Interfaces**: Nomeie os arquivos de classes e interfaces de forma que reflitam a finalidade, usando `CamelCase`. Exemplo: `Usuario.java`, `GerenciadorDeTarefas.java`.
- **Métodos**: Utilize `camelCase` para nomear métodos e funções. Exemplo: `calcularSalarioMensal()`.
- **Diretórios de Projeto**: Cada projeto deve ser armazenado em uma pasta com o nome `Projeto_X`, onde `X` representa o número do projeto.

## Padrões de Código

Para manter a consistência, siga as práticas abaixo para formatação e organização do código.

### 1. Estrutura e Organização de Classes

- **Encapsulamento**: Todas as variáveis de instância devem ser `private`, com métodos `public` de acesso (`getters` e `setters`) quando necessário.
- **Modularização**: Mantenha cada classe em seu próprio arquivo. Evite classes longas e prefira criar métodos para funções específicas.
- **Herança e Polimorfismo**: Utilize herança para classes que compartilhem características comuns, mas evite heranças excessivas e crie classes concretas quando apropriado.

### 2. Padrões de Nomenclatura

- **Classes**: `CamelCase` para nomes de classes, com substantivos claros e significativos, que reflitam a responsabilidade da classe.
- **Métodos e Variáveis**: `camelCase` para métodos e variáveis. Use verbos que descrevam o propósito para métodos. Exemplo: `calcularDesconto()`, `nomeDoUsuario`.

### 3. Boas Práticas de Programação Orientada a Objetos

- **Coesão e Responsabilidade Única**: Cada classe deve ter uma única responsabilidade, conforme o princípio SOLID de responsabilidade única (SRP).
- **Documentação de Classes e Métodos**: Adicione comentários Javadoc para descrever a funcionalidade de cada classe e método.
- **Uso de Interfaces**: Utilize interfaces para definir contratos e comportamentos comuns entre classes.

## Regras para Envio de Pull Requests (PR)

1. **Título da PR**: Use o formato `Projeto_X - [Nome do Aluno]`. Exemplo: `Projeto_1 - João Silva`.
2. **Descrição**: Inclua uma breve descrição do que foi implementado e quais problemas foram resolvidos. Mencione quaisquer funcionalidades extras.
3. **Revisão de Código**: Aguarde o feedback da revisão antes da fusão da PR. Faça correções necessárias antes de enviar novamente para revisão.
4. **Testes**: Certifique-se de que todas as funcionalidades principais estão testadas, preferencialmente com testes automatizados.

## Estilo de Código

- **Indentação**: Use 4 espaços para a indentação de código.
- **Comprimento de Linha**: Limite cada linha a no máximo 80 caracteres.
- **Comentários**: Mantenha comentários curtos e claros. Use `//` para comentários inline e `/* ... */` para explicações mais longas.

## Exemplo de Estrutura de Classe

```java
/**
 * Representa um usuário no sistema com suas informações pessoais e métodos de autenticação.
 */
public class Usuario {
    private String nome;
    private String email;
    private String senha;

    /**
     * Construtor da classe Usuario.
     * 
     * @param nome  Nome do usuário
     * @param email Email do usuário
     */
    public Usuario(String nome, String email) {
        this.nome = nome;
        this.email = email;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public boolean autenticar(String senha) {
        // Lógica de autenticação
        return this.senha.equals(senha);
    }
}
```

## Contato

Para qualquer dúvida sobre as diretrizes de contribuição, entre em contato com o professor responsável pela disciplina.
