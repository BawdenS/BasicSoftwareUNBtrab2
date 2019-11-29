#include <iostream>
#include <string>

using namespace std;

void ligacao_solo(){
    // todo - abrir um arquivo de texto para escrever
    // todo - se for 1 .obj, soh remover cabecalhos, copiar e colar e ta feito
};

void ligacao_dupla(){
    // todo - se nao for, arrumar .text e .data dos dois e somar enderecos com tamanhos
};

int main(int argc, char* argv[]) {

    // Checa a quantidade de argumentos (arquivos .obj) passados ao executar o programa
    if(argc < 2)
        cout << "Erro! Arquivos .obj nao especificados!" << endl;

    // Apenas um arquivo
    else if(argc == 2)
    {
        cout << "That's the way!" << endl;
        // Chamar funcao de ligacao para um arquivo
        ligacao_solo();
    }
    // Dois arquivos
    else if(argc == 3)
    {
        cout << "I like it!" << endl;
        // Chamar funcao de ligacao para os dois arquivos
        ligacao_dupla();
    }

    return 0;
}