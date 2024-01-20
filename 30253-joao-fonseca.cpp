#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/*********************************
 Lista bidireccional com carros
 
 Fila (inserir e apagar � cauda)
 
**********************************/

// Cria o tipo de estrutura "carro"
struct carro {
	char matricula[81];// dados
	char marca[81];  //dados
	char modelo[81]; //dados
	char motor[81];  //dados
	int aluguer; //dados
	int cc;	  // dados
	
	carro *next;	  // pointer para o pr�ximo elemento da lista
	carro *prev;	  // pointer para o elemento anterior da lista
} *pHead=NULL, *pTail=NULL;
 // Cria as vari�veis pHead e pTail que s�o apontadorer para um "carro"


// Insere uma pessoa no in�cio da lista
void inserirTail(){
	carro *novo; // cria um pointer para o carro
	
	// Criar espa�o para um elemento (um carro)
	novo = (carro *) malloc( sizeof(carro) );
	
	// testar se conseguiu obter mem�ria
	if( !novo ){
		cout << "N�o consegui inserir\n\n";
		return;
	}

	// pedir o matricula, marca, modela, tipo de motor, cilindrada e aluguer (preencher os dados)
	cout << "Matricula: ";
	cin.clear(); cin.sync(); // com isto, podemos misturar cin com cin.getline()
	cin.getline(novo->matricula, sizeof(novo->matricula)); // para ler um array de char com espa�os
	cout << "Marca: ";
	cin.clear(); cin.sync();
	cin.getline(novo->marca, sizeof(novo->marca));
	cout << "Modelo: ";
	cin.clear(); cin.sync();
	cin.getline(novo->modelo, sizeof(novo->modelo));
	cout << "Tipo de Motor: ";
	cin.clear(); cin.sync();
	cin.getline(novo->motor, sizeof(novo->motor));
	cout << "Cilindrada: ";
	cin.clear(); cin.sync(); 
	cin >> novo->cc;
	cout << "Aluguer Diario: ";
	cin.clear(); cin.sync(); 
	cin >> novo->aluguer;
	
	// Inserir o elemento na lista (� cauda)
	novo->prev = pTail;
	novo->next = NULL;
	if (!pTail){
		pHead = novo;
	} else{
	

		pTail->next = novo;
	}
	pTail = novo;
}


// Apaga a pessoa do in�cio da lista
void apagarHead(){
	carro *pAux;
	
	// ver se a lista est� vazia
	if( !pTail ) return;
	
	pAux = pHead; // guardar apontador para o elemento a apagar
	
	if( pHead == pTail ){ // lista s� com 1 elemento
		pTail = NULL;
		pHead = NULL;
	}else{ //lista com v�rios elementos
		pHead->next->prev = NULL; //o 1� elemento tem sempre NULL no prev
		pHead = pHead->next;
	}
	free(pAux); // libertar mem�ria do "apagado"
}


// lista todas as pessoas (do in�cio para o fim)
void listar(){
	carro *pAux;
	
	if( !pHead ){
		cout << "***********\n"
			 << "Lista vazia\n"
			 << "***********\n\n";
		return;
	}
	
	cout << "*******************\n"
		 << "Listagem de pessoas\n"
		 << "*******************\n\n";
	
	pAux = pHead; //apontar para o in�cio
	
	while( pAux ){ // enquanto houver elementos...
		cout << "Matricula: "
			 << pAux->matricula
			 << endl;
		cout << "Marca: "
			 << pAux->marca
			 << endl
			 << endl;
		cout << "Modelo: "
			 << pAux->modelo
			 << endl
			 << endl;
		cout << "Cilindrada: "
			 << pAux->cc
			 << endl
			 << endl;
		cout << "Tipo de Motor: "
			 << pAux->motor
			 << endl
			 << endl;
		cout << "Aluguer diario: "
			 << pAux->aluguer
			 << endl
			 << endl;	 	 	 	 
		pAux = pAux->next; // passar ao pr�ximo
	}

	cout << "***************\n"
		 << "Fim da lista\n"
		 << "***************\n";
}


// lista todas as pessoas (do fim para o in�cio)
void listarInverso(){
	carro *pAux;
	
	if( !pTail ){
		cout << "***********\n"
			 << "Lista vazia\n"
			 << "***********\n\n";
		return;
	}
	
	cout << "*******************\n"
		 << "Lista de carros\n"
		 << "*******************\n\n";
	
	pAux = pTail; //apontar para o fim
	
	while( pAux ){ // enquanto houver elementos...
				cout << "Matricula: "
			 << pAux->matricula
			 << endl;
		cout << "Marca: "
			 << pAux->marca
			 << endl
			 << endl;
		cout << "Modelo: "
			 << pAux->modelo
			 << endl
			 << endl;
		cout << "Cilindrada: "
			 << pAux->cc
			 << endl
			 << endl;
		cout << "Tipo de Motor: "
			 << pAux->motor
			 << endl
			 << endl;
		cout << "Aluguer diario: "
			 << pAux->aluguer
			 << endl
			 << endl;
		pAux = pAux->prev; // passar ao anterior
	}

	cout << "***************\n"
		 << "Fim da lista\n"
		 << "***************\n";
}



 	
 	



int main(int argc, char** argv) {
	setlocale(LC_ALL,""); // para usar caracteres portugueses
	
	char op;
	
	// programa para manipular a fila
	
	do{

		cout << "\n************\n"
			 << "* 1- Inserir  *\n"
			 << "* 2- Apagar   *\n"
			 << "* 3- Listar   *\n"
			 << "* 4- Inverso  *\n"
			 << "* 5- Terminar"
			 << "**************\n"
			 << "Insira a sua escolha: ";
			 
		cin.clear(); cin.sync();
		cin >> op;
		
		switch(op){
			case '1':{
				inserirTail();
				break;
			}
			case '2':{
				apagarHead();
				break;
			}
			case '3':{
				listar();
				break;
			}
			case '4':{
				listarInverso();
				break;
			}
			
			
		}
		
	} while( op!='5' );
	
	cout << "\n\nBye bye\n";
	
	return 0;
}
