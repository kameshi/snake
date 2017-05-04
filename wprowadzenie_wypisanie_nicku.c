#include "snake.h"

/**
    @file wprowadzenie_wypisanie_nicku.c
    \brief Przechowuje definicje funkcji odpowiedzialnych za rysowanie klawiatury, pobranie i wypisanie nicku.
*/

/**
    * \fn void wypisz_nick(BITMAP * bufor, char * nick, int dlugosc_nicku)
    * \brief Funkcja wypisuje nick zawarty w tablicy nick[].
    * \param bufor, wskaznik na bitmape, ktora sluzy do podwojnego buforowania.
    * \param nick, wskaznik na tablice zawierajaca nick gracza
    * \param dlugosc_nicku, ilosc elementow w tablicy nick[]
*/

void wypisz_nick(BITMAP * bufor, char * nick, int dlugosc_nicku){
    int i, x=580;
    FONT* cz_wyniki;
    cz_wyniki  = load_font("tekst_wyn.PCX", default_palette, NULL);
    sprawdzenie_czcionek(cz_wyniki);
    textprintf_ex( bufor, cz_wyniki, 520, 200, makecol( 68, 232, 187), - 1, "Nick:" );
    for(i=0;i<dlugosc_nicku;i++){
        textprintf_ex( bufor, cz_wyniki, x, 200, makecol( 68, 232, 187), - 1, "%c", nick[i]);
        x+=20;
    }
    destroy_font(cz_wyniki);
}

/**
    * \fn void rys_klaw(int ascii, FONT * czcionka_klaw, BITMAP * litery, BITMAP * bufor)
    * \brief Funkcja rysuje klawiature ekranowa alfabetyczne.
    * \param ascii, kod ascii pierwszej rysowanej litery.
    * \param czcionka_klaw, wskaznik na czcionke, uzywanej do wypisania liter na klawiszach.
    * \param litery, wskaznik na bitmape ktora sluzy za klawisze.
    * \param bufor, wskaznik na bitmape ktora sluzy do podwojnego buforowania.
*/

void rys_klaw(int ascii, FONT * czcionka_klaw, BITMAP * litery, BITMAP * bufor){
    int i=0, xz=300, yz=400;
    for(;i<10;i++){
        clear_to_color( litery, makecol( 247, 244, 159));
        textprintf_ex( litery, czcionka_klaw, 20, 11, makecol( 0, 0, 0 ), - 1, "%c", i+ascii);
        blit( litery, bufor, 0, 0, xz, yz, litery->w, litery->h );
        xz+=60;
    }
    xz=300;
    yz+=60;
    for(;i<19;i++){
        clear_to_color( litery, makecol( 247, 244, 159));
        textprintf_ex( litery, czcionka_klaw, 20, 11, makecol( 0, 0, 0 ), - 1, "%c", i+ascii);
        blit( litery, bufor, 0, 0, xz, yz, litery->w, litery->h );
        xz+=60;
    }
    clear_to_color( litery, makecol( 247, 244, 159));
    textprintf_ex( litery, font, 3, 15, makecol( 0, 0, 0 ), - 1, "Back");
    textprintf_ex( litery, font, 3, 22, makecol( 0, 0, 0 ), - 1, "space");
    blit( litery, bufor, 0, 0, xz, yz, litery->w, litery->h );
    yz+=60;
    xz=330;
    clear_to_color( litery, makecol( 247, 244, 159));
    textprintf_ex( litery, font, 5, 20, makecol( 0, 0, 0 ), - 1, "Shift");
    blit( litery, bufor, 0, 0, xz, yz, litery->w, litery->h );
    xz+=60;
    for(;i<26;i++){
        clear_to_color( litery, makecol( 247, 244, 159));
        textprintf_ex( litery, czcionka_klaw, 20, 11, makecol( 0, 0, 0 ), - 1, "%c", i+ascii);
        blit( litery, bufor, 0, 0, xz, yz, litery->w, litery->h );
        xz+=60;
    }
    clear_to_color( litery, makecol( 247, 244, 159));
    textprintf_ex( litery, font, 5, 20, makecol( 0, 0, 0 ), - 1, "Enter");
    blit( litery, bufor, 0, 0, xz, yz, litery->w, litery->h );
    blit( bufor, screen, 0, 0, 0, 0, 1280, 720 );
}

/**
    * \fn void pob_nick(char * nick)
    * \brief Funkcja pobiera i zapisuje nick na tablicy nick[], nick może mieć maksymalnie 10 elementow.
    * \param nick, wskaznik na tablice zawierajaca nick gracza
*/

void pob_nick(char * nick){
    BITMAP * bufor;
    bufor = create_bitmap( 1280,  720);
    sprawdzenie_bitmap(bufor);
    FONT * czcionka_klaw;
    czcionka_klaw  = load_font("klawiatura.PCX", default_palette, NULL);
    sprawdzenie_czcionek(czcionka_klaw);
    BITMAP * litery;
    litery = create_bitmap(50,50);
    sprawdzenie_bitmap(litery);
    int i=0, xz=300, yz=400, ascii=97, dlugosc_nicku=0;
    do{
        clear_to_color( bufor, makecol( 0, 0, 80 ) );
        wypisz_nick(bufor,nick,dlugosc_nicku);
        rys_klaw(ascii,czcionka_klaw,litery,bufor);
        xz=300;
        yz=400;
        if(mouse_b==1){
            for(;i<10;i++){
                if(mouse_x<xz+60 && mouse_x>xz && mouse_y<yz+60 && mouse_y>yz){
                    nick[dlugosc_nicku]= i+ascii;
                    dlugosc_nicku++;
                }
                xz+=60;
            }
            xz=300;
            yz+=60;
            for(;i<19;i++){
                if(mouse_x<xz+60 && mouse_x>xz && mouse_y<yz+60 && mouse_y>yz){
                    nick[dlugosc_nicku]= i+ascii;
                    dlugosc_nicku++;
                }
                xz+=60;
            }
            if(mouse_x<xz+60 && mouse_x>xz && mouse_y<yz+60 && mouse_y>yz){
                if(dlugosc_nicku!=0){
                    dlugosc_nicku--;
                }
            }
            yz+=60;
            xz=330;
            if(mouse_x<xz+60 && mouse_x>xz && mouse_y<yz+60 && mouse_y>yz){
                if(ascii==97){
                    ascii=65;
                }
                else ascii=97;
            }
            xz+=60;
            for(;i<26;i++){
                if(mouse_x<xz+60 && mouse_x>xz && mouse_y<yz+60 && mouse_y>yz){
                    nick[dlugosc_nicku]= i+ascii;
                    dlugosc_nicku++;
                }
                xz+=60;
            }
            if(mouse_x<xz+60 && mouse_x>xz && mouse_y<yz+60 && mouse_y>yz){
                if(nick[0]==NULL){
                    allegro_message( "Proszê wprowadziæ nick." );
                }
                else{
                    if(dlugosc_nicku==6 || dlugosc_nicku == 7 || dlugosc_nicku == 8){
                        nick[dlugosc_nicku]='\0';
                    }
                    dlugosc_nicku=10;
                }
            }
        }
        mouse_b=0;
        i=0;
        if(dlugosc_nicku==9){
            textprintf_ex( bufor, font, 3, 3, makecol( 0, 0, 255 ), - 1, "Została do dyspozycji ostatnia litera po jej wybraniu pobieranie nicku zakonczy sie." );
        }
        blit( bufor, screen, 0, 0, 0, 0, 1280, 720 );
    }while(dlugosc_nicku!=10);
    destroy_bitmap(bufor);
    destroy_bitmap(litery);
    destroy_font(czcionka_klaw);
}

