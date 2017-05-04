#include "snake.h"

/**
    @file obsluga_plikow.c
    \brief Przechowuje definicje funkcji odczytujacych i zapisujacych do pliku 10 najlepszych wynikow.
*/

/**
    * \fn void zapisz()
    * \brief funkcja otwiera plik WYNIKI.txt (gdy plik nieistnieje tworzy nowy), zapisuje do niego 10 najlepszych wynikow z tablicy struktur wyniki[] i zamyka go.
*/

void zapisz(){
    FILE *plik;
    plik = fopen("WYNIKI.txt", "w");
    if(plik==NULL){
        allegro_message("Blad otwarcia pliku!");
        return ;
    }
    int i=0;
    for(i;i<10;i++){
        fprintf(plik, "%s\t%d\n", wyniki[i].nick, wyniki[i].punkty[0]);
    }
    if(fclose(plik)){
        allegro_message("Blad zamkniecia pliku!");
    }
}

/**
    * \fn void odczyt()
    * \brief funkcja otwiera plik WYNIKI.txt, pobiera z niego 10 najlepszych wynikow do tablicy struktur wyniki[] (gdy plik nie istnieje funkcja konczy dzialanie) i zamyka go.
*/

void odczyt(){
    FILE *plik;
    int i=0;
    plik = fopen("WYNIKI.txt", "r");
    if(plik==NULL){
        allegro_message("Nie znaleziono pliku WYNIKI.txt zostanie utworzony nowy plik podczas zapisywania.");
        return;
    }
    else{
        while(!feof(plik)){
            (fscanf(plik, "%s", wyniki[i].nick));
            (fscanf(plik, "%d", wyniki[i].punkty));
            i++;
        }
        i--;
        // petla wywolywana jest w przypadku, gdy w pliku nie ma zapisanych 10 najlepszych wynikow, zastepuje w tedy nicki '-' a punkty zerami.
        for(i;i<10;i++){
            wyniki[i].nick[0] = '-';
            wyniki[i].punkty[0] = 0;
        }
        if(fclose(plik)){
            allegro_message("Blad zamkniecia pliku!");
        }
    }
}


