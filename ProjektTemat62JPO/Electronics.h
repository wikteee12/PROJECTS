#pragma once
#include <string>
#include <iostream>
#include "Product.h"
using namespace std;

class Electronics : public Product
{
private:
	string f_brand;    // np. "Sony"
	string f_model;    // np. "WH-1000XM4"
	int f_warranty_months;  // np. 24 (miesi¹ce)

public:
	Electronics(const string& name = "", float nettoprice = 0, float bruttoprice = 0, const string& brand = "", const string& model = "", int warranty_months = 0);

	string get_brand() const;

	string get_model() const;

	int get_warranty_months() const;

	void display() const;

};