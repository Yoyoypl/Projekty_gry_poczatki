#include "map.h"
#include <iostream>
#include <conio.h>


void Map::pokaz_map()
{
    std::cout<<maps;                            // pokazujemy mape
}

void Map::start()
{

    while(true)
    {
        pokaz_map();
       char pobrany_znak = pobierz_znak();                    //tworzymy petle while w której beda wywoływane funkcje tak aby gra działała
       zmiana_poz(pobrany_znak);
       system("cls");
       
    }
}

char Map::pobierz_znak()
{
    char chwilowy_znak{};
    while(true)
    {
        chwilowy_znak = getch();
        if(chwilowy_znak == 'w'||chwilowy_znak == 's'||chwilowy_znak == 'a'||chwilowy_znak == 'd'||chwilowy_znak == 'q')           // pobieramy znak, jez eli jest zgodny z znakmia
        {                                                                                                                         // w warunku if to funkcja sie konzcy zwracjac 
            break;                                                                                                                // wartosc pobranego znaku
        }
    }
    return chwilowy_znak;

}



void Map::umiejscowienie()
{
    static int miejsce_pop;                                                                                // umiejscowienie naszej postaci na poczatku gry
    if(miejsce_pop!=0)
    {
        maps[miejsce_pop] = ' ';
    }
    maps[1+(2+1+szerokosc)*poz_y+poz_x] = charachter;
    miejsce_pop = 1+(2+1+szerokosc)*poz_y+poz_x;
}




void Map::zmiana_poz(char znak)                                                                        // zmieniamy pozycje naszej posatci, poprez wpisywanie jej 
{                                                                                                        // w odpowiednim miejscu stringa
    string czasowy;
    if(znak=='s')
    {
         poz_y++;
          if(spr_granice_y())
        {
        
         umiejscowienie();
          czy_wygrana();
        }
        else
        {
            poz_y--;
        }
    }
    if(znak=='w')
    {
         poz_y--;
     if(spr_granice_y())
        {
        
         umiejscowienie();
          czy_wygrana();
        }
        else
        {
            poz_y++;
        }
    }
    if(znak=='a')
    {  
        poz_x--;
         if(spr_granice_x())
        {
         
         umiejscowienie();
          czy_wygrana();
        }
        else
        {
            poz_x++;
        }
    }
    if(znak=='d')
    {
        poz_x++;
         if(spr_granice_x())
        {
        
         umiejscowienie();
          czy_wygrana();
        }
        else
        {
            poz_x--;
        }
       
    }
    if(znak=='q')
    {
        exit(0);
    }
   

}
bool Map::spr_granice_y()
{
    if(poz_y>11 || poz_y<=0)
    {
        return false;
    }
    else
    {
        return true;
    }
}



bool Map::spr_granice_x()
{
    if(poz_x>86 || poz_x<=0)
    {
        return false;
    }
    else
    {
        return true;
    }
}


void Map::czy_wygrana()                    //funkcja sprawdzajaca czy wygralismy gre
{
    if(poz_x==poz_x_win && poz_y==poz_y_win)
    {
        koniec();
    }
}

void Map::koniec()
{
    system("cls");
    cout<<"Wygrana !!!"<<endl;
    _sleep(1500);
    exit(0);
}

void Map::ile_szerokosz()   //funkcja liczaca szerokosc mapy
{ 
  
    char pocz  = maps[1];
    for(int i=2;pocz!=maps[i];i++)
    {
       szerokosc = i;
    }
    szerokosc-=1; // bo liczy do jednego za znakiem
   
} 

void Map::ile_dlugosc()                // funkcja liczaca dlugosc mapy
{
    char pocz  = maps[1];
 
    for(int i=szerokosc+1+2+1;pocz!=maps[i];i+=szerokosc+3)
    {
       wysokosc++;
    } 

}

Map::Map() 
{
    ile_szerokosz();
    ile_dlugosc();
    umiejscowienie();
}
