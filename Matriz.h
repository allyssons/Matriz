#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>

COMEDOR DE PIROCA SAFADO
using namespace std;

//Classe da matriz.
template <typename T> class Matriz{
private:
	int nl, nc;
	T **M;
public:
   Matriz():nl(0), nc(0), M(NULL){};
	
	Matriz(int l, int c):nl(l), nc(c){
		M = new T*[nl];
		for (int i = 0; i < nl; ++i){
			M[i] = new T[nc];
			for (int j = 0; j < nc; ++j) M[i][j] = 0;
		}			
	}
	
   ~Matriz();
	
	int getnl();
	int getnc();
	void set(int i, int j, const T &val);
	T get(int i, int j);
	
	Matriz<T>& operator+(Matriz<T> &B);
	Matriz<T>& operator-(Matriz<T> &B);
	Matriz<T>& operator*(Matriz<T> &B);
	Matriz<T>& operator/(Matriz<T> &B);
};

//D
template <typename T> Matriz<T>::~Matriz(){
	for (int i = 0; i < nl; ++i) delete[]M[i];
	delete M;
	M = NULL;
}

template <typename T> int Matriz<T>::getnl(){
	return nl;
}

template <typename T> int Matriz<T>::getnc(){
	return nc;
}

template <typename T> void Matriz<T>::set(int i, int j, const T &val){
	M[i][j] = val;
}

template <typename T> T Matriz<T>::get(int i, int j){
	return (M[i][j]);
}

//Sobrecarga de operador mais.
template <typename T> Matriz<T>& Matriz<T>::operator+(Matriz<T> &B){
	Matriz<int> *temp = new Matriz<int>(getnl(), getnc());
	
	for (int i = 0; i < getnl(); ++i){
		for (int j = 0; j < getnc(); ++j){
			temp->set(i, j, get(i, j) + B.get(i, j));
		}
	}
	
	return *temp;
}


// Sobrecarga de operador menos.
template <typename T> Matriz<T>& Matriz<T>::operator-(Matriz<T> &B){
	Matriz<int> *temp = new Matriz<int>(getnl(), getnc());
	
	for (int i = 0; i < getnl(); ++i){
		for (int j = 0; j < getnc(); ++j){
			temp->set(i, j, get(i, j) - B.get(i, j));
		}
	}
	
	return *temp;
}

// Sobrecarga de operador vezes.
template <typename T> Matriz<T>& Matriz<T>::operator*(Matriz<T> &B){

	int  auxresul=0;
	Matriz<int> *temp = new Matriz<int>(getnl(), B.getnc());
	for (int i = 0; i < getnl(); ++i){
		for (int j = 0; j < B.getnc(); ++j){
			for (int v = 0; v < getnc(); ++v){
				auxresul += (get(i, v) * B.get(v, j));
			}
		temp -> set(i, j, auxresul);
		auxresul = 0;
		}
	}
	return *temp;
}

// Sobrecarga de operador transposta.
template <typename T> Matriz<T>& Matriz<T>::operator/(Matriz<T> &B){
	Matriz<int> *temp = new Matriz<int>(getnc(), getnl());
		for (int i = 0; i < getnl(); i++){
			for(int j = 0; j < getnc(); j++){
					temp->set(j, i, get(i, j));
			}
		}
	return *temp;
}

#endif

