#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
#include <map>
#include <algorithm>
#include <iomanip>

#include "Product.h"
#include "Clothes.h"
#include "Furniture.h"
#include "Electronics.h"
#include "Book.h"
#include "Toys.h"


using namespace std;

void displayshop(const vector<shared_ptr<Product>>& list,int page, int elements_on_page);  //Wyœwietlanie sklepu

void load_database(string database_name, vector<shared_ptr<Product>>& list); //Do³¹czenie do programu predefiniowanej listy przedmiotów w sklepie i tworzenie obiektów (przedmiotów)

void program_loop(map<shared_ptr<Product>, int>& summary,const vector<shared_ptr<Product>>& list, int* discount); //G³ówna pêtla programu

bool isInteger(const string& isint); //sprawdzenie czy liczba jest typu integer

void save_summary(const map<shared_ptr<Product>, int>& summary, const vector<shared_ptr<Product>>& list, int* discount); //zapisanie podsumowania do pliku(zni¿ka,koszyk)

void load_summary(map<shared_ptr<Product>, int>& summary, const vector<shared_ptr<Product>>& list, int* discount); //odczytanie podsumowania z pliku (zni¿ka,koszyk
