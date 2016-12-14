//============================================================================
// Name        : Main.cpp  für Berechnung von Widerstandsschaltungen
// Author      : rma 1.12.2016
// Version     : 1.0
/* Description : Zeigt den Einsatz von Klassen, Methoden und Attributen
   ============================================================================   */
#include <stdio.h>
#include <conio.h>
#include <windows.h>
// #include "gotoxy_clrscr.h"
// 
#include  <iostream>  
#include "classZeichnen.h"
// #include "xy_Lib.h"
using namespace std;       // damit cout und cin erreichbar sind ohne immer std::cin schreiben zu müssen :-)
// ---------------------------------------------------


unsigned int  AnzahlRs=0;    // Die Anzahl von Widerständen welche eröffnet wurde. siehe http://www2.informatik.uni-halle.de/lehre/c/c_globv.html

// Prototypen lokale Funktionen ---------------------------------------------------
void abbrechen(void);      // Prototyp für Abbruch der Ausgabe. 

void gotoxy(int xpos, int ypos);
void zeichne_rahmen(void);
void zeichne_achse(void);
void beschrifte_xachse(unsigned char dx);
void initDosWindow();
// --------------------------------------------------------------------------------

/*     MAIN Programm           */
int main () {
 
	cZeichnen Kreis1;
	cZeichnen Kreis2;
	Kreis1.zeichneKreis(12, 6, 5, 12, 12);
	Kreis2.zeichneKreis(5, 6, 5, 12, 12);
  //initDosWindow();
  //zeichne_rahmen();    // ------ Zeichnen des Rahmens ---------------

  // printf("DEMO");
  // Achsen zeichnen -------------------------------------
  // zeichne_achse();
  // beschrifte_xachse(10);           // beschrifte x Achse, setze an jeder 10Stelle eine Beschriftung
  // Ende DEMO ------------------------------------------------


	//gotoxy(3,2);					// Setze Cursor auf die Position 3,2 als Startpunkt 
  // Instanziere die Widerstaende
  //cRCalc R1;
  //cRCalc R2;
  //cRCalc Rs;    // Ersatz Serie-Widerstand
  //cRCalc Rp;    // Ersatz Parallel-Widerstand
  //// cout <<endl;
  //R1.setWiderstandswert(12,10);
  //R1.setWiderstandsPv(1.5);
  //gotoxy(3,3);
  //R1.zeige ("R1");  cout << std::endl;
  //R2.setWiderstandswert(47,0);
  //R2.setWiderstandsPv(1.0);
  //gotoxy(3,4); R2.zeige ("R2");   cout << std::endl;
  //gotoxy(3,5); Rs.zeige("Rsvorher ");  cout << std::endl;
  //gotoxy(3,6);cout <<"Anzahl R's= " << AnzahlRs <<endl;
  //gotoxy(3,7);cout <<".........................." <<endl;
  //Rs.getSerieschaltung(R1, R2);
  //gotoxy(3,8); Rs.zeige("Rsnachher");   cout << std::endl;
  //// cout << endl <<endl;
  //gotoxy(3,9); cout <<"Die PV jedes Rs ist wie folgt definiert: 0.9Pv << Pv  << 1.1Pv"     << endl;
  //gotoxy(3,10); cout <<"Alle anderen Toleranzen sind bei +/-5% sofern nicht anders definiert"<< endl;
  //gotoxy(3,12); cout <<"Wie gross ist der Leitwert" <<endl;
  //gotoxy(3,12); cout <<"Wie viele Widerstaende wurden erzeugt?" <<endl;
  //gotoxy(3,13); cout <<"Wie hoch ist die maximale Verlustleistung aller Widerstaende" <<endl;
  //gotoxy(3,14); cout <<"Wie hoch ist die Parallelwiderstand aller Widerstaende" <<endl;
  //gotoxy(3,15); cout <<"Welche Reihe muss in der Produktion fuer alle Widerstaende"     << endl;
  //gotoxy(3,16); cout <<"gewaehlt werden damit alle R's aus der gleichen Reihe kommen" <<endl;

  //Rs.zeige("Rs");
  //R1.zeige ("R1");
  //R2.zeige ("R2");
  abbrechen();
  return 0;
}





/* Funktionen ausprogrammiert.    */
void abbrechen(void) {
  char tempin;// Warte auf Abbruch der Ausgabe 
  gotoxy(20,22); cout << "Abbruch mit j/J" ;
  do {
    cin >> tempin;
	} while (  ! ((tempin == ('j'))  ||  (tempin == ('J')))   );
}