O Projeto 8 funciona de forma independente e não depende de projetos anteriores.
Todo o sistema está organizado dentro da pasta Projeto_8/src, onde ficam os arquivos principais do programa.

A execução do sistema é feita a partir do executável gerado do projeto, permitindo o uso normal do sistema acadêmico.

Os dados utilizados pelo sistema são salvos em arquivos de texto.
Esses arquivos não precisam existir antes, pois são criados automaticamente quando o sistema realiza o salvamento.

O arquivo alunos_dados.txt guarda as informações dos alunos.
Cada linha do arquivo possui o identificador do aluno, o nome e o curso.

O arquivo professores_dados.txt contém os dados dos professores.
Em cada linha são armazenados o identificador, o nome e a área do professor.

O arquivo disciplinas_dados.txt armazena as informações das disciplinas.
Cada linha possui o identificador da disciplina, o nome e a carga horária.

O sistema também possui tratamento de sinais do sistema operacional.
Quando o programa é interrompido pelo teclado, o sinal de interrupção é capturado e os dados são salvos automaticamente.

O encerramento solicitado pelo próprio sistema operacional também é tratado.
Em casos de erro grave, como falha de segmentação, o sistema exibe uma mensagem informando o problema.

Nessas situações mais críticas, o salvamento dos dados pode não ser totalmente garantido, pois o estado do programa pode estar comprometido.