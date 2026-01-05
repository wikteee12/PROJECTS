#include "Product.h"
#include "Book.h"

// Konstruktor
Book::Book(const string& name, float nettoprice, float bruttoprice,
    const string& author, const string& isbn, int pages)
    : Product(name, nettoprice, bruttoprice), // Wywo³anie konstruktora klasy bazowej (Product)
    f_author(author),
    f_isbn(isbn),
    f_pages(pages)
{

}

// Gettery
string Book::get_author() const
{
    return f_author;
}

string Book::get_isbn() const
{
    return f_isbn;
}

int Book::get_pages() const
{
    return f_pages;
}

// Metoda wyœwietlaj¹ca
void Book::display() const
{
    // 1. Wyœwietlamy podstawowe dane z klasy Product
    Product::display(); 

    // 2. Wyœwietlamy specyficzne dane dla Ksi¹¿ki
    cout << "Author: " << f_author << endl;
    cout << "ISBN: " << f_isbn << endl;
    cout << "Pages: " << f_pages << endl << endl;
    cout << "========================================" << endl;
}