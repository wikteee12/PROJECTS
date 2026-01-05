#include "Toys.h"
#include "Product.h"

// Konstruktor
Toys::Toys(const string& name, float nettoprice, float bruttoprice,
    int min_age, const string& material, const string& type)
    : Product(name, nettoprice, bruttoprice),
    f_min_age(min_age),
    f_material(material),
    f_type(type)
{
}

// Gettery
int Toys::get_min_age() const { return f_min_age; }
string Toys::get_material() const { return f_material; }
string Toys::get_type() const { return f_type; }

// Display
void Toys::display() const
{
    Product::display();
    cout << "Min: " << f_min_age << "+ years old" << endl;
    cout << "Material: " << f_material << endl;
    cout << "Type: " << f_type << endl << endl;
    cout << "========================================" << endl;
}