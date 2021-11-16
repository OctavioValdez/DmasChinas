#include "settings.h"
#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>

struct ficha
{
    int x;
    int y;
    int id;
    int vida;
    struct ficha* sig;
}typedef Ficha;

void TableroDisplay(int width,int height)
{
    int y;
    int x;

    for (y = 0; y <= 700; y = y + 200)
    {
        for(x = 100; x <= 700; x = x + 200)
        {
            DrawRectangle(x,y,100,100,BROWN);
        }
    }

    for(y = 100; y <= 700;y = y+ 200)
    {
        for(x = 0; x <= 700; x = x + 200)
        {
            DrawRectangle(x,y,100,100,BROWN);
        }
    }

    for (int i = 0; i < width; i = i + width /8)
        DrawLine(i + width/8, 0, i + width/8, height, BLACK);
    for (int i = 0; i < height; i = i + height/8)
        DrawLine(0, i + height/8, width, i + height/8, BLACK);

}

int** CrearTablero()
{
    int** tablero = (int**)malloc(8 * sizeof (int *));

    for (int i = 0; i < 8; i++)
    {
        tablero[i] = (int *)malloc(8 * sizeof(int));
    }

    for (int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            tablero[i][j] = 0;
        }
    }
//  Negras
    for (int i = 1; i < 8; i = i + 2)
    {
        tablero[0][i] = 1;
    }

    for(int i = 0 ; i < 8; i = i + 2)
    {
        tablero[1][i] = 1;
    }

    for(int i = 1 ; i < 8; i = i + 2)
    {
        tablero[2][i] = 1;
    }
//    Blancas
    for (int i = 0; i < 8; i = i + 2)
    {
        tablero[5][i] = 2;
    }

    for(int i = 1 ; i < 8; i = i + 2)
    {
        tablero[6][i] = 2;
    }

    for(int i = 0 ; i < 8; i = i + 2)
    {
        tablero[7][i] = 2;
    }

    return tablero;
}

void addF(Ficha * ficha,int x, int y, int id)
{
     Ficha* Current = ficha;

    while(Current -> sig != NULL)
        Current = Current -> sig;

    Current -> sig = malloc(sizeof(Ficha));
    Current -> sig -> x = x;
    Current -> sig -> y = y;
    Current -> sig -> vida = 1;
    Current -> sig -> id = id;
    Current -> sig -> sig = NULL;

}

Ficha *Crear_fichas(int C)
{
    if(C == 1) {
        Ficha *N1 = malloc(sizeof(Ficha));
        N1->sig = NULL;
        int pos_x = 150;
        int pos_y = 50;
        int cont_id = 0;

        for (int i = 0; i < 4; i++) {
            addF(N1, pos_x, pos_y, cont_id);
            pos_x = pos_x + 200;
            cont_id++;
        }

        pos_x = 50;
        pos_y = pos_y + 100;

        for (int i = 0; i < 4; i++) {
            addF(N1, pos_x, pos_y, cont_id);
            pos_x = pos_x + 200;
            cont_id++;
        }

        pos_x = 150;
        pos_y = pos_y + 100;

        for (int i = 0; i < 4; i++) {
            addF(N1, pos_x, pos_y, cont_id);
            pos_x = pos_x + 200;
            cont_id++;
        }

        return N1;
    }
    else
    {
        Ficha *N1 = malloc(sizeof(Ficha));
        N1->sig = NULL;
        int pos_x = 50;
        int pos_y = 550;
        int cont_id = 12;

        for (int i = 0; i < 4; i++) {
            addF(N1, pos_x, pos_y, cont_id);
            pos_x = pos_x + 200;
            cont_id++;
        }

        pos_x = 150;
        pos_y = pos_y + 100;

        for (int i = 0; i < 4; i++) {
            addF(N1, pos_x, pos_y, cont_id);
            pos_x = pos_x + 200;
            cont_id++;
        }

        pos_x = 50;
        pos_y = pos_y + 100;

        for (int i = 0; i < 4; i++) {
            addF(N1, pos_x, pos_y, cont_id);
            pos_x = pos_x + 200;
            cont_id++;
        }

        return N1;
    }

}

void DibujarFichas(Ficha * fichas, color C)
{
    Ficha* Current = fichas -> sig;
    while(Current != NULL)
    {
        DrawCircle(Current->x,Current->y, 45, C);
        Current = Current -> sig;
    }
}

void Display(Ficha * fichas)
{
    Ficha* Current = fichas;
    while (Current != NULL)
    {
        printf("%d, %d, %d\n",Current -> x, Current -> y, Current -> id);
        Current = Current -> sig;
    }
}

void premovimiento(int x, int y,Ficha * fichas)
{
    Ficha * current = fichas -> sig;
    int x_fichaD = current -> x + 45, x_fichaI = current -> x - 45;
    int y_fichaD = current -> y + 45, y_fichaU = current -> y - 45;

    while(current != NULL)
    {
        x_fichaD = current -> x + 45, x_fichaI = current -> x - 45;
        y_fichaD = current -> y + 45, y_fichaU = current -> y - 45;

        if (x > x_fichaI &&  x < x_fichaD)
        {
            if ( y > y_fichaU &&  y < y_fichaD)
            {
                printf("Ahuevo que si");
                break;
            }
        }
        current = current -> sig;
    }

    if(current == NULL)
        printf("Pendejo\n");
}