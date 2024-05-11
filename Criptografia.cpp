#include <iostream>
#include <string>
#include "Cifrados.h"
using namespace std;

int main()
{
	int opcion = 0;
	string Frase = "";
	string Frase_Cifrada = "";

	int cifrado = 0;

	Cifrados* cifrados =  new Cifrados();
	//Cifrado Cesar
	int desplazamientos = 0;
	string direccion = "";


	//Cifrado Vigenere
	string clave = "";

	//Cifrado Espartano
	int diametro = 0;
	
	do 
	{
		
		if (opcion == 0)
		{
			cout << "\n\n**** Menu ****\n\n";
			if(Frase == ""){
				cout << "Ingresa la frase que quieres cifrar: ";
				getline(cin ,Frase);

				cifrados = new Cifrados(Frase);
			}
			
			cout << "\nTu frase a cifrar es: " << Frase << "\n";
			cout << "\nQue metodo de cifrado deseas usar: \n";
			cout << " 1 - Cifrado Espartano\n";
			cout << " 2 - Cifrado Cesar\n";
			cout << " 3 - Cifrado Vigenere\n";
			cout << " 4 - Cambiar la frase a cifrar\n";
			cout << " 5 - Salir\n";
			cout << "Ingresa el numero de opcion que quieres realizar: ";
			cin >> opcion;

		}

		if (opcion == 1) 
		{
			cout << "\n **** Cifrado Espartano **** \n";
			cout << "Ingrese el diametro: ";
			cin >> diametro;

			Frase_Cifrada = cifrados->C_Espartano(diametro);
			Frase = Frase_Cifrada;
			opcion = 6;
			cifrado = 1;
		}
		
		if (opcion == 2) 
		{
			cout << "\n **** Cifrado Cesar **** \n";
			cout << "Ingrese la cantidad de desplazamientos(1-26): ";
			cin >> desplazamientos;
			cout << "\nIngrese la direccion de los desplazamientos(derecha o izquierdda): ";
			cin >> direccion;

			

			Frase_Cifrada = cifrados->C_Cesar(desplazamientos, direccion);
			Frase = Frase_Cifrada;
			opcion = 6;
			cifrado = 2;

		}

		if (opcion == 3) 
		{
			cout << "\n**** Cifrado Videnere ****\n";
			cout << "!!No debe contener espacios ni ser mayor que la frase a cifrar!!\n";
			cout << "Ingrese la clave(): ";
			cin >> clave;

			if (clave.size() > Frase.size()) 
			{
				cout << "\nLa clave debe ser mas pequeña que la frase a cifrar \n";
				cout << "Ingrese la clave: ";
				cin >> clave;
			}

			Frase_Cifrada = cifrados->C_Vigenere(clave);
			Frase = Frase_Cifrada;
			opcion = 6;
			cifrado = 3;
		}

		if(opcion == 4)
		{
			
			cout << "\nIngresa la nueva frase que quieres cifrar: ";
			cin.ignore();
			getline(cin, Frase);

			
			cifrados = new Cifrados(Frase);
			opcion = 0;
		}

		if (opcion == 6) 
		{
			cout << "\n Tu frase cifrada es: " << Frase_Cifrada << "\n";
			
			cout << "Qué deseas hacer: \n";
			cout << "7 - Descifrar tu frase\n";
			cout << "8 - Cifrar una nueva frase\n";
			cout << "5 - Salir\n";
			cout << "Ingresa el numero de opcion que quieres realizar: ";
			cin >> opcion;
		}

		if (opcion == 7)
		{
			if (cifrado == 1)
			{
				Frase = cifrados->D_Espartano(diametro);
				cout << "\nTu frase era: " << Frase << "\n";
				
			}
			else if (cifrado == 2)
			{
				Frase = cifrados->D_Cesar(desplazamientos, direccion);
				cout<< "\nTu frase era: " << Frase << "\n";
				
			}
			else if (cifrado == 3) 
			{
				Frase = cifrados->D_Vigenere(clave);
				cout << "\nTu frase era: " << Frase << "\n";
				
			}

			opcion = 0;


		}

		if (opcion == 8) 
		{
			Frase = "";
			Frase_Cifrada = "";
			desplazamientos = 0;
			direccion = "";
			cifrado = 0;
			clave = "";
			opcion = 0;
			diametro = 0;
		}


	} while (opcion != 5);
}