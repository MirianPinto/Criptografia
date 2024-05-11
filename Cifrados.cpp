#include "Cifrados.h"

Cifrados::Cifrados()
{
	Frase = "";
}

Cifrados::Cifrados(string _Frase)
{
	for (char& c : _Frase) {
		c = toupper(c);
	}

	Frase = _Frase;
}

string Cifrados::C_Espartano(int diametro)
{
	std::string cifrado;
	int longitud = Frase.length();
	int columnas = (longitud + diametro - 1) / diametro; // Calculamos el número de columnas

	// Creamos una matriz para almacenar el mensaje cifrado
	char** matriz = new char* [diametro]; // Aquí 3 es el número de filas

	// Asignación de punteros a las filas de la matriz
	for (int i = 0; i < diametro; ++i) {
		matriz[i] = new char[columnas]; // Aquí 3 es el número de columnas
	}

	// Llenamos la matriz con los caracteres del mensaje
	int k = 0;
	for (int i = 0; i < columnas; ++i) {
		for (int j = 0; j < diametro; ++j) {
			if (k < longitud) {
				matriz[j][i] = Frase[k];
				++k;
			}
			else {
				matriz[j][i] = ' '; // Rellenamos con espacios si no hay más caracteres
			}
		}
	}

	for (int i = 0; i < diametro; ++i) {
		for (int j = 0; j < columnas; ++j) {
			
			cifrado += matriz[i][j];
			
			
		}
	}

	Frase = cifrado;
	return cifrado;

}

string Cifrados::D_Espartano(int diametro)
{
	int longitud = Frase.length();
	int columnas = (longitud + diametro - 1) / diametro;

	char** matriz = new char* [diametro]; // Aquí 3 es el número de filas

	// Asignación de punteros a las filas de la matriz
	for (int i = 0; i < diametro; ++i) {
		matriz[i] = new char[columnas]; // Aquí 3 es el número de columnas
	}

	// Llenamos la matriz con los caracteres del mensaje cifrado
	int k = 0;
	for (int i = 0; i < diametro; ++i) {
		for (int j = 0; j < columnas; ++j) {
			matriz[i][j] = Frase[k];
			++k;
		}
	}

	std::string descifrado;
	for (int i = 0; i < columnas; ++i) {
		for (int j = 0; j < diametro; ++j) {
			if (matriz[j][i] != ' ') 
			{
				descifrado += matriz[j][i];
			}
			
		}
	}

	Frase = descifrado;
	return descifrado;
}

string Cifrados::C_Cesar(int desplazamientos, string direccion)
{

	string cifraa = "";
	for (char& c : direccion) {
		c = toupper(c);
	}

	if (direccion == "DERECHA") 
	{
		
		for (char letra : Frase)
		{
			
			if ((letra + desplazamientos) > 90) 
			{
				letra = (letra + desplazamientos) - 26;
			}
			else 
			{
				letra = (letra + desplazamientos);
			}

			cifraa = cifraa + letra;
		}


	}
	else if(direccion == "IZQUIERDA")
	{
		
		for (char letra : Frase)
		{
			
			if ((letra - desplazamientos) < 65)
			{
				letra = (letra - desplazamientos) + 26;
			}
			else
			{
				letra = (letra - desplazamientos);
			}
			
			cifraa = cifraa + letra;
		}
	}


	Frase = cifraa;

	return cifraa;
}

string Cifrados::D_Cesar(int desplazamientos, string direccion)
{
	string cifraa = "";
	for (char& c : direccion) {
		c = toupper(c);
	}
	if (direccion == "DERECHA")
	{
	
		for (char letra : Frase)
		{

			if ((letra - desplazamientos) < 65)
			{
				letra = (letra - desplazamientos) + 26;
			}
			else
			{
				letra = (letra - desplazamientos);
			}

			cifraa = cifraa + letra;
		}
	}
	else if (direccion == "IZQUIERDA")
	{
		
		for (char letra : Frase)
		{
			if ((letra + desplazamientos) > 90)
			{
				letra = (letra + desplazamientos) - 26;
			}
			else
			{
				letra = (letra + desplazamientos);
			}

			cifraa = cifraa + letra;
		}
	}
	Frase = cifraa;
	return cifraa;
}

string Cifrados::C_Vigenere(string clave)
{
	string cifrado = "";
	int counter = 0;
	int size = clave.size();

	for (char& c : clave) {
		c = toupper(c);
	}

	for (char letra : Frase)
	{
		if (counter < size)
		{
			if (letra == ' ')
			{
				
			}
			else if (((letra - 64) + (clave[counter] - 64)) > 26)
			{
				letra = (((letra - 64) + (clave[counter] - 64)) - 26) + 64;
				counter++;
				cifrado = cifrado + letra;
			}
			else
			{
				letra = ((letra - 64) + (clave[counter] - 64)) + 64;
				counter++;
				cifrado = cifrado + letra;
			}

		}
		else
		{
			counter = 0;
			if (letra == ' ')
			{

			}
			else if (((letra - 64) + (clave[counter] - 64)) > 26)
			{
				letra = (((letra - 64 + (clave[counter] - 64)) - 26) + 64);
				counter++;
				cifrado = cifrado + letra;
			}
			else
			{
				letra = ((letra - 64) + (clave[counter] - 64)) + 64;
				counter++;
				cifrado = cifrado + letra;
			}
			
		}
		
	}
	Frase = cifrado;

	return cifrado;
}

string Cifrados::D_Vigenere(string clave)
{
	string cifrado = "";
	int counter = 0;
	int size = clave.size();
	for (char& c : clave) {
		c = toupper(c);
	}

	for (char letra : Frase)
	{
		if (counter < size)
		{
			if (letra == ' ')
			{

			}
			else if (((letra - 64) - (clave[counter] - 64)) < 1)
			{
				letra = (((letra - 64) - (clave[counter] - 64)) + 26) + 64;
				counter++;
				cifrado = cifrado + letra;
			}
			else
			{
				letra = ((letra - 64) - (clave[counter] - 64)) + 64;
				counter++;
				cifrado = cifrado + letra;
			}

			
		}
		else
		{
			counter = 0;
			if (letra == ' ')
			{

			}
			else if (((letra - 64) - (clave[counter] - 64)) < 1)
			{
				letra = (((letra - 64) - (clave[counter] - 64)) + 26) + 64;
				counter++;
				cifrado = cifrado + letra;
			}
			else
			{
				letra = ((letra - 64) - (clave[counter] - 64)) + 64;
				counter++;
				cifrado = cifrado + letra;
			}
		}
		
	}

	Frase = cifrado;

	return cifrado;
}
