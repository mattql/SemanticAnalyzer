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

<hr/> <b>-Observações:</b>
    Ao executar o projeto com os comandos acima, caso apareça no terminal o seguinte erro:<br/> <pre>"bash: ./syntAnalyzer: Permissão negada"</pre>
    Execute o comando abaixo no terminal e depois execute o projeto novamente:
    <pre>chmod +x syntAnalyzer</pre><hr/>
    Ao executar no WSL, caso a saida do terminal mostre várias linhas de: "é um token inválido!" como na imagem abaixo:<br/>
    (A imagem é referente ao trabalho do Analisador Sintático mas o erro é o mesmo)
    <img src="erro.png">
    Faça os passos abaixo para corrigir:<br/>
    (O erro é um provável bug do WSL e não um problema do projeto) 
    
    1. Exclua a pasta do projeto
    2. Execute o comando no terminal do GIT, GIT Bash:

        git config --global core.autocrlf false

    3. Clone o projeto novamente, compile e execute


<hr/>Caso apareça o seguinte erro no terminal:

    "./syntAnalyzer: /lib/x86_64-linux-gnu/libstdc++.so.6: version `GLIBCXX_3.4.32' not found (required by ./syntAnalyzer)"

Execute os comandos abaixo no terminal e teste a execução novamente:

    sudo add-apt-repository ppa:ubuntu-toolchain-r/test
    sudo apt-get update
    sudo apt-get install --only-upgrade libstdc++6

<hr/> <b>-Saída do terminal:<br/></b>
    Os 6 tipos de classes estão organizadas da seguinte maneira:<br/>
    • Classe primitiva: Número 1 e cor <span style="color:#00FF00">Verde</span><br/>
    • Classe Definida: Número 2 e cor <span style="color:#0000FF">Azul</span><br/>
    • Classe com axioma de fechamento: Número 3 e cor <span style="color:#FFFF00">Amarelo</span><br/>
    • Classe com descrições aninhadas: Número 4 e cor <span style="color:#FF00FF">Magenta</span><br/>
    • Classe Enumerada: Número 5 e cor <span style="color:#00FFFF">Ciano</span><br/>
    • Classe Coberta: Número 6 e cor <span style="color:#8D008D">Roxo</span><br/><br/>
    • Tipos de Propriedades são de cor <span style="color:#FFFFFF">Branco</span><br/>
    • Erros são de cor <span style="color:#FF0000">Vermelho</span><br/>
    • Alertas são de cor <span style="color:#FFA500">Laranja</span><hr/>