/***********************************************************************
 * Module:  Menu.cpp
 * Author:  USER
 * Modified: viernes, 10 de junio de 2022 1:30:46
 * Purpose: Implementation of the class Menu
 ***********************************************************************/


#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>




#include "Menu.h"


using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Menu::Menu()
// Purpose:    Implementation of Menu::Menu()
// Return:     
////////////////////////////////////////////////////////////////////////

Menu::Menu()
{
	*(menuHead + 0) = "	REGISTRAR UN NUEVO AUTO  	";//0
	*(menuHead + 1) = "	MOSTRAR REGISTROS 			";//1
	*(menuHead + 2) = "	BUSCAR REGISTRO				";//2
	*(menuHead + 3) = "	ELIMINAR REGISTRO			";//3
	*(menuHead + 4) = "	GENERAR ARCHIVO             ";//4
	*(menuHead + 5) = "	FOTO PIXELEADA";//5
	*(menuHead + 6) = "	SALIR";                       //6
}


////////////////////////////////////////////////////////////////////////
// Name:       Menu::MenuCursor()
// Purpose:    Implementation of Menu::MenuCursor()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Menu::MenuCursor()
{
	int cursor = 0;
	char tecla;

	for (;;) {
		system("cls");
		cout << endl;
		cout << "					MENU DE OPCIONES                    " << endl;
		for (int i = 0; i < 7; i++) {
			if (cursor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << *(menuHead + i) << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << *(menuHead + i) << endl;
			}
		}
		for (;;) {
			tecla = _getch();
			if (tecla == 80) {
				cursor++;
				if (cursor == 7) {
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) {
				cursor--;
				if (cursor == -1) {
					cursor = 7;
				}
				break;
			}
			if (tecla == 13) {
				return cursor;
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Menu::Gotoxy(int x, int y)
// Purpose:    Implementation of Menu::Gotoxy()
// Parameters:
// - x
// - y
// Return:     void
////////////////////////////////////////////////////////////////////////

void Menu::Gotoxy(int x, int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}


////////////////////////////////////////////////////////////////////////
// Name:       Menu::Marquesina(std::string texto)
// Purpose:    Implementation of Menu::Marquesina()
// Parameters:
// - texto
// Return:     void
////////////////////////////////////////////////////////////////////////

void Menu::Marquesina(std::string texto)
{
	unsigned short derecha, izquierda, repite;
	int longitud = texto.length();

	for (repite = 1; repite <= 1; repite++)
	{
		for (izquierda = longitud; izquierda >= 1; izquierda--)
		{
			system("cls");
			printf("\b");
			Menu::Gotoxy(izquierda, 1);
			cout << texto;
			usleep(10000);
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Menu::usleep(__int64 usec)
// Purpose:    Implementation of Menu::usleep()
// Parameters:
// - usec
// Return:     void
////////////////////////////////////////////////////////////////////////


void Menu::usleep(__int64 usec)
{
	HANDLE timer;
	LARGE_INTEGER ft;
	ft.QuadPart = -(10 * usec); // Convert to 100 nanosecond interval, negative value indicates relative time
	timer = CreateWaitableTimer(NULL, TRUE, NULL);
	SetWaitableTimer(timer, &ft, 0, NULL, NULL, 0);
	WaitForSingleObject(timer, INFINITE);
	CloseHandle(timer);
}
