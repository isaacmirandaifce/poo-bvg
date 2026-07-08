# Projeto 6 - Sistema de Autenticação e Auditoria (IAM)

## Descrição
Sistema de gestão de identidades e acessos com rigoroso controle de auditoria, utilizando classes abstratas, interfaces e classes internas para isolamento de dados sensíveis.

## Funcionalidades
- **Contratos:** Implementação de `Relatorio` como interface (classe puramente abstrata) e `UsuarioAutenticavel` como classe base abstrata.
- **Segurança:** Uso de `enum class` para triagem de tipos de usuário e encapsulamento rigoroso de dados na classe interna `HistoricoAcessos` (dentro de `UsuarioOperador`).
- **Polimorfismo:** Execução polimórfica via `std::vector<Relatorio*>`, garantindo o disparo correto dos relatórios de cada perfil.

## Como Compilar
O projeto foi estruturado com a lógica de implementação contida nos arquivos de cabeçalho (`.h`), o que facilita a compilação direta:

1. Navegue até a pasta raiz:
   `cd Projeto_6`

2. Compile utilizando o comando:
   `g++ -Isrc src/main.cpp -o secure_bank`

3. Execute:
   `./secure_bank`

## Notas Técnicas
- **Encapsulamento:** A classe interna `HistoricoAcessos` é acessível apenas pela sua classe externa (`UsuarioOperador`), protegendo o histórico contra acessos externos indevidos.
- **Gerenciamento de Memória:** O `main.cpp` realiza a desalocação manual dos ponteiros `Relatorio*` via `delete` em laço, garantindo a conformidade com as políticas de memória do C++.
