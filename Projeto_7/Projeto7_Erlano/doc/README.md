# Sistema Acadêmico com Filtros Genéricos

Este projeto é um sistema acadêmico em C++ que usa programação orientada a objetos e templates. Ele gerencia Alunos, Professores, Funcionários Administrativos e Monitores, com recursos para filtrar e ordenar dados.

A arquitetura segue os pilares da POO:
Herança organiza a hierarquia de usuários.
Polimorfismo permite tratar diferentes usuários de forma genérica.
Templates possibilitam filtros reutilizáveis.
Encapsulamento protege os dados internos das classes.

O sistema é compilado com g++ usando a flag -std=c++11, e a execução ocorre no terminal. Todos os arquivos .cpp dos usuários são incluídos no comando de compilação.

O uso do sistema é simples e poderoso. É possível:
Filtrar alunos com média maior ou igual a 7.
Ordenar usuários por nome.
Localizar professores que ministram disciplinas específicas, como "POO".

## A classe de filtro oferece métodos como:

-adicionarElemento
-filtrarPorCondicao
-ordenar
-imprimirTodos
-getElementos

Os filtros funcionam com qualquer tipo de dado (ex: int, string, objetos personalizados). Também aceitam condições compostas, como buscar alunos de um curso específico com nota mínima.

Em resumo, o sistema é modular, flexível e reutilizável, unindo POO com templates para gerenciar dados acadêmicos com eficiência.