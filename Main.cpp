#include <iostream>
#include "Matriz.h"

SEU CHUPADOR DE ROLA

using namespace std;

int main(){
	int opt;
	int i, j;
	int linha, coluna;
	cout << "Programa para realizar opera��o com matrizes";
	cout << endl<<"Qual opera��o deseja realizar??"<<endl;
	cout << "0 - Sair" << endl;
	cout << "1 - Soma"<<endl;
	cout << "2 - Subtra��o"<<endl;
	cout << "3 - Multiplica��o"<<endl;
	cout << "4 - Transposta"<<endl;
	cin >> opt;	

	while(opt){
		cout<<"Digite o n�mero de linhas e de colunas da primeira matriz: ";
		cin>>linha>>coluna;
		Matriz<int> *A = new Matriz<int>(linha, coluna);
		cout<<"Digite o n�mero de linhas e de colunas da segunda matriz: ";
		cin>>linha>>coluna;
		Matriz<int> *B = new Matriz<int>(linha, coluna);
		Matriz<int> *C = new Matriz<int>(); 
		
		int a;
		cout<<"Digite os valores da primeira matriz"<<endl;
		for (i = 0; i < A->getnl(); ++i){
			for (j = 0; j < A->getnc(); ++j){
				cin >> a;
				A->set(i, j, a);
			}
		}
		cout<<"Digite os valores da segunda matriz"<<endl;
		for (i = 0; i < B->getnl(); ++i){
			for (j = 0; j < B->getnc(); ++j){
				cin >> a;
				B->set(i, j, a);
			}
		}
		//Soma
		if (opt == 1){
			if ((A->getnl() == B->getnl()) && (A->getnc() == B->getnc())){
				*C = *A + *B;
				cout << endl;
				for (i = 0; i < C->getnl(); ++i){
					for (j = 0; j < C->getnc(); ++j){
						cout << C->get(i, j) << ' ';
					}
					cout << endl;
				}
			}
			else
				cout<< endl << "Matrizes n�o podem ser operadas" << endl;
		}
		
		//Subtra��o
		if (opt == 2){
			if ((A->getnl() == B->getnl()) && (A->getnc() == B->getnc())){
				*C = *A - *B;
				cout << endl;
				for (i = 0; i < C->getnl(); ++i){
					for (j = 0; j < C->getnc(); ++j){
						cout << C->get(i, j) << ' ';
					}
					cout << endl;
				}
			}
			else
				cout<< endl << "Matrizes n�o podem ser operadas" << endl;
		}
		
		//Multiplica��o
		if (opt == 3){
			if ((A->getnc() == B->getnl())){
				*C = *A * *B;
				cout << endl;
				for (i = 0; i < C->getnl(); ++i){
					for (j = 0; j < C->getnc(); ++j){
						cout << C->get(i, j) << ' ';
					}
					cout << endl;
				}
			}
			else
				cout << endl << "Matrizes n�o podem ser operadas" << endl;
		}		
	
		//Transposta
		if (opt == 4){
			cout << endl;
			cout << "A:" << endl;
			*C = *A / *B;
			for (i = 0; i < C->getnl(); ++i){
				for (j = 0; j < C->getnc(); ++j){
					cout << C->get(i, j) << ' ';
				}
				cout << endl;
			}
			cout << endl;
			cout << "B:" << endl;
			*C = *B / *A;
		
			for (i = 0; i < C->getnl(); ++i){
				for (j = 0; j < C->getnc(); ++j){
					cout << C->get(i, j) << ' ';
				}
				cout << endl;
			}
		}
		char aux;// variavel auxiliar para travar o programa
		cout << endl << "[PRESS ANY KEY TO CONTINUE]" << endl;
		cin.get(aux);
		cin.get(aux);
		//Nova chamada do menu
		cout << endl<<"Qual opera��o deseja realizar??"<<endl;
		cout << "0 - Sair" << endl;
		cout << "1 - Soma"<<endl;
		cout << "2 - Subtra��o"<<endl;
		cout << "3 - Multiplica��o"<<endl;
		cout << "4 - Transposta"<<endl;
		cin >> opt;
	}
	return 0;
}
