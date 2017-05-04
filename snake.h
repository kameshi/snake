#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>
#include <stdbool.h>

/**
    @file snake.h
    \brief Przechowuje deklaracje uzytych funkcji, zmiennych globalnych oraz definicje uzywanych struktur.
*/

extern volatile long predkosc;

/// \struct cialo_weza, struktura uzywana do okreslania wspolrzednych kolejnych czesci ciala na kolejce cialo.
/// \param x_ciala, wspolrzedna x elementu ciala.
/// \param y_ciala, wspolrzedna y elementu ciala.
/// \param kierunek, zmienna okreslajaca kierunek poruszania sie elementu ciala.
/// \param prev, wskaznik na poprzedni element kolejki.
/// \param next, wskaznik na nastepny element kolejki.

struct cialo_weza{
    int x_ciala;
    int y_ciala;
    int kierunek;
    struct cialo_weza * prev, *next;
};

/// \struct cialo_weza_poczatek_koniec, struktura okreslajaca wartowniki poczatku i konca kolejki cialo.
/// \param poczatek, wskaznik na pocztek kolejki.
/// \param koniec, wspaznik na koniec kolejki.

struct cialo_weza_poczatek_koniec{
    struct cialo_weza * poczatek, * koniec;
};

/// \param wyniki, tablica zawierajaca dziesiec najlepszych wynikow.
/// \struct wynik, structura bedaca pojedynczym elementem w tablicy wyniki[].
/// \param nick, nick gacza.
/// \param punkty, ilosc zdobytych punktow.

struct wynik{
    char nick[10], punkty[3];
}wyniki[10];

int losuj(int);
void sprawdzenie_bitmap(BITMAP*);
void zapisz();
void odczyt();
void szybkosc();
void wypisz_nick(BITMAP*,char*,int);
void rys_klaw(int,FONT*,BITMAP*,BITMAP*);
void pob_nick(char*);
int pauza(int,BITMAP*);
void wyp_wynik(BITMAP*);
void sprawd(int,char*);
void menu(char*);
void gra(char*);
bool dodaj_czesc_ciala(struct cialo_weza_poczatek_koniec*,int,int,int);
void rysuj_cialo(struct cialo_weza_poczatek_koniec,BITMAP*,BITMAP*);
void przesun_cialo_weza(struct cialo_weza_poczatek_koniec*,int);
int czy_zjadl_siebie(struct cialo_weza_poczatek_koniec,int,int);
void usun_czesc_ciala(struct cialo_weza_poczatek_koniec*);
void sprawdzenie_czcionek(FONT *);

#endif // SNAKE_H_INCLUDED

