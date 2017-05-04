#include "snake.h"

/**
    @file funkcje_pomocnicze.c
    \brief Przechowuje definicje funkcji uzywanych w funkcji gra.
*/

/**
    * \fn void szybkosc()
    * \brief funkcja funkcja inkremetnujaca zmienna globalna predkosc o 1.
*/

void szybkosc(){
    predkosc++;
}

/**
    * \fn int losuj(int zakres)
    * \brief funkcja losujaca liczbe z podanego zakresu podzielna przez 15.
    * \param zakres zmienna okresla zakres losowania liczby.
    * \return zwraca wylosowana liczbe z podanego zakresu podzielna przez 15.
*/

int losuj(int zakres){
    int liczba=0;
    do{
        liczba = rand()%zakres;
    }while(liczba%15!=0);
    return liczba;
}

/**
    * \fn int pauza(int punkty, BITMAP * bufor)
    * \brief funkcja pauzuje gre oraz wypisuje ilosc zdobytych dotychczas punktow.
    * \param punkty, ilosc punktow zdobytych dotychczas przez gracza.
    * \param bufor, wskaznik na bitmape ktora sluzy do podwojnego buforowania.
    * \return 0 po zakonczeniu wykonywania.
*/

int pauza(int punkty, BITMAP * bufor){
    key[KEY_P] = 0;
    while(!key[KEY_P]){
        textout_ex( bufor, font, "PAUZA", 590, 340, makecol( 0, 0, 255 ), - 1 );
        textprintf_ex( bufor, font, 590, 360, makecol( 0, 0, 255 ), - 1, "Punkty : %d", punkty );
        blit( bufor, screen, 0, 0, 0, 0, 1280, 720 );
    }
    return 0;
}

