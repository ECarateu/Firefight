Skip to content
 
Search or jump to…

Pull requests
Issues
Marketplace
Explore
 
@ECarateu 
 The password you provided is weak and can be easily guessed. To increase your security, you must update your password. After September 1st, 2019 we will automatically reset your password. Change your password on the settings page.

Read our documentation on safer password practices.

Learn Git and GitHub without any code!
Using the Hello World guide, you’ll start a branch, write comments, and open a pull request.

 
0
1 2 calebeof/ThermoBeer
 Code  Issues 0  Pull requests 0  Projects 0  Wiki  Security  Insights
You’re editing a file in a project you don’t have write access to. Submitting a change to this file will write it to a new branch in your fork ECarateu/ThermoBeer, so you can send a pull request.
ThermoBeer
/
README.md
 

43
### Utilizando o software do ThermoBeer
44
#### Monitorando a temperatura 
45
​
46
![QTInicial](figuras/telainicialQT.PNG)
47
​
48
A tela de início da aplicação do projeto é bastante direta. Primeiro, o usuário deve conectar o seu cabo microUSB da ESP8266 com alguma entrada USB do seu computador. A seguir, deve ser selecionada a porta na qual a placa está conectada. Para que as informações sejam passadas, faz-se necessário ter uma velocidade específica (em bauds) para comunicação, sendo selecionado 115200 a padrão da placa. Haverá um texto exibindo se o programa conseguiu se conectar com a placa ou não, após clicar no botão de Conectar. Se conseguiu, a temperatura será passada instantaneamente. Se não foi possível, há a possibilidade de clicar no botão Reiniciar, no qual tentará a comunicação novamente. 
49
​
50
#### Cadastrando novas cervejas
51
![QTCadastro](figuras/cadastroQT.PNG)
52
​
53
Também há a possibilidade de cadastrar suas cervejas, para maior facilidade em selecioná-las posteriormente. Na aba de Cadastro, devem ser preenchidos o Nome, o Tipo, o Link da Receita (para consulta a posteriori), a Levedura da cerveja, da Quantidade Produzida e o Teor Alcóolico. Qualquer uma dessas informações não preenchidas, resultará em uma mensagem de aviso para serem informadas, ou seja, são obrigatórias. Basta, em seguida, clicar em Salvar. Ao clicar em Salvar, o usuário deve escolher onde quer salvar o seu arquivo de cervejas, podendo organizá-las em pastas de categorias depois.
54
​
55
#### Carregando cervejas salvas
56
![QTCarregar](figuras/carregarQT.png)
57
​
58
Na aba de Dados, há a possibilidade de consultar os arquivos das cervejas salvas e carregá-las para o programa, a fim de selecioná-las para verificar os limites corrigidos da levedura no site. Ao clicar em Mostrar, será enviada a informação diretamente ao [site](https://thermobeer.herokuapp.com), se houver conexão da ESP8266 com a internet, com as delimitações dos limites necessários para cada levedura. 
59
​
60
### Utilizando o site da ThermoBeer
61
​
62
#### Monitorando a temperatura com os limites
63
​
64
![Tela Inicial](figuras/telainicialWEB.PNG)
65
​
66
O [site](https://thermobeer.herokuapp.com) da ThermoBeer permite que o usuário tenha acesso remoto à aplicação, apenas sendo necessário conexão com a internet. Aqui, temos uma barra de temperatura do termômetro com os ajustes finos dos limites da levedura escolhida via software do computador, de maneira a mostrar para o usuário se ele deve ou não desligar o relé do refrigerador.
67
​
68
#### Alterando o estado do Relé
69
​
70
Também há as informações da conexão, da temperatura, da cerveja atual (escolhida previamente) e do estado do relé. Os botões de ligar e desligar permitem o controle do relé responsável pela refrigeração, de maneira a conseguir realizar o propósito de oferecer ao usuário um controle fora do ambiente do nosso circuito. 
71
​
72
​
73
### Informações técnicas
74
​
75
​
76
#### Materiais 
77
​
78
- [ESP8266](https://cdn-shop.adafruit.com/product-files/2471/0A-ESP8266__Datasheet__EN_v4.3.pdf)
79
- Sensor de Temperatura à Prova D'água [DS18B20](https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf)
80
 - [Módulo Relé](https://www.fecegypt.com/uploads/dataSheet/1480848003_2_channel_5v_10a_relay_module.pdf)
81
​
82
#### O Circuito
83
​
84
![circuito](figuras/circuito.jpg)
85
​
86
Utilizamos o sensor DS18B20 pois este é à prova d'água, facilitando o processo de captura das informações da temperatura da cerveja. Além disso, precisamos do módulo relé de 5V para acionar o refrigerador, a fim de permitir o controle da situação da fermentação pelo usuário. É notável aqui que a ESP8266 é fundamental para todo o processo de alimentação do circuito e da comunicação tanto com a página web quanto com o software para computador, visto que ela é quem passa e recebe as informações para o circuito, sendo o "cérebro" de tudo.
87
​
88
Também vale a pena levantar o ponto de que a ESP8266 precisa estar conectada à uma rede WiFi com internet para poder comunicar-se com a página web. Entretanto, a alternativa offline para este caso é apenas plugar o seu cabo microUSB em uma porta USB do computador, de maneira que o usuário possa obter as informações via serial pelo software. 
89
​
90
#### A Página Web
91
​
92
Esta página web está hospedada gratuitamente no Heroku, uma plataforma cloud que permite o deploy de aplicações para desenvolvedores. Aqui, foi utilizado HTML e CSS, para poder organizar o site, além de JavaScript e Python, para reagir à eventos e fazer a comunicação com o software para computador e para a ESP8266. É notável indicar a importância da biblioteca Flask feita pela comunidade do Python, que é bastante crítica para a realização da comunicação e o deploy do servidor. 
93
​
94
#### O Software para Desktop
95
​
96
Desenvolvemos um software para pc a fim do usuário ter controle da nossa aplicação mesmo sem acesso à internet. Aqui, foi utilizado a framework Qt junto com a IDE Qt Creator. A linguagem utilizada foi o C++ e ainda foi necessário a utilização de XML para editar a parte gráfica do programa. 
97
​
@ECarateu
Propose file change
Commit summary 
Update README.md
Optional extended description
Add an optional extended description…
 
© 2019 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
Pricing
API
Training
Blog
About
