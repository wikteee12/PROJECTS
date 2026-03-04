// ProjektTemat62JPO.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include "DefFunctions.h"
#include <vector>
#include <map>

using namespace std;

int main()
{  
    char save;
    map<shared_ptr<Product>,int> summary; //mapa produktów dodanych do koszyka
    vector<shared_ptr<Product>> list; // wskaźniki na obiekty stworzone z pliku
    int discount = 0; //zniżka w procentach

    load_database("database.txt",list); //załadowanie produktów z predefiniowanej listy
    load_summary(summary, list, &discount); //załadowanie historii koszyka
   program_loop(summary, list, &discount); //Pętla głowna programu

   cout << "Do you want to save your cart history? (y/n)"; 
   cin >> save;

   if (save == 'y')
   {
       cout << "History saved successfully" << endl;
       save_summary(summary, list, &discount);
   }

   
}


