-Instalações necessárias no ambiente Linux:
    sudo apt update
    sudo apt upgrade
    sudo apt install g++ gdb
    sudo apt install make cmake
    sudo apt install flex
    sudo apt install bison

-Extensões necessárias no VsCode:
    Pacote C/C++ - Microsoft
    CMake - twxs
    Cmake Tools - Microsoft
    Makefile Tools - Microsoft
    Yash - daohong emilio

-Compilar projeto:
    ctrl + shift + b

-Execução dos testes: 
    ./syntAnalyzer < Tests/test.txt
    ./syntAnalyzer < Tests/test1Primitiva.txt
    ./syntAnalyzer < Tests/test2Definida.txt
    ./syntAnalyzer < Tests/test3Axioma.txt
    ./syntAnalyzer < Tests/test4Aninhada.txt
    ./syntAnalyzer < Tests/test5Enumerada.txt
    ./syntAnalyzer < Tests/test6Coberta.txt
    ./syntAnalyzer < Tests/testeDados.txt

-Observação:
    Ao executar o projeto com os comandos acima, caso apareça no terminal o seguinte erro:
    bash: ./syntAnalyzer: Permissão negada
    
    Execute o comando abaixo no terminal e depois tente executar o projeto novamente:
    chmod +x syntAnalyzer

-Saída do terminal:
    Os 6 tipos de classes estão organizadas da seguinte maneira:
    Classe primitiva: Número 1 e cor Verde
    Classe Definida: Número 2 e cor Azul
    Classe com axioma de fechamento: Número 3 e cor Amarelo
    Classe com descrições aninhadas: Número 4 e cor Magenta
    Classe Enumerada: Número 5 e cor Ciano
    Classe Coberta: Número 6 e cor Roxo
    Erros são de cor Vermelho
    Alertas são de cor Laranja