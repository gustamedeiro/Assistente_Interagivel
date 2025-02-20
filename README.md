# Relatório do Projeto:

## Apresentação

Este projeto visa criar um assistente virtual interativo usando a placa BitDogLab RP2040, controlando uma matriz de LEDs 5x5 para representar as emoções do assistente. O assistente recebe mensagens do usuário através dos botões e as emoções podem ser alteradas com o (ou o não) pressionamento, e o assistente também emite sons via buzzer para alertar ou responder ao usuário, e mostra mensagens através do Display OLED.

# Assistente Virtual Interativo

## Objetivos do projeto

O objetivo deste projeto é desenvolver um sistema embarcado inovador que represente emoções de um assistente virtual através de uma matriz de LEDs 5x5. Esse sistema deve ser capaz de responder dinamicamente às interações do usuário por meio de botões físicos e fornecer feedback sonoro utilizando um buzzer. A ideia principal é criar uma experiência interativa onde o assistente virtual demonstre reações emocionais semelhantes às humanas, tornando a interação mais natural e envolvente. Além de servir como um experimento prático em sistemas embarcados, este projeto também pode ser aplicado em contextos educacionais, de acessibilidade e até mesmo em interfaces homem-máquina mais intuitivas.

O projeto explora conceitos essenciais de hardware e software embarcados, como controle de GPIOs, tratamento de interrupções, debounce de botões, manipulação de matrizes de LEDs, e geração de sinais sonoros com o buzzer. Assim, ele também serve como um estudo aprofundado sobre sistemas de resposta rápida e interatividade, promovendo aprendizado prático em eletrônica e programação embarcada.

## Descrição do funcionamento

O sistema embarcado é baseado em uma matriz de LEDs 5x5 que exibe diferentes expressões faciais, refletindo o estado emocional do assistente virtual. Esse estado pode ser modificado pelo usuário utilizando três botões físicos, cada um responsável por uma ação específica:

O usuário "faz perguntas" pressionando botões, ou reinicia as emoções do Assistente.
  - Botão 1 = Pergunta "Como você está?".
  - Botão 2 = Pergunta "Me dê um conselho"
  - Botão 3 = Reinicia o estado emocional para "feliz"
A qualquer momento, o usuário pode redefinir o estado emocional do assistente pressionando o botão de reinicialização, restaurando a expressão "feliz" como padrão.

O assistente responde no display e com LEDs.
  - Se estiver "feliz", exibe um rosto sorridente na matriz de LEDs 5x5 e a mensagem "Estou ótimo! Vamos codar!" no display OLED.
  - Se estiver "triste" (muito tempo sem interagir), exibe um rosto triste na matriz e "Estou meio solitário..." no display OLED.
  - Se for pressionado repetidamente, pode "se irritar" e responder de forma engraçada.

Além das expressões faciais, o assistente reage quando recebe um estímulo prolongado no botão associado à "cócegas". Se o usuário pressiona repetidamente o botão, o sistema interpreta isso como uma ação de cócegas, ativando o buzzer para emitir um som específico e mudando momentaneamente a expressão facial para uma reação de desconforto. O som e a exibição da expressão duram um curto intervalo de tempo antes de retornar ao estado anterior.
O projeto opera de forma contínua, monitorando a entrada dos botões e atualizando as expressões faciais conforme necessário. A estrutura do código segue um modelo baseado em estados, onde cada estado representa uma emoção e as transições entre estados ocorrem conforme os eventos de entrada dos botões.
Cada botão é conectado a um pino digital e utiliza interrupções para garantir resposta rápida e eficiente. Para evitar leituras falsas ou múltiplas detecções indesejadas, um sistema de debounce é implementado.

## Justificativa 

A execução deste projeto justifica-se pela necessidade de criar interfaces de interação mais ricas e dinâmicas em sistemas embarcados. Utilizando apenas a BitDogLab RP2040, o projeto mostra como é possível criar interações emocionais simples em dispositivos de baixo custo e tamanho reduzido. Pode ser usado em diversos contextos, desde educação até entretenimento, e serve como uma excelente ferramenta para aprendizado em sistemas embarcados.
Embora existam projetos correlatos de assistentes virtuais e interações com microcontroladores, a abordagem deste projeto, envolvendo uma simulação de emoções digitais com feedbacks sonoros e visuais integrados, é inovadora. Não foi encontrada nenhuma solução que combine exatamente com esses elementos usando a BitDogLab RP2040.


## Diagrama em bloco 

O diagrama em bloco do projeto mostra a interconexão dos principais componentes:

BitDogLab RP2040 (controlador principal).

Matriz de LEDs 5x5 (representação das emoções).

Botões (para mudar emoções e reiniciar o estado).

Display OLED: Exibição de mensagens

Buzzers (para alertas de cócegas e mudanças de emoção).


-----------Adicionar Diagrama em bloco, nao esquecer--------------------------------

## Função de cada bloco

BitDogLab RP2040 (Microcontrolador Principal) --> Atua como o cérebro do sistema, gerenciando todos os periféricos e executando o firmware do assistente.
Processa as entradas dos botões e altera as emoções do assistente conforme as interações.
Controla a matriz de LEDs 5x5 para exibir as expressões faciais.
Gera os sinais necessários para ativar o buzzer e exibir mensagens no display OLED.
Utiliza interrupções para garantir respostas rápidas aos eventos dos botões.

Matriz de LEDs 5x5 --> Representa o rosto do assistente, exibindo diferentes expressões faciais com base no estado emocional.
Conectada ao GPIO 7, sendo controlada diretamente pela RP2040.
Cada LED pode ser ligado ou desligado de acordo com padrões predefinidos para formar expressões como "feliz", "triste", "surpreso", etc.
A matriz responde instantaneamente às mudanças de estado emocional, oferecendo uma interface visual ao usuário.

Botões -->
Botão 1 ou Botão A: Se pressionado 3 vezes em menos de 2 segundos, reinicia o assistente para o estado "feliz".
Botão 2 ou Botão B: Alterna entre os diferentes estados emocionais do assistente.
Botão 3 ou Botão do Joystick: Reinicia as emoções para "feliz" de forma imediata.
Funcionam através de interrupções para evitar atrasos e garantir que os comandos sejam reconhecidos sem precisar de polling contínuo.

Buzzers --> Emite diferentes sons dependendo do estado emocional do assistente.
Quando o assistente "sente cócegas", ele ativa um alerta sonoro para indicar desconforto.
Controlado por PWM (Modulação por Largura de Pulso), permitindo variação da frequência do som gerado.

Display OLED (SSD1306, comunicação I2C) --> Exibe mensagens textuais relacionadas ao estado emocional do assistente.
Pode mostrar frases como "Estou feliz!", "Estou triste...", ou "Pare com as cócegas kkk".
Atualizado em tempo real conforme as interações do usuário.
Usa comunicação I2C para reduzir o número de pinos necessários na RP2040.

## Configuração de cada bloco

Botões --> Configurados como entradas digitais na RP2040.
Utilizam resistores pull-up internos para evitar leitura de valores indefinidos.
Associados a interrupções, garantindo resposta rápida ao pressionamento.

Matriz de LEDs 5x5 --> Conectada ao GPIO 7 e operada via tabela de bits no firmware.
O software define padrões de acendimento dos LEDs para representar cada emoção.
A matriz é atualizada sempre que o estado emocional muda.

Buzzers --> Conectado a um pino PWM da RP2040, permitindo controle preciso da frequência do som.
Emite tons diferentes dependendo da interação do usuário.
Ativado apenas quando necessário, economizando energia.

Display OLED (SSD1306, I2C) --> Usa dois pinos GPIO para comunicação via barramento I2C.
Atualizado sempre que há uma mudança de estado emocional.
Exibe mensagens curtas para complementar a matriz de LEDs.

## Descrição da pinagem usada 

A matriz de LEDs controlada com um único pino que é a GPIO 7.

Os botões são conectados a outros pinos, são eles: 
GPIO 5 (Push botton A), GPIO 6 (Push botton B), GPIO 22 (Joystick Push botton).

O buzzer A e o buzzer B conectados, respectivamente, as GPIO 21 e GPIO 10. 

Display OLED conectado na GPIO 14 (SDA) e GPIO 15 (SCL)
__________________________
| Componente | Pino GPIO |
|------------|-----------|
| Matriz de LEDs 5x5 | 7 |
| Botão 1            | 5 |
| Botão 2            | 6 |
| Botão 3            | 22 |
| Buzzer 1           | 21 |
| Buzzer 2           | 10 |
| Display OLED SDA   | 14 |
| Display OLED SCL   | 15 |
___________________________


-----------------------------------------------------------------------------------------------------------------------
Diagram Circuito completo do hardware: O circuito será desenhado no Wokwi, incluindo todos os componentes, e conexões.-
-----------------------------------------------------------------------------------------------------------------------


--------------------------------------------------------------------------------------------------------------------------------------------------------
## Blocos funcionais 
--------------------------------------------------------------------------------------------------------------------------------------------------------


## Descrição das funcionalidades:
O código gerencia a matriz de LEDs para exibir diferentes expressões faciais.
O controle de botões altera o estado emocional do assistente.
Os buzzers emite sons conforme o comando.


Gerenciamento de estado emocional: Monitora as interações do usuário e ajusta o estado emocional do assistente, alternando entre "feliz", "triste" e "irritado". A mudança ocorre de acordo com o tempo sem interação ou pelo número de vezes que os botões são pressionados.
Entrada do usuário: Detecta quando um botão é pressionado e interpreta qual ação deve ser tomada, seja para perguntar algo ao assistente ou para resetar seu estado emocional.
Saída visual: Controla a matriz de LEDs 5x5, exibindo expressões faciais correspondentes ao estado emocional do assistente. Além disso, utiliza o display OLED para mostrar mensagens complementares às emoções expressas.
Saída sonora: Ativa o buzzer para fornecer feedback sonoro ao usuário, reforçando os estados emocionais e emitindo alertas em determinadas condições, como quando o assistente "sente cócegas".

## Definição das variáveis: 
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
