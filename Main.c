/*
	Programa: Main.c
	Autor: The Survivors
	Fecha: 21/10/2021
	Objetivo: Realizar los programas de la lista 1
		
*/

//Bibliotecas
#include <stdio.h>
#include "Biblioteca.h"

//Prototipos
void MenuOpciones();
void MenuProgramas1_5();
void MenuProgramas6_10();
void MenuProgramas11_15();
void MenuProgramas17_21();
void MenuProgramas22_24();

//Programa Principal
int main(){
	
						
	MenuOpciones();
						
	return 0;

}//Fin Programa Principal

/*
	Procedimiento: MenuOpciones
	Objetivo: Realizar un menú de opciones 
	Parámetros:

*/

void MenuOpciones(){
	
	//Variables locales
	
	int eOpcion;
	
	char sCadena[6][100] = {
						"1. Programas 1-5", "2. Programas 6-10", "3. Programas 11-15", "4. Programas 17-21", "5. Programas 22-24", "6. Salir"};	
	
	do{
		
		system("cls");
		
		gotoxy(45, 2); printf("MENU DE OPCIONES");
		gotoxy(35, 16); printf("Elija una opci%cn: ", 162);
					
		Menu(sCadena, 6);
		
		eOpcion = LeerEnteroEnRango(1, 6, 55, 16);
		
		switch(eOpcion){
			
			case 1:
				
				MenuProgramas1_5();
				
				break;
				
			case 2:
			
				MenuProgramas6_10();
					
				break;
				
			case 3:
			
				MenuProgramas11_15();
			
				break;		
			
			case 4:
				
				MenuProgramas17_21();
				
				break;
			
			case 5:
			
				MenuProgramas22_24();
			
				break;	
				
			case 6:
				
				gotoxy(45, 24); printf("Saliendo del sistema...");
				
				break;	
				
		}
		
		getchar();
	
	}while(eOpcion != 6);
	
}//Fin MenuDeOpciones

/*
	Procedimiento: MenuPrograma1_5
	Objetivo: Realizar un menú de opciones para los programas del 6 al 10
				y mandar a llamar sus funciones para que se ejecute el código
	Parámetros:

*/


void MenuProgramas1_5(){
	
	//Variables locales
	int eOpcion, eLongitud, eRen, eCol;
	char sCadena1[20],cCaracter;
	
	char sCadena[6][100] = {
						"1. LeerEntero", "2. LeerAlfa", "3. LeerSN", "4. LeerCadena", "5. LeerPositivo", "6. Regresar al menu"};
	
	
	do{
		
		system("cls");
		
		gotoxy(45, 2); printf("PROGRAMAS 1-5");
		gotoxy(35, 16); printf("Elija una opci%cn: ", 162);
					
		Menu(sCadena, 6);
		
		eOpcion = LeerEnteroEnRango(1, 6, 55, 16);
		
		if(eOpcion != 6) system("cls");

		switch(eOpcion){
			
			case 1:
				
				gotoxy(35, 16); printf("Ingrese un n%cmero: ", 163);
				
				printf("El n%cmero es: %d", 163, LeerEntero(sCadena1, 55, 16));
				
		
				
				break;
				
			case 2:
				
				gotoxy(35, 3); printf("Ingrese una cadena: ");
			
				printf("La cadena es: %s", LeerAlfa(sCadena1, 55, 3));
				
				break;
				
			case 3:
				
				gotoxy(20, 3); printf("Ingrese un caracter [S/N]: ");
				
				if(LeerSN(cCaracter, 'S', 'N', 48, 3) == 'S'){
					
					gotoxy(25, 4); printf("El caracter es verdadero");
					
				}
				
				else{
					
					gotoxy(25, 4); printf("El caracter es falso");
					
				}
				
				break;		
			
			case 4:
				
				gotoxy(25, 3); printf("Ingrese la longitud de la cadena: ");
				gotoxy(60, 3); scanf("%d", &eLongitud);
				
				gotoxy(35, 4); printf("Ingrese la cadena: ");
				
				gotoxy(35, 5); printf("La cadena es: %s", LeerCadenaDeNCaracteres(sCadena1, eLongitud, 55, 4));
						
								
				break;
				
			case 5:
				
				gotoxy(30, 3); printf("Ingresa un n%cmero positivo: ", 163);
								
				printf("El n%cmero positivo es: %d ", 163, LeerEnteroPositivo(sCadena1, 60, 3));
												
				break;
				
			case 6:
				
				gotoxy(45, 24); printf("REGRESANDO AL MEN%c PRINCIPAL", 233);
				
				break;	
				
		}
		
		fflush(stdin);
		getchar();
	
	}while(eOpcion != 6);
	
	
}//Fin MenuProgramas1_5


/*
	Procedimiento: MenuPrograma6_10
	Objetivo: Realizar un menú de opciones para los programas del 6 al 10
				y mandar a llamar sus funciones para que se ejecute el código
	Parámetros:

*/

void MenuProgramas6_10(){
	
	//Variables locales
	int eOpcion, eLimiteInf, eLimiteSup;
	float fLimiteInf, fLimiteSup;
	char cLimiteInf, cLimiteSup, sCadena1[20], sCadena2[20];
	char sCadena[6][100] = {
						"1. LeerEnteroRan", "2. LeerFlotanteRan", "3. LeerCaracterRan", "4. LeerMayus", "5. LeerCaracter", "6. Regresar al menu"};
	
	do{
		
		system("cls");
		
		gotoxy(45, 2); printf("PROGRAMAS 6-10");
		gotoxy(35, 16); printf("Elija una opci%cn: ", 162);
					
		Menu(sCadena, 6);
		
		gotoxy(15, 15); eOpcion = LeerEnteroEnRango(1, 6, 55, 16);
		
		if(eOpcion != 6) system("cls");
		
		switch(eOpcion){
			
			
			case 1:
				
				gotoxy(30, 14); printf("Ingrese el limite inferior: ");
				gotoxy(60, 14); scanf("%d", &eLimiteInf);	
				
				gotoxy(30, 15); printf("Ingrese el limite superior: ");
				gotoxy(60, 15); scanf("%d", &eLimiteSup);
				
				gotoxy(30, 16); printf("Ingrese un n%cmero: ", 163);
				
				gotoxy(30, 18); printf("El n%cmero entero es: %d\n", 163, LeerEnteroEnRango(eLimiteInf, eLimiteSup, 55, 16));
				
				
				break;
				
			case 2:
			
				printf("Ingrese el limite inferior: ");
				scanf("%f", &fLimiteInf);	
				
				printf("Ingrese el limite superior: ");
				scanf("%f", &fLimiteSup);
				
				printf("El n%cmero flotante es: %.2f\n", 163, LeerFlotanteEnRango(fLimiteInf, fLimiteSup));
				
					
				break;
				
			case 3:
				
				gotoxy(25, 3); printf("Ingrese el limite inferior: ");
				fflush(stdin);
				gotoxy(55, 3); cLimiteInf = getchar();
				
				gotoxy(25, 4); printf("Ingrese el limite superior: ");
				fflush(stdin);
				gotoxy(55, 4);cLimiteSup = getchar();
				
				gotoxy(25, 5); printf("El caracter es: %c\n", LeerCaracterEnRango(cLimiteInf, cLimiteSup));
				
				
				break;		
			
			case 4:
				
				gotoxy(20, 3); printf("Ingrese una palabra en min%csculas: ", 163);
				
				printf("\t\t\t\tLa palabra convertida a may%csculas es: %s\n", 163, LeerMayusculas(sCadena1, sCadena2)); 
				
				break;
			
			case 5:
				
				gotoxy(35, 3); printf("Ingrese una cadena: ");
				fflush(stdin);
				gotoxy(55, 3); gets(sCadena1);
				
				printf("\t\t\t\tEl caracter es: %c\n", LeerCaracterEnConjunto(sCadena1));
				
				break;
				
			case 6:
				
				gotoxy(45, 24); printf("REGRESANDO AL MEN%c PRINCIPAL", 233);
				
				break;	
				
		}
		
		fflush(stdin);
		getchar();
			
	}while(eOpcion != 6);
	
}//Fin MenuProgramas6_10


/*
	Procedimiento: MenuProgramas11_15
	Objetivo: Realizar un menú de opciones 
	Parámetros:

*/

void MenuProgramas11_15(){
	
	//Variables locales
	int eOpcion ,eRenglon, eColumna;
	char sCadena1[20];
	char sCadena[6][100] = {
						"1. LeerFormato", "2. LeerFecha", "3. EscribirRenglon", "4. Mensaje", "5. Escribir", "6. Regresar al menu"};
	
	TrFecha rFecha;
	
	do{
		
		system("cls");
		
		gotoxy(45, 2); printf("PROGRAMAS 11-15");
		gotoxy(35, 16); printf("Elija una opci%cn: ", 162);
					
		Menu(sCadena, 6);
		
		gotoxy(15, 15); eOpcion = LeerEnteroEnRango(1, 6, 55, 16);
		
		if(eOpcion != 6) system("cls");
		
		switch(eOpcion){
			
			case 1:
				
				gotoxy(10, 3); printf("Ingrese el formato [A = Alfab%ctico][9 = Num%crico][X = Alfan%cmerio]: ", 130, 130, 130);
				fflush(stdin);
				gotoxy(85, 3); gets(sCadena1);
				
				gotoxy(35, 4); printf("Formato %s: ", sCadena1);
				
				char* sCadena3 = LeerCadenaConFormato(sCadena1, 55, 4);
				
				gotoxy(35, 5); printf("Formato Correcto");
				
				break;
				
			case 2:
				
				gotoxy(5, 2); printf("INGRESE UNA FECHA: ");
				
				gotoxy(5, 3); printf("A%co: ", 164);
				
				gotoxy(5, 4); printf("Mes: "); 
				
				gotoxy(5, 5); printf("D%ca: ", 161); 
							
				rFecha = LeerFecha(12, 3, 12, 4, 12, 5);	
				
				gotoxy(7, 6); printf("%d / %d / %d\n", rFecha.eDia, rFecha.eMes, rFecha.eAnio);
									
				break;
				
			case 3:
			
				printf("Ingrese el Rengl%cn: ", 162);
				scanf("%d", &eRenglon);
				
				printf("Ingresa una cadena: ");
				fflush(stdin);
				gets(sCadena1);
				
				EscribirEnRenglon(0, eRenglon, sCadena1);
			
				break;		
			
			case 4:
				
				printf("Ingrese una cadena: ");
				fflush(stdin);
				gets(sCadena1);
				
				Mensaje(sCadena1);
				
				gotoxy(26, 26);
				
				break;
				
			case 5:
				
				printf("Ingrese una cadena: ");
				fflush(stdin);
				gets(sCadena1);
				printf("Ingrese el Rengl%cn: ", 162);
				scanf("%d", &eRenglon);
				printf("Ingrese la Columna: ");
				scanf("%d", &eColumna);
				
				Escribir(sCadena1, eRenglon, eColumna);
				
				break;
				
			case 6:
				
				gotoxy(45, 24); printf("REGRESANDO AL MEN%c PRINCIPAL", 233);
				
				break;	
				
		}
		
		fflush(stdin);	
		getchar();
			
	}while(eOpcion != 6);
	
}//Fin MenuProgramas11_15


/*
	Procedimiento: MenuProgramas17_21
	Objetivo: Realizar un menú de opciones para los programas del 18 al 22
				y mandar a llamar sus funciones para que se ejecute el código
	Parámetros:

*/

void MenuProgramas17_21(){
	
	//Variables locales
	int eOpcion, eNumero, eRenInicio, eColFinal, eColInicio, eRenFinal, eCol, eRen;
	char sCadena1[20];
	char sCadena[6][100] = {
						"1. Limpiar", "2. EnteroACad", "3. CadenaAFlo", "4. MargenEn", "5. Margen", "6. Regresar al menu"};
	
	do{
		
		system("cls");
		
		gotoxy(45, 2); printf("PROGRAMAS 17-21");
		gotoxy(35, 16); printf("Elija una opci%cn: ", 162);
				
		Menu(sCadena, 6);
		
		gotoxy(15, 15); eOpcion = LeerEnteroEnRango(1, 6, 55, 16);
		
		if(eOpcion != 6) system("cls");
		
		switch(eOpcion){
			
			case 1:
				
				system("cls");
				
				for(eRen = 1; eRen <= 118; eRen++){
					
					for(eCol = 1; eCol <= 25; eCol++){
						
						gotoxy(eRen, eCol); printf("*");
						
					}
						
				}
				
				gotoxy(10, 10); printf("Ingrese el rengl%cn inicial: ", 162);
				scanf("%d", &eRenInicio);
				
				gotoxy(10, 11); printf("Ingrese el rengl&cn final: ", 162);
				scanf("%d", &eRenFinal);
				
				gotoxy(10, 12); printf("Ingrese la columna inicial: ");
				scanf("%d", &eColInicio);
				
				gotoxy(10, 13); printf("Ingrese la columna final: ");
				scanf("%d", &eColFinal);
				
				Limpiar(eRenInicio, eColFinal, eColInicio, eRenFinal);
								
				break;
			
			case 2:
				
				printf("Ingresa un n%cmero: ", 163);
				scanf("%d", &eNumero);
				
				printf("\nEl n%cmero es: %d ", 163, eNumero);
				printf(" La cadena es de: %s", EnteroACadena(eNumero, sCadena1));
				
				break;
				
			case 3:
			
				printf("Ingresa un n%cmero: ", 163);
				fflush(stdin);
				gets(sCadena1);
				
				printf("La cadena convertida %s", sCadena1);
				printf(" a flotante es: %.2f", CadenaAFlotante(sCadena1));
							
					
				break;
				
			case 4:
			
				printf("Ingrese el rengl%cn inicial: ", 162);
				scanf("%d", &eRenInicio);
				
				printf("Ingrese el reng%cn final: ", 162);
				scanf("%d", &eRenFinal);
				
				printf("Ingrese la columan inicial: ");
				scanf("%d", &eColInicio);
				
				printf("Ingrese la columna final: ");
				scanf("%d", &eColFinal);
				
				MargenEn(eRenInicio, eColInicio, eRenFinal, eColFinal);
				
				break;		
			
			case 5:
				
				Margen();
								
				break;
			
			case 6:
				
				gotoxy(45, 24); printf("REGRESANDO AL MEN%c PRINCIPAL", 233);
				
				break;	
				
		}
		
		fflush(stdin);
		getchar();
			
	}while(eOpcion != 6);
		
}//Fin MenuProgramas17_21

/*
	Procedimiento: MenuProgramas22_24
	Objetivo: Realizar un menú de opciones para los programas del 18 al 22
				y mandar a llamar sus funciones para que se ejecute el código
	Parámetros:

*/

void MenuProgramas22_24(){
	
	//Variables locales
	
	int eOpcion, eTamanio;
	
	char sCadena[4][100] = {"1. GeneraEntero","2. Menu", "3. Interfaz", "4. Regresar al menu"};
	char sCadena1[6][100] = {"1. Insertar", "2. Enlistar", "3. Buscar", "4. Modificar", "5. Borrar", "6. Salir"};
	
	do{
		
		system("cls");
							
		gotoxy(45, 2); printf("PROGRAMAS 22-24");
		gotoxy(35, 12); printf("Elija una opci%cn: ", 162);
					
		Menu(sCadena, 4);
		
		eOpcion = LeerEnteroEnRango(1, 4, 55, 12);
		
		if(eOpcion != 4) system("cls");
		
		switch(eOpcion){
			
			case 1:
				
				printf("El n%cmero generado es: %d ", 163, GeneraNumero(100));
				
				break;
				
			case 2:
					
				Menu(sCadena1, 6);
				
				gotoxy(35, 16); printf("Elija una opci%cn: ", 162);
							
				eOpcion = LeerEnteroEnRango(1, 6, 55, 16);
					
				break;
				
			case 3:
			
				Interfaz();
				
				break;		
			
			case 4:
				
				gotoxy(45, 24); printf("REGRESANDO AL MEN%c PRINCIPAL", 233);
				
				break;
				
		}
		
		fflush(stdin);
		getchar();
	
	}while(eOpcion != 4);
	
}//Fin MenuProgramas22_24
