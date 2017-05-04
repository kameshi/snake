#include "snake.h"

/**
    @file menu.c
    \brief Przechowuje funkcje menu.
*/

/**
    * \fn void menu(char * nick)
    * \brief Funkcja rysuje menu na ekranie, wykrywa ktory przycisk wciska gracz i zaleznie od tego wykonuje odpowiednie instrukcje.
    * \param nick, wskaznik na tablice zawierajaca nick gracza.
*/

void menu(char * nick){
    BITMAP * bufor;
    bufor = create_bitmap( 1280,  720);
    sprawdzenie_bitmap(bufor);
    FONT* czcionka;
    czcionka  = load_font("Monotype_corsiva.PCX", default_palette, NULL);
    sprawdzenie_czcionek(czcionka);
    BITMAP * przycisk;
    przycisk = create_bitmap(90,50);
    sprawdzenie_bitmap(przycisk);
    int i = 1;
    while(i){
        clear_to_color( bufor, makecol( 0, 0, 128 ) );
        clear_to_color( przycisk, makecol( 247, 244, 159) );
        textout_ex( przycisk, czcionka, "Start", 16, 10, makecol( 0, 0, 255 ), - 1 );
        blit( przycisk, bufor, 0, 0, 590, 250, przycisk->w, przycisk->h );
        clear_to_color( przycisk, makecol( 247, 244, 159) );
        textout_ex( przycisk, czcionka, "Wyniki", 2, 10, makecol( 0, 0, 255 ), - 1 );
        blit( przycisk, bufor, 0, 0, 590, 350, przycisk->w, przycisk->h );
        clear_to_color( przycisk, makecol( 247, 244, 159) );
        textout_ex( przycisk, czcionka, "Koniec", 10, 10, makecol( 0, 0, 255 ), - 1 );
        blit( przycisk, bufor, 0, 0, 590, 450, przycisk->w, przycisk->h );
        textout_ex( bufor, czcionka, "SNAKE!", 585, 200, makecol( 68, 232, 187), - 1 );
        blit( bufor, screen, 0, 0, 0, 0, 1280, 720 );
        if(mouse_b==1){
            mouse_b=0;
            // Po nacisnieciu tego przycisku przechodzimy do funkcji gra i razpoczynamy gre.
            if(mouse_x<690 && mouse_x>590 && mouse_y<300 && mouse_y>250){
                gra(nick);
            }
            // Po nacisnieciu tego przycisku przechodzimy do funkcji wyp_wynik, ktora wypisuje 10 najlepszych wynikow.
            else if(mouse_x<690 && mouse_x>590 && mouse_y<400 && mouse_y>350){
                wyp_wynik(bufor);
            }
            // Po nacisnieciu tego przycisku konczymy gre.
            else if(mouse_x<690 && mouse_x>590 && mouse_y<500 && mouse_y>450){
                i = 0;
            }
        }
        clear_keybuf();
    }
    clear_to_color( screen, makecol( 0, 0, 128) );
    textout_ex( screen, font, "Nacisnij ESC", 590, 360, makecol( 68, 230, 255 ), - 1 );
    destroy_font(czcionka);
    destroy_bitmap(przycisk);
}

