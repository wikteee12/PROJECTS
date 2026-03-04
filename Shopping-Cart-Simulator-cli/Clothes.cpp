#include "Product.h"
#include "Clothes.h"

Clothes::Clothes(const string& name, float nettoprice, float bruttoprice, int size, const string& material, const string& colour)
	:Product(name, nettoprice, bruttoprice), f_size(size), f_material(material), f_colour(colour) {
}

int Clothes::get_size() const
{
	return f_size;
}

string Clothes::get_material() const
{
	return f_material;
}

string Clothes::get_colour() const
{
	return f_colour;
}

void Clothes::display() const
{
	Product::display();

	cout << "Size: " << f_size << endl;
	cout << "Material: " << f_material << endl;
	cout << "Colour: " << f_colour << endl << endl;
	cout << "========================================" << endl;
}