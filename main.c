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
    int clicks = 0;

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
                Ficha *num;
                    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    {
                        num = DetectF(GetMouseX(), GetMouseY(), Blancas);
                        if(num == NULL)
                        {
                            DrawText("Pendejo", 200,400,36,RED);
                        }
                        else
                        {
                            CirculosR(num);
                        }
                    }
            }

        EndDrawing();
        }
    CloseWindow();
    return 0;
}