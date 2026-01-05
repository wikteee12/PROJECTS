#include "Product.h"
#include "Electronics.h"
//Konstruktor
Electronics::Electronics(const string& name, float nettoprice, float bruttoprice, const string& brand, const string& model, int warranty_months)
	: Product(name, nettoprice, bruttoprice), f_brand(brand), f_model(model), f_warranty_months(warranty_months) {
}
//Gettery
string Electronics::get_brand() const
{
	return f_brand;
}

string Electronics::get_model() const
{
	return f_model;
}

int Electronics::get_warranty_months() const
{
	return f_warranty_months;
}

void Electronics::display() const
{
	// Display
	Product::display();

	
	cout << "Brand: " << f_brand << endl;
	cout << "Model: " << f_model << endl;
	cout << "Warranty: " << f_warranty_months << " month/months" << endl << endl;
	cout << "========================================" << endl;
}