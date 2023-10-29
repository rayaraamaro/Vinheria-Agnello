# CP2 - Edge Computing
# Desenvolvimento de Monitoramento para Vinheria Agnello

O caso apresenta uma vinheria tradicional, que opera como loja física, e que está demandando o desenvolvimento de um portal de e-commerce, para começar a vender também na Internet, mas com uma exigência básica: que a loja virtual consiga criar uma experiência do usuário similar à do atendimento presencial em sua loja física.

A equipe foi contratada pela Vinheria Agnello para desenvolver um sistema de monitoramento a ser instalado no ambiente em que os vinhos são armazenados. O dono da Vinheria informou que a qualidade do vinho é influenciada diretamente pelas condições de temperatura, umidade e luminosidade do ambiente. A primeira parte do projeto foi apresentada aos proprietários da Vinheria, e eles ficaram muito satisfeitos com o resultado. Porém, há um segundo desafio: elaborar um sistema usando Arduino que faça a captura das informações de luminosidade do ambiente, temperatura e umidade. As fases da segunda etapa são:

- Medir a temperatura e umidade do ambiente, para isso foi escolhido o sensor integrado DHT11, que já possui uma biblioteca implementada para o Arduino. É necessário aprender a instalar essa biblioteca no IDE do Arduino e utilizá-la para ler a temperatura e umidade do ambiente.
- Os proprietários querem ver os valores de temperatura e umidade de alguma forma, por isso foi sugerido o uso de um display para mostrar esses valores.
- Os sinais de alerta foram bem aceitos, e os proprietários querem estender essa funcionalidade para temperatura e umidade, portanto, além de sinalizar com os LEDs e o Buzzer a luminosidade, também é necessário indicar quando a temperatura e/ou a umidade estiverem em níveis críticos.

## Pré-requisitos

Para executar os códigos da placa Arduino, é necessário ter o Arduino IDE instalado em sua máquina.

## Instalação

Para configurar sua placa Arduino conforme o projeto, siga as instruções apresentadas no site do Wokwi. Após montar a placa de acordo com as especificações, conecte-a ao seu computador. Em seguida, baixe o arquivo "vinheira.ino", compile-o, e seu projeto estará funcionando!

## Ferramentas Utilizadas

Este projeto foi construído com as seguintes ferramentas:

- [Wokwi](https://wokwi.com/)
- [Arduino IDE](https://www.arduino.cc/en/software)

## Autores

<table>
  <tr>
    <td align="center">
      <a href="https://github.com/VictorRodrigues16">
        <img src="https://avatars.githubusercontent.com/u/143040764?v=4" width="100px;" alt="Foto do Victor no GitHub"/><br>
        <sub>
          <b>Victor</b>
        </sub>
      </a>
    </td>
   <td align="center">
      <a href="https://github.com/educf-code">
        <img src="https://avatars.githubusercontent.com/u/127149439?v=4" width="100px;" alt="Foto do Edu no GitHub"/><br>
        <sub>
          <b>Eduardo</b>
        </sub>
      </a>
    </td>
   <td align="center">
      <a href="https://github.com/joraysuke">
        <img src="https://avatars.githubusercontent.com/u/143045200?v=4" width="100px;" alt="Foto da Rayara no GitHub"/><br>
        <sub>
          <b>Rayara</b>
        </sub>
      </a>
    </td>
   <td align="center">
      <a href="https://github.com/FelipeSalazar1">
        <img src="https://avatars.githubusercontent.com/u/91813889?v=4" width="100px;" alt="Foto do Felipe no GitHub"/><br>
        <sub>
          <b>Felipe</b>
        </sub>
      </a>
    </td>
   <td align="center">
      <a href="https://github.com/CodedByLucke">
        <img src="https://avatars.githubusercontent.com/u/145406645?v=4" width="100px;" alt="Foto do Lucas no GitHub"/><br>
        <sub>
          <b>Lucas</b>
        </sub>
      </a>
    </td>
  </tr>
</table>

## Agradecimentos

A equipe agradece ao Professor Airton Yassushiko Coppini pela oportunidade de aprender com este projeto, que foi muito significativo e interessante para o desenvolvimento profissional, e que ajudou a aprender mais sobre Edge Computing!
