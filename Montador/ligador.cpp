#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctype.h>

using namespace std;

///////////////////////////////////////////////////////////////////
//               Teste is_number                                 //
/////////////////////////////////////////////////////////////////
//bool is_number(const)



///////////////////////////////////////////////////////////////////
//      Metodo que faz a ligacao de um unico arquivo .obj       //
/////////////////////////////////////////////////////////////////
void ligacaoSolo(char* arquivo){
    ofstream saida;
    saida.open("ArquivoDeSaida.obj");
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
            saida << Opcodes[i] << " ";
        }
        //cout << endl;
    }

    saida.close();
    Leitura.close();
};


////////////////////////////////////////////////////////////////
//      Metodo que faz a ligacao de dois arquivos .obj       //
//////////////////////////////////////////////////////////////
void ligacaoDupla(char* arquivo1, char* arquivo2){
    ofstream saida;
    saida.open("ArquivoDeSaida.obj");
    // todo - se nao for, arrumar .text e .data dos dois e somar enderecos com tamanhos
    int i, text1Size, auxiliar;
    vector<int> subtrairposicao;
    string apoio;
    bool finalText1 = false, finalText2 = false;
    string NomeArquivo = arquivo1, Linha, Word;
    vector<string> OpcodesText, OpcodesData, Linhas1, Linhas2;
    ifstream Leitura;
    vector<string> arquivo1Nome, arquivo1Tamanho, arquivo1MapadeBits, arquivo1TD, arquivo1Pendencias;
    vector<string> arquivo2Nome, arquivo2Tamanho, arquivo2MapadeBits, arquivo2TD, arquivo2Pendencias;


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
        //Pega o Codigo OBJ
        istringstream iss(Linhas1.at(5));
        while (iss >> Word) {
            OpcodesText.push_back(Word);
        }
        //Nome do arquivo
        arquivo1Nome.push_back(Linhas1.at(0));
        cout << "Nome do arquivo1: "<< arquivo1Nome.at(0) << endl;
        //Tamanho do arquivo
        arquivo1Tamanho.push_back(Linhas1.at(1));
        cout << "Tamanho do arquivo1: "<< arquivo1Tamanho.at(0) << endl;
        
        //Mapa de Bits
        istringstream iss1(Linhas1.at(2));
        while (iss1 >> Word) {
            arquivo1MapadeBits.push_back(Word);
        }
        cout << "Mapa de Bits do arquivo1: ";
        for (i = 0; i < arquivo1MapadeBits.size(); i++) {
            cout << arquivo1MapadeBits.at(i) << " ";
        }
        cout << endl; 
        //Mapa de Publicos
        istringstream iss2(Linhas1.at(3));
        while (iss2 >> Word) {
            arquivo1TD.push_back(Word);
        }
        cout << "Tabela de Definicoes do arquivo1: ";
        for (i = 0; i < arquivo1TD.size(); i++) {
            cout << arquivo1TD.at(i) << " ";
        }
        cout << endl;

        //Pendencias do arquivo
        istringstream iss3(Linhas1.at(4));
        while (iss3 >> Word) {
            arquivo1Pendencias.push_back(Word);
        }
        cout << "Pendencias do arquivo1: ";
        for (i = 0; i < arquivo1Pendencias.size(); i++) {
            cout << arquivo1Pendencias.at(i) << " ";
        }
        cout << endl; 


        // Print para verificar se a leitura está sendo feita de forma correta
        cout << "Opcodes text presentes no arquivo1: ";
        for (i = 0; i < OpcodesText.size(); i++) {
            cout << OpcodesText[i] << " ";
        }
        //cout << endl;
    }
    

        //cout << endl;
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

        istringstream iss(Linhas2.at(5));
        while (iss >> Word) {
            OpcodesText.push_back(Word);
        }
//Nome do arquivo
        arquivo2Nome.push_back(Linhas2.at(0));
        cout << "Nome do arquivo2: "<< arquivo2Nome.at(0) << endl;
        //Tamanho do arquivo
        arquivo2Tamanho.push_back(Linhas2.at(1));
        cout << "Tamanho do arquivo2: "<< arquivo2Tamanho.at(0) << endl;
        
        //Mapa de Bits


        istringstream iss1(Linhas2.at(2));
        while (iss1 >> Word) {
            arquivo2MapadeBits.push_back(Word);
        }
        cout << "Mapa de Bits do arquivo2: ";
        for (i = 0; i < arquivo2MapadeBits.size(); i++) {
            cout << arquivo2MapadeBits.at(i) << " ";
        }
        cout << endl; 
        //Mapa de Publicos
        istringstream iss2(Linhas2.at(3));
        while (iss2 >> Word) {
            arquivo2TD.push_back(Word);
        }
        cout << "Tabela de simbolos do arquivo2: ";
        for (i = 0; i < arquivo2TD.size(); i++) {
            cout << arquivo2TD.at(i) << " ";
        }
        cout << endl;

        //Pendencias do arquivo
        istringstream iss3(Linhas2.at(4));
        while (iss3 >> Word) {
            arquivo2Pendencias.push_back(Word);
        }
        cout << "Pendencias do arquivo2: ";
        for (i = 0; i < arquivo2Pendencias.size(); i++) {
            cout << arquivo2Pendencias.at(i) << " ";
        }
        cout << endl; 

        //Tratamento do Segundo arquivo
        
        //Tratamento da tabela de definicoes
        cout << "Tabela de definicoes corrigida: ";
        for(i = 0;i < arquivo2TD.size(); i++){
            if((i%2) != 0){
                auxiliar = stoi(arquivo2TD.at(i));
                auxiliar += stoi(arquivo1Tamanho.at(0));
                arquivo2TD.at(i) = to_string(auxiliar);
            }
            cout << arquivo2TD.at(i) << " ";
        }
        cout << endl;
        cout << "Pendencias corrigidas: ";
        char* b;
        char c[10];
        for(i = 0;i < arquivo2Pendencias.size(); i++){
            strcpy(c, arquivo2Pendencias.at(i).c_str());
            b = c;
            //impossivel ter pendencias em 0
            //e atoi retorna 0 para letras

            if(isdigit(*b)){ 
                 auxiliar = stoi(arquivo2Pendencias.at(i));
                 auxiliar += stoi(arquivo1Tamanho.at(0));
                 subtrairposicao.push_back(auxiliar);
                 arquivo2Pendencias.at(i) = to_string(auxiliar);

            }
            
            cout << arquivo2Pendencias.at(i) << " ";
        }
        cout << endl;
        // cout << "Arquivo 2: "; 
        int j, flagTD;

        //ADCIONAR EM TODOS OS RELATIVOS E
        cout << "OPCODE DO 2: "; 
        j = 0;

        for(i = stoi(arquivo1Tamanho.at(0)); i < OpcodesText.size();i++){
             cout << OpcodesText.at(i) << " ";

             if(arquivo2MapadeBits.at(j) == "1"){
                
                OpcodesText.at(i) = to_string(stoi(OpcodesText.at(i)) + stoi(arquivo1Tamanho.at(0)));
                
             }
            j++;
        }
        cout << endl;
        //SUBTRAIR AONDE NAO PODIA ADICIONAR
        for(i = 0;i < subtrairposicao.size();i++){
            auxiliar = stoi(OpcodesText.at(subtrairposicao.at(i)));
            auxiliar = auxiliar - stoi(arquivo1Tamanho.at(0));
            OpcodesText.at(subtrairposicao.at(i)) = to_string(auxiliar);
        }
        //PENDENCIAS CRUZADAS  SENDO RESOLVIDAS
        
        //PENDENCIAS DO ARQUIVO 1
        flagTD = 0;
        for(i = 0;i < arquivo2TD.size();i++){
            for(j = 0;j < arquivo1Pendencias.size();j++){
                if(arquivo1Pendencias.at(j) == "-1"){
                    flagTD = 0;
                }

                if(flagTD == 1){
                    auxiliar = stoi(OpcodesText.at(stoi(arquivo1Pendencias.at(j))));
                    //Pega o NUMERO em i+1
                    auxiliar += stoi(arquivo2TD.at(i+1));
                    OpcodesText.at(stoi(arquivo1Pendencias.at(j))) =  to_string(auxiliar);

                }
                //se alguma pendencia for igual
                if(arquivo1Pendencias.at(j) == arquivo2TD.at(i)){
                    flagTD = 1;
                }
            //formato das pendencias
            //nome numero numero... numero -1
            }


        }
        //PENDENCIAS DO ARQUIVO 2        
        flagTD = 0;
        for(i = 0;i < arquivo1TD.size();i++){
            for(j = 0;j < arquivo2Pendencias.size();j++){
                if(arquivo2Pendencias.at(j) == "-1"){
                    flagTD = 0;
                }

                if(flagTD == 1){
                    auxiliar = stoi(OpcodesText.at(stoi(arquivo2Pendencias.at(j))));
                    //Pega o NUMERO em i+1
                    auxiliar += stoi(arquivo1TD.at(i+1));
                    OpcodesText.at(stoi(arquivo2Pendencias.at(j))) =  to_string(auxiliar);

                }
                //se alguma pendencia for igual
                if(arquivo2Pendencias.at(j) == arquivo1TD.at(i)){
                    flagTD = 1;
                }
            //formato das pendencias
            //nome numero numero... numero -1
            }
        }
        
        
        



        // Print para verificar se a leitura está sendo feita de forma correta
        cout << "Opcodes dos dois, mas sem a somados enderecos: ";
        for (i = 0; i < OpcodesText.size(); i++) {
            saida << OpcodesText[i] << " ";
        }
        cout << endl;
        




    }
    saida.close();
    Leitura.close();





















    //cout << "Mapa de Bits do modulo 2: " << Linhas2.at(2) << endl;
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