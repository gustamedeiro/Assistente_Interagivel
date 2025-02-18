# Assistente_Interagivel

# Relatório do Projeto:

## Apresentação

Este projeto visa criar um assistente virtual interativo usando a placa BitDogLab RP2040, controlando uma matriz de LEDs 5x5 para representar as emoções do assistente. As emoções podem ser alteradas através de botões, e o assistente também emite sons via buzzer para alertar ou responder ao usuário, e mostra mensagens através do Display OLED.

# Assistente Virtual Interativo

## Objetivos do projeto

O objetivo é desenvolver um sistema embarcado que exiba as emoções de um assistente virtual através de uma matriz de LEDs 5x5, com reações baseadas em interações do usuário. O projeto inclui controle de LEDs, botões de entrada, e buzzer para a comunicação.

## Descrição do funcionamento

O sistema utiliza três botões para controlar as emoções do assistente, que são exibidas na matriz de LEDs. Além disso, o buzzer é ativado quando o assistente "sente cócegas". As emoções podem ser alteradas e reiniciadas a qualquer momento com os botões.

## Justificativa 

A execução deste projeto justifica-se pela necessidade de criar interfaces de interação mais ricas e dinâmicas em sistemas embarcados. Utilizando apenas a BitDogLab RP2040, o projeto mostra como é possível criar interações emocionais simples em dispositivos de baixo custo e tamanho reduzido. Pode ser usado em diversos contextos, desde educação até entretenimento, e serve como uma excelente ferramenta para aprendizado em sistemas embarcados.
Embora existam projetos correlatos de assistentes virtuais e interações com microcontroladores, a abordagem deste projeto, envolvendo uma simulação de emoções digitais com feedbacks sonoros e visuais integrados, é inovadora. Não foi encontrada nenhuma solução que combine exatamente com esses elementos usando a BitDogLab RP2040.


## Diagrama em bloco 

O diagrama em bloco do projeto mostra a interconexão dos principais componentes:

BitDogLab RP2040 (controlador principal).

Matriz de LEDs 5x5 (representação das emoções).

Botões (para mudar emoções e reiniciar o estado).

Display OLED: Exibição de mensagens

Buzzer (para alertas de cócegas e mudanças de emoção).


-----------Adicionar Diagrama em bloco, nao esquecer--------------------------------

## Função de cada bloco

BitDogLab RP2040: Controla todos os outros componentes e processa as entradas dos botões.

Matriz de LEDs 5x5: Exibe as expressões faciais do assistente com base nas interações.

Botões: Permitem alterar ou reiniciar as emoções do assistente.

Buzzer: Emite sons para alertar o usuário.

Display OLED: Exibe mensagens relacionadas ao estado emocional.

## Configuração de cada bloco

Botões: Usados para gerar interrupções que alteram o estado do assistente.

LEDs: Controlados via pinos GPIO da RP2040, ajustando as cores.

Buzzer: Controlado por PWM para gerar diferentes frequências.

Display OLED: Comunicação via I2C com a RP2040.

## Descrição da pinagem usada 

A matriz de LEDs controlada com um único pino que é a GPIO 7.

Os botões são conectados a outros pinos, são eles: 
GPIO 5 (Push botton A), GPIO 6 (Push botton B), GPIO 22 (Joystick Push botton).

O buzzer A e o buzzer B conectados, respectivamente, as GPIO 21 e GPIO 10. 

Display OLED conectado na GPIO 14 (SDA) e GPIO 15 (SCL)

-----------------------------------------------------------------------------------------------------------------------
Diagram Circuito completo do hardware: O circuito será desenhado no Wokwi, incluindo todos os componentes, e conexões.-
-----------------------------------------------------------------------------------------------------------------------


--------------------------------------------------------------------------------------------------------------------------------------------------------
## Blocos funcionais 
--------------------------------------------------------------------------------------------------------------------------------------------------------


## Descrição das funcionalidades:
O código gerencia a matriz de LEDs para exibir diferentes expressões faciais.
O controle de botões altera o estado emocional do assistente.
O buzzer emite sons conforme a necessidade (alertas de cócegas, por exemplo).
Definição das variáveis: Variáveis como estadoEmocao e tempoPressionado serão usadas para armazenar o estado do assistente e controlar a entrada dos botões.

--------------------------------------------------------------------------------------------------------------------------------------------------------
## Fluxograma
--------------------------------------------------------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------------------------------------------------------
Inicialização:
--------------------------------------------------------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------------------------------------------------------
Configurações dos registros: A configuração dos registros será feita para controlar a matriz de LEDs e os botões.
--------------------------------------------------------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------------------------------------------------------
Estrutura e formato dos dados: O código usará matrizes para representar as expressões faciais na matriz de LEDs.
--------------------------------------------------------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------------------------------------------------------
## Metodologia 
--------------------------------------------------------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------------------------------------------------------
Testes de validação: O sistema foi testado para garantir que as emoções sejam exibidas corretamente e que os botões funcionem conforme esperado.
--------------------------------------------------------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------------------------------------------------------
Discussão dos Resultados:
--------------------------------------------------------------------------------------------------------------------------------------------------------

--------------------------------------------------------------------------------------------------------------------------------------------------------
## Referências
--------------------------------------------------------------------------------------------------------------------------------------------------------
