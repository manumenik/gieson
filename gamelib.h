#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//IN QUESTO FILE.H VENGONO DICHIARATI GLI STRUCT CONTENENTI LE VARIABILI DI ZONA E GIOCATORE E I typedef DELL STATO GIOCATORE
//DELLE ZONE E DEGLI OGGETTI

typedef enum {Morto, Ferito, Vivo}Stato_Giocatore;
typedef enum {Cucina, Soggiorno, Rimessa, Strada, Lungo_Lago, Uscita_Campeggio}Tipo_Zona;
typedef enum {Cianfrusaglia, Bende, Coltello, Pistola, Benzina, Chiavi_Auto, Adrenalina}Tipo_Oggetto;

typedef struct Zona
{
	int i_Zona;
	int Oggetto_Nascosto;
	Tipo_Zona N_Zona;
	Tipo_Oggetto Oggetto;
	struct Zona *Zona_Successiva;
}Zona;

typedef struct Giocatore
{
	int Vittoria;
	struct Zona *Posizione;
	Stato_Giocatore Stato;
	unsigned short Zaino[7];
	int Mossa;
}Giocatore;
