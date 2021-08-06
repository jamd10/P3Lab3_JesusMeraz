#include <iostream>
#include <time.h>
#include <string>
#include <stdbool.h>
#include <stdio.h>
using namespace std;
int menu();
int* ejercicio1(int*&, int);
bool ejercicio2(string, string);
void ejercicio3();
int main(int argc, char** argv) {
	int op = menu();
	while(op != 4){
		switch(op){
			case 1:{
				cout<<"Ingrese tamano del arreglo: "<<endl;
				int size;
				cin>>size;
				int* arreglo = new int[size];
				srand (time(NULL));
				for(int i = 0; i < size; i++){
					arreglo[i] = 1+rand()%7;	
				}
				cout<<"Arreglo aleatorio"<<endl;
				for(int i = 0; i < size; i++){
					cout<<	arreglo[i]<<", ";	
				}
				cout<<endl;
				cout<<"Arreglo ordenado"<<endl;
				for(int i = 0; i < size; i++){
					cout<<	ejercicio1(arreglo, size)[i]<<", ";	
				}
				cout<<endl;
				delete[]ejercicio1(arreglo, size);
				break;
			}
							
			case 2:{
				
				string palabra1, palabra2;
				cin.ignore();
				cout<<"Ingrese la primera palabra: "<<endl;
				getline(cin,palabra1);
				cout<<"Ingrese la segunda palabra: "<<endl;
				getline(cin,palabra2);
				// retorno
				bool flag = ejercicio2(palabra1, palabra2);
				if(flag == true){
					cout<<palabra1<<", "<<palabra2<<" = True"<<endl;
				}else{
					cout<<palabra1<<", "<<palabra2<<" = False"<<endl;
				}
				break;
			}
			case 3:{
			ejercicio3();
				break;
			}
			default: {
				cout<<"Opcion invalida"<< endl;
				menu();
				break;
			}
		}
		op = menu();
	}
	return 0;
}
int menu(){
	int opcion = 0;
	cout<<"********** Menu **********"<<endl;
	cout<<"* 1. Ejercicio 1         *"<<endl;
	cout<<"* 2. Ejercicio 2         *"<<endl;
	cout<<"* 3. Ejercicio 3         *"<<endl;
	cout<<"* 4. Salir               *"<<endl;
	cout<<"**************************"<<endl;
	cout<<"Elija una opcion: "<<endl;
	cin>> opcion;
	return opcion;
}
int* ejercicio1(int*& arreglo, int size){
	int contador = 0;
	int posMayor, posMenor;
	int* ordenado = new int[size];
	for(int i = 0; i < size; i++){
		if(arreglo[i] > arreglo[i+1]){
			ordenado[i] = contador++;
		}else if(arreglo[i] < arreglo[i+1]){
			ordenado[i+1] = contador++;
		}else{
			ordenado[i] = contador++;
			ordenado[i+1] = contador++;
		}	
		if(arreglo[i+1] == size){
			if(arreglo[i] > arreglo[0]){
				ordenado[i] = contador++;
			}else if(arreglo[i] < arreglo[0]){
				ordenado[0] = contador++;
			}else{
				ordenado[i] = contador++;
				ordenado[0] = contador++;
			}		
		}
		
	}
	return ordenado;
	}
bool ejercicio2(string palabra1, string palabra2){
	bool flag = false;
	int num = 0;
	for(int i = 0; i < palabra1.size(); i++){
		for(int j = 0; j < palabra2.size(); j++){
			if(palabra1[i] == palabra2[num]){
				flag = true;
				num++;
			}
		}
	}	
	return flag;
}
void ejercicio3(){
	cout<<"Ingrese tamano del arreglo: "<<endl;
	int size;
	cin>>size;
	while(size%2!=0){
		cout<<"El tamano debe de ser par, intente nuevamente: "<<endl;
		cin>>size;	
	}
	int* arreglo = new int[size];
	int* player1 = new int[size/2];
	int* player2 = new int[size/2];
	int* repetidos = new int[size];
	int* arregloUsado = new int[size];
	for(int i = 0; i < size; i++){
		repetidos[i] = -1;	
	}
	int suma1 = 0, suma2 = 0; 
	srand (time(NULL));
	for(int i = 0; i < size; i++){
		arreglo[i] = -50+rand()%50;	
	}
	for(int i = 0; i < size/2; i++){
		int num1, num2;
		//player 1
		cout<<"Jugador 1 ingrese un numero: "<<endl;
		cin>>num1;
		for(int j = 0; j < size; j++){
			while(repetidos[j] == num1){
				cout<<"Ese numero ya ha sido escojido, intente nuevamene: "<<endl;
				cin>>num1;
			}
		}
		repetidos[i] = num1;
		suma1 += arreglo[num1];
		player1[i] = arreglo[num1];
		cout<<"Jugador 1 escoje: "<<num1<<endl;
		cout<<"obtiene "<<arreglo[num1]<<endl;
	
		
		// player2
	
		cout<<"Jugador 2 ingrese un numero: "<<endl;
		cin>>num2;
		for(int j = 0; j <= size; j++){
			while(repetidos[j+1] == num2){
				cout<<"Ese numero ya ha sido escojido, intente nuevamene: "<<endl;
				cin>>num2;
			}
		}
		repetidos[i+1] = num2;
		suma2 += arreglo[num2];
		player2[i] = arreglo[num2];
		cout<<"Jugador 2 escoje: "<<num2<<endl;
		cout<<"obtiene "<<arreglo[num2]<<endl;
		
		// rondas de jugadores
		
		cout<<"Ronda "<< i+1 << " PTS J1: "<<suma1<<" <-> PTS J2: "<<suma2<<endl;
	}
	if(suma1 > suma2){
		cout<<"Jugador 1 es el ganador "<<endl;
	} else if(suma1 < suma2){
		cout<<"Jugador 2 es el ganador "<<endl;
	} else {
		cout<<"Jugador 1 y jugador 2 quedaron en empate "<<endl;
	}
	for(int i = 0; i < size/2; i++){
		arregloUsado[i] = player1[i];	
	}
	for(int i = size/2; i < size; i++){
		arregloUsado[i] = player2[i - (size/2)];	
	}
	cout<<"Arreglo usado"<<endl;
	for(int i = 0; i < size; i++){
		cout<<	arregloUsado[i]<<", ";	
	}
	delete[] arreglo;
	delete[] player1;
	delete[] player2;
	delete[] repetidos;
	delete[] arregloUsado;
	cout<<endl;
}