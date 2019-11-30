#ifndef TRABALHO1_TABELA_DE_SIMBOLOS_H
#define TRABALHO1_TABELA_DE_SIMBOLOS_H

#include <string>
#include <vector>

using namespace std;

class TabelaDeSimbolos {
public:
    TabelaDeSimbolos();
    ~TabelaDeSimbolos();
    void elementoDefinido(string nome, int posicao, string tipo);    // funcao que acrescenta um elemento na tabela de simbolos
    string procuraElemento(string nome, int posicao, string anterior, int linha);     // funcao que procura string atual na tabela de simbolos
    void procuraPendencias(string nome, int posicao, vector<string>* opcodes, int flagtipo, int tamanho, int linha);
	void RegistraExterno(string nome);
    void RegistraPublico(string nome);
    vector<bool> definido;
	vector<vector<int>> lista_de_pendencias;
    vector<string> ListaDeExterno;
    vector<string> ListaDePublico;
    vector<string> lista_de_nomes;
    vector<int> endereco;

private:
    
    
    
    
	vector<string> tipo;
};

#endif //TRABALHO1_TABELA_DE_SIMBOLOS_H