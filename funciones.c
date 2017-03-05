#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "funciones.h"

void 
crearDirectorioConArchivos()
{
	system("clear");
	DIR *dir;//Puntero de tipo DIR
	int len;//logitud de cadena de la ruta
	char *username = getenv( "USER" );//Obtener el nombre del usuario
	if(username==NULL) 
		printf("Error al obtener el nombre de usuario :(\n");
	else // Crear directorio
	{
		int crearDir;
		char ruta[100];
		printf("Hola %s :D\n",username);
		printf("Ingrese la ruta donde serán creados los archivos:\n");
		scanf( "%s" , ruta );
		len = strlen(ruta);
		if( ruta[len-1] != '/' )
			strcat(ruta,"/");
		dir = opendir( ruta );//Regresa puntero al directorio si existe, NULL en caso contrario
		if( dir != NULL )//Si existe el directorio
		{
			printf("\nError al crear el directorio, ya existe o la ruta esta mal especificada\n");
			closedir( dir );
		}
		else//Si no existe
		{
			crearDir = mkdir( ruta, 0777 );//Crear el directorio con todos los permisos
			if( crearDir != 0 )
				printf("\nOcurrio un error al crear el archivo\n");
			else
			{
				printf("\nSe ha creado exitosamente el directorio :)\n");
				generarArchivos( ruta );
			}
			
			
		}
	}
}

void
generarArchivos( char* ruta )
{
	int a;
	int i;
	int n;
	char cadena[100];
	char archivo[20];//Nombre del archivo
	char direccion[150]={};
	system("clear");
	printf("\nIngresa la cantidad de archivos a generar:\t");
	scanf("%d",&n);
	fflush(stdin);
	for( i = 0 ; i <n ; i++ )
	{
		strcat(direccion,ruta);
		fflush(stdin);
		printf("\nIngresa el nombre del archivo %d:\t", i+1);
		fflush(stdin);
		scanf("%s",archivo);
		strcat(direccion,archivo);
		printf("\n\tIngresa la cadena a ingresar en el archivo:\t");
		fflush(stdin);
		scanf("%s",cadena);
		printf("\n\tSe ha guardado el archivo en:\n\t %s\n",direccion);
		a = open (direccion, O_CREAT|O_WRONLY,0777);//Crea el archivo
		write(a,cadena,strlen(cadena));//Escribe la cadena ingresada en el archivo
		close(a);//Cierra el archivo
		memset(archivo,0,20);
		memset(cadena,0,100);
		memset(direccion,0,150);
		fflush(stdout);
	}
	
}
