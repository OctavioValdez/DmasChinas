
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
void cambioDeTurno(int* Turno);
Ficha* DetectF(int x, int y,Ficha* ficha);
void CirculosR(Ficha *ficha);
void Movimiento(Ficha *ficha);
int PosDiagonal(int x, int y, Ficha* ficha);
void prueba(Ficha* fichas);
#endif //PROYECTOPROGRA_SETTINGS_H
