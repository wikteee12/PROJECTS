#pragma once
#include <string>
#include <iostream>
#include "Product.h"

using namespace std;

class Toys : public Product
{
private:
    int f_min_age;       // np. 3, 7, 12 (lat)
    string f_material;   // np. "Plastik", "Drewno"
    string f_type;       // np. "Lalka", "Klocki", "Puzzle"

public:
    Toys(const string& name = "", float nettoprice = 0, float bruttoprice = 0,
        int min_age = 0, const string& material = "", const string& type = "");

    int get_min_age() const;
    string get_material() const;
    string get_type() const;

    void display() const;
};