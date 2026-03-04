#include "Product.h"
//Konstruktor
Product::Product(const string& name, float nettoprice, float bruttoprice) // idk czy to te¿
	: f_name(name), f_nettoprice(nettoprice), f_bruttoprice(bruttoprice) {
}
//Gettery
string Product::get_name() const
{
	return f_name;
}

float Product::get_nettoprice() const
{
	return f_nettoprice;
}

float Product::get_bruttoprice() const
{
	return f_bruttoprice;
}
//Display
void Product::display() const
{
	cout << "Name: " << f_name << endl; 
	cout << "Netto price: " << f_nettoprice << endl; 
	cout << "Brutto price: " << f_bruttoprice << endl;
}