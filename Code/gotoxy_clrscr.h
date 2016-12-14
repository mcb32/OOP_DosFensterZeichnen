#ifndef _gotoxy_clscr_     // Prüfe ob der Begriff _gotoxy_clscr_ schon dem Präprozesor  bekannt ist. Wenn nein dann ......
#define _gotoxy_clscr_      // Wenn der Begriff _Widerstandsrechner_H nicht bekannt ist dann definiere ihn nun (bis #endif) 
       
#include <windows.h>

// ---------------------------------
void gotoxy(int xpos, int ypos);
void SetConsoleDimension(short x0, short y0, short x1, short y1, short buffx, short buffy);
void zeichne_rahmen(void);
void zeichne_achse(void);
void beschrifte_xachse(unsigned char dx);
void initDosWindow();
void SetConsoleFont(unsigned char fonthight);
void abbrechen(void);
//
#endif
