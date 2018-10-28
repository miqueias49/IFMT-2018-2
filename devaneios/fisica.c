
//[ informacoes do criador e do sistema ]///////////////////////////////////////////
//
// Create by: Miqueias da Silva Miranda
//
// Program: calculadora de fisica
//
// Release:
//
//	v.1 - Iniciado o projeto - 2018-10-27
//
//
////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <form.h>
#include <ncurses.h>
#include <panel.h>
#include <menu.h>
//========================================================================================
//    Funcoes standard usadas neste projeto
//========================================================================================
// 	stdio.h
// 		printf();
//
// 	stdio_ext.h
// 		
// 	stdlib.h
//
// 	string.h
//
// 	ncurses.h
//
//========================================================================================
   

//========================================================================================


//========================================================================================


int main( int argc, char** argv )
{
	FIELD *field[3];
	FORM *my_form;
	int ch;


	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);


	my_wins[0] = newwin(lines, cols, y, x);
	my_wins[1] = newwin(lines, cols, y + 1, x + 5);
	my_wins[2] = newwin(lines, cols, y + 2, x + 10);
	
	field[0] = 

//========================================================================================

//========================================================================================
	getch();
	endwin();


	return 0;
}// fim da função main

