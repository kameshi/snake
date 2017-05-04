#include "snake.h"

/**
    @file bitmapy_czcionki_dzwieki.c
    \brief Przechowuje definicje funkcji sprawdzajacych poprawnosc utworzenia bitmapy, czcionki i dzwieku.
*/

/**
    * \fn sprawdzenie_bitmap(BITMAP * spraw)
    * \brief funkcja sprawdza, czy bitmapa zostala poprawnie utworzona, jezeli nie konczy dzialanie programu.
    * \param spraw, wskaznik na sprawdzana bitmape.
*/

void sprawdzenie_bitmap(BITMAP * spraw){
    if( !spraw ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "Nie moge utworzyc bitmapy !" );
        allegro_exit();
    }
}

/**
    * void sprawdzenie_czcionek(FONT * spraw)
    * \brief funkcja sprawdza, czy czcionka zostala poprawnie utworzona, jezeli nie konczy dzialanie programu.
    * \param spraw, wskaznik na sprawdzana czcionke.
*/

void sprawdzenie_czcionek(FONT * spraw){
    if( !spraw ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "Nie moge zaladowac czcionki !" );
        allegro_exit();
    }
}

/**
    * \fn void sprawdzenie_dzwiekow(SAMPLE * spraw)
    * \brief funkcja sprawdza, czy dzwiek zostal poprawnie utworzony, jezeli nie konczy dzialanie programu.
    * \param spraw, wskaznik na sprawdzany dzwiek.
*/

void sprawdzenie_dzwiekow(SAMPLE * spraw){
    if( !spraw ){
        set_gfx_mode( GFX_TEXT, 0, 0, 0, 0 );
        allegro_message( "Nie moge zaladowac dzwieku !" );
        allegro_exit();
    }
}
