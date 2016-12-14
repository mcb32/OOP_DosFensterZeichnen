//============================================================================
// Name        : Class Zeichnenm  für Operationen rund um das DOS Fenster
// Author      : rma 1.12.2016
// Version     : 3.0
/* Description : Zeigt den Einsatz von Klassen, Methoden und Attributen
============================================================================   */
#include  <iostream>    
#include "..\Code\classZeichnen.h"
#include <math.h>
#include "..\Code\gotoxy_clrscr.h" 
// using namespace std;   // einschalten wenn std::  wegfallen soll

unsigned char NoError=0;
double  DefaultToleranz = 5;			// Wert in %
unsigned int max_coord_x1 = 35;			// some default values for the konstruktor
unsigned int max_coord_y1 = 75;			// some default values for the konstruktor
extern unsigned int  NumberofObj;		// Number of objects installed 
extern unsigned int ui_swcx0;			// Start coordinates of DOS Console Window
extern unsigned int ui_swcy0;			// Start coordinates of DOS Console Window
extern unsigned int ui_swcx1;			// Start coordinates of DOS Console Window
extern unsigned int ui_swcy1;			// Start coordinates of DOS Console Window


cDrawing::cDrawing()  // Konstruktor  
{
	NumberofObj = NumberofObj + 1;
	std::cout << NumberofObj << "/";			// << std::endl;       
	ui_wcx0 = 0;
	ui_wcy0 = 0;
	if (ui_swcx1 > 0) { ui_wcx1 = ui_swcx1; }
	else { ui_wcx1 = max_coord_x1; }
	// DEBUG std::cout << ui_wcx1 << "ui/";			// << std::endl; 
	if (ui_swcy1 > 0) { ui_wcy1 = ui_swcy1; }
	else { ui_wcx1 = max_coord_y1; }
	// ui_wcy1 = max_coord_y1;
}
void cDrawing::setwcord(unsigned int ui_x0, unsigned int ui_y0, unsigned int ui_x1, unsigned int ui_y1)
{
	ui_wcx0 = ui_x0;  // set Worldcoordinate x0 to value  xxxx
	ui_wcy0 = ui_y0;
	ui_wcx1 = ui_x1;   
	ui_wcy1 = ui_y1;
}

unsigned int cDrawing::getwcordx0(void)
{
	return(ui_wcx0);
}
unsigned int cDrawing::getwcordx1(void)
{
	return(ui_wcx1);
}

unsigned int cDrawing::getwcordy1(void)
{
	return(ui_wcy1);
}
cDrawing::~cDrawing() // DeKonstruktor   was macht der genau
{}      

void cDrawing::drawCircle(double x0, double y0, double Radius, unsigned int colorline, unsigned int colorfill, char Filltext)
{
	y0 = getwcordy1() - y0;  // Adjust y0 because 0,0 is upper left corner
	// debug gotoxy(19, 10); std::cout << getwcordy1();
	unsigned int iaufl = 0;
	if (colorline == 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			colorline);  // FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_GREEN);
	}

	for (iaufl=0; iaufl<360;iaufl++){
		x0= x0 + Radius*cos((float)iaufl);
		y0= y0 + (Radius*sin((float)iaufl));
		gotoxy((int) x0, (int) y0);
		printf("%c",Filltext);   // Filltext = "*" for Example
		// gotoxy(24, 10); std::cout << (getwcordy1());
	}
}



void cDrawing::drawLine(double lx0, double ly0, double lx1, double ly1, unsigned int colorline, unsigned int colorfill, char Linetext)
{
	// std::cout << "/" << getwcordx1() << "\\" ;      // debug  to check if the wcord are overwritten by setwc....
	unsigned int iaufl = 0;								// temp local variable
	if (colorline == 0) {								// Check for No Color
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	}
	else
	{	// Set default Value for Line Color 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
			colorline);  // FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_INTENSITY | BACKGROUND_GREEN);
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

//void cDrawing::zeige (char Rnummer[12]) {
//  std::cout << Rnummer << " = " << dWiderstandswert << " ; Pv = " << dPv << " und Tolanz = " << dToleranz<< "%"; //  << std::endl;
//}

//void cDrawing::setWiderstandswert ( double Widerstandswert  , double Toleranz) {
//  dWiderstandswert = Widerstandswert;
//
//  if ( Toleranz == 0) 
//  {dToleranz= DefaultToleranz; }
//  else
//  { dToleranz = Toleranz; }                       // Wert gilt +/-  wenn Wert 0 gilt Defaultwert
//
//}
//
//void cDrawing::setWiderstandsPv ( double Pv) {
//  dPv= Pv;
//}
//
//double cDrawing::getWiderstandswert () {
//  return(dWiderstandswert);
//}
//
//double cDrawing::getWiderstandswertToleranz(){
//	return(dToleranz);
//}


//unsigned char cDrawing:: getSerieschaltung(cDrawing oR1,cDrawing oR2)
//{
//	dWiderstandswert = (oR1.getWiderstandswert() + oR2.getWiderstandswert());
//	// Wie sieht es mit der Verlustleistung aus?  Welcher Wert von Pv ist gültig da wir möglicherweise unterschiedliche Pvs haben
//	return(NoError);
//}
