 #include <stdio.h>
 #include <stdlib.h>
#include <string.h>
#include"..\Code\gotoxy_clrscr.h"   // REF[3]
#include <windows.h>
#include  <iostream>  
#define sign		'*'
int i = 0;
int e = 0;
int a = 3;
int b = 18;

WORD Attributes = 0;   // Attri. for resetting DOS Colors
// ---------------------------------

void initDosWindow(){
// REF[4]
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
   FOREGROUND_INTENSITY | FOREGROUND_BLUE| FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_BLUE);
}

// REF[5]
void SetConsoleColour(WORD* Attributes, DWORD Colour)
{
	CONSOLE_SCREEN_BUFFER_INFO Info;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdout, &Info);
	*Attributes = Info.wAttributes;
	
	SetConsoleTextAttribute(hStdout, Colour);
}


void SetConsoleFont(unsigned char fonthight){
CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = 0;                   // Width of each character in the font
cfi.dwFontSize.Y = fonthight;                  // Height  eg. 24
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
// std:wcscpy(cfi.FaceName, L"Arial"); // Choose your font   Consolas  'wcscpy': This function or variable may be unsafe. Consider using wcscpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
 wcscpy_s(cfi.FaceName, L"Arial");     // Choose your font   Consolas  

SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

// std::cout << "Font: Consolas, Size: 24\n";

}


// REF[6]

void SetConsoleDimension(short  x0, short y0, short x1, short y1, short buffx, short buffy)
{
	// Set up the handles for reading/writing:
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
		
	// Change the window title Default:
	SetConsoleTitle(TEXT("Win32 Console Control Demo"));

	// Set up the required window size:
	// SMALL_RECT windowSize = { 0, 0, 79, 49 };
	SMALL_RECT windowSize = { x0,y0, x1, y1};
	// Change the console window size:
	SetConsoleWindowInfo(hStdout, TRUE, &windowSize);

	// Create a COORD to hold the buffer size:
	COORD bufferSize = { buffx, buffy };

	// Change the internal buffer size:
	SetConsoleScreenBufferSize(hStdout, bufferSize);

}

void ResetConsoleColour(WORD Attributes)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
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

// #include <stdlib.h>
// system("cls");
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

