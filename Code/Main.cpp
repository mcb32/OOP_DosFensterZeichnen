//============================================================================
// Name        : Main.cpp  für Operationen rund um das DOS Fenster
// Author      : rma 1.12.2016
// Version     : 3.0
/* Description : Zeigt den Einsatz von Klassen, Methoden und Attributen
   ============================================================================   */
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "..\Code\gotoxy_clrscr.h"
// 
#include  <iostream>  
#include "classZeichnen.h"
// #include "xy_Lib.h"
using namespace std;       // damit cout und cin erreichbar sind ohne immer std::cin schreiben zu müssen :-)
// ---------------------------------------------------

unsigned int ui_swcx0 =  0;   // Start coordinates of DOS Console Window
unsigned int ui_swcy0 =  0;   // Start coordinates of DOS Console Window
unsigned int ui_swcx1 = 79;   // Start coordinates of DOS Console Window
unsigned int ui_swcy1 = 40;   // Start coordinates of DOS Console Window

unsigned int  AnzahlRs=0;    // Die Anzahl von Widerständen welche eröffnet wurde. // REF[7]

// Prototypen lokale Funktionen ---------------------------------------------------
void abbrechen(void);      // Prototyp für Abbruch der Ausgabe. 


// --------------------------------------------------------------------------------

/*     MAIN Programm           */
int main () {
	
	
	// Init DOS Console
	SetConsoleFont(12);
	SetConsoleDimension(ui_swcx0, ui_swcy0, ui_swcx1, ui_swcy1 , 0, 0);   // setze DOS Fenster neu auf. 
	SetConsoleTitle(TEXT("My first Step with DOS Windows GAMES"));
	
  //initDosWindow();
  //zeichne_rahmen();    // ------ Zeichnen des Rahmens ---------------

  // printf("DEMO");
  // Achsen zeichnen -------------------------------------
  // zeichne_achse();
  // beschrifte_xachse(10);           // beschrifte x Achse, setze an jeder 10Stelle eine Beschriftung
  // Ende DEMO ------------------------------------------------
	
	
	// End of Init DOS Console
	 

	
	
	// Start  Drawing
	cZeichnen SetWindow;
	cZeichnen Kreis1;
	cZeichnen Kreis2;
	cZeichnen Linie1;
	SetWindow.setwcord(ui_swcx0, ui_swcy0, ui_swcx1, ui_swcy1);
	// cout << "...getwcordx1():  " << SetWindow.getwcordx1() << endl;
	Kreis1.zeichneKreis(12, 6, 5, 12, 12,'.');
	Kreis2.zeichneKreis(44, 6, 5, 12, 12,'.');
	Kreis2.zeichneKreis(45, 6, 5, 0, 12,'.');
	Kreis2.zeichneKreis(45, 6, 5, 0, 0,'.');
	// Kreis1.zeichneKreis(12, 6, 5, 0, 0,'.');
	Linie1.setwcord(ui_swcx0, ui_swcy0, ui_swcx1, ui_swcy1);
	Linie1.zeichneLinie(20, 20, 40, 40, 0, 12, '*');
 
	

  abbrechen();
  return 0;
}


/* Funktionen ausprogrammiert.    */
void abbrechen(void) {
  char tempin;// Warte auf Abbruch der Ausgabe 
  gotoxy(50,1); cout << "Abbruch mit j/J" ;
  do {
    cin >> tempin;
	} while (  ! ((tempin == ('j'))  ||  (tempin == ('J')))   );
}


