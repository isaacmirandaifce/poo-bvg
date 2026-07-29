# Documentação do Sistema - Projeto 1

## Diagrama de Classe (UML Simplificado)
Classe: Cliente
---------------------------
- __nome: str
- __idade: int
- __saldo: float
- __status_ativo: bool
---------------------------
+ depositar(valor: float)
+ sacar(valor: float)
+ exibir_dados()
---------------------------

## Decisões de Projeto
- Foi utilizado o prefixo `__` para garantir o encapsulamento restrito.
- A validação de saldo negativo foi movida para dentro do método `sacar`.