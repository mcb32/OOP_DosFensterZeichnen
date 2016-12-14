//============================================================================
// Name        : Main.cpp  für Berechnung von Widerstandsschaltungen
// Author      : rma 1.12.2016
// Version     : 1.0
/* Description : Zeigt den Einsatz von Klassen, Methoden und Attributen
============================================================================   */
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <stdexcept>


// #include "gotoxy_clrscr.h"
// 
#include  <iostream>  
#include "classZeichnen.h"
// #include "xy_Lib.h"
using namespace std;       // damit cout und cin erreichbar sind ohne immer std::cin schreiben zu müssen :-)
						   // ---------------------------------------------------


unsigned int  AnzahlRs = 0;    // Die Anzahl von Widerständen welche eröffnet wurde. siehe http://www2.informatik.uni-halle.de/lehre/c/c_globv.html

							   // Prototypen lokale Funktionen ---------------------------------------------------
void abbrechen(void);      // Prototyp für Abbruch der Ausgabe. 

void gotoxy(int xpos, int ypos);
void zeichne_rahmen(void);
void zeichne_achse(void);
void beschrifte_xachse(unsigned char dx);
void initDosWindow();
// --------------------------------------------------------------------------------


void SetConsoleWindowSize(int x, int y)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	if (h == INVALID_HANDLE_VALUE)
		throw std::runtime_error("Unable to get stdout handle.");

	// If either dimension is greater than the largest console window we can have,
	// there is no point in attempting the change.
	{
		COORD largestSize = GetLargestConsoleWindowSize(h);
		if (x > largestSize.X)
			throw std::invalid_argument("The x dimension is too large.");
		if (y > largestSize.Y)
			throw std::invalid_argument("The y dimension is too large.");
	}


	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
	if (!GetConsoleScreenBufferInfo(h, &bufferInfo))
		throw std::runtime_error("Unable to retrieve screen buffer info.");

	SMALL_RECT& winInfo = bufferInfo.srWindow;
	COORD windowSize = { winInfo.Right - winInfo.Left + 1, winInfo.Bottom - winInfo.Top + 1 };

	if (windowSize.X > x || windowSize.Y > y)
	{
		// window size needs to be adjusted before the buffer size can be reduced.
		SMALL_RECT info =
		{
			0,
			0,
			x < windowSize.X ? x - 1 : windowSize.X - 1,
			y < windowSize.Y ? y - 1 : windowSize.Y - 1
		};

		if (!SetConsoleWindowInfo(h, TRUE, &info))
			throw std::runtime_error("Unable to resize window before resizing buffer.");
	}

	COORD size = { x, y };
	if (!SetConsoleScreenBufferSize(h, size))
		throw std::runtime_error("Unable to resize screen buffer.");


	SMALL_RECT info = { 0, 0, x - 1, y - 1 };
	if (!SetConsoleWindowInfo(h, TRUE, &info))
		throw std::runtime_error("Unable to resize window after resizing buffer.");
}



void ShowLastSystemError()
{
	LPSTR messageBuffer;
	FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
		0,          // source
		GetLastError(),
		0,          // lang
		(LPSTR)&messageBuffer,
		0,
		NULL);

	std::cerr << messageBuffer << '\n';
	LocalFree(messageBuffer);
}

COORD QueryUserForConsoleSize()
{
	COORD size = { 0, 0 };

	std::cout << "New console size: ";
	std::cin >> size.X >> size.Y;

	return size;
}

int main()
{
	COORD consoleSize;

	std::cout << "An x or y size of 0 will terminate the program\n";
	while (consoleSize = QueryUserForConsoleSize(), consoleSize.X && consoleSize.Y)
	{
		try {
			SetConsoleWindowSize(consoleSize.X, consoleSize.Y);
		}

		catch (std::logic_error& ex)
		{
			std::cerr << ex.what() << '\n';
		}

		catch (std::exception& ex)
		{
			std::cerr << ex.what() << "\nSystem error: ";
			ShowLastSystemError();
		}
	}
}
