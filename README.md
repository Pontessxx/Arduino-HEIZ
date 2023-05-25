# Projeto de Monitoramento Ambiental
![image](https://github.com/Pontessxx/Arduino-HEIZ/assets/126187491/08413365-8481-4565-a545-8f946a448ebd)

Este projeto utiliza um Arduino para monitorar a temperatura, umidade, nível de luz e umidade do solo em um ambiente. Com base nos valores coletados, o sistema aciona LEDs e um motor de acordo com as condições ambientais.
Nosso projeto é um sistema de irrigação autônomo, Desenvolvido voltado para fazendas de pequeno e médio porte padronizando a produção de canas de açúcar o item que temos reconhecimento a fora do mundo. a configuração pode ser   editada para atuar em qualquer condição de: Temperatura , incidência de luz solar e umidade presente no solo. Identificando a umidade do solo, e ligando a bomba de água para regar as plantas assim que se identificar necessário. Pode-se complementar esse projeto instalando novas placas solares que captam e utilizam a energia a qual é escassa em regiões rurais.

## Materiais Necessários

- Arduino Uno
- Sensor de temperatura
- Sensor de umidade
- Sensor de luz (LDR)
- Sensor de umidade do solo
- Display LCD 16x2
- LED verde
- LED amarelo
- LED vermelho
- Motor

## Montagem do Circuito

- Conecte o sensor de temperatura ao pino A0 do Arduino.
- Conecte o sensor de umidade ao pino A1 do Arduino.
- Conecte o sensor de luz (LDR) ao pino A2 do Arduino.
- Conecte o LED verde ao pino 2 do Arduino.
- Conecte o LED amarelo ao pino 3 do Arduino.
- Conecte o LED vermelho ao pino 4 do Arduino.
- Conecte o motor ao pino 10 do Arduino.
- Conecte o display LCD aos pinos 12, 11, 8, 7, 6 e 5 do Arduino.
- Conecte o sensor de umidade do solo ao pino A5 do Arduino.

## Configuração do Ambiente

- Certifique-se de ter a biblioteca LiquidCrystal instalada na sua IDE do Arduino. Caso contrário, você pode instalá-la acessando "Sketch" -> "Incluir Biblioteca" -> "LiquidCrystal".

## Como Usar

1. Carregue o código no Arduino utilizando a IDE do Arduino.
2. Abra o Monitor Serial para visualizar as leituras dos sensores.
3. Observe as informações exibidas no Monitor Serial para verificar as condições do ambiente.
4. O sistema acenderá o LED correspondente à condição do ambiente: verde para ambiente bom, amarelo para ambiente mediano e vermelho para ambiente ruim.
5. O motor será acionado conforme a umidade do solo: desligado para umidade alta, ligado para umidade baixa e desligado para umidade média.
6. As informações também serão exibidas no display LCD.

## Contribuição

Este projeto está aberto a contribuições. Sinta-se à vontade para fazer melhorias, adicionar novos recursos ou relatar problemas.

## Licença

Este projeto está licenciado sob a [MIT License](https://opensource.org/licenses/MIT).

## Recursos Adicionais

- [Documentação da biblioteca LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal)
- [Tutorial sobre sensores de temperatura e umidade](https://www.arduino.cc/en/Tutorial/TempAndHumiSensor)
- [Tutorial sobre sensor de luz (LDR)](https://www.arduino.cc/en/Tutorial/LightSensor)
- [Tutorial sobre sensor de umidade do solo](https://www.arduino.cc/en/Tutorial/CapacitiveSensor)
