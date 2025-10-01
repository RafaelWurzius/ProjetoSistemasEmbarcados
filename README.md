# Jogo da Velha Mecânico com Arduino 🎮✏️

Este projeto utiliza **Arduino** e **servomotores** para controlar mecanicamente uma caneta que desenha o **tabuleiro do jogo da velha** e marca **X** ou **O** nas posições correspondentes ao apertar dos botões.

---

## 🛠️ Componentes Utilizados

- 2 × Servomotores (controlam o movimento da caneta nos eixos X e Y)
- 9 × Botões (um para cada posição do tabuleiro)
- Arduino Uno (ou compatível)
- Caneta ou marcador
- Estrutura mecânica de plástico para suportar e movimentar a caneta
- Fios e protoboard

---

## ⚙️ Funcionamento

1. **Desenho do tabuleiro:**  
   Ao iniciar, os servos movem a caneta para desenhar o tabuleiro completo do jogo da velha.

2. **Marcação das jogadas:**  
   - O jogador aperta um botão correspondente à posição desejada no tabuleiro.
   - O sistema alterna entre desenhar **X** ou **O**.
   - Cada posição é mapeada com coordenadas específicas para que a caneta desenhe corretamente.

3. **Controle mecânico:**  
   - **Servo 1:** controla o movimento vertical da caneta.  
   - **Servo 2:** controla o movimento horizontal da caneta.  
   - Movimentos precisos são feitos com loops incrementais para traçar linhas ou curvas do X e O.

4. **Alternância de turno:**  
   - A variável `vezX` determina se a próxima jogada será X ou O.  
   - Após cada jogada, `vezX` alterna entre verdadeiro e falso.

---

## 📌 Código Principal (Arduino)

O código principal está no arquivo `jogo_da_velha.ino` e contém funções principais:

- `desenhaJogo()`: desenha o tabuleiro completo.
- `desenhaX(int x, int y)`: desenha um **X** na posição (x, y) especificada.
- `desenhaO(int x, int y)`: desenha um **O** na posição (x, y) especificada.
- `loop()`: monitora os botões e chama as funções de desenho correspondentes, alternando entre X e O.
- `ajusta()`: ajusta a caneta para posição inicial.

---
