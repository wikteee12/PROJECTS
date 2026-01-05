#pragma once
#include <string>
#include <iostream>
using namespace std;

class Product
{
private:
	string f_name;
	float f_nettoprice;
	float f_bruttoprice;

public:
	Product(const string& name = "", float nettoprice = 0, float bruttoprice = 0);

	string get_name() const;

	float get_nettoprice() const;

	float get_bruttoprice() const;

	virtual void display() const;

};