#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Variables globales
int matrizDelAutomata[7][6] = {{2, 1, 1, 6, 6, 6}, {1, 1, 1, 6, 6, 6}, {3, 3, 6, 6, 4, 6}, {3, 3, 6, 6, 6, 6}, {5, 5, 5, 5, 6, 6}, {5, 5, 5, 5, 6, 6}, {6, 6, 6, 6, 6, 6}};

// Prototipos de funcion
int automata(char *palabra);
int darColumna(char caracter);

void main() {
    // Variables y Constantes
    char fnameInsert[] = "cadenas.txt";
    FILE *punteroFile;
    char *lineas = NULL;
    size_t len = 0;
    ssize_t lectura;
    char *palabras = malloc(sizeof(char)*20);

    punteroFile = fopen(fnameInsert, "r"); // Apertura del archivo de texto, modo lectura unicamente.
    if(punteroFile == NULL) {
        exit(EXIT_FAILURE);
    }

    while((lectura = getline(&lineas,&len,punteroFile) != -1)){ // Leo el archivo linea por linea.
        // Para hacer splits de un str, usamos la funcion strtok de la libreria string.h
        // Toma un string y lo divide segun un caracter condicion.
        palabras = strtok(lineas, " ");
        
        while(palabras != NULL){
            automata(palabras);
            palabras = (NULL, " ");
        }
        
    }
    
    fclose(punteroFile); // Cierre del archivo de texto.
    if(lineas) {
        free(lineas);
    }
}

int automata(char *palabra) {
	int estado = 0;
	int columna;
	int posicionEnPalabra =0;
	do {
	    columna = darColumna(palabra[posicionEnPalabra]);
	    estado = matrizDelAutomata[estado][columna];
		posicionEnPalabra ++;
	} while(estado != 6 || posicionEnPalabra < 20 || palabra[posicionEnPalabra] == '\n' );
	return (estado);
}

int darColumna(char caracter) {
    int columna = 5;
    if (caracter > 0) {
        if (caracter > 7) {
            if (caracter <= 9)
            columna = 2;
        } else {
            columna = 1;
        }
    } else {
        columna = 0;
        if ((caracter >= 'a' && caracter <= 'f') || (caracter >= 'A' && caracter <= 'F')) {
		    columna = 3;
        }
	    if (caracter == 'x' || caracter == 'X') {
		    columna = 4;
        }
    }
	return columna;
}