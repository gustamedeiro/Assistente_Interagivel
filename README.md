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
## Inicialização:
--------------------------------------------------------------------------------------------------------------------------------------------------------

## Configurações dos registros: 
Para garantir o funcionamento adequado dos periféricos utilizados no projeto, os registradores do RP2040 são configurados conforme as necessidades de cada componente:

Configuração dos GPIOs (Entradas e Saídas)--> Os botões (GPIO5, GPIO6 e GPIO22) são configurados como entradas com pull-up interno para detectar pressões. Isso é feito ativando os registradores de controle do GPIO (SIO).
A matriz de LEDs (GPIO7) e os buzzers (GPIO21 e GPIO10) são configurados como saídas digitais para permitir o controle do assistente emocional.

Configuração do PWM para o Buzzer--> Os pinos GPIO21 e GPIO10 utilizam PWM para gerar tons sonoros. Para isso, os registradores PWM_CHx_CSR (Control and Status Register) são configurados, ativando o modo PWM e ajustando a frequência do sinal.

Configuração do I2C para o Display OLED --> A comunicação com o display OLED ocorre por meio do barramento I2C, utilizando os pinos GPIO14 (SDA) e GPIO15 (SCL). Esses pinos são configurados com a função I2C ajustando os registradores I2C_CTRL (I2C Control Register), garantindo uma taxa de comunicação eficiente.

Configuração dos Temporizadores Internos --> Para monitorar o tempo sem interação e alterar o estado emocional do assistente, são utilizados temporizadores internos do RP2040. Os registradores correspondentes são ajustados para gerar interrupções em intervalos regulares, garantindo que o estado emocional mude dinamicamente.

------------------------------------------------------------------------------------------------------------------------------------------------------
Estrutura e formato dos dados: O código usará matrizes para representar as expressões faciais na matriz de LEDs.
--------------------------------------------------------------------------------------------------------------------------------------------------------

## Metodologia 
O desenvolvimento do assistente emocional foi realizado seguindo um conjunto de etapas organizadas para garantir um funcionamento eficiente e previsível. A abordagem adotada seguiu um fluxo estruturado, conforme descrito abaixo:

PESQUISA INICIAL
Antes do desenvolvimento, foi realizada uma pesquisa sobre projetos similares que utilizam expressões faciais em matrizes de LEDs e interação com botões. Além disso, foram analisadas as capacidades da placa BitDogLab RP2040, seus periféricos e protocolos suportados, como GPIO, PWM e I2C. Essa etapa foi essencial para entender as limitações e possibilidades do hardware disponível.

DEFINIÇÃO DAS FUNCIONALIDADES
Com base na pesquisa, foi elaborado um escopo detalhado das funcionalidades do assistente. A lógica de mudança emocional foi planejada, considerando os diferentes estados emocionais e as condições que os ativam. Foram estabelecidos os seguintes pontos principais:
Quais botões afetariam cada estado emocional.
Como a matriz de LEDs exibiria as expressões faciais.
O uso do display OLED para exibir mensagens relacionadas às emoções.
O acionamento do buzzer em situações específicas, como alertas e reações.
Configuração do ambiente de desenvolvimento no Wokwi
O Wokwi, um simulador de hardware embarcado, foi escolhido para a prototipagem inicial. 
Nele, foram adicionados os componentes necessários:
Matriz de LEDs 5x5 para exibir expressões faciais.
Botões físicos para permitir a interação do usuário.
Display OLED via comunicação I2C.
Buzzer controlado por PWM.
RP2040 como unidade central de controle.
Essa configuração permitiu testar o comportamento do sistema sem a necessidade imediata de hardware físico.

IMPLEMENTAÇÃO DO FIRMWARE 
O código foi escrito em C, utilizando as bibliotecas adequadas para a BitDogLab RP2040. Foram desenvolvidos os seguintes módulos principais:
Gerenciamento de estados emocionais: lógica para mudar entre "feliz", "triste" e "irritado".
Leitura dos botões com interrupções: para detectar interações do usuário de forma eficiente.
Controle da matriz de LEDs: exibição de diferentes expressões faciais conforme o estado emocional.
Exibição de mensagens no display OLED: comunicação via I2C para mostrar respostas do assistente.
Acionamento do buzzer: geração de sons conforme a emoção do assistente.

TESTES E AJUSTES 
Após a implementação, foram realizados testes para validar a resposta do sistema. Os principais testes incluíram:
Pressionamento dos botões para verificar se as emoções mudam corretamente.
Tempo sem interação para testar se o assistente muda para o estado "triste" automaticamente.
Exibição correta das expressões faciais na matriz de LEDs.
Comunicação I2C funcional para exibir mensagens no display OLED.
Teste do buzzer para garantir que os sons indicam corretamente as emoções e alertas.
Com base nos testes, pequenos ajustes foram feitos para otimizar a responsividade dos botões e melhorar a suavidade da transição entre estados emocionais.

## Testes de validação
Os testes foram conduzidos para garantir que cada componente do sistema funcionasse conforme esperado e que o assistente emocional interativo respondesse corretamente às interações do usuário. As validações foram realizadas individualmente para cada módulo e, posteriormente, de forma integrada.

Verificação da Matriz de LEDs 5x5
Objetivo: Confirmar que as expressões faciais mudam corretamente conforme o estado emocional do assistente.
Procedimento: Teste inicial com a matriz de LEDs exibindo o rosto "feliz" ao ligar o sistema.
Pressionamento dos botões para alterar o estado emocional e observar as mudanças visuais na matriz.
Simulação de falta de interação para verificar a transição automática para o estado "triste".
Teste de múltiplos pressionamentos rápidos para simular o estado de "irritação".
Resultado esperado: A matriz de LEDs exibe expressões correspondentes aos estados emocionais do assistente.

Respostas aos Botões
Objetivo: Garantir que os botões alterem o estado emocional conforme projetado.
Procedimento: Pressionar o botão 1 e verificar se a resposta do assistente corresponde ao estado emocional esperado.
Pressionar o botão 2 para testar a exibição da resposta no display OLED e a mudança no rosto do assistente.
Pressionar repetidamente os botões para observar mudanças de estado e garantir que o assistente não entre em loops inesperados.
Testar o botão 3 (do joystick) para resetar o estado emocional para "feliz".
Resultado esperado: O assistente responde corretamente a cada botão, mudando expressões e mensagens de forma apropriada.

Interação com o Buzzer
Objetivo: Validar que o buzzer é acionado corretamente conforme as interações do usuário.
Procedimento: Pressionar um botão e verificar se há um alerta sonoro quando necessário.
Simular "cócegas" repetidas para garantir que o buzzer emita um alerta de sobrecarga.
Monitorar se há variações na frequência dos sons gerados conforme o estado emocional muda.
Resultado esperado: O buzzer responde de maneira apropriada às interações, emitindo alertas sonoros quando necessário.

Monitoramento do Tempo sem Interação
Objetivo: Testar se o assistente altera seu estado emocional de forma autônoma quando não há interação por um período prolongado.
Procedimento: Inicializar o sistema e aguardar sem pressionar nenhum botão.
Observar se, após um tempo pré-definido, o assistente muda para um estado "triste".
Verificar se, ao interagir novamente, o assistente retorna ao estado "feliz".
Resultado esperado: O assistente se torna "triste" após um período de inatividade e retorna ao normal ao receber interações.


## Discussão dos Resultados:
Os testes mostraram que o sistema responde bem às interações do usuário. O assistente consegue alterar seu estado emocional dinamicamente e oferece um retorno visual e sonoro eficaz. Pequenos ajustes foram feitos para melhorar a responsividade dos botões e a suavidade da mudança de emoções

## Referências
RASPBERRY PI. RP2040 Datasheet. Disponível em: https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf. Acesso em: 18 fev. 2025.
BITDOGLAB. Documentação técnica da placa BitDogLab RP2040. Disponível em: https://github.com/BitDogLab/BitDogLab. Acesso em: 18 fev. 2025.
ADAFRUIT INDUSTRIES. Adafruit SSD1306 Library. Disponível em: https://github.com/adafruit/Adafruit_SSD1306. Acesso em: 20 fev. 2025.
WOKWI. Simulador Online para RP2040. Disponível em: https://wokwi.com. Acesso em: 20 fev. 2025.
ARTIGOS SOBRE EXPRESSÕES FACIAIS EM MATRIZES DE LED: Estudos indicam que expressões simplificadas podem ser eficazmente representadas com pequenos conjuntos de LEDs, melhorando a interação humano-máquina.  
PROJETOS SIMILARES: Análise de dispositivos interativos utilizando LEDs para exibição de estados emocionais em ambientes educacionais e robóticos. Pesquisa feita em: 17 fev. 2025
