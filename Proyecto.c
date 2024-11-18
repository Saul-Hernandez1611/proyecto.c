/*FUNDAMENTOS DE PROGRAMACION
GARCIA HERNANDEZ ERCIK SAUL
PROYECTO FINAL*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PUEBLOS 100
#define BEBIDAS 8

void inicializarMatriz(int matriz[PUEBLOS][BEBIDAS]);
void llenarMatriz(int matriz[PUEBLOS][BEBIDAS]);
void calcularTotales(int matriz[PUEBLOS][BEBIDAS], int totales[BEBIDAS]);
int RegistrarBebidaMasConsumida(int totales[BEBIDAS]);
int calculoConsumoAlcohol(int matriz[PUEBLOS][BEBIDAS], int totalAlcohol[PUEBLOS]);

int main()

{
    int matriz[PUEBLOS][BEBIDAS]; 
    int totales[BEBIDAS] = {0}; 
    int totalAlcohol[PUEBLOS] = {0};
    int bebidaMasConsumida, puebloMaxAlcohol;

    inicializarMatriz(matriz);

    llenarMatriz(matriz);

    calcularTotales(matriz, totales);

    bebidaMasConsumida = RegistrarBebidaMasConsumida(totales);
    printf("La bebida %d es la más consumida con %d litros.\n", bebidaMasConsumida, totales[bebidaMasConsumida]);

    puebloMaxAlcohol = calculoConsumoAlcohol(matriz, totalAlcohol);
    printf("El pueblo %d consume más alcohol con %d litros.\n", puebloMaxAlcohol, totalAlcohol[puebloMaxAlcohol]);

    return 0;
}

void inicializarMatriz(int matriz[PUEBLOS][BEBIDAS])
{
    for (int i = 0; i < PUEBLOS; i++)
        for (int j = 0; j < BEBIDAS; j++)
            matriz[i][j] = 0;
}


void llenarMatriz(int matriz[PUEBLOS][BEBIDAS])
{
    int pueblo, bebida, cantidad;

    for (pueblo = 0; pueblo < PUEBLOS; pueblo++)
    {
        printf("\nRegistro de consumo para el pueblo %d\n", pueblo);
        while (1)
        {
            printf("Ingrese el número de la bebida (0-7, -1 para terminar): ");
            scanf("%d", &bebida);
            if (bebida == -1)
                break;

            if (bebida < 0 || bebida >= BEBIDAS)
            {
                printf("Bebida no válida. Intente nuevamente.\n");
                continue;
            }

            printf("Ingrese la cantidad en litros: ");
            scanf("%d", &cantidad);

            if (cantidad < 0)
            {
                printf("La cantidad no puede ser negativa. Intente nuevamente.\n");
                continue;
            }

            matriz[pueblo][bebida] += cantidad;
        }
    }
}

void calcularTotales(int matriz[PUEBLOS][BEBIDAS], int totales[BEBIDAS])
{
    for (int j = 0; j < BEBIDAS; j++)
        for (int i = 0; i < PUEBLOS; i++)
            totales[j] += matriz[i][j];
}

int RegistrarBebidaMasConsumida(int totales[BEBIDAS])
{
    int max = 0, bebida = 0;

    for (int i = 0; i < BEBIDAS; i++)
    {
        if (totales[i] > max)
        {
            max = totales[i];
            bebida = i;
        }
    }

    return bebida;
}

int calculoConsumoAlcohol(int matriz[PUEBLOS][BEBIDAS], int totalAlcohol[PUEBLOS])
{
    int maxAlcohol = 0, puebloMax = 0;

    for (int i = 0; i < PUEBLOS; i++)
    {
        for (int j = 0; j < BEBIDAS; j++)
        {
            if (j != 1 && j != 6)
                totalAlcohol[i] += matriz[i][j];
        }

        if (totalAlcohol[i] > maxAlcohol)
        {
            maxAlcohol = totalAlcohol[i];
            puebloMax = i;
        }
    }

    return puebloMax;
}
