#include "gamelib.h"
int Crea_Mappa(int, int, int,int);

int Crea_Mappa();
int Menu();
void Dealloca_Memoria();
int Titoli_di_Testa();
int Gioca();

//NELLA FUNZIONE MENU VENGONO EFFETTUATI DEI PRINT CHE TRAMITE UNO switch CON ISTRUZIONE GETCH RICARICANO IL MENU DANDO L'IDEA DI MOVIMENTO
//DENTRO LO switch VENGONO EFFETTUATI DEI CONTROLLI ANCHE SUL NUMERO DI ZONE INSERITE NELLA MAPPA
//TRAMITE UNA VARIABILE i_Zona

int Menu(int i, int i_Zona)
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
    printf("Gioca\t");
    if (i_Zona < 8 && i == 0)
    {
      printf("\t\tTroppe poche Zone per poter Giocare [%d]", i_Zona);
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
    printf("Crea Mappa");
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
    printf("Termina Gioco\n");
    printf("\t\t\t_________________________________________________________________________________________________________________________");

  switch (getch())
  {
    case 119:
      if (i > 0)
        i--;
      else
        i = 2;
    break;

    case 115:
      if (i < 2)
        i++;
      else
        i = 0;
    break;

    case 13:
      if (i == 0)
      {
        if (i_Zona < 8 && i == 0)
        {
          Menu(i, i_Zona);
        }
        else
    		Gioca(0,-1,0, i_Zona);
      }
    	if (i == 1)
    		Crea_Mappa(0, 0, 0, i_Zona);
    	if (i == 2)
        Dealloca_Memoria();
    break;

    default:
      Menu(i, i_Zona);
    break;
  }

  Menu(i, i_Zona);

}

int main()
{
  Menu(0, 0);
}
