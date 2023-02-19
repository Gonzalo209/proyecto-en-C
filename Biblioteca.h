#ifndef BIBLIOTECA_H
#define BIBIOTECA_H

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//Tipos

typedef struct{
	
	int eDia, eMes, eAnio;
		
}TrFecha;

//Prototipos
/*1. */int LeerEntero(char [], int, int );
int ValidarNumero(char []);

/*2. */char* LeerAlfa(char [], int, int );
int ValidarCadena(char []);

/*3. */char LeerSN(char , char , char , int , int );

/*4. */char* LeerCadenaDeNCaracteres(char [], int , int , int );

/*5. */ int LeerEnteroPositivo(char [], int, int );

/*6. */ int LeerEnteroEnRango(int , int , int , int );

/*7. */ float LeerFlotanteEnRango(float , float );
float LeerFlotante(char []);
int LeerDigitos(char []);

/*8. */ int LeerCaracterEnRango(char , char );

/*9. */ char* LeerMayusculas(char [], char []);

/*10. */ char LeerCaracterEnConjunto(char []);

/*11. */ char *LeerCadenaConFormato(char [], int, int );
int ValidarFormato(char []);

/*12. */ TrFecha LeerFecha(int, int, int, int , int, int);
int AnioBisiesto(TrFecha );

/*13. */ void EscribirEnRenglon(int , int , char []);

/*14. */ void Mensaje(char []);

/*15. */ void Escribir(char [], int , int );

/*16. */ int Error(int );

/*17. */ void Limpiar(int , int, int, int);

/*18. */ char *EnteroACadena(int , char []);

/*19. */ float CadenaAFlotante(char []);

/*20. */ void MargenEn(int , int , int , int );

/*21. */ void Margen();

/*22. */ int GeneraNumero(int );

/*23. */ void Menu(char [][100], int );

/*24. */ void Interfaz();
float SaldoPositivo(float , int , int );

/*
	Procedimiento: gotoxy
	Objetivo: Mueve el cursor de la venta de texto a un posición específica
	Parámetros: eCol es la columna que representa la posición en la consola
				 eRen es la renglón que representa la posición en la consola

*/

void gotoxy(int eCol, int eRen){
	
	HANDLE ventana;
	ventana = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordenadas;
	coordenadas.X = eCol;
	coordenadas.Y = eRen;
	
	SetConsoleCursorPosition(ventana, coordenadas);
	
}//Fin gotoxy

/*
	Función: LeerEntero
	Objetivo: Lee  una  cadena  de  caracteres,  verifica  que  sólo  contenga 
				dígitos 
	Parámetros: sCadena es un arreglo de cadena 
	Retorna: Un número positivo o negativo

*/

int LeerEntero(char sCadena[20], int eCol, int eRen){
	
	int eNumero, eOpcion;

	do{
	
		
		fflush(stdin);
		gotoxy(eCol, eRen); gets(sCadena);
		
		if(ValidarNumero(sCadena) != 1){
			
			eOpcion = Error(1);
			
		}
		
	}while(ValidarNumero(sCadena) != 1);
			
	eNumero = atoi(sCadena);
		
	return eNumero;
		
}//Fin LeerEntero

/*
	Función: ValidarNumero
	Objetivo: Comprobar a través del código ASCII si son puros digitos, para retornar un valor verdadero 
	Parámetros: sCadena es una arreglo de cadena
	Retorna: lLogico si es verdadero o falso
	
*/

int ValidarNumero(char sCadena[20]){
	
	int eRecorre, lLogico, eComprobar;
	
	eRecorre = 0; 
	lLogico = 1;
	
	while(lLogico && eRecorre < strlen(sCadena)){
	
		eComprobar = sCadena[eRecorre];
		
		if(eComprobar >= 48 && eComprobar <= 57 || eComprobar == 45){
			
			eRecorre++;
			
		}			
		
		else{
			
			lLogico = 0;
			
		}
		
	}
	
	return lLogico;
	
}//Fin ValidarNumero

/*
	Función: LeerAlfa
	Objetivo: Lee una cadena de caracteres, valida que sólo contenga 
			caracteres alfabéticos
	Parámetros: sCadena es un arreglo de cadena
	Retorna: sCadena 
	
*/

char *LeerAlfa(char sCadena[20], int eCol, int eRen){
	
	int eOpcion;
	
	do{
	
		
		fflush(stdin);
		gotoxy(eCol, eRen); gets(sCadena);
		
		if(ValidarCadena(sCadena) != 1){
		
			eOpcion = Error(2);
			
		}
	
	}while(ValidarCadena(sCadena) != 1);
		
	return sCadena;
	
}//Fin LeerAlfa

/*
	Función: ValidarCadena
	Objetivo: Comprobar a través del código ASCII si son puros letras, para retornar un valor verdadero 
	Parámetros: sCadena es un arreglo de cadena
	Retorna: lLogico si es verdadero o falso
	
*/

int ValidarCadena(char sCadena[20]){
	
	int eRecorre, lLogico, eComprobar;
	
	lLogico = 1; 
	eRecorre = 0;
	 
	while(lLogico && eRecorre < strlen(sCadena)){
	
		eComprobar = sCadena[eRecorre];
		
		if(eComprobar >= 97 && eComprobar <= 122 || eComprobar >= 65 && eComprobar <= 90){
			
			eRecorre++;
			
		}
		
		else{
			
			lLogico = 0;
			
		}
		
		
	}
			
	return lLogico;

}//Fin ValidarCadena

/*
	Función: LeerSN
	Objetivo: Lee un carácter, verifica que sea S o N
	Parámetros: cCaracter es un caracter
	Retorna: Un caracter
	
*/

char LeerSN(char cCaracter, char cCaracter1, char cCaracter2, int eCol, int eRen){
	
	int eOpcion;
		
	do{
		
		
		fflush(stdin);
		gotoxy(eCol, eRen); cCaracter = toupper(getchar());
		
		if(cCaracter != cCaracter1 && cCaracter != cCaracter2){
			
			eOpcion = Error(3);
			
		}
		
	}while(cCaracter != cCaracter1 && cCaracter != cCaracter2);
	
	return cCaracter;
	
}//Fin LeerSN

/*
	Función: LeerCadenaDeNCaracteres
	Objetivo: Lee una cadena de caracteres cualesquiera de longitud N
	Parámetros: sCadena es un arreglo de cadena y eLongitud el tamaño del arreglo de cadena
	Retorna: sCadena
	
*/

char* LeerCadenaDeNCaracteres(char sCadena[20], int eLongitud, int eRen, int eCol){
	
	int eOpcion;
	
	do{
	
		
		fflush(stdin);
		gotoxy(eRen, eCol); gets(sCadena);
		
		if(strlen(sCadena) > eLongitud){
			
			eOpcion = Error(4);
		
		}
		
	}while(strlen(sCadena) > eLongitud);
	
	return sCadena;

}//Fin LeerCadenaDeNCaracteres


/*
	Función: LeerEnteroPositivo
	Objetivo:  Lee  sólo  enteros  positivos
	Parámetros: sCadena es un arreglo de cadena
	Retorna: Un número positivo

*/

int LeerEnteroPositivo(char sCadena[20], int eCol, int eRen){
	
	int eNumero, eOpcion;

	do{
		
		eNumero = LeerEntero(sCadena, eCol, eRen);
		
		if(eNumero < 0){
			
			eOpcion = Error(5);
			
		}
		
	}while(eNumero < 0);
	
	return eNumero;
	
}//Fin LeerEnteroPositivo

/*
-------------------------------------------------------------------------------------------------

		INICIO DEL PROGRAMA DEL 6 AL 10
-------------------------------------------------------------------------------------------------
*/

/*
	Función: LeerEnteroEnRango
	Objetivo: Lee  un entero  que  pertenezca a un  rango  de  valores 
				enteros
	Parámetros: eLimiteInf es como inicia el rango de un valor dado, eLimiteSup es como finaliza el rango de un valor dado,
				eCol es la columna donde se va a posicionar, eRen es el renglón donde se va a posicionar 
	Retorna: Un número positivo o negativo de tipo entero
	
*/

int LeerEnteroEnRango(int eLimiteInf, int eLimiteSup, int eCol, int eRen){
	
	int eNumero, eOpcion;
	char sCadena[20];
		
	do{
		
		eNumero = LeerEntero(sCadena, eCol, eRen);
		
		if(eLimiteInf  > eNumero || eNumero  > eLimiteSup){
			
			eOpcion = Error(6);
			
		}
		
	}while(eLimiteInf  > eNumero || eNumero > eLimiteSup);
			
	return eNumero;		

}//Fin LeerEnteroEnRango

/*
	Función: LeerFlotanteEnRango
	Objetivo: Lee  una  cadena,  verifica  que  los  caracteres  sólo  sean  dígitos
	Parámetros:  eLimiteInf es como inicia el rango de un valor dado, eLimiteSup es como finaliza el rango de un valor dado
	Retorna: Un número positivo o negativo de tipo flotante
	
*/

float LeerFlotanteEnRango(float fLimiteInf, float fLimiteSup){
	
	float fNumero;
	int eOpcion;	
	char sCadena[20];
		
	do{
		
		fNumero = LeerFlotante(sCadena);
		
		if(fLimiteInf  > fNumero || fNumero  > fLimiteSup){
			
			eOpcion = Error(7);
			
		}
		
	}while(fLimiteInf  > fNumero || fNumero > fLimiteSup);
			
	return fNumero;	
	
}

/*
	Función: LeerFlotante
	Objetivo: Vetificar que la cadena solo tenga digitos
	Parámetros: sCadena es un arreglo de cadena
	Retorna: Un número flotante
*/

float LeerFlotante(char sCadena[20]){
	
	float fNumero;
	
	do{
		
		printf("Ingrese una cadena: ");
		fflush(stdin);
		gets(sCadena);
		
		if(LeerDigitos(sCadena) != 0){
			
			printf("Cadena inv%clida", 160);
			
		}
		
	}while(LeerDigitos(sCadena) != 0);
	
	fNumero = atof(sCadena);
	
	return fNumero;
	
}

/*
	Función: LeerDigitos
	Objetivo: Verificar que la cadena solo lea digitos
	Parámetros: sCadena es un arreglo de cadena
	Retorna: lLogico si es verdadero o falso
*/

int LeerDigitos(char sCadena[20]){
	
	int eLongitud, eRecorre, lLogico;
	float fComprobar;
	
	eLongitud = strlen(sCadena);
		
	eRecorre = 0;
	lLogico = 1;
		
	while(lLogico && sCadena[eRecorre]){
		
		fComprobar = (sCadena[eRecorre]);
				
		if(fComprobar >= 1.1 && fComprobar <= 9.9){
				
			eRecorre++;
			
		}
		
		else{
			
			lLogico = 0;
			
		}
		
	}
	
	return lLogico;	
}

/*

	Función: LeerCaracterEnRango
	Objetivo: Lee un carácter, verifica que pertenezca a un rango 
				de  caracteres
	Parámetros: cLimiteInf es como inicia el rango de un valor dado, cLimiteSup es como finaliza el rango de un valor dado
	Retorna: Un caracter
	
*/

int LeerCaracterEnRango(char cLimiteInf, char cLimiteSup){
	
	char cCaracter;
	int eOpcion;
		
	do{
		
		gotoxy(25, 5); printf("Ingrese un caracter: ");
		fflush(stdin);
		gotoxy(55, 5); cCaracter = getchar();
		
		if(cLimiteInf  > cCaracter || cCaracter  > cLimiteSup){
			
			eOpcion = Error(8);
			
			
		}
		
	}while(cLimiteInf  > cCaracter || cCaracter > cLimiteSup);
			
	return cCaracter;	
	
}//Fin LeerCaracteerEnRango

/*

	Función: LeerMayusculas
	Objetivo: Lee una cadena sólo de caracteres alfabéticos, la convierte a mayúsculas
	Parámetros: sCadena es un arreglo de cadena, sCadenaMayus es un arreglo de cadena
	Retorna: Una cadena en mayúsculas
	
*/

char* LeerMayusculas(char sCadena[20], char sCadenaMayus[20]){
	
	int eRecorre, eOpcion;
		
	sCadena = LeerAlfa(sCadena, 60, 3);
	
	strcpy(sCadenaMayus, sCadena);	
		
    for(eRecorre = 0; eRecorre <= strlen(sCadenaMayus); eRecorre++){

        sCadenaMayus[eRecorre] = toupper(sCadenaMayus[eRecorre]);
    }
	
			
	return sCadenaMayus;
	
}//Fin LeerMayusculas

/*

	Función: LeerCaracterEnConjunto
	Objetivo: Lee  un  carácter,  valida  que  pertenezca  a  un conjunto de caracteres 
	Parámetros: sCadena es un arreglo de cadena
	Retorna: Un caracter
	
*/

char LeerCaracterEnConjunto(char sCadena[20]){
	
	int eOpcion;
	char cCaracter;
							
	do{
		
		gotoxy(35, 4); printf("Ingrese un caracter: ");
		fflush(stdin);
		gotoxy(58, 4); cCaracter = getchar();
		
		if(strchr(sCadena, cCaracter) == NULL){
				
			eOpcion = Error(10);
				
		}
			
	}while(strchr(sCadena, cCaracter) == NULL);
			
	return cCaracter;
		
}//Fin LeerCaracterEnConjunto

/*
-------------------------------------------------------------------------------------------------

		FIN DEL PROGRAMA DEL 6 AL 10
-------------------------------------------------------------------------------------------------
*/


/*
-------------------------------------------------------------------------------------------------

		INICIO DEL PROGRAMA DEL 11 AL 15
-------------------------------------------------------------------------------------------------
*/


/*
	Función:  LeerCadenaConFormato
	Objetivo: Lee un conjunto de caracteres, verifica que coincida  con  el  formato 
	Parámetros: sCadena es un arreglo de cadena
	Retorna: Una cadena
*/

char *LeerCadenaConFormato(char sCadena[20], int eCol, int eRen){
	
	int eRecorre, eLongitud = 0, lLogico, eOpcion;
	char sCadena1[20];
	
	eLongitud = strlen(sCadena);
	
	do{
	
		char *sCadena2 = LeerCadenaDeNCaracteres(sCadena1, eLongitud, eCol, eRen);
					
		eRecorre = 0;	
	 	lLogico = 1;
	 	
		while(lLogico && eRecorre < strlen(sCadena)){
				
			if(sCadena[eRecorre] == 'A' && isalpha(sCadena1[eRecorre])){
			
				eRecorre++;
					
			}
			
			else
				if(sCadena[eRecorre] == '9' && isdigit(sCadena1[eRecorre])){
				
					eRecorre++;
				
				}
				
				else
					if(sCadena[eRecorre] == 'X' && isalpha(sCadena1[eRecorre]) || sCadena[eRecorre] ==  'X' && isdigit(sCadena1[eRecorre])){
						
						eRecorre++;
						
					}//fin if
					
					else{
						
						lLogico = 0;
						
						eOpcion = Error(11);
					}	
					
		}//fin while
		
	}while(lLogico != 1);
	
	return sCadena;
}

/*
	Función: TrFecha
	Objetivo: Leer una fecha correctamente (dd/mm/aaaa)
	Parámetros:
	Retorono: Un registro
	
*/


TrFecha LeerFecha(int eColAnio, int eRenAnio, int eColMes, int eRenMes, int eColDia, int eRenDia){
	
	TrFecha rFecha;
			
	rFecha.eAnio = LeerEnteroEnRango(1921, 2003, eColAnio, eRenAnio); 
		
	if(AnioBisiesto(rFecha)){
			
		rFecha.eMes = LeerEnteroEnRango(1, 12, eColMes, eRenMes); 
				
		if(rFecha.eMes == 1 || rFecha.eMes == 3 || rFecha.eMes == 5 || rFecha.eMes == 7 || rFecha.eMes == 8 || rFecha.eMes == 10 || rFecha.eMes == 12 ){
			
		
			rFecha.eDia = LeerEnteroEnRango(1, 31, eColDia, eRenDia); 
										
		} 
		
		else if(rFecha.eMes == 2) {
			
			rFecha.eDia = LeerEnteroEnRango(1, 29, eColDia, eRenDia);
			
		} 
		
		else if (rFecha.eMes == 4 || rFecha.eMes == 6 || rFecha.eMes == 9 || rFecha.eMes == 11){
			
			rFecha.eDia = LeerEnteroEnRango(1, 29, eColDia, eRenDia);
			
		} 
		
	}
	
	else{
		
		rFecha.eMes = LeerEnteroEnRango(1, 12, eColMes, eRenMes);
				
		if(rFecha.eMes == 1 || rFecha.eMes == 3 || rFecha.eMes == 5 || rFecha.eMes == 7 || rFecha.eMes == 8 || rFecha.eMes == 10 || rFecha.eMes == 12 ){
			
			rFecha.eDia = LeerEnteroEnRango(1, 31, eColDia, eRenDia);
			
		} 
		
		else if(rFecha.eMes == 2) {
			
			rFecha.eDia = LeerEnteroEnRango(1, 28, eColDia, eRenDia);
			
		} 
		
		else if (rFecha.eMes == 4 || rFecha.eMes == 6 || rFecha.eMes == 9 || rFecha.eMes == 11){
			
			rFecha.eDia = LeerEnteroEnRango(1, 30, eColDia, eRenDia);
			
		} 
	}
	
	return rFecha;	
		
}//Fin rFecha

/*
	Función: AnioBisiesto
	Objetivo: conocer si un año es bisiesto o no
	Parámetros rFecha es un registro
	Retorna: Un 1 si es bisiesto, 0 si no es bisiesto

*/

int AnioBisiesto(TrFecha rFecha){
	
	if(rFecha.eAnio % 4 == 0 && rFecha.eAnio % 100 != 0 || rFecha.eAnio % 400 == 0){
		
		return 1;
		
	} else {
		
		return 0;
		
	}
}


/*
	Procedimiento: EscibirEnRenglon
	Objetivo: Escribir una cadena  el  renglón  donde  se  desea  mostrar  el  texto  
	y  lo  muestra  en esa línea.
	Parámetros: eColumna la posición de la columna, eRenglon la posición del renglón
				sCadena es un arreglo de cadena
	
*/

void EscribirEnRenglon(int eColumna, int eRenglon, char sCadena[20]){
	
	gotoxy(eColumna, eRenglon); 
	
	printf("%s ", sCadena);
	
}//Fin EscribirEnRenglon

/*

	Procedimiento: Mensaje
	Objetivo: Mostrar un mensaje centrado en la línea 25  de  la  pantalla
	Parámetros: sCadena es un arreglo de cadena
	
*/

void Mensaje(char sCadena[20]){
	
	int eTamanio;
	
	eTamanio = strlen(sCadena);
	
	EscribirEnRenglon(40 - (eTamanio / 2), 24, sCadena);
	
}//Fin Mensaje

/*
	Procedimiento: Escibir
	Objetivo: Muestra un mensaje el  renglón  y  la  columna  donde 
				se mostrará el texto y lo muestre en esa posición
	Parámetros: eColumna la posición de la columna, eRenglon la posición del renglón,
				sCadena es un arreglo de cadena

*/

void Escribir(char sCadena[20], int eRenglon, int eColumna){
	
 	EscribirEnRenglon(eColumna, eRenglon, sCadena);	
	
}//Fin Escribir

/*
-------------------------------------------------------------------------------------------------

		INICIO DEL PROGRAMA DEL 16 AL 20
-------------------------------------------------------------------------------------------------
*/

/*
	Función: Error
	Objetivo: Recibe  un  código  de  error  (entero)  y  dependiendo  de  ese  código 
			 muestre un mensaje indicando el tipo de error cometido
	Parámetros: eOpcion es un número entero
	Retorna: Un número
*/

int Error(int eOpcion){
	
	char sCadena[20];
	
	strcpy(sCadena, " ");
	
	Mensaje(sCadena);
	
	
	switch(eOpcion){
	
		
		case 1:
			
		case 2:
			
		case 9:
	
			printf("Texto no v%clida", 160);
			
			
			break;							
		
		case 3:
			
			printf("Caracter no v%clido", 160);
			
			break;
			
		case 4:
			
			printf("Sobrepaso la longitud el texto");
			
			break;
		
		case 5:
			
			printf("No se permiten n%cmeros negativos", 163);
			
			break;
			
		case 6:
			
		case 7:
			
			printf("Tu n%cmero est%c fuera del rango", 163, 160);
			
			break;
			
		case 8:
			
			printf("Tu caracter est%c fue del rango", 160);
			
			break;
			
		
		case 10:
			
			printf("El caracter no se encontr%c en el texto", 162);
			
			break;
		
		case 11:
			
			printf("Respeta el formato");
		
			break;
		
	}
	
	getchar();
	
	Limpiar(24, 110, 24, 24);
	
	return eOpcion;

}//Fin Error

/*

	Procedimiento: Limpiar
	Objetivo: Borrar una parte de la pantalla en una posición que nosotros le indiquemos
	Parámetros: eRenInicio es el inicio del renglón, eColFinal es el final de la columna, 
				eColInicio es el inicio de la columna, eRenFin es el final del renglón

*/

void Limpiar(int eRenInicio, int eColFinal, int eColInicio, int eRenFin){
	
	int eRen, eCol;
	
	for(eRen = eRenInicio; eRen <= eRenFin; eRen++){
		
		for(eCol = eColInicio; eCol <= eColFinal; eCol++){
			
		gotoxy(eCol, eRen); printf(" ");
			
		}
		
	}
		
}//Fin Limpiar


/*

	Función: EnteroACadena
	Objetivo: Convierte un valor numérico entero en una cadena de caracteres
	Parámetros: eNumero es un entero y sCadenes es un arreglo de cadena
	Retorna: Una cadena

*/

char *EnteroACadena(int eNumero, char sCadena[20]){
	
		
	sprintf(sCadena, "%d", eNumero);

	return sCadena;
	
}//Fin EnteroACadena


/*

	Función: CadenaAFlotante
	Objetivo: Convierte una cadena de caracteres a un valor numérico flotante
	Parámetros: sCadena es un arreglo de cadena
	Retorna: Un número positivo o negativo de tipo flotante

*/

float CadenaAFlotante(char sCadena[20]){
	
	float fNumero;
	
	fNumero = atof(sCadena);
	
	return fNumero;
	
}//Fin CadenaAFlotante

/*

	Procedimiento: MargenEn
	Objetivo:  Muestre  un  margen  alrededor  de  un  área  especificada  con 
				cuatro
	Parámetros: eRenInicio el inicion del renglón, eColInicio el inicio de la columna, 
				eRenFinal el final del renglón, eColFinal el final

*/

void MargenEn(int eRenInicio, int eColInicio, int eRenFinal, int eColFinal){
	
	int eRen, eCol;
	
	for(eRen = eRenInicio; eRen <= eRenFinal; eRen++){
		
		gotoxy(eRen, eColInicio); printf("*");
		gotoxy(eRen,eColFinal); printf("*");
			
	}
	
	for(eCol = eColInicio; eCol <= eColFinal; eCol++){
		
		gotoxy(eRenInicio, eCol); printf("*");
		gotoxy(eRenFinal, eCol); printf("*");
	}
		
}//Fin MargenEn

/*
-------------------------------------------------------------------------------------------------

		FIN DE LOS PROGRAMAS DEL 16 AL 20
-------------------------------------------------------------------------------------------------
*/

/*
-------------------------------------------------------------------------------------------------

		INICIO DE LOS PROGRAMA DEL 21 AL 24
-------------------------------------------------------------------------------------------------
*/

/*
	Procedimiento: Margen
	Objetivo: Muestra  un  margen  alrededor  de  toda  la  pantalla
	Parametros: 
	
*/

void Margen(){
	
	MargenEn(0, 0, 110, 25);
	printf("\n");
	
}//Fin Margen


/*

	Función: GeneraNumero
	Objetivo: Genera  un  número  entero  aleatorio  entre  0  y  un  valor 
			 especificado 
	Parámetros: eTotalNumero es un entero
	Retornar: Un número aleatorio

*/

int GeneraNumero(int eTotalNumero){
	
	int eNumeroAleatorio, eNumero, eM, eN;
	char *sCadena;
	
	eM = 0;
	
	eN = eTotalNumero;
	
	do{
		
		eNumeroAleatorio = rand () % (eN - eM + 1) + eM;		
			
	} while (eNumero < 0);
		
	return eNumeroAleatorio;

}//Fin GeneraNumero

/*
	Procedimiento: Menu
	Objetivo: Muestra un menú centrado verticalmente, con las opciones pasadas 
			  en  un  arreglo  como  parámetro
	Parámetros: sCadena es una matriz de cadena

*/

void Menu(char sCadena[5][100], int eTamanio){
	
	int eRecorre, eOpcion;
	
	Margen();
	MargenEn(4, 3, 105, 23);
	
	for(eRecorre = 0; eRecorre <= eTamanio - 1; eRecorre++){
		
		Escribir(sCadena[eRecorre], eRecorre + eTamanio, 45);
		
			
	}
		
	
}//Fin Menu

/*

	Procedimiento: Interfaz
	Objetivo: Haciendo uso de las funciones anteriores se 
				realizará una alta de clientes
	Parámetros: 
	
*/

void Interfaz(){
	
	int eTamanio;
	char sCadena1[20], cCaracter, cTipoCliente, cAgregarCliente;
	float fSaldo;
	TrFecha rFecha;
	
	MargenEn(0, 0, 100, 27);
	MargenEn(3, 3, 95, 23);
	
	gotoxy(40, 2); printf("Alta de Clientes");
	
	do{
		
			gotoxy(30, 5); printf("R.F.C: "); 
			char *sFormato = LeerCadenaConFormato("AAAA999999XXX", 55, 5); 
			
			gotoxy(30, 7); printf("Nombre del cliente: "); 
			char *sAlfa = LeerAlfa(sCadena1, 55, 7); 
			
			gotoxy(30, 9); printf("Domicilio: "); 
			char *sCadena = LeerCadenaDeNCaracteres(sCadena1, 30, 55, 9);
			
			gotoxy(30, 11); printf("Tel%cfono: ", 130); 
			char *sFormato1 = LeerCadenaConFormato("99999999", 55, 11);
			
			gotoxy(30, 13); printf("Fecha de nacimiento: "); 
			gotoxy(59, 13); printf("/"); gotoxy(62, 13); printf("/"); 
			rFecha = LeerFecha(54, 13, 60, 13, 63, 13); 
			
			gotoxy(30, 15); printf("Saldo $: "); 
			fSaldo = LeerEnteroPositivo(sCadena1, 55, 15);
			
			gotoxy(30, 17); printf("Tipo de cliente [M/F]: "); 
			cTipoCliente = LeerSN(cCaracter, 'M', 'F', 63, 17);
			
			gotoxy(30, 19); printf("%cDesea agregar otro cliente? [S/N]: ", 168); 
			cAgregarCliente = LeerSN(cCaracter, 'S', 'N', 75, 19);
			
			if(cAgregarCliente != 'N'){
				
				Limpiar(5, 75, 54, 5);
			
				Limpiar(7, 75, 54, 7);
			
				Limpiar(9, 75, 54, 9);
			
				Limpiar(11, 75, 54, 11);
			
				Limpiar(13, 58, 54, 13);
			
				Limpiar(13, 61, 60, 13);
			
				Limpiar(13, 64, 63, 13);
			
				Limpiar(15, 75, 54, 15);
			
				Limpiar(17, 75, 60, 17);
			
				Limpiar(19, 75, 70, 19);
				
			}
						
	}while(cAgregarCliente != 'N');
				
}//Fin Interfaz

/*
-------------------------------------------------------------------------------------------------

		FIN DE LOS PROGRAMA DEL 21 AL 24
-------------------------------------------------------------------------------------------------
*/

#endif
