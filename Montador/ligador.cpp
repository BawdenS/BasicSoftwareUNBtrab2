#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


using namespace std;

///////////////////////////////////////////////////////////////////
//      Metodo que faz a ligacao de um unico arquivo .obj       //
/////////////////////////////////////////////////////////////////
void ligacaoSolo(char* arquivo){
    // todo - abrir um arquivo de texto para escrever
    // todo - se for 1 .obj, soh remover cabecalhos, copiar e colar e ta feito
    int i;
    bool comeca = false;
    string NomeArquivo = arquivo, Linha, Word;
    vector<string> Opcodes, Linhas;
    ifstream Leitura;

    // Checa se eh possivel abrir o arquivo
    Leitura.open(NomeArquivo.c_str());
    if (!Leitura.is_open())
    {
        cerr << "\nNao eh possivel abrir o arquivo" << endl;
    }
    else {
        cout << "\nArquivo aberto corretamente" << endl;

        // Coloca os opcodes no vector Unidade
        for(i = 0; i < 6; i++){
            Linhas.push_back("");
            getline(Leitura, Linhas.at(i));
        }
//        while (getline(Leitura, Linha)) {
//            istringstream iss(Linha);
        istringstream iss(Linhas.at(5));
        while (iss >> Word) {
            Opcodes.push_back(Word);
        }
//        }
        for (i = 0; i < Opcodes.size(); i++) {
            cout << Opcodes[i] << " ";
        }
        cout << endl;
    }
    Leitura.close();
};


////////////////////////////////////////////////////////////////
//      Metodo que faz a ligacao de dois arquivos .obj       //
//////////////////////////////////////////////////////////////
void ligacaoDupla(char* arquivo1, char* arquivo2){
    // todo - se nao for, arrumar .text e .data dos dois e somar enderecos com tamanhos
    int i, text1Size;
    bool finalText1 = false, finalText2 = false;
    string NomeArquivo = arquivo1, Linha, Word;
    vector<string> OpcodesText, OpcodesData, Linhas1, Linhas2;
    ifstream Leitura;

    // Checa se eh possivel abrir o arquivo1
    Leitura.open(NomeArquivo.c_str());
    if (!Leitura.is_open())
    {
        cerr << "\nNao eh possivel abrir o primeiro arquivo" << endl;
    }
    else {
        cout << "\nPrimeiro arquivo aberto corretamente" << endl;
        // Coloca os opcodes no vector Unidade
        for(i = 0; i < 6; i++){
            Linhas1.push_back("");
            getline(Leitura, Linhas1.at(i));
        }
//        while (getline(Leitura, Linha)) {
//            istringstream iss(Linha);
        istringstream iss(Linhas1.at(5));
        while (iss >> Word) {
            OpcodesText.push_back(Word);
        }
//        }

        // Print para verificar se a leitura está sendo feita de forma correta
        cout << "Opcodes text presentes no arquivo1: ";
        for (i = 0; i < OpcodesText.size(); i++) {
            cout << OpcodesText[i] << " ";
        }
        cout << endl;
    }
    Leitura.close();

    // Limpa o vetor com os opcodes
    text1Size = OpcodesText.size();
//    OpcodesText.clear();
    NomeArquivo = arquivo2;

    // Checa se eh possivel abrir o arquivo2
    Leitura.open(NomeArquivo.c_str());
    if (!Leitura.is_open())
    {
        cerr << "Nao eh possivel abrir o segundo arquivo" << endl;
    }
    else {
        cout << "\nSegundo arquivo aberto corretamente" << endl;

        // Coloca os opcodes no vector Unidade
        for(i = 0; i < 6; i++){
            Linhas2.push_back("");
            getline(Leitura, Linhas2.at(i));
        }
//        while (getline(Leitura, Linha)) {
//            istringstream iss(Linha);
            istringstream iss(Linhas2.at(5));
            while (iss >> Word) {
                OpcodesText.push_back(Word);
            }
//        }

        // Print para verificar se a leitura está sendo feita de forma correta
        cout << "Opcodes dos dois, mas sem a somados enderecos: ";
        for (i = 0; i < OpcodesText.size(); i++) {
            cout << OpcodesText[i] << " ";
        }
        cout << endl;
    }
    Leitura.close();

    cout << "Mapa de Bits do modulo 2: " << Linhas2.at(2) << endl;
};

int main(int argc, char* argv[]) {

    // Checa a quantidade de argumentos (arquivos .obj) passados ao executar o programa
    if(argc < 2)
        cout << "Erro! Arquivos .obj nao especificados!" << endl;

    // Apenas um arquivo
    else if(argc == 2)
    {
        cout << "Um arquivo .obj" << endl;
        // Chamar funcao de ligacao para um arquivo
        ligacaoSolo(argv[1]);
    }
    // Dois arquivos
    else if(argc == 3)
    {
        cout << "Dois arquivos .obj" << endl;
        // Chamar funcao de ligacao para os dois arquivos
        ligacaoDupla(argv[1], argv[2]);
    }

    return 0;
}