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
    int i;//, Acumulador = 0;
    string NomeArquivo = arquivo, Linha, Word;
//    vector<int> Unidade;
    vector<string> Opcodes;
    ifstream Leitura;

    // Checa se eh possivel abrir o arquivo
    Leitura.open(NomeArquivo.c_str());
    if (!Leitura.is_open())
    {
        cerr << " Nao eh possivel abrir arquivo" << endl;
    }
    else {
        // Coloca os opcodes no vector Unidade
        while (getline(Leitura, Linha)) {
            istringstream iss(Linha);
            while (iss >> Word) {
//                Unidade.push_back(stoi(Word));
                Opcodes.push_back(Word);
            }
        }
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
    int i;//, Acumulador = 0;
    string NomeArquivo = arquivo1, Linha, Word;
//    vector<int> Unidade;
    vector<string> Opcodes;
    ifstream Leitura;

    // Checa se eh possivel abrir o arquivo1
    Leitura.open(NomeArquivo.c_str());
    if (!Leitura.is_open())
    {
        cerr << " Nao eh possivel abrir arquivo1" << endl;
    }
    else {
        // Coloca os opcodes no vector Unidade
        while (getline(Leitura, Linha)) {
            istringstream iss(Linha);
            while (iss >> Word) {
//                Unidade.push_back(stoi(Word));
                Opcodes.push_back(Word);
            }
        }
        for (i = 0; i < Opcodes.size(); i++) {
            cout << Opcodes[i] << " ";
        }
        cout << endl;
    }
    Leitura.close();

    // Limpa o vetor com os opcodes
    Opcodes.clear();
    NomeArquivo = arquivo2;

    // Checa se eh possivel abrir o arquivo2
    Leitura.open(NomeArquivo.c_str());
    if (!Leitura.is_open())
    {
        cerr << " Nao eh possivel abrir arquivo1" << endl;
    }
    else {
        // Coloca os opcodes no vector Unidade
        while (getline(Leitura, Linha)) {
            istringstream iss(Linha);
            while (iss >> Word) {
//                Unidade.push_back(stoi(Word));
                Opcodes.push_back(Word);
            }
        }
        for (i = 0; i < Opcodes.size(); i++) {
            cout << Opcodes[i] << " ";
        }
        cout << endl;
    }
    Leitura.close();
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