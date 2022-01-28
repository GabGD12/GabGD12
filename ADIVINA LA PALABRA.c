//JUEGO ADIVINA LA PALABRA
//PROYECTO FINAL/LENGUAJE C


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>


void categorias();
void ingresoCategoria (int op);
void empezarJuego (char palabras[][15], char nombre[]);


int main()
{
	system("mode con cols=80 lines=25");
	categorias();
	system("pause");
	return 0;
}

void categorias()
{
	int op;
	do
	{
		system("cls");
		printf("\n\t\t\t\tADIVINA LA PALABRA\n\n");
		printf(" Hola, vamos a jugar este divertido juego.\n");
		printf(" A continuacion, escoge la categoria con la que quieras jugar:\n\n");
		printf(" CATEGORIAS\n\n");
		printf(" 1. Ropa\n");
		printf(" 2. Animales\n");
		printf(" 3. Figuras\n");
		printf(" 4. Electrodomesticos\n\n");
		printf(" Ingresa el numero correspondiente a la categoria: ");
		scanf("%i",&op);		
	}
	while(op<1 || op>4);

	if (op==1) ingresoCategoria(op);
	if (op==2) ingresoCategoria(op);
	if (op==3) ingresoCategoria(op);
	if (op==4) ingresoCategoria(op);
}


void ingresoCategoria (int op)
{
	char nombrecat[4][20] = {"Ropa","Animales","Figuras","Electrodomesticos"};
	char ropa [10][15] = {"CAMISA","JEAN","CHAQUETA","FALDA","BUFANDA","BOXER","VESTIDO","GUANTE","GORRA","CALCETINES"};
	char animales [10][15] = {"PERRO","AGUILA","BURRO","CHIGUIRO","JIRAFA","DELFIN","TIGRE","CONEJO","ZEBRA","BUFALO"};
	char figura [10][15] = {"TRIANGULO","CUADRADO","ROMBO","PENTAGONO","HEXAGONO","CIRCULO","PIRAMIDE","CILINDRO","PARALELEPIPEDO","TRAPECIO"};
	char electro [10][15] = {"SANDUCHERA","MICROONDAS","FREIDORA","HORNO","TELEVISOR","LAVADORA","SECADORA","NEVERA","ASPIRADORA","CAFETERA"};
	
	switch(op)
	{
		case 1:
			empezarJuego(ropa,nombrecat[op-1]);
			break;
		case 2:
			empezarJuego(animales,nombrecat[op-1]);
			break;
		case 3:
			empezarJuego(figura,nombrecat[op-1]);
			break;
		case 4:
			empezarJuego(electro,nombrecat[op-1]);
			break;	
	}	
}



void empezarJuego (char palabras[][15], char nombre[])
{
	int opcion,i,j,k,longitud,espacios;
	char letra;
	int aciertos = 0;
	int intentos = 0;
	int ganar = 0;
	srand(time(NULL));
	
	opcion = rand() % 10; 
	longitud = strlen(palabras[opcion]); 
	char frase[longitud];
	
		for(i=0; i < longitud; i++)
	{
		frase[i] = '_';
	}
	
	
	do
	{
		aciertos = 0;
		system("cls");
		printf("\n\t\t\t\tADIVINA LA PALABRA\n\n");
		printf(" CATEGORIA: %s\n\n",nombre);
		printf(" Intentos Disponibles: %i",5-intentos);
		
		printf("\n\n\n");
		for(i=0; i < longitud; i++)
		{
			printf(" %c ",frase[i]);
		}

		
		if (intentos == 5)
		{
			printf("\n\n PERDISTE!!\n");
			printf(" LA SOLUCION ERA: %s\n\n",palabras[opcion]);
			printf(" Presiona Enter para volver a jugar..");
			getch();
			categorias();	
		}
		
		
		espacios=0;
		
		for (i = 0; i < longitud; i++)
		{
			if (frase[i] == '_')
				espacios++;
		}
		
		
		if (espacios == 0)
		{
			printf("\n\n FELICIDADES.. GANASTE!!\n\n");
			printf(" Presiona Enter para volver a jugar..");
			getch();
			categorias();		
		}
		
		
		printf("\n\n Digite una letra en mayuscula: ");
		scanf(" %c",&letra);
		
		for (j = 0; j < longitud; j++)
		{
			if (letra == palabras[opcion][j])
			{
				frase[j] = letra;
				aciertos++;
			}	
		}
		
		if (aciertos == 0)
		{
			intentos++;	
		}
		
		
			
	}
	while(intentos != 6);
	
	
	printf("\n\n");		
}

