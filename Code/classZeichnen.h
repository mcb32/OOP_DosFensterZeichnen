
#ifndef _Zeichnen_H     // Prüfe ob der Begriff _Zeichnen_H schon dem Präprozesor  bekannt ist. Wenn nein dann ......
#define _Zeichnen_H      // Wenn der Begriff _Zeichnen_H nicht bekannt ist dann definiere ihn nun (bis #endif) 
        // http://msdn.microsoft.com/query/dev10.query?appId=Dev10IDEF1&l=DE-DE&k=k(%22%23IFNDEF%22);k(DevLang-%22C%2B%2B%22)&rd=true

extern unsigned int  AnzahlRs;    // Die Anzahl von Widerständen welche eröffnet wurde.


class cZeichnen 
{
public:
    cZeichnen();       // Konstruktor
    ~cZeichnen();
    void cZeichnen::zeichneKreis(double x0, double y0, double Radius, unsigned int colorline, unsigned int colorfill, char Filltext);
	void cZeichnen::zeichneLinie(double lx0, double ly0, double lx1, double ly1, unsigned int colorline, unsigned int colorfill, char Linetext);
	void cZeichnen::setwcord(unsigned int ui_x0 ,unsigned int ui_y0 ,unsigned int ui_x1 , unsigned int ui_y1);
	unsigned int cZeichnen::getwcordx0(void);
	unsigned int cZeichnen::getwcordx1(void);
	unsigned int cZeichnen::getwcordy1(void);


	
	//void zeige(char Rnummer[12]);
	//void setWiderstandswert(double Widerstandswert, double Toleranz);   // Trick mit der Toleranz gleich hier setzen
	//double getWiderstandswert();
	//double getWiderstandswertToleranz();
	//void setWiderstandsPv(double Pv);
	//void setDrahtlänge(double Drahtlänge);
	//void setDrahtDurchmesser(double DrahtDurchmesser);
	//void setRho(double Rho);
	//void setExxSerie(int ExxSerie);       // ask for the E Series Number E6, E12, E24, E96 and E192
	//
	//void setTemperaturRaum(double TemperaturRaum);
	
	// Berechne die Reihe zu der der Widerstandswert gehört. Bsp: 13,5Ohm E12Reihe 12 Ohm
	// und setze den WIderstand entsprechend auf den Wert.
	// int getExxSerie(cZeichnen oRx, double dGenauigkeit);  
    
	// Berechne Serieschaltung der R R1 und R2 und speichere Wert in Rs ab. 
	// Bestimme die anzunehmende Verlustlestung des neuen Widerstandes auf der Basis aller Vorgaben (R1, R2.... und Rs)
	// Rückgabewert = 0 keine Fehler; >0 Fehler in der Berechnung, oRs nicht verändert.
	// unsigned char getSerieschaltung(cZeichnen oR1,cZeichnen oR2); 
	
	// Berechne Parallelschaltung der R R1 und R2 und speichere Wert in Rp ab. 
	// Bestimme die anzunehmende Verlustlestung des neuen Widerstandes auf der Basis aller Vorgaben (R1, R2.... und Rs)
	// Rückgabewert = 0 keine Fehler; >0 Fehler in der Berechnung, oRs nicht verändert.
	// unsigned char getParallelschaltung(cZeichnen oR1,cZeichnen oR2); 
	
	// unsigned int  AnzahlRs;    // Die Anzahl von Widerständen welche eröffnet wurde.
	// double dTemperaturRaum;    // Dieses Wert lassen wir als Fehler einmal zugänglich für alle.
private:
	/*double dWiderstandswert;
	double dToleranz;
	double dPv;
	int    iExxSeries;
	double dDrahtlänge;
	double dDrahtDurchmesser;
	double dRho;*/

	unsigned int ui_wcx0, ui_wcx1, ui_wcy0, ui_wcy1;  // Worldcoordinates for drwaing system
};


#endif /* _Widerstandsrechner_ */

