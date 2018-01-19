#include "gamelib.h"

char *Nome_Zona[6] = {"     Cucina     ", "    Soggiorno   ", "     Rimessa    ", "     Strada     ", "   Lungo Lago   ", "Uscita Campeggio"};
char *Nome_Oggetto[7] = {"Cianfrusaglia", "    Bende    ", "   Coltello  ", "   Pistola   ", "   Benzina   ", " Chiavi Auto ", " Adrenalina  "};
char *Salute[3] = {"Morto", "Ferito", " Vivo "};

Giocatore Marzia;
Giocatore Giacomo;

Zona *Prima_Zona = NULL;
Zona *Ultima_Zona = NULL;
int Crea_Mappa(int, int, int, int);
int Menu(int i, int i_Zona);

//PRINT CHE STAMPA IL TITOLO DEL GIOCO PRESENTE IN OGNI SCHERMATA

int Titoli_di_Testa()
{
	system("cls");
	printf("\n\n\t\t\t				8''''8 8''''8 8''8''8 8''''8 8'''' 8''''8 8''''8 8  8'''88\n"
				 "\t\t\t				8    ' 8    8 8  8  8 8    8 8     8    ' 8    ' 8  8    8\n"
				 "\t\t\t				8e     8eeee8 8e 8  8 8eeee8 8eeee 8e     8e     8e 8    8\n"
				 "\t\t\t				88     88   8 88 8  8 88     88    88  ee 88  ee 88 8    8\n"
				 "\t\t\t				88   e 88   8 88 8  8 88     88    88   8 88   8 88 8    8\n"
				 "\t\t\t				88eee8 88   8 88 8  8 88     88eee 88eee8 88eee8 88 8eeee8\n"
				 "\t\t\t				               8     8''''8 8   8  8''''\n"
				 "\t\t\t				               8     8    8 8   8  8\n"
				 "\t\t\t				               8e    8eeee8 8ee8e 8eeee\n"
				 "\t\t\t				               88    88   8 88   8 88\n"
				 "\t\t\t				               88    88   8 88   8 88\n"
				 "\t\t\t				               88eee 88   8 88   8 88eee\n"
				 "\t\t\t				''8'' 8'''8  8''''8 8''''8 8    8 8''8''8 8'''' 8'''8 8'''88\n"
				 "\t\t\t				  8   8   8  8    8 8      8    8 8  8  8 8     8   8 8    8\n"
				 "\t\t\t				  8e  8eee8e 8eeee8 8eeeee 8eeee8 8e 8  8 8eeee 8e  8 8    8\n"
				 "\t\t\t				  88  88   8 88   8     88   88   88 8  8 88    88  8 8    8\n"
				 "\t\t\t				  88  88   8 88   8 e   88   88   88 8  8 88    88  8 8    8\n"
				 "\t\t\t				  88  88   8 88   8 8eee88   88   88 8  8 88eee 88  8 8eeee8\n"
				 "\t\t\t_________________________________________________________________________________________________________________________");
}

//FUNZIONE CHE INSERISCE IN MEMORIA UNA NUOVA ZONA DEFINENDONE IL TIPO E L'OGGETTO NASCOSTO CHE DOVRA' CONTENERE

void Inserisci_Zona(Tipo_Zona Tipo)
{
	Zona *Nuova_Zona = (Zona*)malloc(sizeof(Zona));
	Nuova_Zona->Zona_Successiva = NULL;
	Nuova_Zona->N_Zona = Tipo;
	Nuova_Zona->Oggetto_Nascosto = 0;

//VIENE GENERATO UN NUMERO CASUALE PER DETERMINARE L'OGGETTO

	time_t Seed;
	srand((unsigned)time(&Seed));
	int Random_Number = rand() % 101;

//L'OGGETTO ASSEGNATO AD OGNI ZONA E' STRETTAMENTE LEGATO AL TIPO DI ZONA
//IN BASE AL TIPO DI ZONA SCELTA LE PROBABILITA' CHE CAPITI UN DETERMINATO OGGETTO CAMBIANO
//QUESTE PROBABILITA' SONO DEFINITE QUI SOTTO

	if (Tipo == Cucina)
	{
		if (Random_Number <= 40)
			{
				Nuova_Zona -> Oggetto = Coltello;
			}

		if (Random_Number > 40 && Random_Number <= 70 )
			{
				Nuova_Zona -> Oggetto = Cianfrusaglia;
			}
		if (Random_Number > 70 && Random_Number <= 90)
		{
			Nuova_Zona -> Oggetto = Bende;
		}
		if (Random_Number > 90 && Random_Number <= 100)
		{
			Nuova_Zona -> Oggetto = Adrenalina;
		}
	}

	if (Tipo == Soggiorno)
	{
		if (Random_Number <= 20)
			{
				Nuova_Zona -> Oggetto = Cianfrusaglia;
			}

		if (Random_Number > 20 && Random_Number <= 30 )
			{
				Nuova_Zona -> Oggetto = Bende;
			}
		if (Random_Number > 30 && Random_Number <= 40)
		{
			Nuova_Zona -> Oggetto = Coltello;
		}
		if (Random_Number > 40 && Random_Number <= 70)
		{
			Nuova_Zona -> Oggetto = Pistola;
		}
		if (Random_Number > 70 && Random_Number <= 100)
		{
			Nuova_Zona -> Oggetto = Adrenalina;
		}
	}

	if (Tipo == Rimessa)
	{
		if (Random_Number <= 20)
			{
				Nuova_Zona -> Oggetto = Cianfrusaglia;
			}
		if (Random_Number > 20 && Random_Number <= 30 )
			{
				Nuova_Zona -> Oggetto = Bende;
			}
		if (Random_Number > 30 && Random_Number <= 60)
		{
			Nuova_Zona -> Oggetto = Coltello;
		}
		if (Random_Number > 60 && Random_Number <= 90)
		{
			Nuova_Zona -> Oggetto = Benzina;
		}
		if (Random_Number > 90 && Random_Number <= 100)
		{
			Nuova_Zona -> Oggetto = Adrenalina;
		}
	}

	if (Tipo == Strada)
	{
		if (Random_Number <= 80)
			{
				Nuova_Zona -> Oggetto = Cianfrusaglia;
			}
		if (Random_Number > 80 && Random_Number <= 90 )
			{
				Nuova_Zona -> Oggetto = Coltello;
			}
		if (Random_Number > 90 && Random_Number <= 100)
		{
			Nuova_Zona -> Oggetto = Benzina;
		}
	}

	if (Tipo == Lungo_Lago)
	{
		if (Random_Number <= 70)
			{
				Nuova_Zona -> Oggetto = Cianfrusaglia;
			}
		if (Random_Number > 70 && Random_Number <= 80 )
			{
				Nuova_Zona -> Oggetto = Coltello;
			}
		if (Random_Number > 80 && Random_Number <= 100)
		{
			Nuova_Zona -> Oggetto = Benzina;
		}
	}
	if (Tipo == Uscita_Campeggio)
	{
		if (Random_Number <= 90)
			{
				Nuova_Zona -> Oggetto = Cianfrusaglia;
			}
		if (Random_Number > 90 && Random_Number <= 100 )
			{
				Nuova_Zona -> Oggetto = Coltello;
			}
	}

//QUI DI SEGUITO VIENE EFFETTUATO UN CONTROLLO SULLA LISTA DI ZONE
//QUESTO BLOCCO SERVIRA' IN SEGUITO PER DEFINIRE NELLA FUNZIONE GIOCA IL NUMERO
//DELLA ZONA NELLA QUALE CI SI TROVA

	if (Prima_Zona == NULL)
	{
		Prima_Zona = Nuova_Zona;
		Ultima_Zona = Nuova_Zona;
		Nuova_Zona->i_Zona = 1;
	}
	else
	{
		Nuova_Zona->i_Zona = Ultima_Zona->i_Zona + 1;
		Ultima_Zona->Zona_Successiva = Nuova_Zona;
		Ultima_Zona = Nuova_Zona;
	}
}

//QUESTA FUNZIONE PERMETTE DI LIBERARE DALLA LISTA DINAMICA UNA ZONA ALLA VOLTA

void Cancella_Zona(int i_Zona)
{

	if (Prima_Zona != NULL)
	{
		Zona *Prev_Zona = NULL;
		Zona *Scan_Zona = Prima_Zona;
		if (Scan_Zona->Zona_Successiva == NULL)
		{
			free(Scan_Zona);
			Prima_Zona = NULL;
		}
		else
		{
			do
			{
					if((Scan_Zona->Zona_Successiva) == Ultima_Zona)
					{
						Prev_Zona = Scan_Zona;
						break;
					}
					else
					Scan_Zona = Scan_Zona -> Zona_Successiva;
			}while ((Scan_Zona -> Zona_Successiva) != NULL);
			free(Prev_Zona->Zona_Successiva);
			Prev_Zona->Zona_Successiva = NULL;
			Ultima_Zona = Prev_Zona;
		}
	}

	Crea_Mappa(1,0,0, i_Zona);
}

//QUESTA FUNZIONE PERMETTE DI STAMPARE A MONITOR LA MAPPA NEL MOMENTO STESSO IN CUI VIENE AGGIUNTA IN MEMORIA
//OGNI SINGOLA ZONA VIENE NUMERATA TRAMITE LA VARIABILE i_Zona

int Stampa_Mappa()
{
	if(Prima_Zona != NULL)
	{
				Zona *Scan_Zona = Prima_Zona;
				printf("\n\t\t\t\t\t\t\t\t ZONA\t\t\t\t\t OGGETTO\t\n");
				do
				{
					printf("\n\n\t\t\t\t\t\t %d)\t %s\t\t\t\t< %s >\t ",Scan_Zona->i_Zona ,Nome_Zona[Scan_Zona->N_Zona],Nome_Oggetto[Scan_Zona->Oggetto]);
					Scan_Zona = Scan_Zona->Zona_Successiva;
				}while(Scan_Zona != NULL);
	}
		return;
}

//FUNZIONE CHE STAMPA IL SECONDO MENU DI GIOCO ED ESEGUE CONTROLLI SUL NUMERO DI ZONE E SUL TIPO DELL'ULTIMA ZONA
//SEMPRE TRAMITE UNO switch E UN getch PERMETTE DI PASSARE DA UN MENU ALL'ALTRO ED ACCEDERE AD ALTRE FUNZIONI

int Crea_Mappa(int i, int i2,int Secondo_Menu, int i_Zona)
{
	Titoli_di_Testa();

  	if (i == 0)
  	{
			printf("\n");
    	printf("\n\t\t\t\t\t\t\t\t\t\t>");
  	}
	else
	{
		printf("\n");
		printf("\n\t\t\t\t\t\t\t\t\t\t  ");
	}

  	printf("Inserisci Zona");
	if (Secondo_Menu == 1)
	{
		printf("\t\t (%s)", Nome_Zona[i2]);
	}
	if (i == 1)
	{
			printf("\n");
    	printf("\n\t\t\t\t\t\t\t\t\t\t>");
  }
  else
  {
		printf("\n");
		printf("\n\t\t\t\t\t\t\t\t\t\t  ");
  }
	printf("Cancella Zona");

	if (i == 2)
	{
		printf("\n");
		printf("\n\t\t\t\t\t\t\t\t\t\t>");
	}
  else
  {
		printf("\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t  ");
  }
	printf("Torna Indietro");
	if (Ultima_Zona != NULL)
	{
		if (Ultima_Zona->N_Zona != Uscita_Campeggio)
		{
			printf(" \tL'ultima zona deve essere Uscita Campeggio");
		}
	}
	printf("\n\t\t\t_________________________________________________________________________________________________________________________\n\n");
	Stampa_Mappa();

	if(Secondo_Menu == 0)
	{
		switch (getch())
	  	{
	    		case 119:
	     			if (i > 0)
	        		i--;
	      		else i = 2;
	    				Crea_Mappa(i, 0, 0, i_Zona);
	    		break;

		    	case 115:
		      	if (i < 2)
		        	i++;
		      	else i = 0;
		      	Crea_Mappa(i, 0, 0, i_Zona);
		    	break;

		    case 13:
					if (i == 0)
		    		Crea_Mappa(0, 0, 1, i_Zona);
		    	if (i == 1)
		    		Cancella_Zona(i_Zona);
		    	if (i == 2)
					if (Ultima_Zona->N_Zona == Uscita_Campeggio || Prima_Zona == NULL)
					{
						Menu(0, i_Zona);
					}
					else
					if (Ultima_Zona->N_Zona != Uscita_Campeggio)
					{
		    		Crea_Mappa(0, 0, 1, i_Zona);
					}
		    break;

	    	default:
	      	Crea_Mappa(i, 0, 0, i_Zona);
	    	break;
			}
	}

	if(Secondo_Menu == 1)
	{
		switch (getch())
	  	{
	  		case 13:
					i_Zona++;
		    	Inserisci_Zona(i2);
		    break;
				case 8:
					Crea_Mappa(i, 0, 0, i_Zona);
				break;
	    	case 97:
	     		if (i2 > 0)
	        		i2--;
	      		else
				  	i2 = 5;
	    	break;

		    case 100:
		      	if (i2 < 5)
		        	i2++;
		      	else
				  	i2 = 0;
		    break;

	    	default:
	      		Crea_Mappa(0, i2, 1, i_Zona);
	    	break;
		}
		Crea_Mappa(0, i2, 1, i_Zona);
	}
}

//LA FUNZIONE SEGUENTE RIPRENDE IL CODICE DI CANCELLA ZONA ESEGUENDOLA TRAMITE UN CICLO while
//VIENE ESEGUITO UN CONTROLLO SULLA PRIMA E SULL'ULTIMA ZONA

void Dealloca_Memoria()
{

			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tSto uscendo dal Programma...");
			if (Prima_Zona != NULL)
			{
						Zona *Prev_Zona = NULL;
						Zona *Scan_Zona = Prima_Zona;
						if (Scan_Zona->Zona_Successiva == NULL)
						{
							free(Scan_Zona);
							Prima_Zona = NULL;
						}
						else
						{
							do
							{
									if((Scan_Zona->Zona_Successiva) == Ultima_Zona)
									{
										Prev_Zona = Scan_Zona;
										break;
									}
									else
									Scan_Zona = Scan_Zona -> Zona_Successiva;
							}while ((Scan_Zona -> Zona_Successiva) != NULL);
							free(Prev_Zona->Zona_Successiva);
							Prev_Zona->Zona_Successiva = NULL;
							Ultima_Zona = Prev_Zona;
						}

						Dealloca_Memoria();
			}

			if (Prima_Zona == NULL)
			{
				exit(1);
			}
}

//FUNZIONE CHE QUANDO VIENE RICHIAMATA ESEGUE CONTROLLI SULLO STATO DEI GIOCATORI E SULLA VARIABILE VITTORIA
//ESSA ALTERNA UN PRINT SEMPRE DIVERSO IN BASE ALLE CONDIZIONI INDICATE

int Game_Over()
{
	Titoli_di_Testa();

	printf("\n\n\t\t\t\t        .88888.   .d888888  8888ba.88ba   88888888b     .88888.  dP     dP  88888888b  888888ba  \n");
	printf("\t\t\t\t       d8'   `88 d8'    88  88  `8b  `8b  88           d8'   `8b 88     88  88         88    `8b \n");
	printf("\t\t\t\t       88        88aaaaa88a 88   88   88  88aaaa       88     88 88    .8P  88aaaa     88aaaa8P' \n");
	printf("\t\t\t\t       88   YP88 88     88  88   88   88  88           88     88 88    d8'  88         88   `8b. \n");
	printf("\t\t\t\t       Y8.   .88 88     88  88   88   88  88           Y8.   .8P 88  .d8P   88         88     88 \n");
	printf("\t\t\t\t        `88888'  88     88  dP   dP   dP  88888888P     `8888P'  888888'    88888888P  dP     dP \n");
	printf("\t\t\t\t       oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n\n");

	if (Giacomo.Vittoria == 1)
	{
		if (Marzia.Vittoria == 1)
		{
			printf("\t\t\t\t\t\t\t\t\tGiacomo e Marzia sono usciti dal campeggio\n");
		}
		else
		if (Marzia.Stato == Morto)
		{
			printf("\t\t\t\t\t\t\t\t\tGiacomo e' uscito dal campeggio e Marzia e' morta\n");
		}
	}
	else
	if (Marzia.Vittoria == 1)
	{
		if (Giacomo.Vittoria == 1)
		{
			printf("\t\t\t\t\t\t\t\t\tGiacomo e Marzia sono usciti dal campeggio\n");
		}
		else
		if (Giacomo.Stato == Morto)
		{
			printf("\t\t\t\t\t\t\t\t\tMarzia e' uscita dal campeggio e Giacomo e' Morto\n");
		}
	}
	if (Giacomo.Stato == Morto && Marzia.Stato == Morto)
	{
		printf("\t\t\t\t\t\t\t\t\t Giacomo e Marzia sono morti");
	}

	getchar();

}

//FUNZIONE CHE GESTISCE IL COMPORTAMENTO DI JASON TRAMITE DEI CHECK CHE VENGONO INSERITI IN UNO SWITCH
//TUTTO QUESTO PERMETTE DI GESTIRE PRINT DIVERSI IN CASO SI POSSIEDA UN SOLO OGGETTO OPPURE UNA SCELTA IN CASO SI POSSIEDA PIU' DI UN OGGETTO

int Gieson(int flag, int Rand_Jason, int CounterJason, int i_Armi)
{
	Titoli_di_Testa();
	Graphic_Gieson();

	int Check_Coltello = 0;
	int Check_Pistola = 0;
	int Check_Benzina = 0;


	if (flag == 1)
	{
		if (Giacomo.Zaino[Coltello] > 0)
		{
			Check_Coltello = 1;
		}
		if (Giacomo.Zaino[Pistola] > 0)
		{
			Check_Pistola = 2;
		}
		if (Giacomo.Zaino[Benzina] > 0)
		{
			Check_Benzina = 4;
		}
	}

	if (flag == 0)
	{
		if (Marzia.Zaino[Coltello] > 0)
		{
			Check_Coltello = 1;
		}
		if (Marzia.Zaino[Pistola] > 0)
		{
			Check_Pistola = 2;
		}
		if (Marzia.Zaino[Benzina] > 0)
		{
			Check_Benzina = 4;
		}
	}



	switch(Check_Benzina + Check_Coltello + Check_Pistola)
	{
		case 0:
			if (flag == 1)
			{
				Giacomo.Stato = Morto;
				printf("\t\t\t\t\t\t\t\t\t Giacomo e' stato ucciso da Jason\n");
				getchar();
				Scelta_Turno(flag, CounterJason, 0);
			}
			else
			{
				Marzia.Stato = Morto;
				printf("\t\t\t\t\t\t\t\t\t Marzia e' stata uccisa da Jason\n");
				getchar();
				Scelta_Turno(flag, CounterJason, 0);
			}
		break;

		case 1:
			if (flag == 1)
			{
				Giacomo.Stato--;
				Giacomo.Zaino[Coltello]--;
				printf("\t\t\t\t\t\t\t\t\t Giacomo Ha usato il Coltello\n");
				getchar();
				if (Giacomo.Stato == Ferito)
				{
					printf("\t\t\t\t\t\t\t\t\tGiacomo e' stato ferito da Jason\n");
				}
				else
				if (Giacomo.Stato == Morto)
				{
					printf("\t\t\t\t\t\t\t\t\tGiacomo e' stato ucciso da Jason\n");
				}
				getchar();
				Scelta_Turno(flag, CounterJason, 0);
			}
			else
			{
				Marzia.Stato--;
				Marzia.Zaino[Coltello]--;
				printf("\t\t\t\t\t\t\t\t\t Marzia ha usato il Coltello\n");
				getchar();
				if (Marzia.Stato == Ferito)
				{
					printf("\t\t\t\t\t\t\t\t\tMarzia e' stata ferita da Jason\n");
				}
				else
				if (Marzia.Stato == Morto)
				{
					printf("\t\t\t\t\t\t\t\t\tMarzia e' stata uccisa da Jason\n");
				}
				getchar();
				Scelta_Turno(flag, CounterJason, 0);
			}
		break;

		case 2:
			if (flag = 1)
			{
				Giacomo.Zaino[Pistola]--;
				printf("\t\t\t\t\t\t\t\t\tGiacomo ha usato la pistola per difendersi\n");
				getchar();
				Scelta_Turno(flag, CounterJason, 0);
			}
			else
			{
				Marzia.Zaino[Pistola]--;
				printf("\t\t\t\t\t\t\t\t\tMarzia ha usato la pistola per difendersi\n");
				getchar();
				Scelta_Turno(flag, CounterJason, 0);
			}
			break;

		case 4:
			if (flag == 1)
				{
					CounterJason = 4;
					Giacomo.Zaino[Benzina]--;
					printf("\t\t\t\t\t\t\t\t\t    Giacomo ha usato la Benzina     \n\n");
					getchar();
					printf("\t\t\t\t\t\t\t\t\tJason non comparira' per altri 4 turni\n\n");
					getchar();
					Scelta_Turno(flag, CounterJason, 0);
				}
			else
				{
					CounterJason = 4;
					Marzia.Zaino[Benzina]--;
					printf("\t\t\t\t\t\t\t\t\t     Marzia ha usato la Benzina     \n\n");
					getchar();
					printf("\t\t\t\t\t\t\t\t\tJason non comparira' per altri 4 turni\n\n");
					getchar();
					Scelta_Turno(flag, CounterJason, 0);
				}
		break;

		default:
			if (i_Armi == 0)
			{
				if (flag == 1)
				{
					if (Giacomo.Zaino[Coltello] > 0)
					{
					printf("\t\t\t\t\t\t\t\t<Coltello>        Pistola        Benzina\n\n");
					printf("\t\t\t\t\t\t\t\t        info: Giacomo viene ferito      \n\n");
					}
					if (Giacomo.Zaino[Coltello] <= 0)
					{
						printf("\t\t\t\t\t\t\t<Coltello>        Pistola        Benzina\n\n");
						printf("\t\t\t\t\t\t\tinfo: Giacomo non possiede questo oggetto     \n\n");
					}
				}
				else
				if (flag == 0)
				{
					if (Marzia.Zaino[Coltello] > 0)
					{
						printf("\t\t\t\t\t\t\t\t  <Coltello>        Pistola        Benzina\n\n");
						printf("\t\t\t\t\t\t\t\t           info: Marzia viene ferita      \n\n");
					}
					if (Marzia.Zaino[Coltello] <= 0)
					{
						printf("\t\t\t\t\t\t\t\t <Coltello>        Pistola        Benzina\n\n");
						printf("\t\t\t\t\t\t\t\t info: Marzia non possiede questo oggetto \n\n");
					}
				}
			}
			if (i_Armi == 1)
			{
				if (flag == 1)
				{
					if (Giacomo.Zaino[Pistola] > 0)
					{
					printf("\t\t\t\t\t\t\t\t Coltello        <Pistola>        Benzina\n\n");
					printf("\t\t\t\t\t\t\t\t info: Giacomo esce incolume dallo scontro      \n\n");
					}
					if (Giacomo.Zaino[Pistola] <= 0)
					{
						printf("\t\t\t\t\t\t\t\t Coltello        <Pistola>         Benzina\n\n");
						printf("\t\t\t\t\t\t\t\t info: Giacomo non possiede questo oggetto     \n\n");
					}
				}
				else
				if (flag == 0)
				{
					printf("\t\t\t\t\t\t\t\t Coltello        <Pistola>        Benzina\n\n");

					if (Marzia.Zaino[Pistola] > 0)
					{
						printf("\t\t\t\t\t\t\t\t info: Marzia esce incolume dallo scontro      \n\n");
					}
					if (Marzia.Zaino[Pistola] <= 0)
					{
						printf("\t\t\t\t\t\t\t\t    Marzia non possiede questo oggetto    \n\n");
					}
				}
			}
			if (i_Armi == 2)
			{
				if (flag == 1)
				{
					if (Giacomo.Zaino[Benzina] > 0)
					{
					printf("\t\t\t\t\t\t\t\t Coltello        Pistola        <Benzina>\n\n");
					printf("\t\t\t\t\t\t\t\t info: Giacomo esce incolume dallo scontro\n\n");
					getchar();
					printf("\t\t\t\t\t\t\t\t  Jason non comparira' per altri 4 turni  \n\n");
					}
					if (Giacomo.Zaino[Benzina] <= 0)
					{
						printf("\t\t\t\t\t\t\t\t Coltello        Pistola        <Benzina>\n\n");
						printf("\t\t\t\t\t\t\t\t info: Giacomo non possiede questo oggetto     \n\n");
					}
				}
				else
				if (flag == 0)
				{
					if (Marzia.Zaino[Benzina] > 0)
					{
						printf("\t\t\t\t\t\t\t\t Coltello        Pistola        <Benzina>\n\n");
						printf("\t\t\t\t\t\t\t\t info: Marzia esce incolume dallo scontro\n\n");
						getchar();
						printf("\t\t\t\t\t\t\t\t  Jason non comparira' per altri 4 turni  \n\n");
					}
					if (Marzia.Zaino[Benzina] <= 0)
					{
						printf("\t\t\t\t\t\t\t\t Coltello        Pistola        <Benzina>\n\n");
						printf("\t\t\t\t\t\t\t\t info: Marzia non possiede questo oggetto \n\n");
					}
				}
			}
		}

		switch (getch())
		{
			case 100:
				if(i_Armi < 2)
				{
					i_Armi++;
				}
				else
				if (i_Armi == 2)
				{
					i_Armi = 0;
				}
				Gieson(flag, Rand_Jason, CounterJason, i_Armi);
			break;

			case 97:
				if (i_Armi > 0)
				{
					i_Armi--;
				}
				else
				if (i_Armi == 0)
				{
					i_Armi = 2;
				}
				Gieson(flag, Rand_Jason, CounterJason, i_Armi);
			break;

			case 13:
				if (i_Armi == 0)
				{
					if (flag == 1)
					{
						if (Giacomo.Zaino[Coltello] <= 0)
						{
							Gieson(flag, Rand_Jason, CounterJason, i_Armi);
						}
						else
						if (Giacomo.Zaino[Coltello] > 0)
						{
							Giacomo.Stato =  Ferito;
							Giacomo.Zaino[Coltello]--;
							Scelta_Turno(flag, CounterJason, 0);
						}
					}
					else
					if (flag == 0)
					{
						if (Marzia.Zaino[Coltello] <= 0)
						{
							Gieson(flag, Rand_Jason, CounterJason, i_Armi);
						}
						else
						if (Marzia.Zaino[Coltello] > 0)
						{
							Marzia.Stato = Ferito;
							Marzia.Zaino[Coltello]--;
							Scelta_Turno(flag, CounterJason, 0);
						}
					}
				}

				if (i_Armi == 1)
				{
					if (flag == 1)
					{
						if (Giacomo.Zaino[Pistola] > 0)
						{
							Giacomo.Zaino[Pistola]--;
							Scelta_Turno(flag, CounterJason, 0);
						}
						else
						if (Giacomo.Zaino[Pistola] <= 0)
						{
							Gieson(flag, Rand_Jason, CounterJason, i_Armi);
						}
					}
					if (flag == 0)
					{
						if (Marzia.Zaino[Pistola] <= 0)
						{
							Gieson(flag, Rand_Jason, CounterJason, i_Armi);
						}
						else
						if (Marzia.Zaino[Pistola] > 0)
						{
							Marzia.Zaino[Pistola]--;
							Scelta_Turno(flag, CounterJason, 0);
						}
					}
				}

				if (i_Armi == 2)
				{
					if (flag == 1)
					{
						if (Giacomo.Zaino[Benzina] <= 0)
						{
							Gieson(flag, Rand_Jason, CounterJason, i_Armi);
						}
						else
						if (Giacomo.Zaino[Benzina] > 0 )
						{
							CounterJason = 4;
							Giacomo.Zaino[Benzina]--;
							Scelta_Turno(flag, CounterJason, 0);
						}
					}
					if (flag == 0)
					{
						if (Marzia.Zaino[Benzina] <= 0)
						{
							Gieson(flag, Rand_Jason, CounterJason, i_Armi);
						}
						else
						if (Marzia.Zaino[Benzina] > 0)
						{
							CounterJason = 4;
							Marzia.Zaino[Benzina]--;
							Scelta_Turno(flag, CounterJason, 0);
						}
					}
				}
			break;
		}
}

//FUNZIONE CHE GESTISCE L'ALTERNANZA DEI TURNI DEI GIOCATORI TRAMITE UN FLAG CHE VIENE INCREMENTATO E DECREMENTATO OGNI VOLTA
//GESTISCE LA LORO MORTE CONTROLLANDO LO STATO AD OGNI TURNO
//GESTISCE L'APPARIZIONE DI JASON TRAMITE UNA NUMERO CASUALE CHIAMATO RAND_JASON
//GESTISCE LA SUA MANCATA APPARIZIONE, NEL CASO IN CUI SI USINO OGGETTI SPECIFICI, TRAMITE UNA VARIABILE COUNTERJASON
//CHE VIENE INCREMENTATA IN CASO DI USO DELL'ADRENALINA O DELLA BENZINA E POI DECREMENTATA AD OGNI TURNO SUCCESSIVO

int Scelta_Turno(int flag, int CounterJason, int Rand_Jason)
{

	if (flag == 1 && CounterJason <= 0)
	{
		if (Giacomo.Posizione != Ultima_Zona && (Rand_Jason >= 35 && Rand_Jason < 65) && Marzia.Stato != Morto)
		{
			Gieson(flag, Rand_Jason, CounterJason, 0);
		}
		if (Giacomo.Posizione == Ultima_Zona && (Rand_Jason >= 20 && Rand_Jason < 95) && Marzia.Stato != Morto)
		{
			Gieson(flag, Rand_Jason, CounterJason, 0);
		}
		if (Marzia.Stato ==  Morto && (Rand_Jason >= 25 && Rand_Jason < 75))
		{
			Gieson(flag, Rand_Jason, CounterJason, 0);
		}
	}

	if (flag == 0 && CounterJason <= 0)
	{
		if (Marzia.Posizione != Ultima_Zona && (Rand_Jason >= 35 && Rand_Jason <= 65) && Giacomo.Stato != Morto)
		{
			Gieson(flag, Rand_Jason, CounterJason, 0);
		}
		if (Marzia.Posizione == Ultima_Zona && (Rand_Jason >= 20 && Rand_Jason <= 95) && Giacomo.Stato != Morto)
		{
			Gieson(flag, Rand_Jason, CounterJason, 0);
		}
		if (Giacomo.Stato ==  Morto && (Rand_Jason >= 25 && Rand_Jason <= 75))
		{
			Gieson(flag, Rand_Jason, CounterJason, 0);
		}
	}

	if (flag == 1)
	{
		if (CounterJason > 0)
		{
			CounterJason --;
		}
	}
	if (flag == 0)
	{
		if (CounterJason > 0)
		{
			CounterJason --;
		}
	}
	if (flag == 1 && Giacomo.Mossa <= 0)
	{
		flag = 0;
		Marzia.Mossa++;
	}
	else
	if (flag == 0 && Marzia.Mossa <= 0)
	{
		flag = 1;
		Giacomo.Mossa++;
	}

	if (Marzia.Stato == Morto)
	{
		flag = 1;
		Giacomo.Mossa ++;
	}
	if (Giacomo.Stato == Morto)
	{
		flag = 0;
		Marzia.Mossa ++;
	}
	if (Marzia.Stato == Morto && Giacomo.Stato == Morto)
	{
		Game_Over();
		Dealloca_Memoria();
	}

	if (Giacomo.Vittoria == 1)
	{
		if (Marzia.Vittoria == 1)
		{
			Game_Over();
			Dealloca_Memoria();
		}
		else
		if (Marzia.Stato ==  Morto)
		{
			Game_Over();
			Dealloca_Memoria();
		}
	}
	else
	if (Marzia.Vittoria == 1)
	{
		if (Giacomo.Stato == Morto)
		{
			Game_Over();
			Dealloca_Memoria();
		}
		else
		if (Giacomo.Vittoria == 1)
		{
			Game_Over();
			Dealloca_Memoria();
		}
	}

	Gioca(0, flag, CounterJason);
}

//LA FUNZIONE CURATI PERMETTE DI CURARSI FACENDO UN CONTROLLO SULLO ZAINO E SULLO STATO DEL GIOCATORE
//CHE GIOCA IN QUEL MOMENTO DECREMENTANDO POI IL LE BENDE DELLO ZAINO, LA MOSSA E RIPORTANDO LO STATO DEL GIOCATORE A VIVO

int Curati(int flag, int CounterJason)
{
	if (flag == 1 && Giacomo.Zaino[Bende] > 0 && Giacomo.Stato == Ferito)
	{
		Giacomo.Zaino[Bende]--;
		Giacomo.Stato = Vivo;
		Giacomo.Mossa--;
	}
	else
	if (flag == 0 && Marzia.Zaino[Bende] > 0 && Marzia.Stato == Ferito)
	{
		Marzia.Zaino[Bende]--;
		Marzia.Stato = Vivo;
		Marzia.Mossa--;
	}
	Scelta_Turno(flag, CounterJason, rand() % 101);
}

//LA FUNZIONE Mostra_Prendi_Oggetto CONTROLLA IL TURNO E TRAMITE UNA VARIABILE DICHIARATA NELLO STRUCT GIOCATORE
//PERMETTE DI SCOPRIRE OPPURE PRENDERE L'OGGETTO NASCOSTO DALLA ZONA TRASFORMANDOLO POI IN CIANFRUSAGLIA

int Mostra_Prendi_Oggetto(flag, CounterJason)
{
	if (flag == 1)
	{
		if (Giacomo.Posizione->Oggetto_Nascosto == 0)
		{
			Giacomo.Posizione->Oggetto_Nascosto = 1;
		}
		else
		if (Giacomo.Posizione->Oggetto_Nascosto == 1)
		{
			Giacomo.Zaino[Giacomo.Posizione->Oggetto]++;
			Giacomo.Posizione->Oggetto = Cianfrusaglia;
		}
		Giacomo.Mossa--;
	}
	else
	if (flag == 0)
	{
		if (Marzia.Posizione->Oggetto_Nascosto == 0)
		{
			Marzia.Posizione->Oggetto_Nascosto = 1;
		}
		else
		if (Marzia.Posizione->Oggetto_Nascosto == 1)
		{
			Marzia.Zaino[Marzia.Posizione->Oggetto]++;
			Marzia.Posizione->Oggetto = Cianfrusaglia;
		}
		Marzia.Mossa--;
	}
	Scelta_Turno(flag, CounterJason, rand() % 101);
}

//LA FUNZIONE GIOCA GESTISCE TUTTE LE ALTRE TRAMITE UN MENU CREATO CON UNO SWITCH
//CREA UN NUMERO CASUALE CHE DECIDE CHI COMINCIA PER PRIMO IL GIOCO
//DENTRO IL MENU CI SONO DIVERSI PRINT CHE STAMAPANO A MONITOR LO STATO DEL GIOCATORE, LE SUE MOSSE, LA ZONA E LO ZAINO
//L'ORDINE DEI PRINT E' PARTICOLARE PER PERMETTERE DI STAMPARE LO ZAINO SULLA STESSA LINEA GRAFICA DELLO SWITCH
//LA FUNZIONE RACCHIUDE ANCHE I COMANDI PER USARE L'ADRENALINA DEFINITI NELLO SWITCH

int Gioca(int i, int flag, int CounterJason, int i_Zona)
{
	Titoli_di_Testa();

		if (flag != 0 && flag != 1)
		{
			Giacomo.Zaino[Coltello] = 1;
			Marzia.Zaino[Adrenalina] = 2;
			Giacomo.Zaino[Bende] = 10;

			Giacomo.Stato = 2;
			Marzia.Stato = 2;

			time_t Seed;
			srand((unsigned)time(&Seed));
			int Random_Number = rand() % 101;

			Giacomo.Posizione = Prima_Zona;
			Marzia.Posizione = Prima_Zona;

			if (Random_Number <= 50)
			{
				Giacomo.Mossa = 1;
				Marzia.Mossa = 0;
				flag = 1;
			}
			else
			if (Random_Number > 50)
			{
				Marzia.Mossa = 1;
				Giacomo.Mossa = 0;
				flag = 0;
			}
		}


	printf("\n");
	printf("\n\n");
	printf("\t\t\t GIOCATORE \t\t");
	if (flag == 0)
	{
		if (Giacomo.Stato == Morto)
		{
		printf("MARZIA\t\t%s [%d]\tMOSSE (%d)\t",Nome_Zona[Marzia.Posizione->N_Zona], Marzia.Posizione->i_Zona, Marzia.Mossa);
		}
		else
		printf("MARZIA\t\t%s [%d]\tMOSSE (%d)\t",Nome_Zona[Marzia.Posizione->N_Zona], Marzia.Posizione->i_Zona,  Marzia.Mossa);
		printf("%s",Salute[Marzia.Stato]);
		if (Marzia.Posizione->Oggetto_Nascosto == 0)
		{
			printf("\t\tOGGETTO\t<  ? ? ? ? ? ?  >\n\n");
		}
		if (Marzia.Posizione->Oggetto_Nascosto == 1)
		{
			printf("\t\t%s\n\n",Nome_Oggetto[Marzia.Posizione->Oggetto]);
		}
	}
	else
	if (flag == 1)
	{
		if (Marzia.Stato == Morto)
		{
		printf("GIACOMO\t\t%s [%d]\tMOSSE (%d)\t", Nome_Zona[Giacomo.Posizione->N_Zona], Giacomo.Posizione->i_Zona, Giacomo.Mossa);
		}
		else
		printf("GIACOMO\t\t%s [%d]\tMOSSE (%d)\t", Nome_Zona[Giacomo.Posizione->N_Zona], Giacomo.Posizione->i_Zona, Giacomo.Mossa);
		printf("%s",Salute[Giacomo.Stato]);
		if (Giacomo.Posizione->Oggetto_Nascosto == 0)
		{
			printf("\t\tOGGETTO\t<  ? ? ? ? ? ?  >\n\n");
		}
		if (Giacomo.Posizione->Oggetto_Nascosto == 1)
		{
			printf("\t\t%s\n\n",Nome_Oggetto[Giacomo.Posizione->Oggetto]);
		}
	}

	if (i == 0)
  {
    printf("\n");
		printf("\n\n\t\t\t>");
  }
  else
  {
    printf("\n");
    printf("\n\n\t\t\t  ");
  }
    printf("Zona Successiva");
		printf("\t\t\t\t\t\tZAINO");
  if (i == 1)
  {
    printf("\n");
		printf("\n\n\t\t\t>");
  }
  else
  {
    printf("\n");
    printf("\n\n\t\t\t  ");
  }
	if (flag == 1)
	{
		if (Giacomo.Posizione->Oggetto_Nascosto == 0)
		{
	    printf("Mostra Oggetto ");
		}
		else
		if (Giacomo.Posizione->Oggetto_Nascosto == 1)
		{
			printf("Prendi Oggetto ");
		}
		printf("\t\t\t\t\t\tCianfrusaglia [%d]", Giacomo.Zaino[Cianfrusaglia]);
	}
	else
	if (flag == 0)
	{
		if (Marzia.Posizione->Oggetto_Nascosto == 0)
		{
			printf("Mostra Oggetto ");
		}
		else
		if (Marzia.Posizione->Oggetto_Nascosto == 1)
		{
			printf("Prendi Oggetto ");
		}
		printf("\t\t\t\t\t\tCianfrusaglia [%d]", Marzia.Zaino[Cianfrusaglia]);
	}
	printf("\n");
  if (i == 2)
  {
			if (flag == 1)
			{
				printf("\t\t\t\t\t\t\t\t\t\t\tBende         [%d]", Giacomo.Zaino[Bende]);
			}
			if (flag == 0)
			{
				printf("\t\t\t\t\t\t\t\t\t\t\tBende         [%d]", Marzia.Zaino[Bende]);
			}
			printf("\n");
			if (flag == 1)
			{
				printf("\t\t\t\t\t\t\t\t\t\t\tColtello      [%d]", Giacomo.Zaino[Coltello]);
			}
			if (flag == 0)
			{
				printf("\t\t\t\t\t\t\t\t\t\t\tColtello      [%d]", Marzia.Zaino[Coltello]);
			}
			printf("\n\t\t\t>");
	}
	else
	{
		if (flag == 1)
		{
			printf("\t\t\t\t\t\t\t\t\t\t\tBende         [%d]", Giacomo.Zaino[Bende]);
		}
		if (flag == 0)
		{
			printf("\t\t\t\t\t\t\t\t\t\t\tBende         [%d]", Marzia.Zaino[Bende]);
		}
		printf("\n");

		if (flag == 1)
		{
			printf("\t\t\t\t\t\t\t\t\t\t\tColtello      [%d]", Giacomo.Zaino[Coltello]);
		}
		if (flag == 0)
		{
			printf("\t\t\t\t\t\t\t\t\t\t\tColtello      [%d]", Marzia.Zaino[Coltello]);
		}
		printf("\n\t\t\t  ");
	}

		printf("Curati");

		if (flag == 1)
		{
			printf(" \t\t\t\t\t\t\tPistola       [%d]", Giacomo.Zaino[Pistola]);
		}
		if (flag == 0)
		{
			printf(" \t\t\t\t\t\t\tPistola       [%d]", Marzia.Zaino[Pistola]);
		}

		if (i == 3)
	  {
	    printf("\n");
			if (flag == 1)
			{
				printf(" \t\t\t\t\t\t\t\t\t\t\tBenzina       [%d]", Giacomo.Zaino[Benzina]);
			}
			if (flag == 0)
			{
				printf(" \t\t\t\t\t\t\t\t\t\t\tBenzina       [%d]", Marzia.Zaino[Benzina]);
			}
			printf("\n");
			if (flag == 1)
			{
				printf(" \t\t\t\t\t\t\t\t\t\t\tChiavi Auto   [%d]", Giacomo.Zaino[Chiavi_Auto]);
			}
			if (flag == 0)
			{
				printf(" \t\t\t\t\t\t\t\t\t\t\tChiavi Auto   [%d]", Marzia.Zaino[Chiavi_Auto]);
			}
			printf("\n\t\t\t>Usa Adrenalina ");
	  }
	  else
	  {
	    printf("\n");
			if (flag == 1)
			{
				printf(" \t\t\t\t\t\t\t\t\t\t\tBenzina       [%d]", Giacomo.Zaino[Benzina]);
			}
			if (flag == 0)
			{
				printf(" \t\t\t\t\t\t\t\t\t\t\tBenzina       [%d]", Marzia.Zaino[Benzina]);
			}

			printf("\n");
			if (flag == 1)
			{
				printf(" \t\t\t\t\t\t\t\t\t\t\tChiavi Auto   [%d]", Giacomo.Zaino[Chiavi_Auto]);
			}
			if (flag == 0)
			{
				printf(" \t\t\t\t\t\t\t\t\t\t\tChiavi Auto   [%d]", Marzia.Zaino[Chiavi_Auto]);
			}
	    printf("\n\t\t\t  Usa Adrenalina");
	  }
			if (flag == 1 && Giacomo.Zaino[Adrenalina] <= 0 && i == 3)
			{
				printf("[Non possiedi questo Oggetto]");

			}
			if (flag == 0 && Marzia.Zaino[Adrenalina] <= 0 && i == 3)
			{
				printf("[Non possiedi questo Oggetto]");
			}

			if (i != 3 || (flag == 1 && Giacomo.Zaino[Adrenalina] > 0) || (flag == 0 && Marzia.Zaino[Adrenalina] > 0))
			{
				printf("                             ");
			}

			if(flag == 1)
			{
				printf(" \t\t\tAdrenalina    [%d]", Giacomo.Zaino[Adrenalina]);
			}

			if(flag == 0)
			{
				printf(" \t\t\tAdrenalina    [%d]", Marzia.Zaino[Adrenalina]);
			}

    	printf("\n\n\t\t\t_________________________________________________________________________________________________________________________\n\n\n");

			time_t Seed;
			srand((unsigned)time(&Seed));

	switch (getch())
	{
		case 119:
			if (i > 0)
				i--;
			else
				i = 3;
		break;

		case 115:
			if (i < 3)
				i++;
			else
				i = 0;
		break;

		case 13:
			if (i == 0)
				{
					if (flag == 1)
					{
						if (Giacomo.Posizione == Ultima_Zona)
						{
							Giacomo.Vittoria = 1;
							Scelta_Turno(flag, CounterJason, rand() % 101);
						}
						else
						if (Giacomo.Posizione != Ultima_Zona)
						{
						Giacomo.Posizione = Giacomo.Posizione -> Zona_Successiva;
						Giacomo.Mossa--;
						Scelta_Turno(flag, CounterJason, rand() % 101);
						}
					}
					else
					if (flag == 0)
					{
						if (Marzia.Posizione == Ultima_Zona)
						{
							Giacomo.Vittoria = 1;
							Scelta_Turno(flag, CounterJason, rand() % 101);
						}
						else
						if (Marzia.Posizione != Ultima_Zona)
						{
						Marzia.Posizione = Marzia.Posizione -> Zona_Successiva;
						Marzia.Mossa--;
						Scelta_Turno(flag, CounterJason, rand() % 101);
						}
					}
				}
			if (i == 1)
			{
				Mostra_Prendi_Oggetto(flag, CounterJason, rand() % 101);
			}
			if (i == 2)
				Curati(flag, CounterJason);
			if (i == 3)
			{
				if (flag == 1 && Giacomo.Zaino[Adrenalina] > 0)
				{
					Giacomo.Mossa += 2;
					Giacomo.Zaino[Adrenalina]--;
					CounterJason += 2;
					Giacomo.Mossa --;
					Scelta_Turno(flag, CounterJason, rand() % 101);
				}
					else
					if (flag == 0 && Marzia.Zaino[Adrenalina] > 0)
					{
						Marzia.Mossa += 2;
						Marzia.Zaino[Adrenalina]--;
						CounterJason += 2;
						Marzia.Mossa --;
						Scelta_Turno(flag, CounterJason, rand() % 101);
					}
			}
		break;

		default:
			Gioca(i, flag, CounterJason, i_Zona);
		break;
	}

	Gioca(i, flag, CounterJason, i_Zona);
}

