<h1><b>Instruções para execução do Projeto</b></h1>
<h3><b>Obs.: Informações sobre a lógica do projeto estão no arquivo Observações.txt</b></h3><hr/>

<b>-Instalações necessárias no ambiente Linux:</b>

    sudo apt update
    sudo apt upgrade
    sudo apt install g++ gdb
    sudo apt install make cmake
    sudo apt install flex
    sudo apt install bison

<b>-Extensões necessárias no VsCode:</b>
    <br/>Pacote C/C++ - Microsoft<br/>
    CMake - twxs<br/>
    Cmake Tools - Microsoft<br/>
    Makefile Tools - Microsoft<br/>
    Yash - daohong emilio<hr/>

<b>-Compilar projeto:</b>

    ctrl + shift + b

<b>-Execução dos testes:</b>

    ./syntAnalyzer < Tests/test.txt
    ./syntAnalyzer < Tests/test1Primitiva.txt
    ./syntAnalyzer < Tests/test2Definida.txt
    ./syntAnalyzer < Tests/test3Axioma.txt
    ./syntAnalyzer < Tests/test4Aninhada.txt
    ./syntAnalyzer < Tests/test5Enumerada.txt
    ./syntAnalyzer < Tests/test6Coberta.txt
    ./syntAnalyzer < Tests/testeDados.txt

<hr/> <b>-Observação:</b>
    Ao executar o projeto com os comandos acima, caso apareça no terminal o seguinte erro:<br/> <pre>"bash: ./syntAnalyzer: Permissão negada"</pre>
    Execute o comando abaixo no terminal e depois execute o projeto novamente:

    chmod +x syntAnalyzer

<hr/> <b>-Saída do terminal:<br/></b>
    Os 6 tipos de classes estão organizadas da seguinte maneira:<br/>
    • Classe primitiva: Número 1 e cor <span style="color:green">Verde</span><br/>
    • Classe Definida: Número 2 e cor <span style="color:blue">Azul</span><br/>
    • Classe com axioma de fechamento: Número 3 e cor <span style="color:yellow">Amarelo</span><br/>
    • Classe com descrições aninhadas: Número 4 e cor <span style="color:magenta">Magenta</span><br/>
    • Classe Enumerada: Número 5 e cor <span style="color:cyan">Ciano</span><br/>
    • Classe Coberta: Número 6 e cor <span style="color:purple">Roxo</span><br/><br/>
    • Tipos de Propriedades são de cor <span style="color:white">Branco</span><br/>
    • Erros são de cor <span style="color:red">Vermelho</span><br/>
    • Alertas são de cor <span style="color:orange">Laranja</span><hr/>