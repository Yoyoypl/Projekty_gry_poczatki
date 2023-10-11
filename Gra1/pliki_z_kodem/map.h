#ifndef MAP_H 
#define MAP_H


#include <iostream>
#include <fstream>
using namespace::std;


class Map{
public:

string maps = R"(
+--------------------------------------------------------------------------------------+
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                      |
|                                                                                   M  |
+--------------------------------------------------------------------------------------+
)";

void start();

Map();
~Map() = default;

protected:

char pobierz_znak();
void czy_wygrana();
void koniec();
bool spr_granice_y();
bool spr_granice_x();
void pokaz_map ();
void zmiana_poz (char);
void ile_szerokosz();
void ile_dlugosc();
void umiejscowienie();

char charachter = '*';
int szerokosc = 0;
int wysokosc = 0;

int poz_x = 4;
int poz_y = 2;

int poz_x_win =84 ;
int poz_y_win =11 ;

private:


};

#endif