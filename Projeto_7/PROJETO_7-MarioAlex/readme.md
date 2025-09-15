Projeto Avaliativo 7 – Métodos e Classes Genéricas em C++
Descrição

Esse projeto amplia nosso sistema acadêmico usando classes e métodos genéricos. A ideia é facilitar o filtro, ordenação e manipulação de dados de alunos, professores e funcionários administrativos de forma prática e reutilizável.

No centro disso tudo está a classe Filtro<T>, que funciona com qualquer tipo de objeto do sistema, permitindo:

Adicionar objetos (adicionarElemento)

Filtrar objetos com condições personalizadas (filtrarPorCondicao)

Imprimir ou executar ações em todos os objetos (imprimirTodos)

Ordenar objetos de acordo com critérios (ordenarPor)

Estrutura do Projeto

Filtro.h → Classe genérica que faz toda a lógica de filtragem e ordenação.

main.cpp → Testa o funcionamento da classe genérica com Aluno, Professor e FuncionarioAdministrativo.

Aluno.h/cpp, Professor.h/cpp, funcionarioAdm.h/cpp → Classes do sistema acadêmico já existentes.

Como Testar

Compile todos os arquivos juntos:

g++ main.cpp Aluno.cpp Professor.cpp funcionarioAdm.cpp -o projeto7


Execute o programa:

./projeto7


Você vai ver no console:

Alunos com média acima de 7.0

Professores que dão uma disciplina específica

Alunos ordenados por nome

Tudo isso usando a classe genérica Filtro<T>, mostrando como dá pra reaproveitar código e organizar os dados de forma eficiente.

Observações

Para funcionar, as classes Aluno, Professor e FuncionarioAdministrativo precisam ter métodos como getNome(), getHistorico() e getDisciplinaPrincipal().

A main.cpp serve como teste e exemplo de uso, mas você pode criar filtros diferentes, condições novas e até ordenar de outros jeitos.