Projeto 2 - Programação Orientada a Objetos (POO)

📌 Objetivo

Refatorar um sistema legado de cálculo de seguros utilizando conceitos de Programação Orientada a Objetos, eliminando estruturas condicionais complexas ("if/else") e melhorando a organização do código.

---

❌ Problema (código legado)

O sistema original utilizava diversas estruturas condicionais para calcular o valor do prêmio de diferentes tipos de seguro:

if tipo == "auto":
    ...
elif tipo == "vida":
    ...
elif tipo == "residencial":
    ...

Problemas dessa abordagem:

- Código difícil de manter
- Baixa escalabilidade
- Alto acoplamento
- Necessidade de modificar código existente para adicionar novos tipos de seguro

---

🚀 Solução aplicada

O sistema foi refatorado utilizando os principais pilares da Programação Orientada a Objetos:

✔ Herança

Foi criada uma classe base "Seguro", da qual derivam:

- "SeguroAuto"
- "SeguroVida"
- "SeguroResidencial"

---

✔ Polimorfismo

Cada classe implementa seu próprio comportamento para o método:

calcular_premio()

Isso permite que o código trate todos os seguros de forma genérica.

---

✔ Encapsulamento

Os atributos foram protegidos utilizando convenções como:

- "_atributo" (protegido)

---

🔥 Como o polimorfismo resolveu o problema

Antes (código legado):

if tipo == "auto":
    calcular_auto()
elif tipo == "vida":
    calcular_vida()

Agora (POO):

for seguro in cliente.listar_seguros():
    seguro.calcular_premio()

✅ Vantagem:

O código não precisa saber o tipo do seguro.

Cada classe é responsável pela sua própria regra de cálculo.

---

📈 Benefícios da solução

- Eliminação de "if/else" no código principal
- Código mais limpo e organizado
- Fácil manutenção
- Alta escalabilidade
- Facilidade para adicionar novos tipos de seguro

---

📊 Diagrama UML

O diagrama de classes está disponível em:

docs/diagrama_classes.png

---

📁 Estrutura do Projeto

Projeto_2/
│
├── docs/
│   └── diagrama_classes.png
│
├── src/
│   ├── models/
│   │   ├── cliente.py
│   │   └── seguros.py
│   │
│   └── main.py
│
└── README.md

---

🧪 Como executar o projeto

1. Acesse a pasta do projeto:

cd Projeto_2

2. Execute o sistema:

python src/main.py

---

🖥️ Exemplo de saída

=== Seguros do Cliente ===
Prêmio: R$ 1200.0
Prêmio: R$ 1600.0
Prêmio: R$ 575.0

---

🎯 Conclusão

A utilização de Programação Orientada a Objetos permitiu transformar um código rígido e difícil de manter em uma solução:

- Modular
- Flexível
- Reutilizável
- Alinhada com boas práticas de desenvolvimento

---

👨‍💻 Autor
Ivamilton Ferreira da Silva Júnior