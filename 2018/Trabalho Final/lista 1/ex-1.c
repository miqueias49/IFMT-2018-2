//==================================================================================
//
// Create by: Miqueias da Silva Miranda
//
//==================================================================================
//==================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DB-TXT.h"
int main( int argc, char** argv )
{	
	int opt;

	while (1) 
	{
		scanf("%d", &opt);
		if (opt < 0) 
		{
			break;
		}
		switch (opt) 
		{
			case 1:
				menu_1();
				db_add(" %a %a %a %s         ");
				break;
			case 2:
				menu_2();
				break;
			case 3:
				menu_3();
				break;
			default:
				printf("Opcao invalida.\n");
				break;
		}
	}// fim do while 
	
	return 0;
}
