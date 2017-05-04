#include "snake.h"

/**
    @file gra.c
    \brief Przechowuje funkcje gra.
*/

/**
    * \fn void gra(char * nick)
    * \brief Funkcja odpowiedzialna za ruch wezem, za zbieranie i pojawianie sie jego pozywienia.
    * \param nick, wskaznik na tablice zawierajaca nick gracza.
*/

void gra(char * nick){
    srand(time(0));
    // BITMAP* wskazniki na obrazki przedstawiajace cialo weza oraz jego pozywienie.
    BITMAP * bufor;
    BITMAP * glowa;
    BITMAP * owoc;
    BITMAP * glowa_lewo;
    BITMAP * moneta;
    BITMAP * czaszka;
    BITMAP * nuclear;
    BITMAP * gwiazda;
    BITMAP * prezent;
    BITMAP * czesc_ciala;
    // SAMPLE* wskazniki na dzwieki pojawiajace sie w czasie zjedzenia i zakonczenia gry.
    SAMPLE * punkt;
    SAMPLE * brawa;
    SAMPLE * kasa;
    SAMPLE * tada;
    SAMPLE * usun;
    SAMPLE * star;
    // FONT* wskaznik na czcionke
    FONT* czcionka_gra;
    // tworzenie i sprawdzanie czy bitmapy, dzwieki i czcionki zostaly poprawnie utworzone.
    bufor = create_bitmap( 1280,  720);
    sprawdzenie_bitmap(bufor);
    glowa = load_bmp( "snake.bmp", default_palette );
    sprawdzenie_bitmap(glowa);
    glowa_lewo = load_bmp( "snake_lewo.bmp", default_palette );
    sprawdzenie_bitmap(glowa_lewo);
    owoc = load_bmp( "food.bmp", default_palette );
    sprawdzenie_bitmap(owoc);
    moneta = load_bmp( "moneta.bmp", default_palette );
    sprawdzenie_bitmap(moneta);
    czaszka = load_bmp( "czaszka.bmp", default_palette );
    sprawdzenie_bitmap(czaszka);
    nuclear = load_bmp( "nuclear.bmp", default_palette );
    sprawdzenie_bitmap(nuclear);
    gwiazda = load_bmp( "gwiazda.bmp", default_palette );
    sprawdzenie_bitmap(gwiazda);
    prezent = load_bmp( "prezent.bmp", default_palette );
    sprawdzenie_bitmap(prezent);
    czesc_ciala = load_bmp( "klocek.bmp", default_palette );
    sprawdzenie_bitmap(czesc_ciala);
    punkt = load_sample("curmove.wav");
    sprawdzenie_dzwiekow(punkt);
    brawa = load_sample("Applause.wav");
    sprawdzenie_dzwiekow(brawa);
    kasa = load_sample("Cash.wav");
    sprawdzenie_dzwiekow(kasa);
    tada = load_sample("Ta Da.wav");
    sprawdzenie_dzwiekow(tada);
    usun = load_sample("Jumping.wav");
    sprawdzenie_dzwiekow(usun);
    star = load_sample("Victory.wav");
    sprawdzenie_dzwiekow(star);
    czcionka_gra = load_font("czcionka_gra.PCX", default_palette, NULL);
    sprawdzenie_czcionek(czcionka_gra);
    // deklaracja ciala weza
    struct cialo_weza_poczatek_koniec cialo = {NULL , NULL };
    // deklaracja zmiennych
    int glowa_x = 600, glowa_y = 345;
    int koniec = 0, punkty = 0, kierunek = 0, kierunek_pomoc, czas = 0, extra, extra2, dodatki=11, poruszenie, i;
    float speed = 15;
    int tablica_x[6];//indeksy: 0-owoc, 1-moneta, 2-czaszka, 3-prezent, 4-gwiazda, 5-nuclear
    int tablica_y[6];//indeksy: 0-owoc, 1-moneta, 2-czaszka, 3-prezent, 4-gwiazda, 5-nuclear

    key[KEY_P] = 0;
    key[KEY_ESC] = 0;
    for(i=0;i<6;i++){
        tablica_x[i] = losuj(1200);
        tablica_y[i] = losuj(700);
    }
    extra = time(NULL)+10;
    clear_to_color( bufor, makecol( 0, 0, 80) );
    // petla wykonuje sie do czasu zjedzenia czaszki, najechania na wlasne cialo, najechania na sciane lub wcisniecia klawisza ESC.
    while(!key[KEY_ESC]){
        install_int_ex( szybkosc, BPS_TO_TIMER( speed ) );
        while( predkosc > 0 ){
        clear_keybuf();
        if(kierunek==1 || kierunek_pomoc==1){
            if(key[KEY_LEFT]){
                glowa_x-=15;
                poruszenie = 0;
                kierunek = 1;
            }
            else if(key[KEY_UP]){
                glowa_y-=15;
                poruszenie = 0;
                kierunek = 3;
            }
            else if(key[KEY_DOWN]){
                glowa_y+=15;
                poruszenie = 0;
                kierunek = 4;
            }
        }
        else if(kierunek==2 || kierunek_pomoc==2){
            if(key[KEY_RIGHT]){
                glowa_x+=15;
                poruszenie = 0;
                kierunek = 2;
            }
            else if(key[KEY_UP]){
                glowa_y-=15;
                poruszenie = 0;
                kierunek = 3;
            }
            else if(key[KEY_DOWN]){
                glowa_y+=15;
                poruszenie = 0;
                kierunek = 4;
            }
        }
        else if(kierunek==3 || kierunek_pomoc==3){
            if(key[KEY_LEFT]){
                glowa_x-=15;
                poruszenie = 0;
                kierunek = 1;
            }
            else if(key[KEY_RIGHT]){
                glowa_x+=15;
                poruszenie = 0;
                kierunek = 2;
            }
            else if(key[KEY_UP]){
                glowa_y-=15;
                poruszenie = 0;
                kierunek = 3;
            }
        }
        else if(kierunek==4 || kierunek_pomoc==4){
            if(key[KEY_LEFT]){
                glowa_x-=15;
                poruszenie = 0;
                kierunek = 1;
            }
            else if(key[KEY_RIGHT]){
                glowa_x+=15;
                poruszenie = 0;
                kierunek = 2;
            }
            else if(key[KEY_DOWN]){
                glowa_y+=15;
                poruszenie = 0;
                kierunek = 4;
            }
        }
        else if(kierunek==0){
            if(key[KEY_LEFT]){
                glowa_x-=15;
                poruszenie = 0;
                kierunek = 1;
            }
            else if(key[KEY_RIGHT]){
                glowa_x+=15;
                poruszenie = 0;
                kierunek = 2;
            }
            else if(key[KEY_UP]){
                glowa_y-=15;
                poruszenie = 0;
                kierunek = 3;
            }
            else if(key[KEY_DOWN]){
                glowa_y+=15;
                poruszenie = 0;
                kierunek = 4;
            }
        }
        //poruszanie glowa i wywolanie funkcji przesuwajacej cialo
        if(poruszenie){
            if(kierunek==1) glowa_x-=15;
            else if(kierunek==2) glowa_x+=15;
            else if(kierunek==3) glowa_y-=15;
            else if(kierunek==4) glowa_y+=15;
        }
        if(cialo.koniec!=NULL && kierunek!=0 ){
            przesun_cialo_weza(&cialo,kierunek);
        }
        //wypisanie punktow i nicku na ekranie gry
        clear_to_color( bufor, makecol( 128, 128, 128) );
        textprintf_ex( bufor, czcionka_gra, 0, 670, makecol( 0, 0, 0), -1,"Punkty: %d", punkty);
        textprintf_ex( bufor, czcionka_gra, 1000, 670, makecol( 0, 0, 0), -1, "Nick: %s", nick);
        poruszenie = 1;
        predkosc--;
        }
        //rysowanie glowy i wywolanie funkcji rysujacej cialo
        if(kierunek == 1 || kierunek_pomoc == 1){
            draw_sprite( bufor, glowa_lewo, glowa_x, glowa_y );
        }
        else if(kierunek == 2 || kierunek_pomoc == 2){
            draw_sprite( bufor, glowa, glowa_x, glowa_y );
        }
        else if(kierunek == 3 || kierunek_pomoc == 3){
            rotate_sprite( bufor, glowa, glowa_x, glowa_y, itofix( 192 ) );
        }
        else if(kierunek == 4 || kierunek_pomoc == 4){
            rotate_sprite( bufor, glowa, glowa_x, glowa_y, itofix( 64 ) );
        }
        if(kierunek!=0){
            kierunek_pomoc = 0;
        }
        rysuj_cialo(cialo,czesc_ciala,bufor);
        //dodanie dwoch elementow do ciala na samym poczatku gry
        if(kierunek && punkty==0 && cialo.koniec==NULL){
            dodaj_czesc_ciala(&cialo,glowa_x,glowa_y,kierunek);
            dodaj_czesc_ciala(&cialo,glowa_x,glowa_y,kierunek);
        }
        //sprawdzanie czy glowa najechala na reszte ciala lub sciane
        koniec = czy_zjadl_siebie(cialo,glowa_x,glowa_y);
        if(glowa_y > 690 || glowa_y < 0 || glowa_x > 1245 || glowa_x < 0){
            key[KEY_ESC] = 1;
            koniec = 200;
        }
        //sprawdzanie czy zjadla owoc
        if(glowa_x+8>=tablica_x[0] && glowa_x<=tablica_x[0]+8 && glowa_y+8>=tablica_y[0] && glowa_y<=tablica_y[0]+8){
            punkty++;
            play_sample( punkt, 255, 127, 1000, 0 );
            speed+=0.2;
            tablica_x[0]=losuj(1200);
            tablica_y[0]=losuj(700);
            dodaj_czesc_ciala(&cialo,glowa_x,glowa_y,kierunek);
        }
        //losowaine dodatkowego pozywienia
        extra2 = time(NULL);
        if(extra2>=extra){
            dodatki = 2+rand()%10;
            extra = time(NULL)+10;
            for(i=1;i<=5;i++){
                tablica_x[i] = losuj(1200);
                tablica_y[i] = losuj(700);
            }
        }
        //rysowanie dodatkowego jedzenia, sprawdzanie czy zostalo zjedzone oraz wykonywanie odpowiednich polecen, jesli zostalo zjedzone
        if(dodatki%3==0){
            masked_blit( moneta, bufor, 0, 0, tablica_x[1], tablica_y[1], moneta->w, moneta->h );
            if(glowa_x+8>=tablica_x[1] && glowa_x<=tablica_x[1]+8 && glowa_y+8>=tablica_y[1] && glowa_y<=tablica_y[1]+8){
                play_sample( kasa, 255, 127, 1000, 0 );
                punkty+=2+rand()%5;
                tablica_x[1]=losuj(1200);
                tablica_y[1]=losuj(700);
                dodatki = 2+rand()%12;
            }
        }
        if(dodatki%10==0){
            masked_blit( czaszka, bufor, 0, 0, tablica_x[2], tablica_y[2], czaszka->w, czaszka->h );
            if(glowa_x+8>=tablica_x[2] && glowa_x<=tablica_x[2]+8 && glowa_y+8>=tablica_y[2] && glowa_y<=tablica_y[2]+8){
                key[KEY_ESC] = 1;
                koniec = 200;
            }
        }
        if(dodatki%2==0){
            masked_blit( prezent, bufor, 0, 0, tablica_x[3], tablica_y[3], prezent->w, prezent->h );
            if(glowa_x+8>=tablica_x[3] && glowa_x<=tablica_x[3]+8 && glowa_y+8>=tablica_y[3] && glowa_y<=tablica_y[3]+8){
                play_sample( tada, 255, 127, 1000, 0 );
                punkty+=-5+rand()%10;
                tablica_x[3]=losuj(1200);
                tablica_y[3]=losuj(700);
                dodatki = 2+rand()%12;
            }
        }
        if(dodatki%4==0&&czas==0){
            masked_blit( gwiazda, bufor, 0, 0, tablica_x[4], tablica_y[4], gwiazda->w, gwiazda->h );
            if(glowa_x+8>=tablica_x[4] && glowa_x<=tablica_x[4]+8 && glowa_y+8>=tablica_y[4] && glowa_y<=tablica_y[4]+8){
                play_sample( star, 255, 127, 1000, 0 );
                speed = speed + 10;
                czas = time(NULL)+10;
                tablica_x[4]=losuj(1200);
                tablica_y[4]=losuj(700);
                dodatki = 2+rand()%12;
            }
        }
        if(dodatki%5==0){
            masked_blit( nuclear, bufor, 0, 0, tablica_x[5], tablica_y[5], nuclear->w, nuclear->h );
            if(glowa_x+8>=tablica_x[5] && glowa_x<=tablica_x[5]+8 && glowa_y+8>=tablica_y[5] && glowa_y<=tablica_y[5]+8){
                play_sample( usun, 255, 127, 1000, 0 );
                usun_czesc_ciala(&cialo);
                tablica_x[5]=losuj(1200);
                tablica_y[5]=losuj(700);
                dodatki = 2+rand()%12;
            }
        }
        if(time(NULL)==czas){
            speed = speed - 10;
            czas = 0;
        }
        //rysowanie owocu na ekranie gry
        masked_blit( owoc, bufor, 0, 0, tablica_x[0], tablica_y[0], owoc->w, owoc->h );
        //rysowanie ekranu gry na ekranie
        blit( bufor, screen, 0, 0, 0, 0, bufor->w, bufor->h );
        //wywolanie pauzy w przypadku wcsniecia klawisza P
        if(key[KEY_P]){
            kierunek_pomoc = kierunek;
            kierunek = pauza(punkty,bufor);
            key[KEY_P] = 0;
        }
    }
    //usuniecie ciala, sprawdzenie wyniku i wypisanie go na ekran
    if(koniec==200){
        while(cialo.koniec != cialo.poczatek){
            usun_czesc_ciala(&cialo);
        }
        sprawd(punkty,nick);
        play_sample( brawa, 255, 127, 1000, 0 );
        textout_ex( bufor, font, "PRZEGRANA", 620, 350, makecol( 0, 0, 255 ), - 1 );
        textout_ex( bufor, font, "Nacisnij ENTER aby przejsc do menu", 520, 370, makecol( 0, 0, 255 ), - 1 );
        textprintf_ex( bufor, font, 618, 360, makecol( 0, 0, 255 ), - 1, "Punkty : %d", punkty);
        blit( bufor, screen, 0, 0, 0, 0, 1280, 720 );
        while(!key[KEY_ENTER]){
        }
    }
    //brief zatrzymanie oraz usuwanie dzwiekow i bitmap uzywanych w tej funkcji.
    destroy_font(czcionka_gra);
    stop_sample( punkt );
    stop_sample( brawa );
    stop_sample( kasa );
    stop_sample( tada );
    stop_sample( usun );
    stop_sample( star );
    destroy_bitmap(bufor);
    destroy_bitmap( glowa );
    destroy_bitmap( glowa_lewo );
    destroy_bitmap(moneta);
    destroy_bitmap(czaszka);
    destroy_bitmap(nuclear);
    destroy_bitmap(gwiazda);
    destroy_bitmap(prezent);
    destroy_bitmap(czesc_ciala);
    destroy_sample( punkt );
    destroy_sample( brawa );
    destroy_sample( kasa );
    destroy_sample( tada );
    destroy_sample( usun );
    destroy_sample( star );
}

