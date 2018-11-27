#ifndef DB_TXT_H
#define DB_TXT_H

	struct produto 
	{
		int 	index;
		char 	nome[80];
		float 	qtd;
		float	preco;
	};
	typedef struct produto PROD;

void db_add(char* tam, ... );
void db_search(char* tam, ... );
void db_exclude(char* tam, ... );

void menu_1();
void menu_2();
void menu_3();


#endif // end DB_TXT_H 
