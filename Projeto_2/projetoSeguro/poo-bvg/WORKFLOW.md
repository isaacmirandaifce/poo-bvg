# Regras para o Workflow de Submissão de Atividades

Para garantir a consistência, a organização e a revisão eficiente dos projetos no repositório, siga cuidadosamente as diretrizes abaixo ao submeter atividades via Pull Requests (PRs).

## Workflow de Submissão com Pull Requests (PRs)

### 1. Criando uma Pull Request (PR)

- **Título da PR**: Para facilitar a identificação, utilize o formato padronizado de título para a sua PR:
  ```
  Projeto_X - [Nome do Aluno]
  ```
  Onde `X` é o número do projeto (ex., `Projeto_1 - João Silva`).
  
- **Descrição da PR**: Na descrição, adicione um resumo conciso do que foi implementado, incluindo:
  - Funcionalidades principais desenvolvidas;
  - Conceitos de Programação Orientada a Objetos aplicados;
  - Módulos ou classes criados.

### 2. Requisitos para Aprovação da PR

As Pull Requests submetidas passarão por uma **revisão de código e de documentação**. Somente PRs que atendam aos critérios a seguir serão aprovadas:

- **Conformidade com os Padrões de Código**: Verifique se o código segue as diretrizes de formatação e estilo descritas no arquivo `CONTRIBUTING.md`.
- **Implementação Completa das Funcionalidades**: A PR deve incluir todas as funcionalidades pedidas no projeto. Verifique se todos os requisitos foram atendidos.
- **Documentação e Comentários**: A documentação Javadoc deve estar presente em todas as classes e métodos. Os comentários devem ser claros e ajudar a entender o código.
- **Boas Práticas de POO**: Assegure-se de que o código demonstra aplicação adequada de encapsulamento, herança, polimorfismo e coesão, conforme necessário para o projeto específico.

### 3. Processo de Revisão e Feedback

Após a submissão da PR, o professor revisará o código e poderá realizar comentários diretamente nas linhas do código. O aluno deve:

1. **Responder ao Feedback**: Verifique os comentários da revisão e faça as correções sugeridas.
2. **Enviar Alterações**: Faça um novo commit com as correções e atualize a PR.
3. **Confirmação de Aprovação**: Após atender a todos os critérios e revisões, a PR será aprovada e integrada ao repositório principal.

### 4. Critérios de Reprovação

Uma PR pode ser recusada ou solicitada para revisão se:

- Não seguir o padrão de título ou a estrutura de descrição necessária;
- Não atender aos requisitos de implementação e aos padrões de POO;
- Conter problemas de formatação, documentação insuficiente ou ausência de comentários;
- Demonstrar práticas inadequadas de POO, como falta de encapsulamento, polimorfismo mal implementado, ou excesso de responsabilidade em uma única classe.

### 5. Reenvio de PR após Correções

Se uma PR for solicitada para correção, realize as alterações necessárias conforme o feedback, commitando as mudanças na mesma PR. Depois de corrigidas as pendências, marque novamente a PR para revisão.
