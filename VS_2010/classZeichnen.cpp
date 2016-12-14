#include  <iostream>    
#include "classZeichnen.h"
#include <math.h>
#include"gotoxy_clrscr.h"
// using namespace std;   // einschalten wenn std::  wegfallen soll

unsigned char NoError=0;
double  DefaultToleranz = 5;   // Wert in %
extern unsigned int  AnzahlRs;    // Die Anzahl von Widerständen welche eröffnet wurde.

cZeichnen::cZeichnen()  // Konstruktor  was macht der genau
{	
		AnzahlRs= AnzahlRs+1; 
		std::cout << AnzahlRs<< "/";			// << std::endl;       
		// Setze alle internen Variablen auf 0 oder auf einen Defaultwert.
		dWiderstandswert=0;			// 0 Ohm
		dPv=0;						// 0 Watt
		dTemperaturRaum=25;			// 25Grad Celsius
	    iExxSeries =12;				// E12 Reihe
		dDrahtlänge=1;				// Default Wert 1m
		dDrahtDurchmesser= 1;		// Default Wert 1mm
		dRho = 0.0178;				// Default Wert von CU [Ohm mm^2/m]
		dToleranz=DefaultToleranz;	// Default Wert der Toleranz
}
cZeichnen::~cZeichnen() // DeKonstruktor   was macht der genau
{
	// AnzahlRs= AnzahlRs-1;   // Der Dekonstruktor wird auch aufgerufen wenn das Objekt noch im Gebrauch ist ?? Warum
	// std::cout << AnzahlRs<< "/";			// << std::endl;    
	// std::cout <<  ":" ; // << std::endl;       // Zeige etwas an wenn der Dekonstruktor aufgerufen wird.
}      

void cZeichnen::zeichneKreis(double x0, double y0, double Radius, unsigned int colorline, unsigned int colorfill)
{
	unsigned int iaufl=0;

	for (iaufl=0; iaufl<360;iaufl++){
		x0=x0+Radius*cos((float)iaufl);
		y0=y0+Radius*sin((float)iaufl);
		gotoxy(x0, y0);
		printf("*");
	}
}


void cZeichnen::zeige (char Rnummer[12]) {
  std::cout << Rnummer << " = " << dWiderstandswert << " ; Pv = " << dPv << " und Tolanz = " << dToleranz<< "%"; //  << std::endl;
}

void cZeichnen::setWiderstandswert ( double Widerstandswert  , double Toleranz) {
  dWiderstandswert = Widerstandswert;

  if ( Toleranz == 0) 
  {dToleranz= DefaultToleranz; }
  else
  { dToleranz = Toleranz; }                       // Wert gilt +/-  wenn Wert 0 gilt Defaultwert

}

void cZeichnen::setWiderstandsPv ( double Pv) {
  dPv= Pv;
}

double cZeichnen::getWiderstandswert () {
  return(dWiderstandswert);
}

double cZeichnen::getWiderstandswertToleranz(){
	return(dToleranz);
}


unsigned char cZeichnen:: getSerieschaltung(cZeichnen oR1,cZeichnen oR2)
{
	dWiderstandswert = (oR1.getWiderstandswert() + oR2.getWiderstandswert());
	// Wie sieht es mit der Verlustleistung aus?  Welcher Wert von Pv ist gültig da wir möglicherweise unterschiedliche Pvs haben
	return(NoError);
}
