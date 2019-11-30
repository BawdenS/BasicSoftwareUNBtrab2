#include "TabelaDeSimbolos.h"
#include <iostream>
/**************
 * Construtor *
 *************/
TabelaDeSimbolos::TabelaDeSimbolos() {
}


/**************
 * Destrutor *
 *************/
TabelaDeSimbolos::~TabelaDeSimbolos() {
}

/***********************************************************
 * Funcao que Registra Externo *
 **********************************************************/
void TabelaDeSimbolos::RegistraExterno(string nome){
	this->ListaDeExterno.push_back(nome);

}
/***********************************************************
 * Funcao que Registra Publico *
 **********************************************************/
void TabelaDeSimbolos::RegistraPublico(string nome){
	this->ListaDePublico.push_back(nome);
}


/***********************************************************
 * Funcao que acrescenta um elemento na tabela de simbolos *
 **********************************************************/
void TabelaDeSimbolos::elementoDefinido(string nome, int posicao, string tipo) {
    vector<int> pendencia;

    pendencia.push_back(-1);
    this->lista_de_nomes.push_back(nome);
    this->endereco.push_back(posicao);
    this->definido.push_back(true);
    this->lista_de_pendencias.push_back(pendencia);
	this->tipo.push_back(tipo);
}


/*********************************************************
 * Funcao que procura string atual na tabela de simbolos *
 ********************************************************/
string TabelaDeSimbolos::procuraElemento(string nome, int posicao, string anterior, int linha) {
    int i, numero = 0;
    bool igual = false;

    for (i=0;i < this->lista_de_nomes.size(); i++)
    {
        if (nome == this->lista_de_nomes.at(i)) {
			igual = true;
            numero = i;     // posicao da lista
        }
    }
    if (igual == true) {
		if (this->definido.at(numero) == true) {
/*			if (anterior == "INPUT" && this->tipo.at(numero) == "CONST") {
				cout << "ERRO SEMANTICO LINHA : " << linha  << endl;
			}
			if (anterior == "ADD" && this->tipo.at(numero) == "ROTULO") {
				cout << "ERRO SEMANTICO LINHA : " << linha  << endl;
			}
			if (anterior == "SUB" && this->tipo.at(numero) == "ROTULO") {
				cout << "ERRO SEMANTICO LINHA : " << linha << endl;
			}
			if (anterior == "DIV" && this->tipo.at(numero) == "ROTULO") {
				cout << "ERRO SEMANTICO LINHA : " << linha << endl;
			}
			if (anterior == "MULT" && this->tipo.at(numero) == "ROTULO") {
				cout << "ERRO SEMANTICO LINHA : " << linha << endl;
			}
			if (anterior == "COPY" && this->tipo.at(numero) == "ROTULO") {
				cout << "ERRO SEMANTICO LINHA : " << linha << endl;
			}
			if (anterior == "LOAD" && this->tipo.at(numero) == "ROTULO") {
				cout << "ERRO SEMANTICO LINHA : " << linha << endl;
			}
			if (anterior == "STORE" && this->tipo.at(numero) == "ROTULO") {
				cout << "ERRO SEMANTICO LINHA : " << linha << endl;
			}
			if (anterior == "INPUT" && this->tipo.at(numero) == "ROTULO") {
				cout << "ERRO SEMANTICO LINHA : " << linha << endl;
			}
			if (anterior == "OUTPUT" && this->tipo.at(numero) == "ROTULO") {
				cout << "ERRO SEMANTICO LINHA : " << linha << endl;
			}
			if (anterior == "STORE" && this->tipo.at(numero) == "CONST") {
				cout << "ERRO SEMANTICO LINHA : "<< linha <<  " TENTATIVA DE ALTERAR VALOR CONST" << endl;
			}
			if (anterior == "JMP" && this->tipo.at(numero) != "ROTULO") {
				cout << "ERRO SEMANTICO LINHA : " << linha << "  USO DE JMP ERRADO" << endl;
			}
			if (anterior == "JMPN" && this->tipo.at(numero) != "ROTULO") {
				cout << "ERRO SEMANTICO LINHA : " << linha << " USO DE JMP ERRADO" << endl;
			}
			if (anterior == "JMPP" && this->tipo.at(numero) != "ROTULO") {
				cout << "ERRO SEMANTICO LINHA : " << linha << " USO DE JMP ERRADO" << endl;
			}
			if (anterior == "JMPZ" && this->tipo.at(numero) != "ROTULO") {
				cout << "ERRO SEMANTICO LINHA : " << linha << " USO DE JMP ERRADO" << endl;
			}
*/			return to_string(this->endereco.at(numero));
		}

		else {
			this->lista_de_pendencias.at(numero).push_back(posicao);
			return "0";
		}
    }
    else {
		vector<int> pendencias;
		pendencias.push_back(posicao);
		this->lista_de_nomes.push_back(nome);
		this->lista_de_pendencias.push_back(pendencias);
		this->endereco.push_back(0);
		this->definido.push_back(false);
		return "0";
    }
}


/*************************************************************
 * Funcao que procura alguma pendencia de endereco no codigo *
 ************************************************************/
void TabelaDeSimbolos::procuraPendencias(string nome, int posicao, vector<string>* opcodes, int flagtipos, int tamanho, int linha) {
    int i, numero = 0, auxint = 0, flag = 0;
    bool igual = false;
	string aux;
	//traduz a flag para um tipo
	if (flagtipos == 0) {
		aux = "SPACE";
	}
	else if (flagtipos == 1) {
		aux = "CONST";
	}
	else if (flagtipos == 2) {
		aux = "ROTULO";
	}

    for (i = 0; i < this->lista_de_nomes.size(); i++)
    {
        if (nome == this->lista_de_nomes.at(i)) {
            igual = true;
            numero = i; // salva posicao da lista
        }
    }
    if (igual == true) {
		if (this->definido.at(numero) == true) {
//			cout << "Erro semantico linha: " << linha << endl;
		}
		else {
			flag = 1;
			while (!this->lista_de_pendencias.at(numero).empty()) {
				this->endereco.at(numero) = posicao;
				this->definido.at(numero) = true;
				auxint = stoi(opcodes->at(this->lista_de_pendencias.at(numero).back()));

				if (auxint > tamanho) {
//					cout << "Erro semantico linha:  " << this->lista_de_pendencias.at(numero).back() / 2 << "  ACESSANDO O QUE NAO PODE!!" << endl;
				}

				auxint = stoi(opcodes->at(this->lista_de_pendencias.at(numero).back() - 1));

				// Casos em q aux = "CONST"
				if (auxint == 12 && aux == "CONST") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1 << endl;
				}
				if (auxint == 11 && aux == "CONST") {
					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1 << endl;
				}
				if (auxint == 0 && aux == "CONST") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1 << endl;
				}

                // Casos em q aux = "ROTULO"
				if (auxint == 1 && aux == "ROTULO") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1 << endl;
				}
				if (auxint == 2 && aux == "ROTULO") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1 << endl;
				}
				if (auxint == 3 && aux == "ROTULO") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1 << endl;
				}
				if (auxint == 4 && aux == "ROTULO") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1 << endl;
				}
				if (auxint == 9 && aux == "ROTULO") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1 << endl;
				}
				if (auxint == 10 && aux == "ROTULO") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1 << endl;
				}
				if (auxint == 11 && aux == "ROTULO") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1 << endl;
				}
				if (auxint == 12 && aux == "ROTULO") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1 << endl;
				}
				if (auxint == 13 && aux == "ROTULO") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1 << endl;
				}
				if (auxint == 5 && aux != "ROTULO") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1<< endl;
				}
				if (auxint == 6 && aux != "ROTULO") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1<< endl;
				}
				if (auxint == 7 && aux != "ROTULO") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1<< endl;
				}
				if (auxint == 8 && aux != "ROTULO") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1<< endl;
				}
//				if (auxint == 11 && aux == "CONST") {
//					cout << "Erro semantico linha: " << this->lista_de_pendencias.at(numero).back() / 2 + 1 << endl;
//				}

                auxint = stoi(opcodes->at(this->lista_de_pendencias.at(numero).back()));
                opcodes->at(this->lista_de_pendencias.at(numero).back()) = to_string(posicao + auxint);
				this->lista_de_pendencias.at(numero).pop_back();
			}
		}
    }


    //Adciona novo elemento
	if(flag == 1){
	this->lista_de_nomes.erase(this->lista_de_nomes.begin() + numero);
	this->endereco.erase(this->endereco.begin() + numero);
    this->definido.erase(this->definido.begin() + numero);
    this->lista_de_pendencias.erase(this->lista_de_pendencias.begin() + numero);
	//this->tipo.erase(this->tipo.begin() + numero);
	}
	
    
	this->elementoDefinido(nome, posicao, aux);




}