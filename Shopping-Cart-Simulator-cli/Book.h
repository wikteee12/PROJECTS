#pragma once
#include <string>
#include <iostream>
#include "Product.h"
using namespace std;

class Book : public Product
{
private:
    string f_author;    // np. "J.K._Rowling"
    string f_isbn;      // np. "978-3-16-148410-0"
    int f_pages;        // np. 350

public:
    Book(const string& name = "", float nettoprice = 0, float bruttoprice = 0,
        const string& author = "", const string& isbn = "", int pages = 0);

    string get_author() const;

    string get_isbn() const;

    int get_pages() const;

    void display() const;
};