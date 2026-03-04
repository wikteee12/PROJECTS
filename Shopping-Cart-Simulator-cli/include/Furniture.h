#pragma once
#include <string>
#include <iostream>
#include "Product.h"

using namespace std;

class Furniture : public Product
{
private:
    string f_material;    // np. "D¹b", "P³yta wiórowa"
    string f_dimensions;  // np. "120x60x75 cm"
    string f_color;       // np. "Bia³y po³ysk"

public:
    Furniture(const string& name = "", float nettoprice = 0, float bruttoprice = 0,
        const string& material = "", const string& dimensions = "", const string& color = "");

    string get_material() const;
    string get_dimensions() const;
    string get_color() const;

    void display() const;
};