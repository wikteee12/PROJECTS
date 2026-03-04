#include "Furniture.h"
#include "Product.h"

// Konstruktor
Furniture::Furniture(const string& name, float nettoprice, float bruttoprice,
    const string& material, const string& dimensions, const string& color)
    : Product(name, nettoprice, bruttoprice),
    f_material(material),
    f_dimensions(dimensions),
    f_color(color)
{
}

// Gettery
string Furniture::get_material() const { return f_material; }
string Furniture::get_dimensions() const { return f_dimensions; }
string Furniture::get_color() const { return f_color; }

// Display
void Furniture::display() const
{
    Product::display();
    cout << "Material: " << f_material << endl;
    cout << "Dimensions: " << f_dimensions << endl;
    cout << "Colour: " << f_color << endl << endl;
    cout << "========================================" << endl;
}