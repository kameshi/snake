#include "snake.h"

/**
    @file punkty.c
    \brief Przechowuje definicje funkcji, ktore sprawdzaja, czy gracz dostal sie do najlepszej dziesiatki oraz wypisujacej 10 najlepszych wynikow.
*/

/**
    * \fn void wyp_wynik(BITMAP * bufor)
    * \brief Funkcja wypisuje 10 najlepszych wynikow zapisanych w tablicy struktur wyniki[], konczy dzialanie po nacisnieciu klawisza ESC.
    * \param bufor, wskaznik na bitmape ktora sluzy do podwojnego buforowania.
*/

void wyp_wynik(BITMAP * bufor){
    key[KEY_ESC]=0;
    FONT* cz_wyniki;
    cz_wyniki  = load_font("tekst_wyn.PCX", default_palette, NULL);
    sprawdzenie_czcionek(cz_wyniki);
    int i, x, y;
    clear_to_color( bufor, makecol( 128, 128, 128 ) );
    x=200;
    y=500;
    textprintf_ex( bufor, cz_wyniki, y, x, makecol( 0, 0, 255 ), - 1, "ID");
    y+=40;
    textprintf_ex( bufor, cz_wyniki, y, x, makecol( 0, 0, 255 ), - 1, "Nick:");
    y+=130;
    textprintf_ex( bufor, cz_wyniki, y, x, makecol( 0, 0, 255 ), - 1, "Punkty:");
    x+=20;
    for(i=0;i<10;i++){
        y=500;
        textprintf_ex( bufor, cz_wyniki, y, x, makecol( 0, 0, 255 ), - 1, "%d", i+1);
        y+=40;
        textprintf_ex( bufor, cz_wyniki, y, x, makecol( 0, 0, 255 ), - 1, "%s", wyniki[i].nick);
        y+=130;
        textprintf_ex( bufor, cz_wyniki, y, x, makecol( 0, 0, 255 ), - 1, "%d", wyniki[i].punkty[0]);
        x+=20;
    }
    blit( bufor, screen, 0, 0, 0, 0, 1280, 720 );
    while(!key[KEY_ESC]){}
    destroy_font(cz_wyniki);
}

/**
    * \fn void sprawd(int punkty,char * nick)
    * \brief funkcja sprawdza, czy zdobyte przez gracza punkty pozwalaja wejsc mu do najlepszej 10, jesli tak ta zapisuje jego nick i punkty w odpowiednim miejscu w tablicy struktur wyniki[].
    * \param punkty, ilosc zdobytych punktow.
    * \param nick, wskaznik na tablice zawierajaca nick gracza
*/

void sprawd(int punkty,char * nick){
    int i;
    char pom;
    char pomo[10];
    char pomo2[10];
    strcpy(pomo2,nick);
    for(i=0;i<10;i++){
        if(wyniki[i].punkty[0] == '0'){
            strcpy(wyniki[i].nick,nick);
            wyniki[i].punkty[0] = punkty;
            i=9;
        }
        else if(punkty > wyniki[i].punkty[0]){
            for(i;i<10;i++){
                strcpy(pomo,wyniki[i].nick);
                strcpy(wyniki[i].nick,pomo2);
                strcpy(pomo2,pomo);
                pom = wyniki[i].punkty[0];
                wyniki[i].punkty[0] = punkty;
                punkty = pom;
                if(wyniki[i+1].punkty[0] == '0'){
                    wyniki[i+1].punkty[0] = punkty;
                    strcpy(wyniki[i].nick,pomo2);
                    i=9;
                }
            }
        }
    }
}

