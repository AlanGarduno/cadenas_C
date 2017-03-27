#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int longitud(char* cadena);
char* concatenacion(char* dest, char* sour);
char* prefijo(char* cad, int n);
char* subfijo(char* cad, int n);
char* invertir(char* cad);
void potencia(char* cad, int n);
char* subcad(char* cad, int n, int m);
char *subsec(char* cad, char* carac);

int main(int argc, char const *argv[])
{
	int loop,res,pre,sub,pot,respot;
	char *cad1 = (char*)malloc(sizeof(char)*5);
	char *cad2 = (char*)malloc(sizeof(char)*5);
	char *elem = (char*)malloc(sizeof(char)*5);
	printf("Opeaciones con cadenas\n");
	printf("Ingresa 2 cadenas\n");
	printf("Cadena 1\n");
	scanf("%s",cad1);
	printf("Cadena 2\n");
	scanf("%s",cad2);
	do
	{
		printf("Elige una opcion:\n");
		printf("1.Concatenacion\n2.Prefijo\n3.Subfijo\n4.Subcadena\n5.Subsecuencia\n6.Inversa\n7.Potencia\n");
		scanf("%d",&res);
		switch(res)
		{
			case 1:
				printf("Concatenacion\n");
				printf("Cadena1-Cadena2\n");
				printf("%s\n",concatenacion(cad1,cad2));
				printf("Cadena2-Cadena1\n");
				printf("%s\n",concatenacion(cad2,cad1));
			break;
			case 2:
				printf("Prefijo\n");
				printf("Ingresa el largo del prefijo\n");
				scanf("%d",&pre);
				printf("Prefijo Cadena1\n");
				printf("%s\n",prefijo(cad1,pre));
				printf("Prefijo Cadena2\n");
				printf("%s\n",prefijo(cad2,pre));
			break;
			case 3:
				printf("Subfijo\n");
				printf("Ingresa el largo del Subfijo\n");
				scanf("%d",&sub);
				printf("Prefijo Cadena1\n");
				printf("%s\n",subfijo(cad1,sub));
				printf("Prefijo Cadena2\n");
				printf("%s\n",subfijo(cad2,sub));
			break;
			case 4:
				printf("Subcadena\n");
				printf("Ingresa el largo del prefijo\n");
				scanf("%d",&pre);
				printf("Ingresa el largo del subfijo\n");
				scanf("%d",&sub);
				printf("Subcadena Cadena1\n");
				printf("%s\n",subcad(cad1,sub,pre));
				printf("Subcadena Cadena2\n");
				printf("%s\n",subcad(cad2,sub,pre));
			break;
			case 5:
				printf("Subsecuencia\n");
				printf("La cadeana1 es %s\n",cad1);
				printf("Ingresa los caracteres que deseas quitar de esa cadena\n");
				scanf("%s",elem);
				printf("Subsecuencia de la cadeana1\n");
				printf("%s\n",subsec(cad1,elem));
				printf("La cadeana2 es %s\n",cad2);
				printf("Ingresa los caracteres que deseas quitar de esa cadena\n");
				scanf("%s",elem);
				printf("Subsecuencia de la cadeana1\n");
				printf("%s\n",subsec(cad2,elem));
			break;
			case 6:
				printf("Inversa\n");
				printf("Inversa Cadena1\n");
				printf("%s\n",invertir(cad1));
				printf("Inversa Cadena2\n");
				printf("%s\n",invertir(cad2));
			break;
			case 7:
				printf("Potencia\n");
				printf("De que cadena deseas obtener la potencia\n1.Cadena1\n2.Cadena2");
				scanf("%d",&respot);
				switch(respot)
				{
					case 1:
						printf("Ingresa el n(numero al que se elevara la cadena)\n");
						scanf("%d",&pot);
						potencia(cad1,pot);
					break;
					case 2:
						printf("Ingresa el n(numero al que se elevara la cadena)\n");
						scanf("%d",&pot);
						potencia(cad2,pot);
					break;
				}
			break;
		}
		printf("1.Volver al menu\n2.Salir");
		scanf("%d",&loop);
		system("cls");
	}while(loop != 2);
	return 0;
}

/*Obtiene la longitud de una cadena, a partir de un puntero a la misma
Programado por: Alan Garduño Velazquez
*/

int longitud(char* cadena)
{
	int i = 0, tam = 0;
	while(cadena[i] != '\0')
	{
		tam = tam + 1;
		i++;
	}
	return tam;
}

/*Concatena dos cadenas, modificando el destino, añaddiendo en la parte final, la segunda cadena
Al ser punteros C los redefine a su nuevo tamaño automaticamente, de igual manera funciona correctamente con arreglos de caracterres
Programado por: Alan Garduño Velazquez
*/

char* concatenacion(char* dest, char* sour)
{
	int i=strlen(dest),j;
	for(j = 0;sour[j] != '\0'; j++)
		dest[i+j] = sour[j];

	dest[i+j] = '\0';

	return dest;
}

/*Se invierte una cadena
programado por: Alan Garduño Velazquez
*/
char* invertir(char* cad)
{
	int i,x;
	char* aux = (char*)malloc(sizeof(longitud(cad)));
	for(i = 0, x = longitud(cad)-1;x>=0;x--,i++)
	{
		aux[i] = cad[x];
	}
	aux[i] = '\0';
	return aux;
}

void potencia(char* cad, int n)
{
	int i;
	char* aux = (char*)malloc(sizeof(longitud(cad))*n);
	//char* aux2 = (char*)malloc(sizeof(longitud(cad))*n);
	if(n > 0)                                                                                                                                                                                                                                                                                                                                                                                                               
	{
		for(i = 1; i <= n ;i++)
		{
			 strcat(aux,cad);
		}
		printf("%s",aux);
	}
	else if( n == 0)
	{
		printf("%c\n",004);
	}
	else
	{
		cad = invertir(cad);
		n = n*(-1);
		printf("%s\n",cad);
		for (i = 1; i<= n;i++)
		{
			strcat(aux,cad);
		}
		printf("%s",aux);
	}
}

/*Se obtine el prefijo de una cadena apartir de n caracteres que se deseen retirar de la cadena origina
programado por: Alan Garduño Velazquez
*/
char* prefijo(char* cad, int n)
{
	char* aux = (char*)malloc(sizeof(longitud(cad))*n);
	int lon = longitud(cad);
	if(lon < n)
	{
		printf("ERROR\n");
	}
	else if(lon == n)
	{
		printf("%s\n",004);
	}
	else
	{
		int i;
		int k = lon - n;
		for (i = 0; i < k ; i++) 
        {
            aux[i] = cad[i];
        }
        aux[i] = '\0';
        return aux;
	}

}

/*Se obtine el prefijo de una cadena apartit de n caracteres que se deseen retirar de la cadena origina
programado por: Alan Garduño Velazquez
*/
char* subfijo(char* cad, int n)
{
	char* aux = (char*)malloc(sizeof(longitud(cad)));
	int lon = longitud(cad);
	if(lon < n)
	{
		printf("ERROR\n");
	} 
	else if( lon == n)
	{
		printf("%s\n",004);
	}
	else
	{
		int i,x;
		for (i=n ,x = 0;i < lon ;i++,x++) // SE PONE COMO INICO DEL FOR DESDE N PARA QUITAR LO DEL PRINCIOPI
        {
            aux[x] = cad[i]; //SE GUARDA EN EL AUXILIAR
        }
        aux[x]='\0';

        return  aux;
	}
}

char* subcad(char* cad, int n, int m)
{
	int lon = longitud(cad);
	char *aux,*aux2;

	if((n + m) > lon)
	{
		printf("ERROR\n");
	}
	else if((n+m) == lon)
	{
		printf("%s\n",004);
	}
	else
	{
		aux = prefijo(cad,n);
		aux2 = subfijo(cad,m);
		return aux2;
	}

}

char* subsec(char* cad, char* carac)
{
	char *aux = (char*)malloc(sizeof(longitud(cad)-longitud(carac)));
	int i =0, j=0,k=0;
	if (longitud(cad) < longitud(carac))
	{
		printf("ERROR\n");
	}
	else if(longitud(cad) == longitud(carac))
	{
		printf("Cadena vacia\n");
	}
	else
	{
		while(cad[i] != '\0')
		{
			if(cad[i] == carac[j])
			{
				j++;
			}
			else
			{
				aux[k] = cad[i];
				k++;
			}
			i++;
		}
	}
	return aux;
}