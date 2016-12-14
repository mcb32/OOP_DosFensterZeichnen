#ifndef _gotoxy_clscr_     // Prüfe ob der Begriff _gotoxy_clscr_ schon dem Präprozesor  bekannt ist. Wenn nein dann ......
#define _gotoxy_clscr_      // Wenn der Begriff _Widerstandsrechner_H nicht bekannt ist dann definiere ihn nun (bis #endif) 
        // http://msdn.microsoft.com/query/dev10.query?appId=Dev10IDEF1&l=DE-DE&k=k(%22%23IFNDEF%22);k(DevLang-%22C%2B%2B%22)&rd=true



// #include <stdio.h>
// #include <stdlib.h>
//Funktion die wir aus dem Internet haben von folgender Seite:http://board.gulli.com/thread/659029-gotoxy-in-c/
	// see https://www.c-plusplus.net/forum/146221-full
	// for more details about colors in DOS Box


#include <windows.h>
#define sign		'*'
int i = 0;
int e = 0;
int a = 3;
int b = 18;
// ---------------------------------

void initDosWindow(){

	// see https://www.c-plusplus.net/forum/146221-full
	// for more details about colors in DOS Box   
	// Die Farben setzen sich aus BACKGROUND_INTENSITY, BACKGROUND_RED, BACKGROUND_GREEN, BACKGROUND_BLUE und FOREGROUND_INTENSITY, FOREGROUND_RED, FOREGROUND_GREEN, FOREGROUND_BLUE zusammen. 

	// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); 
	// FOREGROUND_YELLOW + FOREGROUND_INTENSITY + BACKGROUND_RED + BACKGROUND_INTENSITY 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
		FOREGROUND_INTENSITY | FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_BLUE);
}

// Funktion gotxy für DOS Fenster um Cursor zu setzten.
void gotoxy(int x, int y)
{
	static HANDLE hStdout = NULL;
	COORD coord;
	coord.X = x;
	coord.Y = y;

	if(!hStdout)
	{
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	SetConsoleCursorPosition(hStdout,coord);
}


// Clear Screen Funktion als Ersatz der Funktion 
void clrscr(void)
{
	static HANDLE hStdout = NULL;      
	static CONSOLE_SCREEN_BUFFER_INFO csbi;
	const COORD startCoords = {0,0};   
	DWORD dummy;

	if(!hStdout)               
	{
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(hStdout,&csbi);
	}

	FillConsoleOutputCharacter(hStdout,
		' ',
		csbi.dwSize.X * csbi.dwSize.Y,
		startCoords,
		&dummy);    
	gotoxy(0,0);
}


void zeichne_rahmen(void){
 for (i=0; i<=79; i++)			// Decklinien des Frames
 {
	gotoxy(i,0);
 printf("%c",sign);				 
 }								
 for (i=0; i<=20; i++)
	{
	gotoxy(0,i);				//zeichnet die erste Senkrechtlinien 
	printf( "%c",sign);
	}

  for (i=0; i<=20; i++)
	{
	gotoxy(79,i);				//zeichnet die zweite Senkrechtlinien
	printf("%c",sign);
	} 
 gotoxy(0, 21);	

 for (i=0; i<=79; i++)			//Bodenlinie des Frames
 {
	gotoxy(i,21);
 printf("%c",sign);				 
 }

}
// ------------------------- Ende zeichne-rahmen

/* Funktion void zeichne_achse(void)
*  Damit wird der Fensterrahmen gezeichnet.
*
******************************************* */
void zeichne_achse(void){

  for (i=2; i<=19; i++)
	{
	gotoxy(2,i);				//zeichnet die X-Achse 
	printf( "%c",197);
	}

    for (i=3; i<=77; i++)
	{
	gotoxy(i,19);				//zeichnet die Y-Achse
	printf("%c",197);
	} 

	gotoxy(2,19);				// Koordinate 1/20 <---- Nullpunkt
	printf("%c",192);

	gotoxy(2,1);				// Koordinate 2/1 <--- Pfeil y-Achse
	printf("%c",30);

	gotoxy(78,19);				// Koordinate 20/76 <--- Pfeil x-Achse
	printf("%c",16);

	e=3;
	for (i=8; i>=0; i--)		// beschriftungen y-Achse
	{
	gotoxy(1,e);
	printf("%d",i);
	i--;
	e = e+4;
	}

}
// ------------------------- Ende zeichne-Achse
/*  ******** Achsen Beschriften
*
**********************************/

void beschrifte_xachse(unsigned char dx){
    e=0;
	for(i=2; i<=76; i++)		// beschriftungen x-Achse
	{
	gotoxy(i,20);
	printf("%d",e);
	e=e+dx;
	i=i+9;
	}
}

#endif
