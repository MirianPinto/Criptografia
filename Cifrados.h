#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cifrados
{
public:
	Cifrados();
	Cifrados(string _Frase);
	~Cifrados();


	string C_Espartano(int diametro);
	string D_Espartano(int diametro);
	string C_Cesar(int desplazamientos, string direccion);
	string D_Cesar(int desplazamientos, string direccion);
	string C_Vigenere(string clave);
	string D_Vigenere(string clave);


private:
	string Frase;

};

