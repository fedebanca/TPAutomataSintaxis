#include <stdio.h>

int matrizDelAutomata[7][6] ={{2,1,1,6,6,6},{1,1,1,6,6,6},{3,3,6,6,4,6},{3,3,6,6,6,6},{5,5,5,5,6,6},{5,5,5,5,6,6},{6,6,6,6,6,6}};

int automata (char palabra[10])
{
	int estado = 0;
	int columna;
	int posicionEnPalabra =0;
	do{
	   columna = darColumna(palabra[posicionEnPalabra]);
	   estado = matrizDelAutomata[estado][columna];
		posicionEnPalabra ++;
	}while(estado != 6);
	return (estado);
}

int darColumna(char caracter[1])
{
    int columna = 5;
    if (caracter > 0)
    {
        if (caracter > 7)
        {
            if (caracter <= 9)
            columna = 2;
        }
        else
        columna = 1;
    }
    else
    columna = 0;
    if (caracter >= 'a' && caracter <= 'f' || caracter >= 'A' && caracter <= 'F')
		columna = 3;
	if (caracter == 'x' || caracter == 'X')
		columna = 4;
	return (columna);
}
