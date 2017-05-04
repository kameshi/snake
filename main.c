#include "snake.h"

/**
    @file main.c
    \brief Przechowuje funkcje main.
*/

/// \param predkosc, zmienna sluzy do zmiany predkosci gry( przydomku valatile wylaczona optymalizacje stosowana przez kompilator , stosowaną przy zmiennych których wartość jest często zmieniana)

volatile long predkosc;

/**
    * \fn int main()
    * \brief Funkcja glowna programu .
*/

int main(){
    char nick[10];
    //instalacja biblioteki oraz dodatkowych komponentow.
    allegro_init();
    install_keyboard();
    install_mouse();
    install_timer();
    install_sound( DIGI_AUTODETECT, MIDI_AUTODETECT, "" );

    //ustawienie zainstalowanych komponentow.
    set_volume( 255, 255 );
    set_color_depth( 16 );
    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 1260, 705, 0, 0 );
    clear_to_color( screen, makecol( 0, 0, 80) );
    show_mouse( screen );
    unscare_mouse();

    odczyt();
    pob_nick(nick);
    menu(nick);
    //otwarcie pliku WYNIKI.txt w razie gdyby nie istnia³ instrukcja tworzy go, zapisanie do niego 10 najlepszych wynikow oraz zamkniecie go.
    zapisz();
    remove_int(szybkosc);
    readkey();
    //zakonczenie dzialania biblioteki allegro.
    allegro_exit();
    return 0;
}
END_OF_MAIN()

