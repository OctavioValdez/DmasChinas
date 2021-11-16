
#ifndef PROYECTOPROGRA_SETTINGS_H
#define PROYECTOPROGRA_SETTINGS_H

typedef struct Color color;
typedef struct ficha Ficha;

void TableroDisplay(int width,int height);
int **CrearTablero();
Ficha *Crear_fichas(int C);
void DibujarFichas(Ficha * fichas, color C);
void Display(Ficha * fichas);
void addF(Ficha * ficha,int x, int y, int id);
void premovimiento(int x, int y, Ficha * fichas);
#endif //PROYECTOPROGRA_SETTINGS_H
