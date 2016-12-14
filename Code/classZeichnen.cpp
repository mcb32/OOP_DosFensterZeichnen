#include  <iostream>    
#include "classZeichnen.h"
#include <math.h>
#include "..\Code\gotoxy_clrscr.h" 
// using namespace std;   // einschalten wenn std::  wegfallen soll

unsigned char NoError=0;
double  DefaultToleranz = 5;   // Wert in %
extern unsigned int  AnzahlRs;    // Die Anzahl von Widerständen welche eröffnet wurde.
unsigned int max_coord_x1 = 35;   // some default values for the konstruktor
unsigned int max_coord_y1 = 75;   // some default values for the konstruktor

cZeichnen::cZeichnen()  // Konstruktor  was macht der genau
{	
		AnzahlRs= AnzahlRs+1; 
		std::cout << AnzahlRs<< "/";			// << std::endl;       
		ui_wcx0 = 0;
		ui_wcy0 = 0;
		ui_wcx1 = max_coord_x1;
		ui_wcy1 = max_coord_y1;
												
												// Setze alle internen Variablen auf 0 oder auf einen Defaultwert.
		//dWiderstandswert=0;			// 0 Ohm
		//dPv=0;						// 0 Watt
		//dTemperaturRaum=25;			// 25Grad Celsius
	 //   iExxSeries =12;				// E12 Reihe
		//dDrahtlänge=1;				// Default Wert 1m
		//dDrahtDurchmesser= 1;		// Default Wert 1mm
		//dRho = 0.0178;				// Default Wert von CU [Ohm mm^2/m]
		//dToleranz=DefaultToleranz;	// Default Wert der Toleranz
}


void cZeichnen::setwcord(unsigned int ui_x0, unsigned int ui_y0, unsigned int ui_x1, unsigned int ui_y1)
{
	ui_wcx0 = ui_x0;
	ui_wcy0 = ui_y0;
	ui_wcx1 = ui_x1;   
	ui_wcy1 = ui_y1;
}

unsigned int cZeichnen::getwcordx0(void)
{
	return(ui_wcx0);
}
unsigned int cZeichnen::getwcordx1(void)
{
	return(ui_wcx1);
}

unsigned int cZeichnen::getwcordy1(void)
{
	return(ui_wcy1);
}
cZeichnen::~cZeichnen() // DeKonstruktor   was macht der genau
{
	// AnzahlRs= AnzahlRs-1;   // Der Dekonstruktor wird auch aufgerufen wenn das Objekt noch im Gebrauch ist ?? Warum
	// std::cout << AnzahlRs<< "/";			// << std::endl;    
	// std::cout <<  ":" ; // << std::endl;       // Zeige etwas an wenn der Dekonstruktor aufgerufen wird.
}      

void cZeichnen::zeichneKreis(double x0, double y0, double Radius, unsigned int colorline, unsigned int colorfill, char Filltext)
{
	unsigned int iaufl=0;
	if (colorline == 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_GREEN);
	}

	for (iaufl=0; iaufl<360;iaufl++){
		x0=x0+Radius*cos((float)iaufl);
		y0=y0+Radius*sin((float)iaufl);
		gotoxy((int) x0, (int) y0);
		printf("%c",Filltext);   // Filltext = "*" for Example
	}
}



void cZeichnen::zeichneLinie(double lx0, double ly0, double lx1, double ly1, unsigned int colorline, unsigned int colorfill, char Linetext)
{
	// std::cout << "/////////////" << getwcordx1() << "¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦" ;
	unsigned int iaufl = 0;								// temp local variable
	if (colorline == 0) {								// Check for No Color
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	}
	else
	{	// Set default Value for Line Color 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_GREEN);
	}
	double dinclination = ((ly1 - ly0) / (lx1 - lx0));
	// printf("lx1-lx0=%i / \n", (int)(lx1 - lx0));     // Debug
	for (iaufl = 0; iaufl<((unsigned int)(lx1-lx0)); iaufl++)    // 
	{
		double dcx0 = getwcordx0() + (lx0+iaufl);
		double dcy0 = getwcordy1() - (ly0+(dinclination*iaufl));
		gotoxy((int)dcx0, (int)dcy0);
		printf("%c", Linetext);   // Filltext = "*" for Example
		// printf("x0=%f, y0=%f , X1=%i / \n", dcx0, dcy0, getwcordx1());  // Debug
	
	}

}

//void cZeichnen::zeige (char Rnummer[12]) {
//  std::cout << Rnummer << " = " << dWiderstandswert << " ; Pv = " << dPv << " und Tolanz = " << dToleranz<< "%"; //  << std::endl;
//}

//void cZeichnen::setWiderstandswert ( double Widerstandswert  , double Toleranz) {
//  dWiderstandswert = Widerstandswert;
//
//  if ( Toleranz == 0) 
//  {dToleranz= DefaultToleranz; }
//  else
//  { dToleranz = Toleranz; }                       // Wert gilt +/-  wenn Wert 0 gilt Defaultwert
//
//}
//
//void cZeichnen::setWiderstandsPv ( double Pv) {
//  dPv= Pv;
//}
//
//double cZeichnen::getWiderstandswert () {
//  return(dWiderstandswert);
//}
//
//double cZeichnen::getWiderstandswertToleranz(){
//	return(dToleranz);
//}


//unsigned char cZeichnen:: getSerieschaltung(cZeichnen oR1,cZeichnen oR2)
//{
//	dWiderstandswert = (oR1.getWiderstandswert() + oR2.getWiderstandswert());
//	// Wie sieht es mit der Verlustleistung aus?  Welcher Wert von Pv ist gültig da wir möglicherweise unterschiedliche Pvs haben
//	return(NoError);
//}
