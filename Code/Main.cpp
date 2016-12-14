/* ============================================================================
*  @Name        : Main.cpp  für Operationen rund um das DOS Fenster
*  @Author      : rma 1.12.2016
*  @Version     : 3.0
*  @Description : Zeigt den Einsatz von Klassen, Methoden und Attributen
============================================================================   */
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include  <iostream>  
#include "..\Code\gotoxy_clrscr.h"
#include "..\Code\classZeichnen.h"
// #include "xy_Lib.h"
using namespace std;       // damit cout und cin erreichbar sind ohne immer std::cin schreiben zu müssen :-)
// ---------------------------------------------------

unsigned int ui_swcx0 =  0;   // Start coordinates of DOS Console Window for SetConsoleDimension and Class cDrawing
unsigned int ui_swcy0 =  0;   //      ""
unsigned int ui_swcx1 = 79;   //      ""
unsigned int ui_swcy1 = 40;   //      ""

unsigned int  NumberofObj =0;    // Die Anzahl von Objekten welche eröffnet wird. // REF[7]

// Prototypen lokale Funktionen ---------------------------------------------------
void abbrechen(void);      // Prototyp für Abbruch der Ausgabe. 


// --------------------------------------------------------------------------------

/*     MAIN Programm           */
int main () {
	
	
	// Init DOS Console
	// initDosWindow();
	SetConsoleFont(12);
	if ((ui_swcx1 > 0) && (ui_swcy1 > 0)) {
	SetConsoleDimension(ui_swcx0, ui_swcy0, ui_swcx1, ui_swcy1, 0, 0);   // set console dimension to actual values 
	}
	SetConsoleTitle(TEXT("My first Step with DOS Windows GAMES"));
	/*gotoxy(ui_swcx1 / 2, ui_swcy1 / 2);  cout << ui_swcx1 <<  ";"  << ui_swcy1 << ". ";
	gotoxy(0, ui_swcy1-1);  cout << ui_swcx1 << ";" << ui_swcy1 << ". ";*/

  // zeichne_rahmen();    // ------ Draw Frame ---------------

  // printf("DEMO");
  // Achsen zeichnen -------------------------------------
  // zeichne_achse();
  // beschrifte_xachse(10);           // beschrifte x Achse, setze an jeder 10Stelle eine Beschriftung
  // Ende DEMO ------------------------------------------------
 // End of Init DOS Console
	 

	
	
	/** Start  Drawing. */
	cDrawing Kreis1;
	cDrawing Kreis2;
	cDrawing Linie1;
	// Show: shows all colors for this circle 
	for (unsigned int colori = 0; colori < 0xFF; colori=colori+15) {
		Sleep(70); // wait 0.07 second
		Kreis1.drawCircle(12,30, 5, colori, 12, '.');
		//  Debug gotoxy(ui_swcx1/2, (ui_swcy1-ui_swcy1/2) ); cout << colori;

	}
	Kreis1.drawCircle(12, 30, 5, 0xFFFFF,12,'.');
	Kreis2.drawCircle(44, 30, 5, 0, 12,'.');
	Kreis2.drawCircle(45, 30, 5, 0, 12,'.');
	Kreis2.drawCircle(45, 30, 5, 0, 0,'.');
	Kreis1.drawCircle(12, 30, 5, 0, 0,'.');
	Linie1.setwcord(ui_swcx0, ui_swcy0, ui_swcx1, ui_swcy1);  // only an idea
	Linie1.drawLine(20, 10, 40, 39, 0, 12, '*');
 
	

  abbrechen();
  return 0;
}





