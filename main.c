#include "raylib.h"
#include "settings.h"
#include <stdio.h>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 800;
    Color BAGE;
    BAGE.r = 207;
    BAGE.g = 185;
    BAGE.b = 151;

    InitWindow(screenWidth, screenHeight, "Damas Chinas");

    SetTargetFPS(60);
    int ** Tablero = CrearTablero();
    Ficha * Negras = Crear_fichas(1);
    Ficha * Blancas = Crear_fichas(2);
    int turno = 1;
    int* ptrTurno = &turno;


    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        BeginDrawing();

        ClearBackground(BAGE);
        TableroDisplay(screenWidth,screenHeight);
        DibujarFichas(Negras, BLACK);
        DibujarFichas(Blancas, WHITE);


//            if(turno == 0)
//            {
//                Ficha * num = DetectF(GetMouseX(), GetMouseY(), Negras);
//                CirculosR(num);
//                turno = 1;
//            }
            if(turno == 1)
            {

                if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                    int clicks = 0;
                    clicks ++;
                    int x = GetMouseX();
                    int y = GetMouseY();
                    Ficha *num = DetectF(x, y, Blancas);
                    if(num == NULL)
                    {
                        DrawText("Pendejo", 200,200,36,RED);
                    }
                    else if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && clicks == 1)
                    {
                        CirculosR(num);
                        if(PosDiagonal(x,y,num) == 1)
                            Movimiento(num,Blancas);


                    }

                }

            }
        EndDrawing();
        }




    CloseWindow();

    return 0;
}