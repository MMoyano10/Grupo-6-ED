/***********************************************************************
 * Module:  Menu.h
 * Author:  USER
 * Modified: viernes, 10 de junio de 2022 1:30:46
 * Purpose: Declaration of the class Menu
 ***********************************************************************/

#pragma once
#include <string>

#if !defined(__Class_Diagram_1_Menu_h)
#define __Class_Diagram_1_Menu_h

class Menu {
private:
	std::string *menuHead = new std::string[7];
public:
	Menu();
	int MenuCursor();
	void Gotoxy(int x, int y);
	void Marquesina(std::string texto);
	void usleep(__int64 usec);
};

#endif