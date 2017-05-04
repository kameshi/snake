#include "snake.h"

/**
    @file cialo_weza.c
    \brief Przechowuje definicje funkcji operujacych na ciele weza.
*/

/**
    * \fn bool dodaj_czesc_ciala(struct cialo_weza_poczatek_koniec *cialo , int x_ciala, int y_ciala, int kierunek)
    * \brief funkcja dodaje wspolrzedne pojedynczej czesci ciala, do calego ciala weza.
    * \param cialo, wskaznik na strukture przechowujaca wskazniki na poczatek i koniec ciala weza.
    * \param glowa_x, wspolrzedne x glowy weza.
    * \param glowa_y, wspolrzedne y glowy weza.
    * \param kierunek, zmienna przechowuje kierunek w ktorym porusza sie glowa weza
    * \return true w przypadku udanej operacji dodania.
    * \return false w przypadku niepowodzenia.
*/

bool dodaj_czesc_ciala(struct cialo_weza_poczatek_koniec *cialo , int glowa_x, int glowa_y, int kierunek){
    struct cialo_weza * nowa_czesc = (struct cialo_weza *)malloc(sizeof(struct cialo_weza));
    if (NULL != nowa_czesc){
        nowa_czesc -> next = NULL;
        if(NULL == cialo -> poczatek){
            nowa_czesc -> kierunek = kierunek;
            if(nowa_czesc->kierunek==1){
                nowa_czesc -> x_ciala = glowa_x+15;
                nowa_czesc -> y_ciala = glowa_y;
            }
            else if(nowa_czesc->kierunek==2){
                nowa_czesc -> x_ciala = glowa_x-15;
                nowa_czesc -> y_ciala = glowa_y;
            }
            else if(nowa_czesc->kierunek==3){
                nowa_czesc -> x_ciala = glowa_x;
                nowa_czesc -> y_ciala = glowa_y+15;
            }
            else if(nowa_czesc->kierunek==4){
                nowa_czesc -> x_ciala = glowa_x;
                nowa_czesc -> y_ciala = glowa_y-15;
            }
            nowa_czesc -> prev = NULL;
            cialo -> poczatek = cialo -> koniec = nowa_czesc;
        }
        else{
            nowa_czesc -> kierunek = cialo->koniec->kierunek;
            if(nowa_czesc->kierunek==1){
                nowa_czesc -> x_ciala = cialo->koniec->x_ciala+15;
                nowa_czesc -> y_ciala = cialo->koniec->y_ciala;
            }
            else if(nowa_czesc->kierunek==2){
                nowa_czesc -> x_ciala = cialo->koniec->x_ciala-15;
                nowa_czesc -> y_ciala = cialo->koniec->y_ciala;
            }
            else if(nowa_czesc->kierunek==3){
                nowa_czesc -> x_ciala = cialo->koniec->x_ciala;
                nowa_czesc -> y_ciala = cialo->koniec->y_ciala+15;
            }
            else if(nowa_czesc->kierunek==4){
                nowa_czesc -> x_ciala = cialo->koniec->x_ciala;
                nowa_czesc -> y_ciala = cialo->koniec->y_ciala-15;
            }
            cialo ->koniec -> next = nowa_czesc;
            nowa_czesc -> prev = cialo -> koniec;
            cialo -> koniec = nowa_czesc;
        }
    return true ;
    }
    return false ;
}

/**
    * \fn void rysuj_cialo(struct cialo_weza_poczatek_koniec cialo, BITMAP * czesc_ciala, BITMAP * bufor)
    * \brief Funkcja rysujaca  cialo weza.
    * \param cialo, struktura przechowujaca wskazniki na poczatek i koniec ciala weza.
    * \param czesc_ciala, wskaznik na bitmape bedaca jedna pojedyncza czescia ciala.
    * \param bufor, wskaznik na bitmape ktora sluzy do podwojnego buforowania.
*/

void rysuj_cialo(struct cialo_weza_poczatek_koniec cialo, BITMAP * czesc_ciala, BITMAP * bufor){
    for(; NULL != cialo.poczatek ; cialo.poczatek = cialo.poczatek->next){
        blit( czesc_ciala, bufor, 0, 0, cialo.poczatek->x_ciala, cialo.poczatek->y_ciala, czesc_ciala->w, czesc_ciala->h );
    }
}

/**
    * \fn void przesun_cialo_weza(struct cialo_weza_poczatek_koniec *cialo, int kierunek)
    * \brief Funkcja zmieniajaca wartosc zmiennych x_ciala i y_ciala, tak aby kazdy klocek podazal za glowa weza.
    * \param cialo, wskaznik na strukture przechowujaca wskazniki na poczatek i koniec ciala weza.
    * \param kierunek, zmiennea przechowuje kierunek w ktorym porusza sie glowa weza.
*/

void przesun_cialo_weza(struct cialo_weza_poczatek_koniec *cialo, int kierunek){
    struct cialo_weza_poczatek_koniec dodatkowa = {NULL,NULL};
    dodatkowa.koniec = cialo->koniec;
    for(; NULL!=cialo->koniec->prev; cialo->koniec=cialo->koniec->prev){
        if(cialo->koniec->kierunek==1){
            cialo->koniec -> x_ciala -= 15;
        }
        else if(cialo->koniec->kierunek==2){
            cialo->koniec -> x_ciala += 15;
        }
        else if(cialo->koniec->kierunek==3){
            cialo->koniec -> y_ciala -= 15;
        }
        else if(cialo->koniec->kierunek==4){
            cialo->koniec -> y_ciala += 15;
        }
        cialo->koniec->kierunek=cialo->koniec->prev->kierunek;
    }
    if(cialo->koniec->kierunek==1){
        cialo->koniec -> x_ciala -= 15;
    }
    else if(cialo->koniec->kierunek==2){
        cialo->koniec -> x_ciala += 15;
    }
    else if(cialo->koniec->kierunek==3){
        cialo->koniec -> y_ciala -= 15;
    }
    else if(cialo->koniec->kierunek==4){
        cialo->koniec -> y_ciala += 15;
    }
    cialo->koniec->kierunek=kierunek;
    cialo->koniec = dodatkowa.koniec;
}

/**
    * \fn int czy_zjadl_siebie(struct cialo_weza_poczatek_koniec cialo, int glowa_x, int glowa_y)
    * \brief Funkcja sprawdzajaca, czy glowa weza najechala na reszte ciala.
    * \param cialo, struktura przechowujaca wskazniki na poczatek i koniec ciala weza.
    * \param glowa_x, wspolrzedne x glowy weza.
    * \param glowa_y, wspolrzedne y glowy weza.
    * \return 200 w przypadku potwierdzenia najechania glowy na reszte ciala.
*/

int czy_zjadl_siebie(struct cialo_weza_poczatek_koniec cialo, int glowa_x, int glowa_y){
    for(; NULL != cialo.poczatek ; cialo.poczatek = cialo.poczatek->next){
        if(glowa_x+8>=cialo.poczatek->x_ciala && glowa_x<=cialo.poczatek->x_ciala+8 && glowa_y+8>=cialo.poczatek->y_ciala && glowa_y<=cialo.poczatek->y_ciala+8){
            key[KEY_ESC] = 1;
            return 200;
        }
    }
    return 0;
}

/**
    * \fn void usun_czesc_ciala(struct cialo_weza_poczatek_koniec *cialo)
    * \brief Funkcja usuwajaca dwa ostatnie elementy z ciala weza.
    * \param cialo, wskaznik na strukture przechowujaca wskazniki na poczatek i koniec ciala weza.
*/

void usun_czesc_ciala(struct cialo_weza_poczatek_koniec *cialo){
    int i;
    struct cialo_weza *tmp;
    for(i=0; i<2; i++){
        if (NULL != cialo -> koniec){
            if(cialo->koniec!=cialo->poczatek){
                tmp = cialo->koniec->prev;
                free(cialo -> koniec) ;
                cialo -> koniec= tmp ;
                cialo -> koniec -> next = NULL;
            }
            else{
                free(cialo -> koniec) ;
                cialo -> koniec = cialo -> poczatek = NULL ;
            }
        }
    }
}
