# Repositório da Disciplina de Programação Orientada a Objetos (POO)

Bem-vindo ao repositório oficial da disciplina de **Programação Orientada a Objetos (POO)**! Este espaço será utilizado para a submissão e revisão dos projetos desenvolvidos ao longo do curso. Aqui você encontrará as diretrizes de contribuição, regras de submissão e informações importantes para o desenvolvimento dos projetos.

## Estrutura do Repositório

O repositório está organizado por projetos, cada um em uma pasta própria:
```
Projeto_X/
│
├── src/               # Código-fonte
├── docs/              # Documentação do projeto
└── tests/             # Testes automatizados (quando aplicável)
```
Os projetos devem ser submetidos em Pull Requests (PRs) para o repositório principal seguindo as diretrizes estabelecidas.

## Como Submeter um Projeto

Para submeter seu projeto, você deverá criar uma **Pull Request (PR)** no repositório principal. Cada PR deve conter:

- **Título da PR** no formato: `Projeto_X - [Nome do Aluno]` (ex., `Projeto_1 - João Silva`);
- **Descrição** resumida do que foi implementado, mencionando as principais funcionalidades e classes desenvolvidas.

### Requisitos para Aprovação

Todas as PRs passam por uma revisão de código antes de serem aceitas. As PRs serão aprovadas apenas se cumprirem os requisitos a seguir:

- **Padrões de Código**: O código deve seguir as diretrizes de formatação e estilo descritas no arquivo [`CONTRIBUTING.md`](CONTRIBUTING.md).
- **Funcionalidades Completa**: O projeto deve implementar todas as funcionalidades solicitadas.
- **Documentação e Comentários**: O código deve incluir documentação Javadoc em classes e métodos, bem como comentários explicativos.
- **Boas Práticas de POO**: O código deve aplicar corretamente os princípios de Programação Orientada a Objetos (encapsulamento, herança, polimorfismo, entre outros).

Caso a PR não atenda a esses critérios, ela será marcada para correção, e o aluno deverá realizar as mudanças e reenviar a PR para revisão.

## Diretrizes de Contribuição

Consulte o arquivo [`CONTRIBUTING.md`](CONTRIBUTING.md) para orientações detalhadas sobre como contribuir com o repositório. Ele inclui:

- **Regras para Nomeação de Arquivos e Métodos**: Como nomear classes, métodos e variáveis.
- **Padrões de Organização de Código**: Formatação, indentação e estrutura de classes.
- **Boas Práticas de POO**: Instruções para encapsulamento, herança e outras práticas orientadas a objetos.
- **Regras de Envio de PRs**: Detalhes sobre como estruturar uma PR para que ela seja aprovada.

## Fluxo de Trabalho para Pull Requests (PRs)

1. **Criar uma PR**: Ao concluir um projeto, crie uma PR com o título `Projeto_X - [Nome do Aluno]` e uma descrição breve do que foi implementado.
2. **Aguardar Revisão**: O professor revisará o código, adicionando comentários e sugestões de melhorias.
3. **Fazer Ajustes**: Se necessário, faça os ajustes indicados e atualize a PR com os commits de correção.
4. **Aprovação da PR**: Após atender aos requisitos, a PR será aprovada e integrada ao repositório.

Para mais detalhes, consulte as [Regras para o Workflow](WORKFLOW.md) e o arquivo `CONTRIBUTING.md`.

## Boas Práticas de Programação Orientada a Objetos (POO)

Durante o desenvolvimento dos projetos, lembre-se de aplicar os conceitos de POO abordados em aula. Aqui estão algumas práticas importantes:

- **Encapsulamento**: Mantenha as variáveis de instância como `private`, utilizando `getters` e `setters` conforme necessário.
- **Coesão e Responsabilidade Única**: Cada classe deve ter uma única responsabilidade clara.
- **Polimorfismo e Herança**: Utilize herança e polimorfismo para estender classes e métodos, quando necessário.
- **Interface e Abstração**: Prefira o uso de interfaces para definir contratos de comportamento.

Essas práticas são essenciais para uma codificação limpa e organizada e serão criteriosamente avaliadas nas revisões de PR.

## Exemplo de Estrutura de Classe

```java
/**
 * Classe de exemplo para representar um usuário no sistema.
 */
public class Usuario {
    private String nome;
    private String email;

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

    public String getEmail() {
        return email;
    }

    public void autenticar(String senha) {
        // Método de autenticação
    }
}
```

## Dúvidas e Suporte

Para quaisquer dúvidas, entre em contato com o professor ou use o fórum de discussão no Google Classroom.
