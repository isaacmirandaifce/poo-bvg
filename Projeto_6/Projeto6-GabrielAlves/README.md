# Sistema Avançado de Gestão Acadêmica

## 1. Descrição do Projeto

Este projeto é uma expansão de um sistema de gerenciamento acadêmico, desenvolvido para aplicar e consolidar conceitos avançados de Programação Orientada a Objetos (POO)[cite: 1]. O objetivo é implementar funcionalidades como autenticação de usuários e geração de relatórios polimórficos, utilizando uma estrutura que reflete práticas comuns no mercado de software[cite: 3, 25].

O sistema gerencia diferentes tipos de usuários (alunos, professores e funcionários administrativos), cada um com comportamentos e dados específicos[cite: 8].

## 2. Conceitos de POO Aplicados

A implementação deste projeto foca nos seguintes pilares da POO:

  * **Classes Abstratas:** Foi criada a classe "UsuarioAutenticavel", que herda de uma classe "Usuario" base e define um contrato para todos os usuários que precisam de um método de login, sem implementar os detalhes[cite: 5]. Ela possui um método abstrato "autenticar".
  * **Interfaces (Protocolos):** A interface "Relatorio" foi definida com um método abstrato "gerar_relatorio()"[cite: 6]. As classes "Aluno", "Professor" e "FuncionarioAdministrativo" implementam essa interface, garantindo que cada uma possa gerar um relatório customizado de forma polimórfica.
  * **Classes Enumeradas (Enums):** A enumeração "TipoUsuario" foi criada para categorizar de forma clara e segura os tipos de usuários do sistema ("ALUNO", "PROFESSOR", "FUNCIONARIO_ADMINISTRATIVO")[cite: 8, 13].
  * **Classes Internas:** A classe "Aluno" contém uma classe interna chamada "HistoricoDisciplinar"[cite: 9]. Essa classe encapsula os dados relativos ao histórico de disciplinas cursadas pelo aluno, como nome da disciplina, ano e nota[cite: 10].

## 3. Funcionalidades Principais

  * **Autenticação Segura:** Usuários implementam um método "autenticar(senha)"[cite: 5, 11]. Para maior segurança, as senhas não são armazenadas em texto plano, mas sim como um hash, seguindo boas práticas de segurança[cite: 16].
  * **Geração de Relatórios:** O sistema pode gerar relatórios detalhados e específicos para cada tipo de usuário[cite: 12]. Isso é feito através de uma chamada polimórfica ao método "gerar_relatorio()".
  * **Modularização:** O código é organizado em múltiplos arquivos, separando responsabilidades e facilitando a manutenção, conforme solicitado nos requisitos técnicos[cite: 13].
  * **Encapsulamento:** Todos os atributos de classe são protegidos para garantir que o acesso seja feito de maneira controlada, respeitando os princípios do encapsulamento[cite: 15].

## 4. Estrutura dos Arquivos

O projeto está organizado na seguinte estrutura de arquivos para promover a modularidade:

"""
/Projeto_6/
├── enums.py                  # Contém a enumeração TipoUsuario
├── interfaces.py             # Define a interface Relatorio
├── usuario.py                # Contém as classes Usuario e UsuarioAutenticavel
├── aluno.py                  # Implementação da classe Aluno e sua classe interna HistoricoDisciplinar
├── professor.py              # Implementação da classe Professor
├── funcionario.py            # Implementação da classe FuncionarioAdministrativo
└── main.py                   # Ponto de entrada da aplicação, onde os objetos são criados e as funcionalidades demonstradas
"""

## 5. Diagrama UML (Descrição Textual)

Conforme solicitado, segue uma descrição detalhada da estrutura de classes que seria visualizada em um diagrama UML[cite: 14].

  * **Classes e Enumerações:**

      * "Usuario": Classe base com atributos ("nome", "id").
      * "UsuarioAutenticavel" (Abstrata): Herda de "Usuario". Define o método "autenticar(senha)".
      * "Relatorio" (Interface): Define o método "gerar_relatorio()".
      * "TipoUsuario" (Enum): Contém os valores "ALUNO", "PROFESSOR", "FUNCIONARIO_ADMINISTRATIVO".
      * "Aluno": Herda de "UsuarioAutenticavel" e implementa "Relatorio".
      * "Professor": Herda de "UsuarioAutenticavel" e implementa "Relatorio".
      * "FuncionarioAdministrativo": Herda de "UsuarioAutenticavel" e implementa "Relatorio".
      * "HistoricoDisciplinar" (Classe Interna): Contida dentro de "Aluno".

    **Relacionamentos:**

      * **Herança:** "Aluno", "Professor", e "FuncionarioAdministrativo" estendem "UsuarioAutenticavel".
      * **Implementação:** "Aluno", "Professor", e "FuncionarioAdministrativo" implementam a interface "Relatorio".
      * **Composição:** "Aluno" é composto por "HistoricoDisciplinar".

## 6. Como Executar o Projeto

1.  Certifique-se de que você tem o Python 3 instalado em seu sistema.

2.  Clone ou baixe todos os arquivos (".py") para um mesmo diretório.

3.  Abra um terminal ou prompt de comando nesse diretório.

4.  Execute o arquivo "main.py" com o seguinte comando:

    """bash
    python main.py
    """

5.  A saída no terminal demonstrará a criação dos usuários, os testes de autenticação e a geração de relatórios para cada um.