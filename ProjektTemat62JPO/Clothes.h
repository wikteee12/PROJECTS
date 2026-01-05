#pragma once
#include <string>
#include <iostream>
#include "Product.h"
using namespace std;

class Clothes : public Product
{
private:
	int f_size; // np.55 
	string f_material; //jeans
	string f_colour; //niebieski

public:
	Clothes(const string& name = "", float nettoprice = 0, float bruttoprice = 0, int size = 0, const string& material = "", const string& colour = "");

	int get_size() const;

	string get_material() const;

	string get_colour() const;

	void display() const;
};