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

    SetTargetFPS(20);
    int ** Tablero = CrearTablero();
    Ficha * Negras = Crear_fichas(1);
    Ficha * Blancas = Crear_fichas(2);
    int turno = 1;
    int* ptrTurno = &turno;
    int clicks = 0;

    int wasMousePressed = 0;
    Ficha *selected = NULL;


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
              if(selected)
              {
                // aqui ya tenemos una ficha seleccionada, que queremos hacer con ella
                CirculosR(selected);
                if(IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                  // aqui posiblemente queremos revisar si el siguiente click del usuario es
                  // en un movimiento legal? si lo es, realizarlo, si no lo es, "limpiar" la seleccion con selected=null
                  selected = NULL;
                }

              }

              if( selected == NULL && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                    {
                      selected = DetectF(GetMouseX(), GetMouseY(), Blancas);
                      if(selected == NULL)
                        DrawText("eres un burro", 200,400,36,RED);
                    }

            }

        EndDrawing();
        }
    CloseWindow();
    return 0;
}