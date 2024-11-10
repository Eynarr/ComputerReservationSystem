//Proyecto Sistema De Laboratorio

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<windows.h>
//Declaracion de constantes
#define SIZE 25 
//Funciones color "\033[0;31m"
//Verifica si el ID se encuentra en la base de datos.
int VerificarID(char baseCEDULAS[20][SIZE], char estudianteCEDULA[SIZE])
{
    int c=0,i;
    for(i = 0;i<SIZE;i++)
    {
        if (strcmp(baseCEDULAS[i],estudianteCEDULA)==0)
        {
        	//Si se encuentra retorna la posicion.
            return i;
        }
        else
        {
            c++;
        }
    }
    if(c==SIZE)
    {
    	//De otro modo retorna -1.
        return -1;
    }
}
//Identifica si ya previamente el estudiante ha reservado un computador.
int ValidarReserva(char puestoPC[12][SIZE],char estudianteCedula[SIZE] )
{
	int i,j;
	for(i=0;i<12;i++)
	{
		if(strcmp(puestoPC[i],estudianteCedula)==0) 
			{
				//Retorna la posicion en que se encuentra la ID.
				return i;
			}
		else
		{
			j++;
		}	
	}
	if(j==12)
	{
		//Si no encuentra la ID en las computadoras,retorna -1, dando a entender que no reservo.
		return -1;
	}
}
//Indentifica si en algun momento todos los computadores estan ocupados.
int LimitarPuestos(char puestoPC[12][SIZE])
{
	int i,j=0;
	for(i=0;i<12;i++)	
	{
		if(strcmp(puestoPC[i], "0")==0)
		{
			//Retorna 1, si hay computadores desocupados.
			return 1;		
		}
		else
		{
			j++;
		}
	}
	if(j==12)
	{
		//De otro modo retorna -1 si todos los puestos estan ocupados.
		return -1;
	}
}
//Funcion sin retorno para finalizar la reservacion de la computadora.
void HabilitarPuesto(char puestoPC[12][SIZE] , char estudianteCedula[SIZE],char baseNombres[20][SIZE],int controlID)
{
	int i,j=0;
	for(i=0;i<12;i++)	
	{
		if(strcmp(puestoPC[i], estudianteCedula)==0)//Si encuentra similitud lo reemplaza por 0(Disponible).
		{
				strcpy(puestoPC[i],"0");
				printf("\033[0;32m");
				printf("\n                           !Felicidades %s hemos realizo su check out con exito!\n",baseNombres[controlID]);
				printf("                                          Se ha liberado el puesto #%d\n", (i+1));
				printf("\033[0m");
				i=12;
		}
		else
		{
			j++;
		}
		if(j==12)//Por si no encuentra similitud.
		{
			printf("\033[0;31m");
			printf("\n\t\tNuestra base de datos nos notifica que usted no ha reservado una computadora previamente.\n");
			printf("                                          No se libero ningun puesto. \n");
			printf("\033[0m");
		}
	}	
}
//Funcion sin retorno que imprime en pantalla las diferentes computadoras, en formato 3x4.
void MostrarPuesto(char puestoPC[12][SIZE])
{
	printf("\n");
	//Identifica los colores de disponibilidad de la primera linea de computadoras.
	//Primera computadora.
	if(strcmp(puestoPC[0], "0")==0)
	{	printf("\033[0;32m");
		printf("      Disponible   ");
	}
	else
	{
		printf("\033[0;31m");
		printf("       Ocupado ");
	}	
	//Segunda computadora.
	if(strcmp(puestoPC[1], "0")==0)
	{	printf("\033[0;32m");
		printf("                  Disponible ");
	}
	else
	{
		printf("\033[0;31m");
		printf("                      Ocupado");
	}
	//Tercera computadora.
	if(strcmp(puestoPC[2], "0")==0)
	{	printf("\033[0;32m");
		printf("                    Disponible ");
	}
	else
	{
		printf("\033[0;31m");
		printf("                        Ocupado ");
	}
	//Cuarta computadora.
	if(strcmp(puestoPC[3], "0")==0)
	{	printf("\033[0;32m");
		printf("                    Disponible ");
	}
	else
	{
		printf("\033[0;31m");
		printf("                      Ocupado ");
	}
	printf("\033[0m");
	//Impresion de la primera fila de computadoras, las 4 primeras.		
	printf("\n.-------------------.          .-------------------.          .-------------------.          .-------------------.\n"); 
	printf("||                 ||          ||                 ||          ||                 ||          ||                 ||\n");
	printf("||                 ||          ||                 ||          ||                 ||          ||                 ||\n");
	printf("||                 ||          ||                 ||          ||                 ||          ||                 ||\n");
	printf("'-------.---.-------'          '-------.---.-------'          '-------.---.-------'          '-------.---.-------'\n");
	printf("________|'='|________          ________|'='|________          ________|'='|________          ________|'='|________\n");
	//Identificar los colores de disponibilidad de la segunda linea de computadoras.
	//Quinta computadora.
	if(strcmp(puestoPC[4], "0")==0)
	{	printf("\033[0;32m");
		printf("      Disponible   ");
	}
	else
	{
		printf("\033[0;31m");
		printf("      Ocupado ");
	}
	//Sexta computadora.	
	if(strcmp(puestoPC[5], "0")==0)
	{	printf("\033[0;32m");
		printf("                  Disponible ");
	}
	else
	{
		printf("\033[0;31m");
		printf("                    Ocupado   ");
	}
	//Septima computadora.
	if(strcmp(puestoPC[6], "0")==0)
	{	printf("\033[0;32m");
		printf("                   Disponible ");
	}
	else
	{
		printf("\033[0;31m");
		printf("                       Ocupado ");
	}
	//Octava computadora.
	if(strcmp(puestoPC[7], "0")==0)
	{	printf("\033[0;32m");
		printf("                    Disponible ");
	}
	else
	{
		printf("\033[0;31m");
		printf("                       Ocupado ");
	}
	printf("\033[0m");
	//Impresion de la segunda fila de computadoras,las 4 siguentes.			
	printf("\n.-------------------.          .-------------------.          .-------------------.          .-------------------.\n"); 
	printf("||                 ||          ||                 ||          ||                 ||          ||                 ||\n");
	printf("||                 ||          ||                 ||          ||                 ||          ||                 ||\n");
	printf("||                 ||          ||                 ||          ||                 ||          ||                 ||\n");
	printf("'-------.---.-------'          '-------.---.-------'          '-------.---.-------'          '-------.---.-------'\n");
	printf("________|'='|________          ________|'='|________          ________|'='|________          ________|'='|________\n");
	//Identificar los colores de disponibilidad de la tercera linea de computadoras.
	//Novena computadora.
	if(strcmp(puestoPC[8], "0")==0)
	{	printf("\033[0;32m");
		printf("      Disponible   ");
	}
	else
	{
		printf("\033[0;31m");
		printf("       Ocupado ");
	}
	//Decima computadora.	
	if(strcmp(puestoPC[9], "0")==0)
	{	printf("\033[0;32m");
		printf("                  Disponible ");
	}
	else
	{
		printf("\033[0;31m");
		printf("                       Ocupado ");
	}
	//Onceava computadora.
	if(strcmp(puestoPC[10], "0")==0)
	{	printf("\033[0;32m");
		printf("                    Disponible ");
	}
	else
	{
		printf("\033[0;31m");
		printf("                        Ocupado ");
	}
	//Duodecima computadora.
	if(strcmp(puestoPC[11], "0")==0)
	{	printf("\033[0;32m");
		printf("                    Disponible ");
	}
	else
	{
		printf("\033[0;31m");
		printf("                      Ocupado ");
	}
	printf("\033[0m");
	//Impresion de la tercera fila, ultimas 4 computadoras.			
	printf("\n.-------------------.          .-------------------.          .-------------------.          .-------------------.\n"); 
	printf("||                 ||          ||                 ||          ||                 ||          ||                 ||\n");
	printf("||                 ||          ||                 ||          ||                 ||          ||                 ||\n");
	printf("||                 ||          ||                 ||          ||                 ||          ||                 ||\n");
	printf("'-------.---.-------'          '-------.---.-------'          '-------.---.-------'          '-------.---.-------'\n");
	printf("________|'='|________          ________|'='|________          ________|'='|________          ________|'='|________\n");
}
//Imprime el menu.
void DesplegarMenu()
{
	printf("\033[0;33m");
    printf("\t\t\t\t--------------------");
    printf("\n\t\t\t\tMenu del laboratorio\n");
    printf("\t\t\t\t--------------------\n");
    printf("Bienvenidos al servicio de reservacion de computadoras.\n\n");
    printf("Seleccione un numero para la accion a realizar:\n\n1. Ver los puestos de las computadoras ocupadas y disponibles\n2. Reservar una computadora\n3. Salir del laboratorio.\n4. Registro del uso del laboratorio\n5. Ver el listado de los estudiantes autorizado para usar el laboratorio\n6. Salir del sistema\n");
    printf("\033[0m");
}
int main()
{
	//Definir dimensiones de pantalla
	system("mode con:cols=115 lines=30");
	//Declaracion de las variables
    char baseNombres[20][SIZE]={//Inicializacion del arreglo con nombres
								"Maria Vidal","Tomas Ribas", "Karen Smith", "Maximo Mora", "Mary Mendez", 
								"Ana Alarcon", "Diego Soria","Abdel White", "Jose Alfaro", "Donna Perez",
								"Rafael Mora","Fabio Rojas","Melania Paz", "Marta Lopez","Isabel Ruiz",
								"Javier Sosa", "Julio Gomez","Carol Reina","Alain Silva","Juan David "
								};
    char baseCedulas[20][SIZE]={//Inicializacion del arreglo con las cedulas.
								"8-123-456","7-764-356" ,"6-275-364" ,"5-854-324","4-765-453",
								"8-654-355" ,"9-253-434","3-786-564","2-646-246","1-256-534",
								"5-434-382","8-756-334","9-535-816","5-824-562","8-994-245",
								"7-534-249","3-775-647","7-464-434","8-845-245","4-556-345",
								};							
    char estudianteCedula[SIZE];//Datos de entrada
    char puestoPC[12][SIZE]={"0","0" ,"0" ,"0","0","0" ,"0","0","0","0","0","0"};//0-Disponible, !=0-Ocupado
	//Arreglos para el historial de uso.
    char registroNombres[20][SIZE];
    char registroCedulas[20][SIZE];
    //Variables para uso variado.
	int i=1,j,controlID,controlVald,controlPuesto,controlLista=0;
    while(i!=0)
    {
		system("cls");
		DesplegarMenu();
		printf("\033[0;33m");
		printf("\nElija que accion desea realizar:");
		printf("\033[0m");
		scanf("%d", &i);
		switch (i)
		{
			case 1:
				system("cls"); 
				printf("Ha seleccionado ver las computadoras ocupadas y disponibles:\n");
				MostrarPuesto(puestoPC);//Envio mi arreglo de computadoras para que se imprima.
				system("PAUSE");
				break;
			case 2: 
				system("cls"); 
				printf("Ha seleccionado reservar una computadora\nPara proceder con la reservacion favor de digitar su cedula para confirmar el registro:");
				scanf("%s", estudianteCedula);
				controlVald=ValidarReserva(puestoPC,estudianteCedula);
				if(controlVald==-1)
				{
					controlID=VerificarID(baseCedulas,estudianteCedula);//Retorna la posicion del ID en el arreglo.
					if(controlID!=-1)//Uso el numero que retorna para imprimir los nombre y cedulas correspondientes.
					{
						printf("\033[0;32m");
						printf("\n\t\tBienvenido/a %s, a continuacion te mostraremos las computadoras en disponibilidad:\n" ,baseNombres[controlID]);
						printf("\033[0m");
						MostrarPuesto(puestoPC);
						//Arreglos para el registro de uso
						strcpy(registroNombres[controlLista],baseNombres[controlID]);
						strcpy(registroCedulas[controlLista],baseCedulas[controlID]);
						//Incrementa por cada registro satisfacctorio.
						controlLista++;
						//Indentifica primeramente si el arreglo esta todo lleno, de ser asi no podra asginarle un computador.
						controlPuesto=LimitarPuestos(puestoPC);
						if(controlPuesto==-1)
						{
							//No se le asigna un computador, y le muestra el mensaje en pantalla.
							printf("\033[0;31m");
							printf("\n                 Lastimosamente no tenemos computadores disponibles, favor de regresar mas tarde.\n");
							printf("\033[0m");
						}
						else
						{
							//Asgina el ID del estudiante en el primer lugar disponible que encuentre, recordando que 0 es disponible y la ID ocupado.
							for(i=0;i<12;i++)
							{
								if(strcmp(puestoPC[i], "0")==0) 
								{
									while(j<1)
		                            {
		                            	//Copia el ID del estudiante en el arreglo de las PC.
										strcpy(puestoPC[i],estudianteCedula);
										printf("\033[0;32m");
										printf("\n                           !Enhorabuena %s se le asgino la computadora #%d!\n",baseNombres[controlID], (i+1));
										printf("\033[0m");
										j++;
									}
								}
							}
							j=0;
						}
					}
					else//Retorna -1 si el ID no se encuentra, por ende no podra reservar.
					{
						printf("\033[0;31m");
						printf("\n\t\t\t   Su ID no se encuentra en el registro, no podra reservar una computadora.\n");//No se encuentra en la base de datos.
						printf("\033[0m");
					}
				}
				else//Por si el usuario trata de reservar otro PC.
				{
					printf("\033[0;31m");
					printf("\n\t\t\t    Usted ya se encuentra dentro del laboratorio, no podra reservar.\n");
					printf("\033[0m");
				}
				system("PAUSE"); 
				break;
			case 3:
				system("cls");
				printf("Ha seleccionado salir del laboratorio\n");
				//Se pide que se ingrese el ID para poder reemplazarlo por 0.
				printf("Ingrese su cedula para proceder con el check out: ");
				scanf("%s", estudianteCedula);
				//La funcion retorna la posicion de su nombre en la base de datos.
				controlID=VerificarID(baseCedulas,estudianteCedula);
				//La funcion se encarga de reemplar el ID del estudiante, si la encuentra por un 0, dando a entender que se encuentra disponible.
				HabilitarPuesto(puestoPC,estudianteCedula,baseNombres,controlID);
				//Imprimir el puesto que se han habilitado.
				MostrarPuesto(puestoPC);
				system("PAUSE");
				break;
			case 4:
				system("cls");
				printf("\033[0;34m");
				printf("Cargando el listado . . .\n");
				printf("o_______________________________o\n");
				printf("|        Historial de uso       |\n");
				printf("|_______________________________|\n");
				printf("|    Nombres  ");printf("   | ");printf("   Cedulas   |\n|");
				printf("________________|______________|\n|");
				printf("                |              |\n");
				for(i=0;i<controlLista;i++)//Aumenta dependiendo de las personas que reserven.
				{
					printf("|  %s   |  ", registroNombres[i]);
					printf(" %s  |    \n",registroCedulas[i]);
				}
				printf("o________________|______________o\n");
				system("PAUSE");
				printf("\033[0m");
				break;
			case 5:
				system("cls");
				printf("\033[0;35m");
				printf("Cargando el listado . . .\n");
				printf("o_______________________________o\n");
				printf("|       Listado autorizado      |\n");
				printf("|_______________________________|\n");
				printf("|    Nombres  ");printf("   | ");printf("    Cedulas  |\n|");
				printf("________________|______________|\n|");
				printf("                |              |\n");
				for(i=0; i<20; i++)
				{
					printf("|  %s   |  ", baseNombres[i]);
					printf(" %s  |    \n", baseCedulas[i]);
				}
				printf("o________________|______________o\n");
				system("PAUSE");
				printf("\033[0m");
				break;
			case 6:
				system("cls");
				printf("\033[0;32m");
				printf("Saliendo del sistema . . .\n");
				printf("\033[0m");
				i=0;
				break;
			default:
				system("cls");
				printf("\033[0;31m");
				printf("Tecla equivocada, favor de seleccionar un numero del 1 al 6.\n");
				printf("\033[0m");
				system("PAUSE");
				break;
    	}
	}
    return 0;
}
