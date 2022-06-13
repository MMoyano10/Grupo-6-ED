#include <iostream>
#include <windows.h>


/***********************************************************************
 * Module:  ListaDobleCircular.cpp
 * Author:  USER
 * Modified: viernes, 10 de junio de 2022 1:25:56
 * Purpose: Implementation of the class EaEasyBMP
 ***********************************************************************/
#include "EasyBMP.h"
 /***********************************************************************
  * Module:  ListaDobleCircular.cpp
  * Author:  USER
  * Modified: viernes, 10 de junio de 2022 1:25:56
  * Purpose: Implementation of the class EasyBMP_BMP
  ***********************************************************************/
#include "EasyBMP_BMP.h"
  /***********************************************************************
   * Module:  ListaDobleCircular.cpp
   * Author:  USER
   * Modified: viernes, 10 de junio de 2022 1:25:56
   * Purpose: Implementation of the class EasyBMP_DataStructures
   ***********************************************************************/
#include "EasyBMP_DataStructures.h"
   /***********************************************************************
    * Module:  ListaDobleCircular.cpp
    * Author:  USER
    * Modified: viernes, 10 de junio de 2022 1:25:56
    * Purpose: Implementation of the class EasyBMP_VariousBMPutilities
    ***********************************************************************/
#include "EasyBMP_VariousBMPutilities.h"

 /***********************************************************************
  * Module:  ListaDobleCircular.cpp
  * Author:  USER
  * Modified: viernes, 10 de junio de 2022 1:25:56
  * Purpose: Implementation of the class Imagen
  ***********************************************************************/
#include "Imagen.h"
using namespace std;


////////////////////////////////////////////////////////////////////////
// Name:       Imagen::DrwImage()
// Purpose:    Implementation of Imagen::DrwImage()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Imagen::DrwImage()
{   
    HDC console = GetDC(GetConsoleWindow());
    std::string imagePath = "EasyBMPbackground.bmp";
    system("cls");
    BMP image;
    image.ReadFromFile(imagePath.c_str());
    for (int x = 0; x < image.TellWidth(); x++)
    {
        for (int y = 0; y < image.TellHeight(); y++)
        {
            int RED = image.GetPixel(x, y).Red;
            int GREEN = image.GetPixel(x, y).Green;
            int BLUE = image.GetPixel(x, y).Blue;

            int ALPHA = image.GetPixel(x, y).Alpha;

            COLORREF COLOUR = RGB(RED, GREEN, BLUE);
            if (ALPHA == 0) {
                SetPixel(console, x, y, COLOUR);
            }
        }
    }
}
